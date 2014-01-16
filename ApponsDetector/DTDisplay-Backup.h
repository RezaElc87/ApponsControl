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
	uuid(C22B30FA-860F-4565-8BDC-FC90EFC56F96),
	dual,
	helpstring("IDTDisplay Interface"),
	pointer_default(unique)
]
__interface IDTDisplay : public IDispatch
{
	[propget, id(1), helpstring("property Width")] HRESULT Width([out, retval] ULONG* pVal);
	[propput, id(1), helpstring("property Width")] HRESULT Width([in] ULONG newVal);
	[propget, id(2), helpstring("property Height")] HRESULT Height([out, retval] ULONG* pVal);
	[propput, id(2), helpstring("property Height")] HRESULT Height([in] ULONG newVal);

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
	[propget, id(13), helpstring("property Scale")] HRESULT Scale([out, retval] LONG* pVal);
	[propput, id(13), helpstring("property Scale")] HRESULT Scale([in] LONG newVal);
	
	[id(14), helpstring("method Refresh")] HRESULT Refresh(void);
	[propget, id(15), helpstring("property OrgPoint_X")] HRESULT OrgPoint_X([out, retval] LONG* pVal);
	[propput, id(15), helpstring("property OrgPoint_X")] HRESULT OrgPoint_X([in] LONG newVal);
	[propget, id(16), helpstring("property OrgPoint_Y")] HRESULT OrgPoint_Y([out, retval] LONG* pVal);
	[propput, id(16), helpstring("property OrgPoint_Y")] HRESULT OrgPoint_Y([in] LONG newVal);
	[id(17), helpstring("method Load")] HRESULT Load(BSTR FilePath);
	[id(18), helpstring("method Save")] HRESULT Save(BSTR FilePath);
	[propget, id(19), helpstring("property Object")] HRESULT Object([out, retval] IUnknown** pVal);
	[propget, id(20), helpstring("property AutoSize")] HRESULT AutoSize([out, retval] LONG* pVal);
	[propput, id(20), helpstring("property AutoSize")] HRESULT AutoSize([in] LONG newVal);
};


// _IDTDisplayEvents
[
	uuid("8148D9F9-5ED2-4373-AB88-519E0C22B536"),
	dispinterface,
	helpstring("_IDTDisplayEvents Interface")
]
__interface _IDTDisplayEvents
{
	[id(1), helpstring("method MouseMove")] HRESULT MouseMove([in] LONG X, [in] LONG Y);
};

