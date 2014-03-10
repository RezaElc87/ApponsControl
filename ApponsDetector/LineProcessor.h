#pragma once
#include "stdafx.h"
#define  MAX_PIXEL_NUM 8192
#define ARRAY_SIZE 100
class CLineProcessor
{

public:
	CLineProcessor(void) {}
	virtual ~CLineProcessor(void) {};

	virtual void process (WORD* src, long len) = 0;

};

class CArrayCorrectionProcessor: public CLineProcessor
{
	struct map{
		WORD target;
		double* data;
	};
	map mapArray[ARRAY_SIZE];

public:
	CArrayCorrectionProcessor()
	{
		for(int i=0; i<ARRAY_SIZE; i++){
			mapArray[i].target = 0xFFFF;
			mapArray[i].data = NULL;
		}
	}
	~CArrayCorrectionProcessor() 
	{
		reset();
	}
	void reset()
	{
		for(int i=0; i<ARRAY_SIZE; i++){
			mapArray[i].target = 0xFFFF;
			if(mapArray[i].data) {
				delete [] mapArray[i].data;
				mapArray[i].data = NULL;
			}
		}
	}

	void addData(double* src, long width)
	{
		int i = 0;
		double* data = new double[width];
		double avg = 0;
		memcpy(data,src, width* sizeof(double));
		for(i=0;i<width;i++){
			avg += data[i];
		}
		avg /= width;
		//find proper location for data
		map temp;
		temp.data = data;
		temp.target = avg;
		for(i=0; i< ARRAY_SIZE; i++) {
			if(mapArray[i].target >= avg) {
				break;
			}
		}

		for(int j=i; j <(ARRAY_SIZE-1);j++) {
			mapArray[i] = temp;
			temp = mapArray[i+1];
			if(temp.target == 0xFFFF)
				break;
		}
	}

	WORD arrayCorrection(WORD val, long pixel)
	{
		//find the location of the val,
		long i = 0;
		double target = 0;
		double d = 0;
		double factor = 0;
		for(i=1; i < ARRAY_SIZE; i++)
		{
			if(mapArray[i].target != 0xFFFF) {
				if(mapArray[i].data[pixel] > val) {
					//the pixel map is between target i and target i-1		
					d = mapArray[i].target - mapArray[i-1].target;
					factor = (val - mapArray[i-1].data[pixel])/(mapArray[i].data[pixel] - mapArray[i-1].data[pixel]);
					target = d*factor+mapArray[i-1].target;
					return target;
				}
			} else 
				break;
		}
		//Something wrong cannot find map value return the input
		d = mapArray[i-1].target - mapArray[i-2].target;
		factor = (val - mapArray[i-2].data[pixel])/(mapArray[i-1].data[pixel] - mapArray[i-2].data[pixel]);
		target = d*factor+mapArray[i-2].target ;
		return target ;
	}

	void process(WORD* src, long pixelNum) {
		if(pixelNum > MAX_PIXEL_NUM) {
			ATLTRACE("Pixel Number is %d , exceed range\n", pixelNum);
			return;
		}
		int i = 0;
		for (i=0; i<pixelNum; i++) {
			src[i] = arrayCorrection(src[i], i);
		}
	}
};

class CGainProcessor: public CLineProcessor
{
	float gain[MAX_PIXEL_NUM];
public:
	void setGain(float val, long pixel)
	{
		gain[pixel] = val;
	}

	void process(WORD* src, long pixelNum) {
		int i = 0;
		if(pixelNum > MAX_PIXEL_NUM) {
			ATLTRACE("Pixel Number is %d , exceed range\n", pixelNum);
			return;
		}
		for (i=0; i<pixelNum; i++) {
			src[i] *= gain[i];
		}
	}
};

class COffsetProcessor: public CLineProcessor
{
	unsigned int offset[MAX_PIXEL_NUM]; 
public:
	void setOffset (unsigned int val, long pixel)
	{
		if(pixel > MAX_PIXEL_NUM) {
			ATLTRACE("Pixel Number is %d , exceed range\n", pixel);
			return;
		}
		
		offset[pixel] = val;
	}

	void process(WORD* src, long pixelNum) 
	{
		if(pixelNum > MAX_PIXEL_NUM) {
			ATLTRACE("Pixel Number is %d , exceed range\n", pixelNum);
			return;
		}
		int i = 0;
		for (i=0; i<pixelNum; i++) {
			src[i] -= offset[i];
		}
	}
};

class CPixelOrderProcessor: public CLineProcessor
{
	WORD buf[2048];
public:
	void process(WORD* src, long pixelNum) 
	{
		if(pixelNum > 2048) 
		{
			ATLTRACE("Pixel Number is %d , exceed range\n", pixelNum);
			return;
		}
		int i = 0;
		int j = 0;
		for(i = 0; i < pixelNum/2; i++){
			buf[i] = src[i*2];
		}

		for(i = 0; i < pixelNum/2; i++){
			buf[pixelNum/2 + i] = src[i*2+1];
		}
		memcpy(src, buf, pixelNum*2);
	}
};