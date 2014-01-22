// DTImage.h : Declaration of the CDTImage
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "DTDataSrcIF.h"
#include "DTDetector.h"
#include "DTFrameBufIF.h"
#include "EventmanagerIF.h"
#include "ImageObject.h"
#include "Guids.h"
#include "comdef.h"
#include "IDTImageEventSink.h"

#include "DTFrameBufFactory.h"
#include "DTPPacketFactory.h"
#include "dtpqueuefactory.h"
#include "dtdatasrcfactory.h"


// IDTImage
[
	object,
	uuid(DE232739-9353-452B-8AE3-DACC5DF58486),
	dual,
	helpstring("IDTImage Interface"),
	pointer_default(unique)
]
__interface IDTImage : public IDispatch
{
	[propget, id(1), helpstring("property ImgHeight")] HRESULT ImgHeight([out, retval] LONG* pVal);
	[propput, id(1), helpstring("property ImgHeight")] HRESULT ImgHeight([in] LONG newVal);
	[propget, id(2), helpstring("property ImgWidth")] HRESULT ImgWidth([out, retval] LONG* pVal);
	[propput, id(2), helpstring("property ImgWidth")] HRESULT ImgWidth([in] LONG newVal);
	[propget, id(3), helpstring("property BytesPerPixel")] HRESULT BytesPerPixel([out, retval] LONG* pVal);
	[propput, id(3), helpstring("property BytesPerPixel")] HRESULT BytesPerPixel([in] LONG newVal);
	[propget, id(4), helpstring("property CardType")] HRESULT ChannelType([out, retval] LONG* pVal);
	[propput, id(4), helpstring("property CardType")] HRESULT ChannelType([in] LONG newVal);
	[propget, id(5), helpstring("property ImagePort")] HRESULT ImagePort([out, retval] LONG* pVal);
	[propput, id(5), helpstring("property ImagePort")] HRESULT ImagePort([in] LONG newVal);
	[propget, id(6), helpstring("property DetectorObject")] HRESULT DetectorObject([out, retval] IUnknown**  pVal);
	[propput, id(6), helpstring("property DetectorObject")] HRESULT DetectorObject([in] IUnknown* newVal);
	[propget, id(7), helpstring("property IsOpened")] HRESULT IsOpened([out, retval] LONG* pVal);
	[propget, id(8), helpstring("property LastErrID")] HRESULT LastErrID([out, retval] LONG* pVal);
	[id(9), helpstring("method Open")] HRESULT Open([out,retval] LONG* bOK);
	[id(10), helpstring("method Close")] HRESULT Close(void);
	[id(11), helpstring("method Grab")] HRESULT Grab([in] LONG FrameNum, [out,retval] LONG* bOK);
	[id(12), helpstring("method Snap")] HRESULT Snap([in] LONG FrameNum, [out,retval] LONG* bOK);
	[id(13), helpstring("method PrintErrMsg")] HRESULT PrintErrMsg([in] LONG ErrID, [out] BSTR* ErrMsg);
	
	[propget, id(15), helpstring("property SubFrameHeight")] HRESULT SubFrameHeight([out, retval] LONG* pVal);
	[propput, id(15), helpstring("property SubFrameHeight")] HRESULT SubFrameHeight([in] LONG newVal);
	[id(16), helpstring("method Stop")] HRESULT Stop(void);
	[propget, id(17), helpstring("property IsGrabing")] HRESULT IsGrabing([out, retval] LONG* pVal);
	[propget, id(18), helpstring("property ImageObject")] HRESULT ImageObject([out, retval] IUnknown** pVal);
	[propget, id(19), helpstring("property BandWidth")] HRESULT BandWidth([out, retval] LONG* pVal);
	[propget, id(20), helpstring("property ObjectHandle")] HRESULT ObjectHandle([out, retval] IUnknown** pVal);
	[propget, id(21), helpstring("property TimeOut")] HRESULT TimeOut([out, retval] LONG* pVal);
	[propput, id(21), helpstring("property TimeOut")] HRESULT TimeOut([in] LONG newVal);
	[propget, id(22), helpstring("property ExFrameTrigger")] HRESULT ExFrameTrigger([out, retval] LONG* pVal);
	[propput, id(22), helpstring("property ExFrameTrigger")] HRESULT ExFrameTrigger([in] LONG newVal);
//	[id(23)] HRESULT Advise([in] ICallBack* pCallback, [out] long* dwCookie);
//	[id(24)] HRESULT UnAdvise([in] long dwCookie);
	[propget, id(23)] HRESULT DualScanMode([out, retval] LONG* pVal);
	[propput, id(23)] HRESULT DualScanMode([in] LONG newVal);
	[id(24)] HRESULT OpenMemImage(LONG width, LONG height, BYTE* data);
};


