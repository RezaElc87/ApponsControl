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
	
	if(m_ColMax)
		delete [] m_ColMax;
	if(m_ColAvg)
		delete [] m_ColAvg;
	if(m_ColMin)
		delete [] m_ColMin;
	if(m_RowAvg)
		delete [] m_RowAvg;
	if(m_RowMax)
		delete [] m_RowMax;
	if(m_RowMin)
		delete [] m_RowMin;

	m_YTable = new LONG [m_Height];

	m_ColMax = new double[m_Width];
	m_ColAvg = new double[m_Width];
    m_ColMin = new double [m_Width];

	m_RowAvg = new double[m_Height];
	m_RowMax = new double [m_Height];
    m_RowMin = new double [m_Height];

	for(int i = 0; i<m_Width;i++)
	{
		m_XTable[i] = i*m_BytesPerPixel; 
		m_ColAvg [i] = 0;
		m_ColMax [i] = 0;
		m_ColMin [i] = 0xFFFF;
	}

	for(int i = 0; i<m_Height;i++)
	{
		m_YTable[i] = i*m_Width*m_BytesPerPixel;
		m_RowAvg [i]= 0;
		m_RowMax [i]= 0;
		m_RowMin [i]= 0;
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
	*pAvg = (long)m_ColAvg;

	return S_OK;
}

STDMETHODIMP CImageObject::ColMax(LONG* pMax)
{
	*pMax = (long)m_ColMax;
	return S_OK;
}

STDMETHODIMP CImageObject::ColMin(LONG* pMin)
{
	*pMin = (long) m_ColMin;
	return S_OK;
}

STDMETHODIMP CImageObject::RowMin(LONG* pMin)
{
	*pMin = (long)m_RowMin;
	return S_OK;
}

STDMETHODIMP CImageObject::RowMax(LONG* pMax)
{
	*pMax = (long)m_RowMax;
	return S_OK;
}

STDMETHODIMP CImageObject::RowAverage(LONG* pAvg)
{
	*pAvg = (long)m_RowAvg;
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


STDMETHODIMP CImageObject::DoColStatistic(void)
{
	long i =0;
	long j = 0;
	long pbase;
	long val;
	for(j=0; j < m_Height;j++ ) {
		get_ImageLineAddress(j,&pbase);
		for(i=0; i < m_Width; i++) {
			if(2 == m_BytesPerPixel) {
				val = *(((WORD*)pbase)+i);
				m_ColAvg[i] += val;
				if (val > m_ColMax[i])
					m_ColMax[i] = val;
				if (val < m_ColMin[i])
					m_ColMin[i] = val;
			}
		}
	}

	for(i=0; i < m_Width; i++)
		m_ColAvg[i] /= m_Height;

	return S_OK;
}


STDMETHODIMP CImageObject::DoRowStatistic(void)
{
	long i =0;
	long j = 0;
	long pbase;
	long val;
	for(j=0; j < m_Width;j++ ) {
		get_ImageLineAddress(j,&pbase);
		for(i=0; i < m_Width; i++) {
			if(2 == m_BytesPerPixel) {
				val = *(((WORD*)pbase)+i);
				m_RowAvg[j] += val;
				if (val > m_RowMax[i])
					m_RowMax[i] = val;
				if (val < m_ColMin[i])
					m_RowMin[i] = val;
			}
		}
		m_RowAvg[j] /=m_Width;

	}
	return S_OK;
}
