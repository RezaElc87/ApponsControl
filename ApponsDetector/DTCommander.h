// DTCommander.h : Declaration of the CDTCommander
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "DTConst.h"
#include "DTdetector.h"

// IDTCommanderF3
[
	object,
//	uuid(49422A4C-63E0-4674-9073-5867DF5FECDC),
	uuid(A164B205-1A1E-4345-A6F6-38D4715EC7FB),
	dual,
	helpstring("IDTCommanderF3 Interface"),
	pointer_default(unique)
]
__interface IDTCommanderF3 : public IDispatch
{
	[propget, id(1), helpstring("property DetectorObject")] HRESULT DetectorObject([out, retval] IUnknown** pVal);
	[propput, id(1), helpstring("property DetectorObject")] HRESULT DetectorObject([in] IUnknown* newVal);
	[id(2), helpstring("method OffBoardCalibration")] HRESULT OffBoardCalibration([in] LONG CalibrationType, [in] IUnknown* pImgObject, [in] LONG StartPixel, [in] LONG EndPixel, [in] LONG TargetValue);

	[propget, id(3), helpstring("property Gain")] HRESULT Gain([in] LONG Index, [out, retval] FLOAT* pVal);
	[propput, id(3), helpstring("property Gain")] HRESULT Gain([in] LONG Index, [in] FLOAT newVal);
	[propget, id(4), helpstring("property Offset")] HRESULT Offset([in] LONG Index, [out, retval] LONG* pVal);
	[propput, id(4), helpstring("property Offset")] HRESULT Offset([in] LONG Index, [in] LONG newVal);
	[propget, id(5), helpstring("property CorrectionGain")] HRESULT CorrectionGain([out, retval] LONG* pVal);
	[propput, id(5), helpstring("property CorrectionGain")] HRESULT CorrectionGain([in] LONG newVal);
	[propget, id(6), helpstring("property CorrectionOffset")] HRESULT CorrectionOffset([out, retval] LONG* pVal);
	[propput, id(6), helpstring("property CorrectionOffset")] HRESULT CorrectionOffset([in] LONG newVal);
	[propget, id(7), helpstring("property CorrectionBaseline")] HRESULT CorrectionBaseline([out, retval] LONG* pVal);
	[propput, id(7), helpstring("property CorrectionBaseline")] HRESULT CorrectionBaseline([in] LONG newVal);
	[propget, id(8), helpstring("property Baseline")] HRESULT Baseline([out, retval] LONG* pVal);
	[propput, id(8), helpstring("property Baseline")] HRESULT Baseline([in] LONG newVal);
	[propget, id(9), helpstring("property IntegrationTime")] HRESULT IntegrationTime([out, retval] LONG* pVal);
	[propput, id(9), helpstring("property IntegrationTime")] HRESULT IntegrationTime([in] LONG newVal);
	[propget, id(10), helpstring("property AverageFilter")] HRESULT AverageFilter([out, retval] LONG* pVal);
	[propput, id(10), helpstring("property AverageFilter")] HRESULT AverageFilter([in] LONG newVal);
	[propget, id(11), helpstring("property DataPattern")] HRESULT DataPattern([out, retval] LONG* pVal);
	[propput, id(11), helpstring("property DataPattern")] HRESULT DataPattern([in] LONG newVal);
	[propget, id(12), helpstring("property FrameTrigger")] HRESULT FrameTrigger([out, retval] LONG* pVal);
	[propput, id(12), helpstring("property FrameTrigger")] HRESULT FrameTrigger([in] LONG newVal);
	[propget, id(13), helpstring("property LineTrigger")] HRESULT LineTrigger([out, retval] LONG* pVal);
	[propput, id(13), helpstring("property LineTrigger")] HRESULT LineTrigger([in] LONG newVal);
	[id(14), helpstring("method Initialize")] HRESULT Initialize([in] LONG Mode);
	[id(15), helpstring("method SaveOffset")] HRESULT SaveOffset(void);
	[id(16), helpstring("method SaveGain")] HRESULT SaveGain([in] LONG Index);
	[id(17), helpstring("method LoadOffset")] HRESULT LoadOffset(void);
	[id(18), helpstring("method LoadGain")] HRESULT LoadGain([in] LONG Index);
	[propget, id(19), helpstring("property OutputBits")] HRESULT OutputBits([out, retval] LONG* pVal);
	[propput, id(19), helpstring("property OutputBits")] HRESULT OutputBits([in] LONG newVal);
	[id(20), helpstring("method SendExFrameTrigger")] HRESULT SendExFrameTrigger(void);
	[propget, id(21), helpstring("property FrameOut")] HRESULT FrameOut([out, retval] LONG* pVal);
	[propput, id(21), helpstring("property FrameOut")] HRESULT FrameOut([in] LONG newVal);
	[propget, id(22), helpstring("property ImageOutputType")] HRESULT ImageOutputType([out, retval] LONG* pVal);
	[propput, id(22), helpstring("property ImageOutputType")] HRESULT ImageOutputType([in] LONG newVal);
	[propget, id(23), helpstring("property SensitivityLevel")] HRESULT SensitivityLevel([out, retval] LONG* pVal);
	[propput, id(23), helpstring("property SensitivityLevel")] HRESULT SensitivityLevel([in] LONG newVal);
	[propget, id(24), helpstring("property SumLines")] HRESULT SumLines([out, retval] LONG* pVal);
	[propput, id(24), helpstring("property SumLines")] HRESULT SumLines([in] LONG newVal);
	[id(25), helpstring("method WriteDataPattern")] HRESULT WriteDataPattern([in] LONG Base, [in] LONG Step);
	[propget, id(26), helpstring("property IsOpened")] HRESULT IsOpened([out, retval] LONG* pVal);
	[propget, id(27), helpstring("property ModuleTypeNmae")] HRESULT ModuleTypeName([out, retval] BSTR* pVal);
	[id(28), helpstring("method SaveCurrentStatus")] HRESULT SaveCurrentStatus(void);
	[propget, id(29), helpstring("property PixelSize")] HRESULT PixelSize([out, retval] FLOAT* pVal);
	[propget, id(30), helpstring("property PixelNumber")] HRESULT PixelNumber([out, retval] LONG* pVal);
	[propget, id(31), helpstring("property ModuleType")] HRESULT ModuleType([out, retval] LONG* pVal);
	[propget, id(32), helpstring("property MaxIntTime")] HRESULT MaxIntTime([out, retval] LONG* pVal);
	[propget, id(33), helpstring("property MinIntTime")] HRESULT MinIntTime([out, retval] LONG* pVal);
	[propget, id(34), helpstring("property OverallGain")] HRESULT OverallGain([out, retval] FLOAT* pVal);
	[propput, id(34), helpstring("property OverallGain")] HRESULT OverallGain([in] FLOAT newVal);
	[propget, id(35), helpstring("property StartPixel")] HRESULT StartPixel([out, retval] LONG* pVal);
	[propput, id(35), helpstring("property StartPixel")] HRESULT StartPixel([in] LONG newVal);
	[propget, id(36), helpstring("property EndPixel")] HRESULT EndPixel([out, retval] LONG* pVal);
	[propput, id(36), helpstring("property EndPixel")] HRESULT EndPixel([in] LONG newVal);
	[id(37), helpstring("method OnBoardOffsetCalibration")] HRESULT OnBoardOffsetCalibration(void);
	[id(38), helpstring("method OnBoardGainCalibration")] HRESULT OnBoardGainCalibration([in] LONG TargetValue);
	[id(39), helpstring("method ResetGain")] HRESULT ResetGain(void);
	[id(40), helpstring("method ResetOffset")] HRESULT ResetOffset(void);
	[propget, id(41), helpstring("property FPGA_Version")] HRESULT FPGA_Version([out, retval] LONG* pVal);
	[propget, id(42), helpstring("property FPGA_Build")] HRESULT FPGA_Build([out, retval] LONG* pVal);
	[propget, id(43), helpstring("property MCU_Version")] HRESULT MCU_Version([out, retval] LONG* pVal);
	
	[propget, id(44), helpstring("property SerialNumber")] HRESULT SerialNumber([out, retval] BSTR* pVal);
	[id(45), helpstring("method RetrieveSysinfo")] HRESULT RetrieveSysinfo(void);
};