// _IDTImageEvents
[
	uuid("340DAB3D-DAC5-4E95-BE22-677A68039526"),
	dispinterface,
	helpstring("_IDTImageEvents Interface")
]
__interface _IDTImageEvents
{
	[id(1), helpstring("method FrameReady")] HRESULT FrameReady([in] LONG NumLines);
	[id(2), helpstring("method SubFrameReady")] HRESULT SubFrameReady([in] LONG NumOfBlockLeft, [in] LONG StartLine, [in] LONG NumLines, [in] LONG bLastBlock);
	[id(3), helpstring("method Datalost")] HRESULT Datalost(LONG LostlineNum);
	[id(4), helpstring("method DTError")] HRESULT DTError([in] LONG ErrorID, [in] BSTR ErrorInfo);
};

// CDTImage
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTImage"),
	progid("DTControl.DTImage.1"),
	version(1.0),
	uuid("ADDEC18D-6A72-4873-9BE7-B708463B8ADC"),
	helpstring("DTImage Class"),
	event_source("com"),
	support_error_info(IDTImage),
	registration_script("control.rgs")
]

class ATL_NO_VTABLE CDTImage : 
	//	
	public IDTImage,
	public IPersistStreamInitImpl<CDTImage>,
	public IOleControlImpl<CDTImage>,
	public IOleObjectImpl<CDTImage>,
	public IOleInPlaceActiveObjectImpl<CDTImage>,
	public IViewObjectExImpl<CDTImage>,
	public IOleInPlaceObjectWindowlessImpl<CDTImage>,
	public IPersistStorageImpl<CDTImage>,
	public ISpecifyPropertyPagesImpl<CDTImage>,
	public IQuickActivateImpl<CDTImage>,
	public IDataObjectImpl<CDTImage>,
	public CComControl<CDTImage>,
	public CEventManagerIF
//	public IDispatchImpl<ICallBack, &__uuidof(ICallBack), &LIBID_DTControl, /* wMajor = */ 1, /* wMinor = */ 0>
{
public:

	CDTImage()
	{
		m_ImageHeight = 312;
		m_ImageWidth = 312;
		m_SubFrameHeight = m_ImageHeight;
		m_bIsOpened = FALSE;
		m_CardType = DT_USB;
		m_BytesPerPixel = 2;
		m_ImagePort = 4000;
		m_pDetector = NULL;
		m_pDetector = NULL;
		m_pDataSrc = NULL;
		m_pImageObject = NULL;
		m_LastErrID = 0;
		m_hAllFrameSended = CreateEvent(NULL,TRUE,FALSE,NULL);//Create a manual event
		m_BandWidth = 0;
		m_BytesReceived  = 0;
		m_bWindowOnly = TRUE;
		m_bExFrameTrigger = FALSE;
		m_Timeout = 10000;
		for(int i = 0;i<SINK_SIZE;i++)
			m_SinkArray[i] = NULL;
	}

	DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 

	//	OLEMISC_CANTLINKINSIDE | 
	//	OLEMISC_INSIDEOUT | 
	//	OLEMISC_ACTIVATEWHENVISIBLE | 
	//	OLEMISC_SETCLIENTSITEFIRST
	OLEMISC_INVISIBLEATRUNTIME |
		OLEMISC_CANTLINKINSIDE | 
		OLEMISC_INSIDEOUT | 
		OLEMISC_ACTIVATEWHENVISIBLE | 
		OLEMISC_SETCLIENTSITEFIRST
		)


		BEGIN_PROP_MAP(CDTImage)
			PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
			PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
			// Example entries
			// PROP_ENTRY("Property Description", dispid, clsid)
			// PROP_PAGE(CLSID_StockColorPage)
		END_PROP_MAP()


		BEGIN_MSG_MAP(CDTImage)
			MESSAGE_HANDLER(WM_TIMER, OnTimer)
			CHAIN_MSG_MAP(CComControl<CDTImage>)
			DEFAULT_REFLECTION_HANDLER()
		END_MSG_MAP()
		// Handler prototypes:
		//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

		__event __interface _IDTImageEvents;
		// IViewObjectEx
		DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

		// IDTImage
