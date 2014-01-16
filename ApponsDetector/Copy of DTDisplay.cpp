// DTDisplay.cpp : Implementation of CDTDisplay
#include "stdafx.h"
#include "DTDisplay.h"
#include ".\dtdisplay.h"
#include <math.h>
#include <comutil.h>
#include "DTImage.h"

// CDTDisplay
#define DISP_BLANK_H	20
#define DISP_BLANK_W	20
#define DISP_ORG_X		10
#define DISP_ORG_Y		10
#define DISP_SCROLL_W		10

STDMETHODIMP CDTDisplay::get_DataSource(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	LONG val = (LONG)m_pDataSrc;
	*pVal = (IUnknown*) val;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_DataSource(IUnknown* newVal)
{
	// TODO: Add your implementation code here
	LONG val = (LONG)newVal;
	if(newVal)
		ConnectDataSrc(((CDTImage*)val));
	else
		DisConnectDataSrc();
	return S_OK;
}

void CDTDisplay::OnFrameReady(LONG LineNum)
{
	//Refresh Dipslay buffer use m_pImageObject
};
void CDTDisplay::OnSubFrameReady(LONG NumOfBlockLeft, LONG StartLine, LONG NumLines, BYTE bLastBlock)
{
	//Refresh the Buffer 
};

STDMETHODIMP CDTDisplay::get_DisplayControl(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	*pVal = (IUnknown*) m_pDisplayControl;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_DisplayControl(IUnknown* newVal)
{
	// TODO: Add your implementation code here
	if(newVal)
		ConnectDisplayControl((CDTDisplayControl*)newVal);
	else
		DisConnectDisplayControl();	
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_Gamma(FLOAT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Gamma;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_Gamma(FLOAT newVal)
{
	// TODO: Add your implementation code here
	newVal = m_Gamma;
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_MapStart(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_mapStart;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_MapStart(LONG newVal)
{
	// TODO: Add your implementation code here
	m_mapStart = newVal;
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_MapEnd(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_mapEnd;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_MapEnd(LONG newVal)
{
	// TODO: Add your implementation code here
	m_mapEnd = newVal;
	return S_OK;
}
void CDTDisplay::InitializeLUT()
{		
		m_Gamma = 1.0;
		m_mapStart = 0;
		m_mapEnd = 0xFF;
		SetWindowing();
}


void CDTDisplay::SetWindowing()
{
	
	int map_extend;
	map_extend = abs(m_mapEnd-m_mapStart);
	if((m_mapStart>MAX_ADC)||(m_mapEnd > MAX_ADC))
	{//if start or end more than MAX_ADC, then need increase the MAC_ADC
		m_mapStart %= MAX_ADC; 
		m_mapEnd %= MAX_ADC;
	}
	//(MAX_GRAY- MIN_GRAY)
	if(m_mapStart <= m_mapEnd)
	{
		for(int i=0;i<=m_mapStart;i++)
		{
			m_LUT[i] = 0;
		}
		for(i=m_mapEnd;i<MAX_ADC;i++)
		{
			m_LUT[i] = 255;
		};
		for( i=m_mapStart;i<m_mapEnd;i++)
		{
			int extend = 255;
			float fscale = ((float)(i-m_mapStart))/map_extend ;
			m_LUT[i] = pow( fscale,m_Gamma)*extend;
		}
	}
	else//Start > End
	{
		for(int i=m_mapStart;i<MAX_ADC;i++)
		{
			m_LUT[i] = 0;
		}
		for(i=0;i<=m_mapEnd;i++)
		{
			m_LUT[i] = 255;
		};
		for(i=m_mapEnd;i<m_mapStart;i++)
		{
			int extend = 255;
			float fscale = (float)(i-m_mapEnd)/map_extend ;
			m_LUT[m_mapStart-i+m_mapEnd] = pow( fscale,m_Gamma)*extend;
		}
	}
}

STDMETHODIMP CDTDisplay::get_Width(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Width;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_Width(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_Width = newVal;
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_Height(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Height;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_Height(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_Height = newVal;
	return S_OK;
}

STDMETHODIMP CDTDisplay::Open(BYTE* bOK)
{
	// TODO: Add your implementation code here
	//Create the m_pImageDipslay
/*	if(0==m_Width)
	{
		m_pDataSrc->get_Width(&m_Width);
	}
	
	if(0==m_Height)
	{
		m_pDataSrc->get_Height(&m_Height);
	}
	//Enable
	//For test
	m_DisplayImage.Create(m_Width,m_Height,8);
*/
	//m_DisplayImage.Detach();
	m_DisplayImage.Load("D:\\DTControl 2\\DTControl\\Debug\\testpattern.jpg");
	m_Height = m_DisplayImage.GetHeight();
	m_Width = m_DisplayImage.GetWidth();
	SetScale();
	Invalidate(TRUE);
	m_pDisplayObject->Open(m_Width,m_Height,1);
//	AllocateImgBuffer(m_Width,m_Height);
	return S_OK;
}
void CDTDisplay::ReleaseImgBuffer()
{
	m_DisplayImage.Detach();
	m_DisplayImage.ReleaseGDIPlus();
}
void CDTDisplay::AllocateImgBuffer(LONG Width,LONG Height)
{
	m_DisplayImage.Create(m_Width,m_Height,8);
	m_pDisplayObject->put_ImageDataAddress((LONG)m_DisplayImage.GetBits());
}
STDMETHODIMP CDTDisplay::Close(void)
{
	// TODO: Add your implementation code here
	//Unconnect the data source and display control if there is 
	//Release m_pImageDisplay
	ReleaseImgBuffer();
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_RefreshMode(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_RefreshMode ;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_RefreshMode(LONG newVal)
{
	// TODO: Add your implementation code here
	m_RefreshMode = newVal;
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_RefreshRate(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_RefreshMode ;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_RefreshRate(LONG newVal)
{
	// TODO: Add your implementation code here
	m_RefreshMode = newVal;
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_ImageObject(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_pDisplayObject;
	m_pDisplayObject->AddRef();
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_Scale(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Scale;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_Scale(LONG newVal)
{
	// TODO: Add your implementation code here
	m_Scale = newVal;
	SetScale();
	Invalidate(TRUE);
	return S_OK;
}

STDMETHODIMP CDTDisplay::Refresh(void)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CDTDisplay::get_OrgPoint_X(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Org_X;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_OrgPoint_X(LONG newVal)
{
	// TODO: Add your implementation code here
	m_Org_X = newVal; 
	return S_OK;
}

STDMETHODIMP CDTDisplay::get_OrgPoint_Y(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_Org_X;
	return S_OK;
}

STDMETHODIMP CDTDisplay::put_OrgPoint_Y(LONG newVal)
{
	// TODO: Add your implementation code here
	m_Org_Y = newVal;
	return S_OK;
}

HRESULT CDTDisplay::OnDraw(ATL_DRAWINFO& di)
{
	// TODO: Add your specialized code here and/or call the base class
	return __super::OnDraw(di);
}

LRESULT CDTDisplay::OnVScroll(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
      int xDelta = 0; 
      int yDelta;     // yDelta = new_pos - current_pos 
      int yNewPos;    // new position 
 
    switch (LOWORD(wParam)) 
    { 
        // User clicked the shaft above the scroll box. 

        case SB_PAGEUP: 
            yNewPos = m_yCurrentScroll - 50; 
            break; 

        // User clicked the shaft below the scroll box. 

        case SB_PAGEDOWN: 
            yNewPos = m_yCurrentScroll + 50; 
            break; 

        // User clicked the top arrow. 

        case SB_LINEUP: 
            yNewPos = m_yCurrentScroll - 5; 
            break; 

        // User clicked the bottom arrow. 

        case SB_LINEDOWN: 
            yNewPos = m_yCurrentScroll + 5; 
            break; 

        // User dragged the scroll box. 

        case SB_THUMBPOSITION: 
            yNewPos = HIWORD(wParam); 
            break; 

        default: 
            yNewPos = m_yCurrentScroll; 
    } 

    // New position must be between 0 and the screen height. 

    yNewPos = max(0, yNewPos); 
    yNewPos = min(m_yMaxScroll, yNewPos); 

    // If the current position does not change, do not scroll.

    if (yNewPos == m_yCurrentScroll) 
        return 0; 

    // Determine the amount scrolled (in pixels). 

    yDelta = yNewPos - m_yCurrentScroll; 

    // Reset the current scroll position. 

    m_yCurrentScroll = yNewPos; 

    // Scroll the window. (The system repaints most of the 
    // client area when ScrollWindowEx is called; however, it is 
    // necessary to call UpdateWindow in order to repaint the 
    // rectangle of pixels that were invalidated.) 

	::ScrollWindowEx(this->m_hWnd, -xDelta, -yDelta, (CONST RECT *) NULL, 
        (CONST RECT *) NULL, (HRGN) NULL, (LPRECT) NULL, 
        SW_INVALIDATE); 
	::UpdateWindow(this->m_hWnd); 

    // Reset the scroll bar. 

    m_si.cbSize = sizeof(m_si); 
    m_si.fMask  = SIF_POS; 
    m_si.nPos   = m_yCurrentScroll; 
	::SetScrollInfo(this->m_hWnd, SB_VERT, &m_si, TRUE); 
	return 0;
}

LRESULT CDTDisplay::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default

	return 0;
}

LRESULT CDTDisplay::OnSize(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
        int xNewSize; 
        int yNewSize; 
 
        xNewSize = LOWORD(lParam); 
        yNewSize = HIWORD(lParam); 
		//If window size change , it will effect the content size when the m_scale is 0
        // The horizontal scrolling range is defined by 
        // (bitmap_width) - (client_width). The current horizontal 
        // scroll value remains within the horizontal scrolling range. 

        m_xMaxScroll = max(m_WndWidth, 0); 
        m_xCurrentScroll = min(m_xCurrentScroll, m_xMaxScroll); 
        m_si.cbSize = sizeof(m_si); 
        m_si.fMask  = SIF_RANGE | SIF_PAGE | SIF_POS; 
        m_si.nMin   = m_xMinScroll; 
        m_si.nMax   = m_xMaxScroll; 
        m_si.nPage  = xNewSize; 
        m_si.nPos   = m_xCurrentScroll; 
		::SetScrollInfo(this->m_hWnd, SB_HORZ, &m_si, TRUE); 
 
        // The vertical scrolling range is defined by 
        // (bitmap_height) - (client_height). The current vertical 
        // scroll value remains within the vertical scrolling range. 
 
        m_yMaxScroll = max(m_WndHeight , 0); 
        m_yCurrentScroll = min(m_yCurrentScroll, m_yMaxScroll); 
        m_si.cbSize = sizeof(m_si); 
        m_si.fMask  = SIF_RANGE | SIF_PAGE | SIF_POS; 
        m_si.nMin   = m_yMinScroll; 
        m_si.nMax   = m_yMaxScroll; 
        m_si.nPage  = yNewSize; 
        m_si.nPos   = m_yCurrentScroll; 
		::SetScrollInfo(this->m_hWnd, SB_VERT, &m_si, TRUE); 
		SetScrollExtend();
	return 0;
}

LRESULT CDTDisplay::OnHScroll(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
        int xDelta;     // xDelta = new_pos - current_pos  
        int xNewPos;    // new position 
        int yDelta = 0; 
 
        switch (LOWORD(wParam)) 
        { 
            // User clicked the shaft left of the scroll box. 
 
            case SB_PAGEUP: 
                xNewPos = m_xCurrentScroll - 50; 
                break; 
 
            // User clicked the shaft right of the scroll box. 
 
            case SB_PAGEDOWN: 
                xNewPos = m_xCurrentScroll + 50; 
                break; 
 
            // User clicked the left arrow. 
 
            case SB_LINEUP: 
                xNewPos = m_xCurrentScroll - 5; 
                break; 
 
            // User clicked the right arrow. 
 
            case SB_LINEDOWN: 
                xNewPos = m_xCurrentScroll + 5; 
                break; 
 
            // User dragged the scroll box. 
 
            case SB_THUMBPOSITION: 
                xNewPos = HIWORD(wParam); 
                break; 
 
            default: 
                xNewPos = m_xCurrentScroll; 
        } 
 
        // New position must be between 0 and the screen width. 
 
        xNewPos = max(0, xNewPos); 
        xNewPos = min(m_xMaxScroll, xNewPos); 
 
        // If the current position does not change, do not scroll.
 
        if (xNewPos == m_xCurrentScroll) 
            return 0; 
 
        // Determine the amount scrolled (in pixels). 
 
        xDelta = xNewPos - m_xCurrentScroll; 
 
        // Reset the current scroll position. 
 
        m_xCurrentScroll = xNewPos; 
 
        // Scroll the window. (The system repaints most of the 
        // client area when ScrollWindowEx is called; however, it is 
        // necessary to call UpdateWindow in order to repaint the 
        // rectangle of pixels that were invalidated.) 
 
		::ScrollWindowEx(this->m_hWnd, -xDelta, -yDelta, (CONST RECT *) NULL, 
            (CONST RECT *) NULL, (HRGN) NULL, (LPRECT) NULL, 
            SW_INVALIDATE); 
		::UpdateWindow(this->m_hWnd); 
 
        // Reset the scroll bar. 
 
        m_si.cbSize = sizeof(m_si); 
        m_si.fMask  = SIF_POS; 
        m_si.nPos   = m_xCurrentScroll; 
		::SetScrollInfo(this->m_hWnd, SB_HORZ, &m_si, TRUE); 
	return 0;
}

LRESULT CDTDisplay::OnMouseMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default

	return 0;
}

LRESULT CDTDisplay::OnShowWindow(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	SetScale();
	return 0;
}
void  CDTDisplay::SetScale()
 {
	SetScrollExtend();
	::SetScrollRange(this->m_hWnd, SB_HORZ, 0,m_WndWidth, FALSE);
	::SetScrollRange(this->m_hWnd, SB_VERT, 0,m_WndHeight, FALSE);
	if(0 == m_Scale)
	{
		::ShowScrollBar(this->m_hWnd,SB_BOTH,FALSE);
		//::EnableScrollBar(this->m_hWnd,SB_BOTH,ESB_DISABLE_BOTH);
	}
	else
	{
		::ShowScrollBar(this->m_hWnd,SB_BOTH,TRUE);
		::EnableScrollBar(this->m_hWnd,SB_BOTH,ESB_ENABLE_BOTH);

	}
 }
void CDTDisplay::SetScrollExtend()
{
	RECT rc;
	GetClientRect(&rc);
 	if(0 == m_Scale)
	{
		m_WndHeight = rc.bottom - rc.top;
		m_WndWidth = rc.right - rc.left;
	}
	else
	{//The Content size thould the bigger one of Windows' client area and the Image Size
		m_WndHeight = m_Height*sqrt((float)m_Scale) + DISP_BLANK_H;
		if(m_WndHeight<(rc.bottom - rc.top))
			m_WndHeight = rc.bottom - rc.top;
		m_WndWidth = m_Width*sqrt((float)m_Scale) + DISP_BLANK_W;
		if(m_WndWidth < (rc.right - rc.left))
			m_WndWidth = rc.right - rc.left;
	}
	SetDrawRect();
}
HRESULT CDTDisplay::OnDrawAdvanced(ATL_DRAWINFO& di)
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bRunTime;
	GetAmbientUserMode(bRunTime);
	if(bRunTime)
	{//Draw Picture here Display the image data in the
		if(!m_DisplayImage.IsNull())
		{
			m_DisplayImage.Draw(di.hdcDraw,m_DrawRect,m_SrcRect);
		}
	}
	else
	{
		OLE_COLOR colorOle; 
		GetAmbientBackColor(colorOle); 
		COLORREF colorRgb; 
		::OleTranslateColor(colorOle,0,&colorRgb); 
		HBRUSH hBrush; 
		hBrush=CreateSolidBrush(colorRgb); 
		RECT& rc = *(RECT*)di.prcBounds; 
		FillRect(di.hdcDraw,&rc,hBrush); 
		DeleteObject(hBrush); 
		SetBkMode(di.hdcDraw,TRANSPARENT); 
		HICON hIcon=LoadIcon(_AtlBaseModule.GetResourceInstance(),MAKEINTRESOURCE(IDI_DISPLAY)); 
		DrawIcon(di.hdcDraw,rc.left,rc.top,hIcon); 
		DeleteObject(hIcon);
	}
	return 0;
	//return __super::OnDrawAdvanced(di);
}
void CDTDisplay::SetDrawRect()
{
	int WndHeight = m_WndHeight-DISP_BLANK_H;
	int WndWidth = m_WndWidth-DISP_BLANK_W;
	int MidWidth = WndWidth/2;
	int MidHeight = WndHeight/2;
	float scaleWnd = ((float)(WndHeight))/WndWidth;
	float scaleImg = ((float)(m_Height))/m_Width;
	int Width ;
	int Height;
	if(scaleWnd>scaleImg)
	{
		Width = (WndHeight / scaleWnd) ;
		Height =  m_WndHeight-DISP_BLANK_H ;
	}
	else
	{
		Height = (WndWidth * scaleWnd) ;
		//int Width = (WndHeight / scaleWnd) ;
		Width =  m_WndWidth-DISP_BLANK_W ;
	}
	m_DrawRect.right = MidWidth+Width/2;
	m_DrawRect.left = MidWidth - Width/2;
	m_DrawRect.top = MidHeight - Height/2;
	m_DrawRect.bottom = MidHeight + Height/2;
	m_SrcRect.left = 0;
	m_SrcRect.top = 0;
	m_SrcRect.right = m_Width;
	m_SrcRect.bottom = m_Height;
}
STDMETHODIMP CDTDisplay::Load(BSTR FilePath)
{
	// TODO: Add your implementation code here
	CHAR* pPath = _com_util::ConvertBSTRToString(FilePath);
	m_DisplayImage.Load(pPath);
	m_Height = m_DisplayImage.GetHeight();
	m_Width = m_DisplayImage.GetWidth();
	SetScrollExtend();
	return S_OK;
}

STDMETHODIMP CDTDisplay::Save(BSTR FilePath)
{
	// TODO: Add your implementation code here
	CHAR* pPath = _com_util::ConvertBSTRToString(FilePath);
	m_DisplayImage.Save(pPath);
	return S_OK;
}