// _IDTCommanderEvents
[
	//uuid("6A7003E6-BA52-45D8-8ACE-1700CB01E70A"),
	uuid("3F2A6451-EC6C-4948-9C07-7764FA64A894"),
	dispinterface,
	helpstring("_IDTCommanderF3Events Interface")
]
__interface _IDTCommanderF3Events
{
};

// CDTCommanderF3
[
	coclass,
	threading("apartment"),
	vi_progid("DTControl.DTCommanderF3"),
	progid("DTControl.DTCommanderF3.1"),
	version(1.0),
	//uuid("7D934547-7258-4C06-9AD3-A3143E9056CA"),
	uuid("B08859A2-D75E-4B6D-8C13-A80DAD7BA087"),
	helpstring("DTCommanderF3 Class"),
	event_source("com"),
	support_error_info(IDTCommanderF3),
	registration_script("control.rgs")
]
class ATL_NO_VTABLE CDTCommanderF3 : 
	public IDTCommanderF3,
	public IPersistStreamInitImpl<CDTCommanderF3>,
	public IOleControlImpl<CDTCommanderF3>,
	public IOleObjectImpl<CDTCommanderF3>,
	public IOleInPlaceActiveObjectImpl<CDTCommanderF3>,
	public IViewObjectExImpl<CDTCommanderF3>,
	public IOleInPlaceObjectWindowlessImpl<CDTCommanderF3>,
	public IPersistStorageImpl<CDTCommanderF3>,
	public ISpecifyPropertyPagesImpl<CDTCommanderF3>,
	public IQuickActivateImpl<CDTCommanderF3>,
	public IDataObjectImpl<CDTCommanderF3>,
	public CComControl<CDTCommanderF3>
{
public:

	CDTCommanderF3():
	 m_pDetector(NULL)
	{
		memset(m_SerialNum,20,0) ;
		m_ModuleType = 0;
		memset(m_ModuleName,20,0) ;
		m_PixelNumber	= 0;
		m_PixelSize = 0.0;
		m_MCU_Version = 0;
		m_MinIntTime = 0;
		m_MaxIntTime = 0;
		m_FPGA_Build = 0;
		m_FPGA_Version = 0;
		m_bRetrieved = FALSE;
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDTCommanderF3)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CDTCommanderF3)
	CHAIN_MSG_MAP(CComControl<CDTCommanderF3>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	__event __interface _IDTCommanderF3Events;
// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDTCommanderF3
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
			rc.bottom = rc.top+64;
			rc.right = rc.left +64;
			FillRect(di.hdcDraw,&rc,hBrush); 
			DeleteObject(hBrush); 
			SetBkMode(di.hdcDraw,TRANSPARENT); 
			HICON hIcon=LoadIcon(_AtlBaseModule.GetResourceInstance(),MAKEINTRESOURCE(IDI_COMMANDER)); 
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
	}
	STDMETHOD(get_DetectorObject)(IUnknown** pVal);
	STDMETHOD(put_DetectorObject)(IUnknown* newVal);
	STDMETHOD(OffBoardCalibration)(LONG CalibrationType, IUnknown* pImgObject, LONG StartPixel, LONG EndPixel, LONG TargetValue);
	STDMETHOD(get_Gain)(LONG Index, FLOAT* pVal);
	STDMETHOD(put_Gain)(LONG Index, FLOAT newVal);
	STDMETHOD(get_Offset)(LONG Index, LONG* pVal);
	STDMETHOD(put_Offset)(LONG Index, LONG newVal);
	STDMETHOD(get_CorrectionGain)(LONG* pVal);
	STDMETHOD(put_CorrectionGain)(LONG newVal);
	STDMETHOD(get_CorrectionOffset)(LONG* pVal);
	STDMETHOD(put_CorrectionOffset)(LONG newVal);
	STDMETHOD(get_CorrectionBaseline)(LONG* pVal);
	STDMETHOD(put_CorrectionBaseline)(LONG newVal);
	STDMETHOD(get_Baseline)(LONG* pVal);
	STDMETHOD(put_Baseline)(LONG newVal);
	STDMETHOD(get_IntegrationTime)(LONG* pVal);
	STDMETHOD(put_IntegrationTime)(LONG newVal);
	STDMETHOD(get_AverageFilter)(LONG* pVal);
	STDMETHOD(put_AverageFilter)(LONG newVal);
	STDMETHOD(get_DataPattern)(LONG* pVal);
	STDMETHOD(put_DataPattern)(LONG newVal);
	STDMETHOD(get_FrameTrigger)(LONG* pVal);
	STDMETHOD(put_FrameTrigger)(LONG newVal);
	STDMETHOD(get_LineTrigger)(LONG* pVal);
	STDMETHOD(put_LineTrigger)(LONG newVal);
	STDMETHOD(Initialize)(LONG Mode);
	STDMETHOD(SaveOffset)(void);
	STDMETHOD(SaveGain)(LONG Index);
	STDMETHOD(LoadOffset)(void);
	STDMETHOD(LoadGain)(LONG Index);
	STDMETHOD(get_OutputBits)(LONG* pVal);
	STDMETHOD(put_OutputBits)(LONG newVal);
	STDMETHOD(SendExFrameTrigger)(void);
	STDMETHOD(get_FrameOut)(LONG* pVal);
	STDMETHOD(put_FrameOut)(LONG newVal);
	STDMETHOD(get_ImageOutputType)(LONG* pVal);
	STDMETHOD(put_ImageOutputType)(LONG newVal);
	STDMETHOD(get_SensitivityLevel)(LONG* pVal);
	STDMETHOD(put_SensitivityLevel)(LONG newVal);
	STDMETHOD(get_SumLines)(LONG* pVal);
	STDMETHOD(put_SumLines)(LONG newVal);
	private:
		IDTDetector*	m_pDetector;
		CHAR			m_Command[100];
		CHAR			m_Return[100];
		LONG			m_bOK;
		//Following parameter is the detector property
		//FI command
		LONG			m_FPGA_Version;
		LONG			m_FPGA_Build;
		//RI Command
		LONG			m_MCU_Version;
		LONG			m_PixelNumber;
		float			m_PixelSize;
		LONG			m_ModuleType;
		char			m_ModuleName[20];
		char			m_SerialNum[20];
		LONG			m_FEBoardNum;
		LONG			m_MaxIntTime;
		LONG			m_MinIntTime;
		BOOL			m_bRetrieved;//Flag to indicate whether there is RI Called
	private:
		LONG Min(LONG* pData,LONG Width);
		LONG Mean(LONG* pData,LONG Width);
		LONG Max(LONG* pData,LONG Width);
		ULONG GetNumber(CHAR* pSrc ,LONG Index);
		LONG GetString(CHAR* pSrc ,LONG Index,CHAR* pDest);
