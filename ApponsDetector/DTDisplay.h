// DTDisplay.h : Declaration of the CDTDisplay
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "comdef.h"
#include "IDTImageEventSink.h"
#include "IDipslayControlEventSink.h"
#include "ImageObject.h"
#include "Guids.h"
#include "atlimage.h"
#include "DIBImage.h"


// IDTDisplay
[
	object,
	//uuid(2450999E-E7F6-4538-B990-B6DD94681BA2),
	uuid(C22B30FA-860F-4565-8BDC-FC90EFC56F96),
	dual,
	helpstring("IDTDisplay Interface"),
	pointer_default(unique)
]
__interface IDTDisplay : public IDispatch
{
	[propget, id(1), helpstring("property Width")] HRESULT ImgWidth([out, retval] ULONG* pVal);
	[propput, id(1), helpstring("property Width")] HRESULT ImgWidth([in] ULONG newVal);
	[propget, id(2), helpstring("property Height")] HRESULT ImgHeight([out, retval] ULONG* pVal);
	[propput, id(2), helpstring("property Height")] HRESULT ImgHeight([in] ULONG newVal);
	
	[propget, id(3), helpstring("property Gamma")] HRESULT Gamma([out, retval] FLOAT* pVal);
	[propput, id(3), helpstring("property Gamma")] HRESULT Gamma([in] FLOAT newVal);
	[propget, id(4), helpstring("property MapStart")] HRESULT MapStart([out, retval] LONG* pVal);
	[propput, id(4), helpstring("property MapStart")] HRESULT MapStart([in] LONG newVal);
	[propget, id(5), helpstring("property MapEnd")] HRESULT MapEnd([out, retval] LONG* pVal);
	[propput, id(5), helpstring("property MapEnd")] HRESULT MapEnd([in] LONG newVal);

	[propget, id(6), helpstring("property DataSource")] HRESULT DataSource([out, retval] IUnknown** pVal);
	[propput, id(6), helpstring("property DataSource")] HRESULT DataSource([in] IUnknown* newVal);
	[propget, id(7), helpstring("property DisplayControl")] HRESULT DisplayControl([out, retval] IUnknown** pVal);
	[propput, id(7), helpstring("property DisplayControl")] HRESULT DisplayControl([in] IUnknown* newVal);

	[id(8), helpstring("method Open")] HRESULT Open([out,retval] LONG* bOK);
	[id(9), helpstring("method Close")] HRESULT Close(void);

	[propget, id(10), helpstring("property RefreshMode")] HRESULT RefreshMode([out, retval] LONG* pVal);
	[propput, id(10), helpstring("property RefreshMode")] HRESULT RefreshMode([in] LONG newVal);
	[propget, id(11), helpstring("property RefreshRate")] HRESULT RefreshRate([out, retval] LONG* pVal);
	[propput, id(11), helpstring("property RefreshRate")] HRESULT RefreshRate([in] LONG newVal);
	[propget, id(12), helpstring("property ImageObject")] HRESULT ImageObject([out, retval] IUnknown** pVal);
	[propget, id(13), helpstring("property DisplayScale")] HRESULT DisplayScale([out, retval] LONG* pVal);
	[propput, id(13), helpstring("property DisplayScale")] HRESULT DisplayScale([in] LONG newVal);
	
	[id(14), helpstring("method Refresh")] HRESULT Refresh(void);
	[propget, id(15), helpstring("property OrgPoint_X")] HRESULT OrgPoint_X([out, retval] LONG* pVal);
	[propput, id(15), helpstring("property OrgPoint_X")] HRESULT OrgPoint_X([in] LONG newVal);
	[propget, id(16), helpstring("property OrgPoint_Y")] HRESULT OrgPoint_Y([out, retval] LONG* pVal);
	[propput, id(16), helpstring("property OrgPoint_Y")] HRESULT OrgPoint_Y([in] LONG newVal);
	[id(17), helpstring("method Load")] HRESULT Load(BSTR FilePath);
	[id(18), helpstring("method Save")] HRESULT Save(BSTR FilePath);
	[propget, id(19), helpstring("property ObjectHandle")] HRESULT ObjectHandle([out, retval] IUnknown** pVal);
	[id(20), helpstring("method Repaint")] HRESULT Repaint(void);
};


// _IDTDisplayEvents
[
	//uuid("8148D9F9-5ED2-4373-AB88-519E0C22B536"),
	uuid("CD1AAF81-A669-47B7-94A0-5A2A1FBA4439"),
	dispinterface,
	helpstring("_IDTDisplayEvents Interface")
]
__interface _IDTDisplayEvents
{
		[id(1), helpstring("method MouseMove")] HRESULT MouseMove([in] LONG X, [in] LONG Y,[in] LONG Value);
};

