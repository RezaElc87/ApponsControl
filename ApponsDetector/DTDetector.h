// DTDetector.h : Declaration of the CDTDetector
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "DTConst.h"
#include ".\LIB\CyAPI.h"
#include ".\TCPSocket.h" 
#include ".\LIB\Serial.h"
// IDTDetector
[
	object,
	uuid(3648F72D-1F1C-4D6A-80C5-53DEAA1359AB),
	dual,
	helpstring("IDTDetector Interface"),
	pointer_default(unique)
]
__interface IDTDetector : public IDispatch
{
	[propget, id(1), helpstring("property IPAddress")] HRESULT IPAddress([out, retval] BSTR* pVal);
	[propput, id(1), helpstring("property IPAddress")] HRESULT IPAddress([in] BSTR newVal);
	[propget, id(2), helpstring("property CmdPort")] HRESULT CmdPort([out, retval] LONG* pVal);
	[propput, id(2), helpstring("property CmdPort")] HRESULT CmdPort([in] LONG newVal);
	[propget, id(3), helpstring("property SerialPort")] HRESULT SerialPort([out, retval] LONG* pVal);
	[propput, id(3), helpstring("property SerialPort")] HRESULT SerialPort([in] LONG newVal);
	[propget, id(4), helpstring("property ObjectHandle")] HRESULT ObjectHandle([out, retval] IUnknown** pVal);
	[propget, id(5), helpstring("property IsOpened")] HRESULT IsOpened([out, retval] LONG* pVal);
	[propget, id(6), helpstring("property LastErrID")] HRESULT LastErrID([out, retval] LONG* pVal);
	[propget, id(7), helpstring("property ChannelType")] HRESULT ChannelType([out, retval] LONG* pVal);
	[propput, id(7), helpstring("property ChannelType")] HRESULT ChannelType([in] LONG newVal);
	[propget, id(8), helpstring("property BaudRate")] HRESULT BaudRate([out, retval] LONG* pVal);
	[propput, id(8), helpstring("property BaudRate")] HRESULT BaudRate([in] LONG newVal);
	[propget, id(9), helpstring("property CmdTimeOut")] HRESULT CmdTimeOut([out, retval] LONG* pVal);
	[propput, id(9), helpstring("property CmdTimeOut")] HRESULT CmdTimeOut([in] LONG newVal);	
	[id(10), helpstring("method Open")] HRESULT Open([out,retval] LONG* bOK);
	[id(11), helpstring("method Close")] HRESULT Close(void);
	[id(12), helpstring("method SendCommand")] HRESULT SendCommand(BSTR bstrCmd, [out] BSTR* bstrRTMsg, [out,retval] LONG* bOK);
	[id(13), helpstring("method PrintErrMsg")] HRESULT PrintErrMsg([in] LONG ErrID, [out] BSTR* ErrMsg);
	[id(14), helpstring("method SendCommandA")] HRESULT SendCommandA([in] CHAR* Cmd, [out] CHAR* pRT,[out,retval] LONG* bOK);
};


// _IDTDetectorEvents
[
	uuid("A5EC5E3E-B102-46A7-B589-1B6ADD9EAC03"),
	dispinterface,
	helpstring("_IDTDetectorEvents Interface")
]
__interface _IDTDetectorEvents
{
	[id(1), helpstring("method DTError")] HRESULT DTError([in] LONG ErrorID, [in] BSTR ErrorInfo);
};