public:
	STDMETHOD(WriteDataPattern)(LONG Base, LONG Step);
	STDMETHOD(get_IsOpened)(LONG* pVal);
	STDMETHOD(get_ModuleTypeName)(BSTR* pVal);
	STDMETHOD(SaveCurrentStatus)(void);
	STDMETHOD(get_PixelSize)(FLOAT* pVal);
	STDMETHOD(get_PixelNumber)(LONG* pVal);
	STDMETHOD(get_ModuleType)(LONG* pVal);
	STDMETHOD(get_MaxIntTime)(LONG* pVal);
	STDMETHOD(get_MinIntTime)(LONG* pVal);
	STDMETHOD(get_OverallGain)(FLOAT* pVal);
	STDMETHOD(put_OverallGain)(FLOAT newVal);
	STDMETHOD(get_StartPixel)(LONG* pVal);
	STDMETHOD(put_StartPixel)(LONG newVal);
	STDMETHOD(get_EndPixel)(LONG* pVal);
	STDMETHOD(put_EndPixel)(LONG newVal);
	STDMETHOD(OnBoardOffsetCalibration)(void);
	STDMETHOD(OnBoardGainCalibration)(LONG TargetValue);
	STDMETHOD(ResetGain)(void);
	STDMETHOD(ResetOffset)(void);
	STDMETHOD(get_FPGA_Version)(LONG* pVal);
	STDMETHOD(get_FPGA_Build)(LONG* pVal);
	STDMETHOD(get_MCU_Version)(LONG* pVal);
	
	STDMETHOD(get_SerialNumber)(BSTR* pVal);

	STDMETHOD(RetrieveSysinfo)(void);
};