public:

	HRESULT OnDrawAdvanced(ATL_DRAWINFO& di)
	{
		BOOL bRunTime;
		this->GetAmbientUserMode(bRunTime);
		if(bRunTime)
			return S_OK;
		if(bRunTime)
			return S_OK;
		OLE_COLOR colorOle; 
		GetAmbientBackColor(colorOle); 
		COLORREF colorRgb; 
		::OleTranslateColor(colorOle,0,&colorRgb); 
		HBRUSH hBrush; 
		hBrush=CreateSolidBrush(colorRgb); 
		RECT& rc = *(RECT*)di.prcBounds; 
		rc.bottom = rc.top+64;
		rc.right = rc.left +64;
		FillRect(di.hdcDraw,&rc,hBrush); 
		DeleteObject(hBrush); 
		SetBkMode(di.hdcDraw,TRANSPARENT); 
		HICON hIcon=LoadIcon(_AtlBaseModule.GetResourceInstance(),MAKEINTRESOURCE(IDI_IMG)); 
		DrawIcon(di.hdcDraw,rc.left,rc.top,hIcon); 
		DeleteObject(hIcon);

		return S_OK; 
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() 
	{
		if(	m_bIsOpened)
			Close();
	}
	STDMETHOD(get_ImgHeight)(LONG* pVal);
	STDMETHOD(put_ImgHeight)(LONG newVal);
	STDMETHOD(get_ImgWidth)(LONG* pVal);
	STDMETHOD(put_ImgWidth)(LONG newVal);
	STDMETHOD(get_BytesPerPixel)(LONG* pVal);
	STDMETHOD(put_BytesPerPixel)(LONG newVal);
	STDMETHOD(get_ChannelType)(LONG* pVal);
	STDMETHOD(put_ChannelType)(LONG newVal);
	STDMETHOD(get_ImagePort)(LONG* pVal);
	STDMETHOD(put_ImagePort)(LONG newVal);
	STDMETHOD(get_DetectorObject)(IUnknown** pVal);
	STDMETHOD(put_DetectorObject)(IUnknown* newVal);
	STDMETHOD(get_IsOpened)(LONG* pVal);
	STDMETHOD(get_LastErrID)(LONG* pVal);
	STDMETHOD(Open)(LONG* bOK);
	STDMETHOD(Close)(void);
	STDMETHOD(Grab)(LONG FrameNum, LONG* bOK);
	STDMETHOD(Snap)(LONG FrameNum, LONG* bOK);
	STDMETHOD(PrintErrMsg)(LONG ErrID, BSTR* ErrMsg);
//	STDMETHOD(Advise)(ICallBack* pCallback, long* cookie);
//	STDMETHOD(UnAdvise)(long cookie);

private:
	ULONG	m_Timeout;
	ULONG	m_ImageHeight;
	ULONG	m_ImageWidth;
	BOOL	m_bIsOpened;
	LONG	m_CardType;
	ULONG	m_BytesPerPixel;
	ULONG	m_ImagePort;
	ULONG	m_LastErrID;
	ULONG	m_SubFrameHeight;

	ULONG	m_BandWidth;
	ULONG	m_BytesReceived ;
	BOOL	m_bExFrameTrigger;

	CDTFrameBufFactory		m_FrameBufFactory;
	CDTPPacketFactory		m_DTPPacketFactory;
	CDTPQueueFactory		m_DTPQueueFactory;
	CDTDataSrcFactory		m_DTDataSrcFactory;

private:
	ULONG			m_FrameNum;
	ULONG			m_CurFrameCount;
	HANDLE			m_hAllFrameSended;
private:
	CDTDataSrcIF*	m_pDataSrc;
	IDTDetector*	m_pDetector;
	void*			m_pDisplay;
	CDTFrameBufIF*	m_pFrameBuf;
	CDTPQueueIF*	m_pDTPQueue;
	IImageObject*	m_pImageObject;
	long			m_dualScanMode;


public:
	STDMETHOD(get_SubFrameHeight)(LONG* pVal);
	STDMETHOD(put_SubFrameHeight)(LONG newVal);

private:
	void ResetAllDTPPacket();
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	void OnTimer();
	void OnSinkSubFrameReady( LONG NumOfBlockLeft,  LONG StartLine,  LONG NumLines, BYTE bLastBlock);
	void OnSinkFrameReady(LONG NumLines);
	void SetFrameTrigger();
	void SendFrameTrigger();
public:
	void OnDTEvent(BYTE EventID,BYTE EventContent);
	void OnDTFrameReady(BYTE* pSrc, DWORD Size);
	void OnDTSubFrameReady(LONG  RowID, LONG NumLines,BOOL bLastFrame);
	void OnNewDataComimg(ULONG Size);
	STDMETHOD(Stop)(void);
	STDMETHOD(get_IsGrabing)(LONG* pVal);
	STDMETHOD(get_ImageObject)(IUnknown** pVal);
	STDMETHOD(get_BandWidth)(LONG* pVal);
	void AdviseSink(IDTImageEventSink* pSink,LONG* pCookie);
	void UnAdviseSink(LONG Cookie);
private:
	IDTImageEventSink*	m_SinkArray[SINK_SIZE];

public:
	STDMETHOD(get_ObjectHandle)(IUnknown** pVal);
	STDMETHOD(get_TimeOut)(LONG* pVal);
	STDMETHOD(put_TimeOut)(LONG newVal);
	STDMETHOD(get_ExFrameTrigger)(LONG* pVal);
	STDMETHOD(put_ExFrameTrigger)(LONG newVal);

public:

	STDMETHOD(get_DualScanMode)(LONG* pVal);
	STDMETHOD(put_DualScanMode)(LONG newVal);
	STDMETHOD(OpenMemImage)(LONG width, LONG height, BYTE* data);
};
