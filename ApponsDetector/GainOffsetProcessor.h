#pragma once
class CGainOffsetProcessor
{
public:
	CGainOffsetProcessor(void);
	~CGainOffsetProcessor(void);
	void setOffsetImage(BYTE* src, long len);
	void setXrayImage(BYTE* src, long len, long level);
	void caculateGain(); //do calculation base on offset gain image
	void gainEnable(bool bEnable);
	void offsetEnable(bool bEnable);
	void process(BYTE* target, BYTE* src, long len);//process one line

private:

};

