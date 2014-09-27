#ifndef PIXELORDERCONVERTER_H
#define PIXELORDERCONVERTER_H
#include "stdafx.h"
#include <assert.h>
#include "ImageObject.h"
#include <omp.h>
class PixelOrderConverter
{
public:
    PixelOrderConverter(int bNum, int pNum)
    {
        boardNum = bNum;
        pixelNum = pNum;
    }

    virtual ~PixelOrderConverter() {}
    virtual void process(IImageObject* src, LONG  RowID, LONG NumLines)=0;
protected:
    int boardNum;
    int pixelNum;
};

class RevertConverter
{
	void convertLine(WORD* src, int width)
	{
		//Low Energy Area. First half part
		for(int i=0; i < width ; i++) {
			src[i] = 0xFF - src[i];
		}
	}

	public:
     void process(IImageObject* src, LONG  RowID, LONG NumLines)
	{
		long width = 0;
		src->get_Width(&width);
		long height = 0;
		src->get_Height(&height);

		//assert(width == boardNum*pixelNum);
		int i=0;
		int startline = RowID;
		int endline = RowID + NumLines;

#pragma omp parallel for private(i) shared( width, endline, startline) 
		for(i = startline; i < endline; i++) {
			long pline = 0;
			src->get_ImageLineAddress(i, &pline);
			convertLine((WORD*)pline, width);
		}
#pragma omp barrier
	}

};
class DualToSingleConverter: public PixelOrderConverter
{
public:
    DualToSingleConverter(int boardNum, int pixelNum,int revertValue = 0): PixelOrderConverter(boardNum,pixelNum)
    {
        int size = boardNum*pixelNum;
		revert = revertValue;
    }
    ~DualToSingleConverter()
    {
   
    }

    virtual void process(IImageObject* src, LONG  RowID, LONG NumLines)
    {
        long width = 0;
		src->get_Width(&width);
        long height = 0;
		src->get_Height(&height);
        
        assert(width == boardNum*pixelNum);
		int i=0;
		int startline = RowID;
		int endline = RowID + NumLines;

#pragma omp parallel for private(i) shared( width, endline, startline) 
        for(i = startline; i < endline; i++) {
			long pline = 0;
			src->get_ImageLineAddress(i, &pline);
            convertLine((WORD*)pline, width);
        }
#pragma omp barrier
    }
 private:

    //WORD* buffer;
	int revert;

    void copyBlock(WORD* dest, WORD* src, int srcIndex, int destIndex)
    {
        memcpy (dest+destIndex*pixelNum, src+srcIndex*pixelNum, pixelNum*2);
    }

    void convertLine(WORD* src, int width)
    {
		WORD* buffer = new WORD[width];
        int blockNum = boardNum ;
        //Low Energy Area. First half part
        for(int i=0; i < blockNum/2 ; i++) {
           // copyBlock(buffer, src, i, i*2);
			copyBlock(buffer, src, i*2, i);
        }
        //High Energy Area. Sencond half part
        for(int i = blockNum/2; i < blockNum ; i++) {
            //copyBlock(buffer, src, i, i*2-blockNum+1);
			copyBlock(buffer, src, i*2-blockNum+1, i);
        }
		if(revert) {
			for(int i=0; i < width; i++) {
				buffer[i] = 0xFF - buffer[i];
			}
		}
        memcpy(src, buffer, width*2);
		delete[] buffer;
    }

};

#endif // PIXELORDERCONVERTER_H
