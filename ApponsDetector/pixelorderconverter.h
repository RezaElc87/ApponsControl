#ifndef PIXELORDERCONVERTER_H
#define PIXELORDERCONVERTER_H
#include "stdafx.h"
#include <assert.h>
#include "ImageObject.h"

class PixelOrderConverter
{
public:
    PixelOrderConverter(int bNum, int pNum)
    {
        boardNum = bNum;
        pixelNum = pNum;
    }

    virtual ~PixelOrderConverter() {}
    virtual void process(IImageObject* src)=0;
protected:
    int boardNum;
    int pixelNum;
};

class DualToSingleConverter: public PixelOrderConverter
{
public:
    DualToSingleConverter(int boardNum, int pixelNum): PixelOrderConverter(boardNum,pixelNum)
    {
        int size = boardNum*pixelNum;
        buffer = new WORD[size];
    }
    ~DualToSingleConverter()
    {
        delete[] buffer;
    }

    virtual void process(IImageObject* src)
    {
        long width = 0;
		src->get_Width(&width);
        long height = 0;
		src->get_Height(&height);
        
        assert(width == boardNum*pixelNum);
        for(int i=0; i< height; i++) {
			long pline = 0;
			src->get_ImageLineAddress(i, &pline);
            convertLine((WORD*)pline, width);
        }
    }
 private:

    WORD* buffer;


    void copyBlock(WORD* src, int srcIndex, int destIndex)
    {
        memcpy (buffer+destIndex*pixelNum, src+srcIndex*pixelNum, pixelNum*2);
    }

    void convertLine(WORD* src, int width)
    {
        int blockNum = boardNum ;
        //Low Energy Area. First half part
        for(int i=0; i < blockNum/2 ; i++) {
            copyBlock(src, i, i*2);
        }
        //High Energy Area. Sencond half part
        for(int i = blockNum/2; i < blockNum ; i++) {
            copyBlock(src, i, i*2-blockNum+1);
        }
        memcpy(src, buffer, width*2);
    }

};

#endif // PIXELORDERCONVERTER_H