// CDTDetector
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTDetector"),
	progid("DTControl.DTDetector.1"),
	version(1.0),
	uuid("D3120961-C570-471D-B62E-5B2636502D85"),
	helpstring("DTDetector Class"),
	event_source("com"),
	support_error_info(IDTDetector),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDTDetector : 
	public IDTDetector,
	public IPersistStreamInitImpl<CDTDetector>,
	public IOleControlImpl<CDTDetector>,
	public IOleObjectImpl<CDTDetector>,
	public IOleInPlaceActiveObjectImpl<CDTDetector>,
	public IViewObjectExImpl<CDTDetector>,
	public IOleInPlaceObjectWindowlessImpl<CDTDetector>,
	public IPersistStorageImpl<CDTDetector>,
	public ISpecifyPropertyPagesImpl<CDTDetector>,
	public IQuickActivateImpl<CDTDetector>,
	public IDataObjectImpl<CDTDetector>,
	public CComControl<CDTDetector>
{
public:

	CDTDetector()
		: m_CardType(1),
		m_SerialPortNum(0),
		m_bIsOpened(0),
		m_CmdPort(3000),
		m_LastErrID(0),
		m_BaudRate(4800),
		m_TimeOut(100)
	{
		memset(m_RemoteIP,0,20);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDTDetector)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CDTDetector)
	CHAIN_MSG_MAP(CComControl<CDTDetector>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	__event __interface _IDTDetectorEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDTDetector
public:
		HRESULT OnDrawAdvanced(ATL_DRAWINFO& di)
		{
			BOOL bRunTime;
			GetAmbientUserMode(bRunTime);
			if(bRunTime)
				return S_OK;
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
			HICON hIcon=LoadIcon(_AtlBaseModule.GetResourceInstance(),MAKEINTRESOURCE(IDI_DET)); 
			DrawIcon(di.hdcDraw,rc.left,rc.top,hIcon); 
			DeleteObject(hIcon);
			return S_OK; 
			/*
		RECT& rc = *(RECT*)di.prcBounds;
		// Set Clip region to the rectangle specified by di.prcBounds
		HRGN hRgnOld = NULL;
		if (GetClipRgn(di.hdcDraw, hRgnOld) != 1)
			hRgnOld = NULL;
		bool bSelectOldRgn = false;

		HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);

		if (hRgnNew != NULL)
		{
			bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
		}

		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("ATL 7.0 : DTDetector");
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			pszText, 
			lstrlen(pszText));

		if (bSelectOldRgn)
			SelectClipRgn(di.hdcDraw, hRgnOld);

		return S_OK;*/
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	STDMETHOD(get_IPAddress)(BSTR* pVal);
	STDMETHOD(put_IPAddress)(BSTR newVal);
	STDMETHOD(get_CmdPort)(LONG* pVal);
	STDMETHOD(put_CmdPort)(LONG newVal);
	STDMETHOD(get_SerialPort)(LONG* pVal);
	STDMETHOD(put_SerialPort)(LONG newVal);
	STDMETHOD(get_ObjectHandle)(IUnknown** pVal);
	STDMETHOD(get_IsOpened)(LONG* pVal);
	STDMETHOD(get_LastErrID)(LONG* pVal);
	STDMETHOD(get_ChannelType)(LONG* pVal);
	STDMETHOD(put_ChannelType)(LONG newVal);
	STDMETHOD(Open)(LONG* bOK);
	STDMETHOD(Close)(void);
	STDMETHOD(SendCommand)(BSTR bstrCmd, BSTR* bstrRTMsg, LONG* bOK);
	STDMETHOD(PrintErrMsg)(LONG ErrID, BSTR* ErrMsg);
private:
	BYTE m_CardType;
	ULONG m_SerialPortNum;
	BOOL m_bIsOpened;
	char m_RemoteIP[20];
	ULONG m_CmdPort;
	ULONG m_LastErrID;
	LONG m_BaudRate;
	LONG m_TimeOut;
private:
	CCyUSBDevice		m_DTUSBDevice;
	CCyControlEndPoint  *m_pCtlEndPt;
	CTCPSocket			m_Socket;
	CSerial				m_Serial;
private:
	BOOL SendUSBData(CHAR* pStrCmd);
	BOOL RevUSBData(CHAR* pStrRT);
	int SendNETData(CHAR* pStrCmd);
	int RevNETData(CHAR* pRT,WORD BuffSize = REV_BUF_SIZE);
	int	SendSerialData(CHAR* pStrCmd);
	int RevSerialData(CHAR* pRT,WORD BuffSize = REV_BUF_SIZE);
	BOOL TestConnection();
public:
	STDMETHOD(SendCommandA)(CHAR* Cmd, CHAR* pRT,LONG* pbOK);
	STDMETHOD(get_BaudRate)(LONG* pVal);
	STDMETHOD(put_BaudRate)(LONG newVal);
	STDMETHOD(get_CmdTimeOut)(LONG* pVal);
	STDMETHOD(put_CmdTimeOut)(LONG newVal);
};

