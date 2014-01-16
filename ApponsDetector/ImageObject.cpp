// ImageObject.cpp : Implementation of CImageObject

#include "stdafx.h"
#include "ImageObject.h"
#include ".\imageobject.h"


// CImageObject


STDMETHODIMP CImageObject::get_ImageDataAddress(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (LONG)m_DataBase;
	return S_OK;
}
STDMETHODIMP  CImageObject::put_ImageDataAddress(LONG newVal)
{
	// TODO: Add your implementation code here
	//Update the image pointer when the frame ready
	m_DataBase = (BYTE*)newVal;
		return S_OK;
}

STDMETHODIMP CImageObject::get_Width(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Width;
	return S_OK;
}

STDMETHODIMP CImageObject::get_Height(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Height;
	return S_OK;
}

STDMETHODIMP CImageObject::get_BytesPerPixel(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_BytesPerPixel;
	return S_OK;
}

STDMETHODIMP CImageObject::get_Pixel(LONG X, LONG Y, LONG* pVal)
{
	// TODO: Add your implementation code here
	switch(m_BytesPerPixel)
	{
		case 2:
			*pVal = *((WORD*)(m_DataBase+m_YTable[Y]+m_XTable[X]));
			break;
		case 1:
			*pVal = *((BYTE*)(m_DataBase+m_YTable[Y]+m_XTable[X]));
			break;
	} 
	return S_OK;
}

STDMETHODIMP CImageObject::put_Pixel(LONG X, LONG Y, LONG newVal)
{
	// TODO: Add your implementation code here
	switch(m_BytesPerPixel)
	{
	case 2:
		*(WORD*)(&(m_DataBase[m_YTable[Y]+m_XTable[X]])) = (WORD)newVal;
		break;
	case 1:
		m_DataBase[m_YTable[Y]+m_XTable[X]] = (BYTE)newVal;
		break;
	}
	return S_OK;
}

STDMETHODIMP CImageObject::Open(LONG Width, LONG Height, LONG BytesPerPixel)
{
	// TODO: Add your implementation code here
	m_Width = Width;
	m_Height = Height;
	m_BytesPerPixel = BytesPerPixel;
	if(m_XTable)
		delete [] m_XTable ;
	m_XTable = new LONG [m_Width];
	if(m_YTable)
		delete [] m_YTable ;
	m_YTable = new LONG [m_Height];
	for(int i = 0; i<m_Width;i++)
	{
		m_XTable[i] = i*m_BytesPerPixel; 
	}
	for(int i = 0; i<m_Height;i++)
	{
		m_YTable[i] = i*m_Width*m_BytesPerPixel;
	}
	return S_OK;
}

STDMETHODIMP CImageObject::get_ImageLineAddress(LONG LineIndex, LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_YTable[LineIndex]+(LONG)m_DataBase;
	return S_OK;
}


STDMETHODIMP CImageObject::ColAverage(LONG* pAvg)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::ColMax(LONG* pMax)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::ColMin(LONG* pMin)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::RowMin(LONG* pMin)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::RowMax(LONG* pMax)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::RowAverage(LONG* pAvg)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::ColNoise(FLOAT* pNoise)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CImageObject::RowNoise(FLOAT* pNoise)
{
	// TODO: Add your implementation code here

	return S_OK;
}
