// ImageObject.h : Declaration of the CImageObject

#pragma once
#include "resource.h"       // main symbols


// IImageObject
[
	object,
	uuid("2668B542-3FBD-46B8-A1DE-FF9CD383325D"),
	dual,	helpstring("IImageObject Interface"),
	pointer_default(unique)
]
__interface IImageObject : IDispatch
{
	[propget, id(1), helpstring("property ImageDataAddress")] HRESULT ImageDataAddress([out, retval] LONG* pVal);
	[propput, id(1), helpstring("property ImageDataAddress")] HRESULT ImageDataAddress([in] LONG newVal);
	[propget, id(2), helpstring("property Width")] HRESULT Width([out, retval] LONG* pVal);
	[propget, id(3), helpstring("property Height")] HRESULT Height([out, retval] LONG* pVal);
	[propget, id(4), helpstring("property BytesPerPixel")] HRESULT BytesPerPixel([out, retval] LONG* pVal);
	[propget, id(5), helpstring("property Pixel")] HRESULT Pixel([in] LONG X, [in] LONG Y, [out, retval] LONG* pVal);
	[propput, id(5), helpstring("property Pixel")] HRESULT Pixel([in] LONG X, [in] LONG Y, [in] LONG newVal);
	[id(6), helpstring("method Open")] HRESULT Open([in] LONG Width, [in] LONG Height, [in] LONG BytesPerPixel);
	[propget, id(7), helpstring("property ImageLineAddress")] HRESULT ImageLineAddress([in] LONG LineIndex, [out, retval] LONG* pVal);
	[id(8), helpstring("method ColAverage")] HRESULT ColAverage([out] LONG* pAvg);
	[id(9), helpstring("method ColMax")] HRESULT ColMax([out] LONG* pMax);
	[id(10), helpstring("method ColMin")] HRESULT ColMin([out] LONG* pMin);
	[id(11), helpstring("method RowMin")] HRESULT RowMin([out] LONG* pMin);
	[id(12), helpstring("method RowMax")] HRESULT RowMax([out] LONG* pMax);
	[id(13), helpstring("method RowAverage")] HRESULT RowAverage(LONG* pAvg);
	[id(14), helpstring("method ColNoise")] HRESULT ColNoise([out] FLOAT* pNoise);
	[id(15), helpstring("method RowNoise")] HRESULT RowNoise([out] FLOAT* pNoise);
};



// CImageObject

[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.ImageObject"),
	progid("DTControl.ImageObject.1"),
	version(1.0),
	uuid("C3BDF6C3-7738-41FE-97F9-618B28F4F82B"),
	helpstring("ImageObject Class")
]
class ATL_NO_VTABLE CImageObject : 
	public IImageObject
{
public:
	CImageObject()
	{
		m_Width = 0;
		m_Height = 0;
		m_BytesPerPixel = 2;
		m_XTable = NULL;
		m_YTable = NULL;
		m_DataBase = NULL;
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
		if(m_XTable)
			delete [] m_XTable;
			
		if(m_YTable)
			delete [] m_YTable;
	}

public:
	
	STDMETHOD(get_ImageDataAddress)(LONG* pVal);
	STDMETHOD(put_ImageDataAddress)(LONG newVal);
	STDMETHOD(get_Width)(LONG* pVal);
	STDMETHOD(get_Height)(LONG* pVal);
	STDMETHOD(get_BytesPerPixel)(LONG* pVal);
	STDMETHOD(get_Pixel)(LONG X, LONG Y, LONG* pVal);
	STDMETHOD(put_Pixel)(LONG X, LONG Y, LONG newVal);
private:
	LONG m_Width;
	LONG m_Height;
	LONG m_BytesPerPixel;
	LONG* m_XTable;
	LONG* m_YTable;
	BYTE* m_DataBase;

	
public:
	STDMETHOD(Open)(LONG Width, LONG Height, LONG BytesPerPixel);
	STDMETHOD(get_ImageLineAddress)(LONG LineIndex, LONG* pVal);
	STDMETHOD(ColAverage)(LONG* pAvg);
	STDMETHOD(ColMax)(LONG* pMax);
	STDMETHOD(ColMin)(LONG* pMin);
	STDMETHOD(RowMin)(LONG* pMin);
	STDMETHOD(RowMax)(LONG* pMax);
	STDMETHOD(RowAverage)(LONG* pAvg);
	STDMETHOD(ColNoise)(FLOAT* pNoise);
	STDMETHOD(RowNoise)(FLOAT* pNoise);
};