// CDTDisplay
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTDisplay"),
	progid("DTControl.DTDisplay.1"),
	version(1.0),
//	uuid("908591A9-D1A3-4DC8-8551-DD68FD62DB2E"),
	uuid("F984B792-41DB-4D78-95A7-1C80E40938FD"),
	helpstring("DTDisplay Class"),
	event_source("com"),
	support_error_info(IDTDisplay),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDTDisplay : 
	public IDTDisplay,
	public IDTImageEventSink,
	public IDipslayControlEventSink,
	public IPersistStreamInitImpl<CDTDisplay>,
	public IOleControlImpl<CDTDisplay>,
	public IOleObjectImpl<CDTDisplay>,
	public IOleInPlaceActiveObjectImpl<CDTDisplay>,
	public IViewObjectExImpl<CDTDisplay>,
	public IOleInPlaceObjectWindowlessImpl<CDTDisplay>,
	public IPersistStorageImpl<CDTDisplay>,
	public ISpecifyPropertyPagesImpl<CDTDisplay>,
	public IQuickActivateImpl<CDTDisplay>,
	public IDataObjectImpl<CDTDisplay>,
	public CComControl<CDTDisplay>
{
	
public:
	enum REFRESH_MODE {RF_FRAME,RF_TOPDOWN,RF_MOVING};
public:

	CDTDisplay()
	{
		m_Height = 0;//Buffer Size
		m_Width = 0;
		m_Scale = 1;
		m_Gamma = 1.0;
		m_mapStart=1;
		m_mapEnd =3000;
		m_pDisplayObject = NULL;
		m_pImageSrcObject = NULL;
		m_pDisplayControl = NULL;
		m_pDataSrc = NULL;

		m_Org_X = 0;
		m_Org_X = 0;
		m_Org_Y = 0;
		m_Org_Y = 0;

		m_bOpened = FALSE;
		m_RefreshMode = 0;
		m_RefreshRate = 0;
		
		m_WndHeight = 0;
		m_WndWidth = 0;

		InitializeLUT();
		m_bWindowOnly = TRUE;
		m_pTempBuf = NULL;
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDTDisplay)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CDTDisplay)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_VSCROLL, OnVScroll)
	MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	MESSAGE_HANDLER(WM_SIZE, OnSize);
	MESSAGE_HANDLER(WM_DISPLAY_REFRESH,OnRefresh)
	CHAIN_MSG_MAP(CComControl<CDTDisplay>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	__event __interface _IDTDisplayEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDTDisplay
public:
	//	HRESULT OnDrawAdvanced(ATL_DRAWINFO& di)
		HRESULT OnDraw(ATL_DRAWINFO& di)
		{
			BOOL bRunTime;
			GetAmbientUserMode(bRunTime);
			RECT& Rect = *(RECT*)di.prcBounds;
			// Set Clip region to the rectangle specified by di.prcBounds
			HRGN hRgnOld = NULL;
			if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
				hRgnOld = NULL;
			bool bSelectOldRgn = false;

			if(!bRunTime)
			{
				HICON hIcon=LoadIcon(_AtlBaseModule.GetResourceInstance(),MAKEINTRESOURCE(IDI_DISPLAY)); 
				DrawIcon(di.hdcDraw,Rect.left,Rect.top,hIcon); 
				DeleteObject(hIcon);
			}
			else
			{
				if(!::IsWindow(m_hWnd))
				{
					return 0;
				}
				if(m_SizeChanged)//Redraw all
				{
					Refresh();
					m_SizeChanged = FALSE;
					BitBlt(di.hdcDraw, 
						0,0, 
						m_WndWidth,m_WndHeight,
						m_hMemDC, 
						0,0, 
						SRCCOPY); 
				}
				else//Update Part
				{
					LPRECT prect = (LPRECT)di.prcBounds;
					BitBlt(di.hdcDraw, 
						prect->left, prect->top, 
						(prect->right - prect->left), 
						(prect->bottom - prect->top), 
						m_hMemDC, 
						prect->left + m_xCurrentScroll, 
						prect->top + m_yCurrentScroll, 
						SRCCOPY); 

				}
			}
			if( m_Scale == 0)
				DrawEdge(di.hdcDraw,&Rect,EDGE_ETCHED,BF_ADJUST|BF_FLAT|BF_TOP|BF_BOTTOM|BF_LEFT|BF_RIGHT);
			return 0;
		}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	/**************************Message handle*********************************/
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		//Create the memDC Here
		m_hMemDC = CreateCompatibleDC(this->GetDC());
		::SetBkColor(m_hMemDC,RGB(255, 255, 255));
		::SetStretchBltMode(m_hMemDC,HALFTONE);
		HPEN hPen = (HPEN)SelectObject(m_hMemDC,GetStockObject(BLACK_PEN)); 
		DeleteObject(hPen);


		m_xMinScroll = 0;       // minimum horizontal scroll value 
		m_xCurrentScroll = 0;   // current horizontal scroll value 
		m_xMaxScroll = 0;       // maximum horizontal scroll value 
 
// These variables are required for vertical scrolling. 
 
		m_yMinScroll = 0;       // minimum vertical scroll value 
		m_yCurrentScroll = 0;   // current vertical scroll value 
		m_yMaxScroll = 0;       // maximum vertical scroll value 
		return 0;
	}
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnVScroll(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnHScroll(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnMouseMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnRefresh(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
private:
	int m_WndHeight;//Display Size
	int m_WndWidth;
	LONG m_Height;//Buffer Size
	LONG m_Width;

	float m_Gamma;
	LONG  m_mapStart;
	LONG  m_mapEnd;

	IImageObject* m_pDisplayObject;
	IImageObject* m_pImageSrcObject;

	BOOL m_bOpened;
	LONG m_RefreshMode;
	LONG m_RefreshRate;

	BYTE* m_pTempBuf;
	CDIBImage m_DisplayImage;

	
// These variables are required for Horizonal scrolling. 
	int m_xMinScroll;       // minimum horizontal scroll value 
	int m_xCurrentScroll;   // current horizontal scroll value 
	int m_xMaxScroll;       // maximum horizontal scroll value 
 
// These variables are required for vertical scrolling. 
 
	int m_yMinScroll;       // minimum vertical scroll value 
	int m_yCurrentScroll;   // current vertical scroll value 
	int m_yMaxScroll;       // maximum vertical scroll value 

	BYTE  m_LUT[MAX_ADC];
	RGBQUAD m_ColorTable[256];
	BOOL m_SizeChanged;
	LONG m_bAutoSize;
	HDC m_hMemDC;
	RECT	m_DrawRect;
	RECT	m_SrcRect;
	SCROLLINFO m_si; 
	LONG m_Scale;//Be 0 1 2,3 ....

	LONG m_Org_X;
	LONG m_Org_Y;
	CComAutoCriticalSection m_displayCs;
private://Service Function
	void	AllocateImgBuffer(LONG Width,LONG Height);
	void	ReleaseImgBuffer();
	void	SetScale();
	void	SetScrollExtend();
	void	SetDrawRect();
	void	SetScrollInfo();
	void	InitializeLUT();
	void	SetWindowing();
	void	LUTMap(LONG StartLine, LONG NumLines,BOOL bMoving);
protected:

	void OnFrameReady(LONG LineNum);

	void OnSubFrameReady(LONG NumOfBlockLeft, LONG StartLine, LONG NumLines, BYTE bLastBlock);
public:
	STDMETHOD(get_ImgWidth)(ULONG* pVal);
	STDMETHOD(put_ImgWidth)(ULONG newVal);
	STDMETHOD(get_ImgHeight)(ULONG* pVal);
	STDMETHOD(put_ImgHeight)(ULONG newVal);

	STDMETHOD(get_Gamma)(FLOAT* pVal);
	STDMETHOD(put_Gamma)(FLOAT newVal);
	STDMETHOD(get_MapStart)(LONG* pVal);
	STDMETHOD(put_MapStart)(LONG newVal);
	STDMETHOD(get_MapEnd)(LONG* pVal);
	STDMETHOD(put_MapEnd)(LONG newVal);

	STDMETHOD(get_DataSource)(IUnknown** pVal);
	STDMETHOD(put_DataSource)(IUnknown* newVal);
	STDMETHOD(get_DisplayControl)(IUnknown** pVal);
	STDMETHOD(put_DisplayControl)(IUnknown* newVal);

	STDMETHOD(Open)(LONG* bOK);
	STDMETHOD(Close)(void);

	STDMETHOD(get_RefreshMode)(LONG* pVal);
	STDMETHOD(put_RefreshMode)(LONG newVal);
	STDMETHOD(get_RefreshRate)(LONG* pVal);
	STDMETHOD(put_RefreshRate)(LONG newVal);
	STDMETHOD(get_ImageObject)(IUnknown** pVal);
	STDMETHOD(get_DisplayScale)(LONG* pVal);
	STDMETHOD(put_DisplayScale)(LONG newVal);

	STDMETHOD(Refresh)(void);
	STDMETHOD(get_OrgPoint_X)(LONG* pVal);
	STDMETHOD(put_OrgPoint_X)(LONG newVal);
	STDMETHOD(get_OrgPoint_Y)(LONG* pVal);
	STDMETHOD(put_OrgPoint_Y)(LONG newVal);
	STDMETHOD(get_ObjectHandle)(IUnknown** pVal);
	STDMETHOD(Load)(BSTR FilePath);
	STDMETHOD(Save)(BSTR FilePath);
	STDMETHOD(Repaint)(void);

};

