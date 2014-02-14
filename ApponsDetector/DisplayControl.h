// DisplayControl.h : Declaration of the CDTDisplayControl
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>

// IDisplayControl
[
	object,
//	uuid(6CDC46F2-4137-4093-AE9F-4443633F6DA7),
	uuid(5A79B1CB-FF34-4F4F-A394-4972066A5763),
	dual,
	helpstring("IDTDisplayControl Interface"),
	pointer_default(unique)
]
__interface IDTDisplayControl : public IDispatch
{
	[propput, bindable, requestedit, id(DISPID_AUTOSIZE)]
	HRESULT AutoSize([in]VARIANT_BOOL vbool);
	[propget, bindable, requestedit, id(DISPID_AUTOSIZE)]
	HRESULT AutoSize([out,retval]VARIANT_BOOL* pbool);
	[propput, bindable, requestedit, id(DISPID_BORDERVISIBLE)]
	HRESULT BorderVisible([in]VARIANT_BOOL vbool);
	[propget, bindable, requestedit, id(DISPID_BORDERVISIBLE)]
	HRESULT BorderVisible([out, retval]VARIANT_BOOL* pbool);
	[propget, id(1), helpstring("property Object")] HRESULT Object([out, retval] IUnknown** pVal);
};


// _IDisplayControlEvents
[
	//uuid("B71C75E1-3CB0-40E7-A8B1-6FCEE7A479CF"),
	uuid(51F345B5-044F-49F2-A824-59B2869CEF23),
	dispinterface,
	helpstring("_IDTDisplayControlEvents Interface")
]
__interface _IDTDisplayControlEvents
{
};

// CDTDisplayControl
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTDisplayControl"),
	progid("DTControl.DTDisplayControl.1"),
	version(1.0),
	//uuid("DCE3040A-003A-4325-9FAE-C5A9DA79203C"),
	uuid("14B6C482-806F-4171-AEA4-FB424E07A758"),
	helpstring("DTDisplayControl Class"),
	event_source("com"),
	support_error_info(IDTDisplayControl),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDTDisplayControl : 
	public CStockPropImpl<CDTDisplayControl, IDTDisplayControl>,
	public IPersistStreamInitImpl<CDTDisplayControl>,
	public IOleControlImpl<CDTDisplayControl>,
	public IOleObjectImpl<CDTDisplayControl>,
	public IOleInPlaceActiveObjectImpl<CDTDisplayControl>,
	public IViewObjectExImpl<CDTDisplayControl>,
	public IOleInPlaceObjectWindowlessImpl<CDTDisplayControl>,
	public IPersistStorageImpl<CDTDisplayControl>,
	public ISpecifyPropertyPagesImpl<CDTDisplayControl>,
	public IQuickActivateImpl<CDTDisplayControl>,
	public IDataObjectImpl<CDTDisplayControl>,
	public CComControl<CDTDisplayControl>
{
public:
	CContainedWindow m_ctlStatic;

#pragma warning(push)
#pragma warning(disable: 4355) // 'this' : used in base member initializer list

	CDTDisplayControl()
		: m_ctlStatic(_T("Static"), this, 1)
	{
		m_bWindowOnly = TRUE;
	}

#pragma warning(pop)

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_ACTSLIKELABEL |
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDTDisplayControl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("AutoSize", DISPID_AUTOSIZE, CLSID_NULL)
	PROP_ENTRY("BorderVisible", DISPID_BORDERVISIBLE, CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CDTDisplayControl)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	CHAIN_MSG_MAP(CComControl<CDTDisplayControl>)
ALT_MSG_MAP(1)
	// Replace this with message map entries for superclassed Static
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LRESULT lRes = CComControl<CDTDisplayControl>::OnSetFocus(uMsg, wParam, lParam, bHandled);
		if (m_bInPlaceActive)
		{
			if(!IsChild(::GetFocus()))
				m_ctlStatic.SetFocus();
		}
		return lRes;
	}

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		m_ctlStatic.Create(m_hWnd, rc);
		return 0;
	}

	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CDTDisplayControl>::SetObjectRects(prcPos, prcClip);
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
		::SetWindowPos(m_ctlStatic.m_hWnd, NULL, 0,
			0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		return S_OK;
	}

	__event __interface _IDTDisplayControlEvents;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDisplayControl
	void OnAutoSizeChanged()
	{
		ATLTRACE(_T("OnAutoSizeChanged\n"));
	}
	BOOL m_bBorderVisible;
	void OnBorderVisibleChanged()
	{
		ATLTRACE(_T("OnBorderVisibleChanged\n"));
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
	STDMETHOD(get_Object)(IUnknown** pVal);
};