// CDTDisplay
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTDisplay"),
	progid("DTControl.DTDisplay.1"),
	version(1.0),
	uuid("F984B792-41DB-4D78-95A7-1C80E40938FD"),
	helpstring("DTDisplay Class"),
	event_source("com"),
	support_error_info(IDTDisplay),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDTDisplay : 
	public IDTDisplay,
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
	public CComControl<CDTDisplay>,
	public IDTImageEventSink,
	public IDipslayControlEventSink
{
public:
//	CContainedWindow m_ctlStatic;

#pragma warning(push)
#pragma warning(disable: 4355) // 'this' : used in base member initializer list

	CDTDisplay()
	//	: m_ctlStatic(_T("Static"), this, 1)
	{
		m_pDisplayControl = NULL;
		m_pDataSrc = NULL;
		m_pDisplayObject = NULL;

		m_pImageSrcObject = NULL;
		m_RefreshMode = 0;
		m_RefreshRate = 0;
		m_Height = 0;
		m_Width = 0;
		m_Org_X = 0;
		m_Org_Y = 0;
		m_Scale = 0;
		m_WndHeight = 0;
		m_WndWidth = 0;

		m_bSizeChanged = FALSE;
		m_bOpened = FALSE;
		InitializeLUT();
		m_pTempBuf = NULL;
		//m_bWindowOnly = TRUE;
		m_SizeChanged = FALSE;
		m_bAutoSize = TRUE;
		m_mapEnd = 3000;
		m_mapStart = 0;
	}

#pragma warning(pop)

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
//	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_VSCROLL, OnVScroll)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
//	MESSAGE_HANDLER(WM_SIZE, OnSize)
	MESSAGE_HANDLER(WM_HSCROLL, OnHScroll)
	MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
//	MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	
	CHAIN_MSG_MAP(CComControl<CDTDisplay>)
	DEFAULT_REFLECTION_HANDLER()
	//ALT_MSG_MAP(1)
	// Replace this with message map entries for superclassed Static
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

/*	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LRESULT lRes = CComControl<CDTDisplay>::OnSetFocus(uMsg, wParam, lParam, bHandled);
		if (m_bInPlaceActive)
		{
			//if(!IsChild(::GetFocus()))
	//			m_ctlStatic.SetFocus();
		}
		return lRes;

	}
*/
//	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
/*	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
	//	m_ctlStatic.Create(m_hWnd, rc);

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
*/
/*	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
	//	IOleInPlaceObjectWindowlessImpl<CDTDisplay>::SetObjectRects(prcPos, prcClip);
	//	int cx, cy;
	//	cx = prcPos->right - prcPos->left;
	//	cy = prcPos->bottom - prcPos->top;
	//	::SetWindowPos(m_ctlStatic.m_hWnd, NULL, 0,
	//		0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		return S_OK;
	}
*/
	__event __interface _IDTDisplayEvents;
// IViewObjectEx
	//DECLARE_VIEW_STATUS(0)
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDTDisplay

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
	HRESULT FinalConstruct()
	{
		HRESULT hr = ::CoCreateInstance(CLSID_IImageObject,NULL,CLSCTX_ALL,IID_IImageObject,(LPVOID*) &m_pDisplayObject);
		if(FAILED(hr))
		{
			_com_error err(hr);
			MessageBox(err.ErrorMessage(),NULL);
			return S_OK;
		}
		return S_OK;
	}
	
	void FinalRelease() 
	{
		m_pDisplayObject->Release();
	}

public:
	enum REFRESH_MODE {RF_FRAME,RF_TOPDOWN,RF_MOVING};
private:
	BOOL m_bOpened;
	IImageObject* m_pDisplayObject;
	IImageObject* m_pImageSrcObject;
	float m_Gamma;
	LONG  m_mapStart;
	LONG  m_mapEnd;
	BYTE  m_LUT[MAX_ADC];
	RGBQUAD m_ColorTable[256];

	LONG m_RefreshMode;
	LONG m_RefreshRate;
	LONG m_Org_X;
	LONG m_Org_Y;

	LONG m_Scale;
	LONG m_Height;//Buffer Size
	LONG m_Width;

	int m_WndHeight;//Display Size
	int m_WndWidth;
// These variables are required for Horizonal scrolling. 
	int m_xMinScroll;       // minimum horizontal scroll value 
	int m_xCurrentScroll;   // current horizontal scroll value 
	int m_xMaxScroll;       // maximum horizontal scroll value 
 
// These variables are required for vertical scrolling. 
 
	int m_yMinScroll;       // minimum vertical scroll value 
	int m_yCurrentScroll;   // current vertical scroll value 
	int m_yMaxScroll;       // maximum vertical scroll value 
	SCROLLINFO m_si; 
	BOOL m_bSizeChanged;
	
	RECT	m_DrawRect;
	RECT	m_SrcRect;

	HDC m_hMemDC;
	CDIBImage m_DisplayImage;
	BYTE* m_pTempBuf;
	BOOL m_SizeChanged;
	LONG m_bAutoSize;
	void	InitializeLUT();
	void	SetWindowing();
	void	AllocateImgBuffer(LONG Width,LONG Height);
	void	ReleaseImgBuffer();
	void	SetScale();
	void	SetScrollExtend();
	void	SetDrawRect();
	void	SetScrollInfo();
	void	LUTMap(LONG StartLine, LONG NumLines,BOOL bMoving);
protected:

	void OnFrameReady(LONG LineNum);

	void OnSubFrameReady(LONG NumOfBlockLeft, LONG StartLine, LONG NumLines, BYTE bLastBlock);
public:
		
		
	STDMETHOD(get_DataSource)(IUnknown** pVal);
	STDMETHOD(put_DataSource)(IUnknown* newVal);
	STDMETHOD(get_DisplayControl)(IUnknown** pVal);
	STDMETHOD(put_DisplayControl)(IUnknown* newVal);
	STDMETHOD(get_Gamma)(FLOAT* pVal);
	STDMETHOD(put_Gamma)(FLOAT newVal);
	STDMETHOD(get_MapStart)(LONG* pVal);
	STDMETHOD(put_MapStart)(LONG newVal);
	STDMETHOD(get_MapEnd)(LONG* pVal);
	STDMETHOD(put_MapEnd)(LONG newVal);
	STDMETHOD(get_Width)(ULONG* pVal);
	STDMETHOD(put_Width)(ULONG newVal);
	STDMETHOD(get_Height)(ULONG* pVal);
	STDMETHOD(put_Height)(ULONG newVal);
	STDMETHOD(Open)(LONG* bOK);
	STDMETHOD(Close)(void);
	STDMETHOD(get_RefreshMode)(LONG* pVal);
	STDMETHOD(put_RefreshMode)(LONG newVal);
	STDMETHOD(get_RefreshRate)(LONG* pVal);
	STDMETHOD(put_RefreshRate)(LONG newVal);
	STDMETHOD(get_ImageObject)(IUnknown** pVal);
	STDMETHOD(get_Scale)(LONG* pVal);
	STDMETHOD(put_Scale)(LONG newVal);
	STDMETHOD(Refresh)(void);
	STDMETHOD(get_OrgPoint_X)(LONG* pVal);
	STDMETHOD(put_OrgPoint_X)(LONG newVal);
	STDMETHOD(get_OrgPoint_Y)(LONG* pVal);
	STDMETHOD(put_OrgPoint_Y)(LONG newVal);
	
	LRESULT OnVScroll(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnHScroll(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	LRESULT OnShowWindow(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	
	STDMETHOD(Load)(BSTR FilePath);
	STDMETHOD(Save)(BSTR FilePath);
	

	LRESULT OnMouseMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	STDMETHOD(get_Object)(IUnknown** pVal);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	//LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	STDMETHOD(get_AutoSize)(LONG* pVal);
	STDMETHOD(put_AutoSize)(LONG newVal);
};