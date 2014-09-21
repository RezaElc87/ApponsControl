// DTImage.cpp : Implementation of CDTImage
#include "stdafx.h"
#include <atlctl.h>
#include <comutil.h>

#include "dtimage.h"
#include "DTException.h"
#include "Guids.h"
#include "pixelorderconverter.h"
#include <omp.h>

// CDTImage
#define IDT_TIMER1   0x10000


STDMETHODIMP CDTImage::get_ImgHeight(LONG* pVal)
{
	
	*pVal = m_ImageHeight;
	return S_OK;
}

STDMETHODIMP CDTImage::put_ImgHeight(LONG newVal)
{
	
	if(!m_bIsOpened)
	{
		m_ImageHeight = newVal;
		m_SubFrameHeight = m_ImageHeight;
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_ImgWidth(LONG* pVal)
{
	
	*pVal = m_ImageWidth;
	return S_OK;
}

STDMETHODIMP CDTImage::put_ImgWidth(LONG newVal)
{
	
	if(!m_bIsOpened)
	{
		m_ImageWidth = newVal;
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_BytesPerPixel(LONG* pVal)
{
	
	*pVal = m_BytesPerPixel;
	return S_OK;
}

STDMETHODIMP CDTImage::put_BytesPerPixel(LONG newVal)
{
	
	if(!m_bIsOpened)
	{
		m_BytesPerPixel = newVal;
	}	
	return S_OK;
}

STDMETHODIMP CDTImage::get_ChannelType(LONG* pVal)
{
	
	*pVal = m_CardType;
	return S_OK;
}

STDMETHODIMP CDTImage::put_ChannelType(LONG newVal)
{
	if(!m_bIsOpened)
	{	
		m_CardType = newVal;
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_ImagePort(LONG* pVal)
{
	*pVal = m_ImagePort;
	return S_OK;
}

STDMETHODIMP CDTImage::put_ImagePort(LONG newVal)
{
	
	if(!m_bIsOpened)
	{
		m_ImagePort = newVal;
	}	

	return S_OK;
}

STDMETHODIMP CDTImage::get_DetectorObject(IUnknown**  pVal)
{
	if(m_pDetector)
	{
		m_pDetector->QueryInterface(IID_IUnknown,(void**)pVal); 
	}
	else
	{
		*pVal = NULL;
	}
	
	return S_OK;
}

STDMETHODIMP CDTImage::put_DetectorObject(IUnknown* newVal)
{
	
	if(!m_bIsOpened)
	{//If not open then allow change
		newVal->QueryInterface(IID_IDTDetector,(void**)&m_pDetector); 
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_IsOpened(LONG* pVal)
{
	
	*pVal = m_bIsOpened;
	return S_OK;
}

STDMETHODIMP CDTImage::get_LastErrID(LONG* pVal)
{
	
	*pVal = m_LastErrID;
	return S_OK;
}

STDMETHODIMP CDTImage::Open(LONG* b_OK)
{
	ULONG SubFrameNum = 1;
	m_dualScanMode = 0;

	m_LastErrID = EID_SUCCESS;
	
	BOOL bRunTime;
	//To avoid VB2005 call this automaticlly
	GetAmbientUserMode(bRunTime);
	if(!bRunTime)
	{
    	
		return S_OK;
	}
	if(m_hWnd)
	{
		this->SetTimer(10001,1000);//Timer be used for caculate bandwidth
	}
	//::SetTimer(m_wndHidden.m_hWnd,10001,1000,NULL);
	if(m_bIsOpened)
	{
    	
		*b_OK = TRUE;
		return S_OK;
	}

	SubFrameNum = m_ImageHeight/m_SubFrameHeight;
	//Get DTFrameBuffer
	m_pFrameBuf = m_FrameBufFactory.GetDTFrameBuf(this,m_ImageWidth,m_ImageHeight,m_BytesPerPixel,SubFrameNum);
	//Apply ImageObejct
	if(m_bPixelOrderEnable) {
		m_pFrameBuf->setPixelOrderProcessor(&m_pixelOrderProcessor);
	} else {
		m_pFrameBuf->setPixelOrderProcessor(NULL);
	}



	HRESULT hr = ::CoCreateInstance(CLSID_IImageObject,NULL,CLSCTX_ALL,IID_IImageObject,(LPVOID*) &m_pImageObject);
	if(FAILED(hr))
	{
		_com_error err(hr);
		MessageBox(err.ErrorMessage(),NULL);
	}
	m_pImageObject->AddRef();

	if(m_pImageObject)
	{
		m_pImageObject->Open(m_ImageWidth,m_ImageHeight,m_BytesPerPixel);
		m_pFrameBuf->SetImageObject(m_pImageObject);
	}
	else
	{
		m_LastErrID = EID_CANNOT_OPEN_IMG_OBJ;
		m_bIsOpened = FALSE;
		*b_OK = FALSE;
	}
	//Get DTPQueue
	m_pDTPQueue = m_DTPQueueFactory.GetDTPQueue();
	m_DTPPacketFactory.ReleaseAllPacket();
	//Get PacketList
	CDTPPacketIF* pPacket = NULL;
	
	if(DT_USB == m_CardType)
	{
		ULONG SubFrameSize = ((m_BytesPerPixel*DT_USB_PXIEL_NUMBER+DTP_HEAD_LEN)*m_SubFrameHeight/DT_USB_PACKET_LEN+1)*DT_USB_PACKET_LEN;
		if(SubFrameSize > 0x8000)
			SubFrameSize = 0x8000;
		DWORD PacketSize = SubFrameSize ;
		DWORD PacketNum = SubFrameNum;
		if(PacketNum < PACKET_NUM)
			PacketNum = PACKET_NUM;
		
		pPacket = m_DTPPacketFactory.GetNewDTPPacketList(DT_USB,PacketSize,PacketNum);
	}
	else
		pPacket = m_DTPPacketFactory.GetNewDTPPacketList(DT_USB,NET_PACKET_BUF_SIZE,PACKET_NUM);
	if(m_pFrameBuf)
	{
		//Create DataSrc form CardType
		switch(m_CardType)
		{
		case DT_USB:
			{
				//Check the USB deveice status;
                UCHAR ucUSBPort;
				LONG ulPort=0;
				m_pDetector->get_SerialPort(&ulPort);
				ucUSBPort=ulPort;
				m_pDTPQueue->SetDeviceID(ulPort);
				//ucUSBPort=0;
				m_pDataSrc = m_DTDataSrcFactory.GetDataSrc(DT_USB,m_pDetector, &ucUSBPort);
				//if m_pDataSrc return NULL shoudl return with false
				if(m_pDataSrc == NULL)
				{
					m_LastErrID = EID_USB_IMG_CHANEL_OPEN_FAILED;
					*b_OK = FALSE;
					return S_OK;
				}
				
				ATLASSERT(m_pDataSrc);
				//Add packet list to Data Source
				m_pDataSrc->AddDTPPacketList(pPacket);
				//Connect Queue and Data Source
				m_pDataSrc->SetDTPQueue(m_pDTPQueue);
				m_pDTPQueue->SetDataSrc(m_pDataSrc);
				//Connect Frame Buffer with Queue
				m_pDTPQueue->SetFrameBuf(m_pFrameBuf);
				//Connect Eventmanager with Queue
				m_pDTPQueue->SetEventManager(this);
				m_bIsOpened = TRUE;
				*b_OK = TRUE;
			}
			break;
		case DT_NET:
			{
				char RemoteIP[20];
				BSTR BSTRIP;
				m_pDetector->get_IPAddress(&BSTRIP);
				CHAR* tempbuf = _com_util::ConvertBSTRToString(BSTRIP);
				strncpy((CHAR*)RemoteIP,tempbuf,19);
				delete [] tempbuf;

				NetParam Param(RemoteIP,m_ImagePort);
				m_pDataSrc = m_DTDataSrcFactory.GetDataSrc(DT_NET,m_pDetector,&Param);
				if(m_pDataSrc)
				{
					m_pDataSrc->AddDTPPacketList(pPacket);
					m_pDataSrc->SetDTPQueue(m_pDTPQueue);
					m_pDTPQueue->SetDataSrc(m_pDataSrc);
					m_pDTPQueue->SetFrameBuf(m_pFrameBuf);
					m_pDTPQueue->SetEventManager(this);
					m_bIsOpened = TRUE;
					*b_OK = TRUE;
				}
				else
				{
					m_bIsOpened = FALSE;
					*b_OK = FALSE;
				}
			}
			break;
		default:
			{
				m_LastErrID = EID_UNKNOWN_IMG_CHANNEL;
				m_bIsOpened = FALSE; 
				*b_OK = FALSE;
			}
		}
		
	}
	else
	{
		m_LastErrID = EID_FRAMEBUF_ALLOC_FAIL;
		m_bIsOpened = FALSE;
		*b_OK = FALSE;
	}
	CDTException Err(m_LastErrID);
	DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
   	
	return S_OK;
}

STDMETHODIMP CDTImage::Close(void)
{
	// TODO: Release All resource
	m_LastErrID = EID_SUCCESS;
	if(m_bIsOpened )
	{
		m_bIsOpened = FALSE;
		Stop();
		//m_pDataSrc->Close();
		//CDTException Err(m_LastErrID);
		//DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	}
	if(m_pImageObject)
		m_pImageObject->Release();
	m_pImageObject = NULL;
	return S_OK;
}
void CDTImage::SendFrameTrigger()
{
	char cmd[100];
	char rt[100];
	LONG bSuccess;
	if(m_bExFrameTrigger)
	{
		sprintf(cmd,"[SE]");
		m_pDetector->SendCommandA(cmd,rt,&bSuccess);
	}
}
void CDTImage::SetFrameTrigger()
{
	char cmd[100];
	char rt[100];
	LONG bSuccess;
	if(m_bExFrameTrigger)
	{
		int size = m_ImageHeight/DT_FRAME_UNIT;
		//int size = 7;
		//sprintf(cmd,"[EF,W,%X]",size);
		sprintf(cmd,"[EF,W,%X]",m_ImageHeight);
	}
	else
	{
		sprintf(cmd,"[EF,W,0]");
	}
	if(m_pDataSrc)
		m_pDataSrc->SetTimeOut(m_Timeout);
	m_pDetector->SendCommandA(cmd,rt,&bSuccess);
	if(!bSuccess)
	{
//		throw CDTException(EID_USB_CMD_SEND_FAIL);
	}
}
STDMETHODIMP CDTImage::Grab(LONG FrameNums, LONG* bOK)
{
	BOOL bRunTime;
	//To avoid VB2005 call this automaticlly
	GetAmbientUserMode(bRunTime);
	if(!bRunTime)
		return S_OK;
	try
	{
		m_LastErrID = EID_SUCCESS;
		if(m_pDataSrc)
		{   
			m_FrameNum = FrameNums;
			m_CurFrameCount = 0;
			
			m_pFrameBuf->Reset();
			ResetAllDTPPacket();//Clear all DTPPacket Content
			SetFrameTrigger();
			if(m_pDataSrc->Start())//start the thread to get the fame
			{
				*bOK = TRUE;
			}
			else
			{
				*bOK = FALSE;
			}
		}
		else
		{
			m_LastErrID = EID_NO_IMG_CHANEL;
			*bOK =  FALSE;
			throw CDTException(m_LastErrID);
		}
		
	}
	catch (CDTException E)
	{
		//E.PrintErrInfo();
		E.ProcessError();
		//End all commit packet
	}
	return S_OK;
}

STDMETHODIMP CDTImage::Snap(LONG FrameNums, LONG* bOK)
{
	// TODO: Add your implementation code here
	//If Datasrc avalible
	BOOL bRunTime;
	//To avoid VB2005 call this automaticlly
	GetAmbientUserMode(bRunTime);
	if(!bRunTime)
		return S_OK;
	m_LastErrID = EID_SUCCESS;
	try
	{
		if(m_pDataSrc)
		{
			//Stop First
			
			m_pDataSrc->Stop();
			
			//FrameNum at least be 1
			m_FrameNum = ((FrameNums>1)?FrameNums:1);
			//Reset Current Frame Count
			m_CurFrameCount = 0;
			//Reset the Event Flag of all frame send
			ResetEvent(m_hAllFrameSended);
			//Clear all DTPPacket Content to clean the DTPStack
			m_pFrameBuf->Reset();
			SetFrameTrigger();
			ResetAllDTPPacket();//Clear all DTPPacket Content
			//start the therad to get the frame
			if(m_pDataSrc->Start())
			{
				//If start succesful, Wait untill all Frame finnish
				while(WaitForSingleObject(m_hAllFrameSended,10) == WAIT_TIMEOUT)
				{//Check the Frame Number every 10ms
					if(!m_pDataSrc->IsRunning())
					{//If for some reason the thread is stopped, then break,
						//MessageBox("T3");
						break;
					}
				};
				*bOK = TRUE;
			}
			else
			{//If Datasrc start failed then means no image channel
				m_LastErrID = EID_NO_IMG_CHANEL;
				*bOK = FALSE;
				throw CDTException(m_LastErrID);
			}
		}
		else
		{//If no datasrc 
			m_LastErrID = EID_NO_IMG_CHANEL;
			*bOK =  FALSE;
			throw CDTException(m_LastErrID);
		}
	
	}
	catch (CDTException E)
	{
		//E.PrintErrInfo();
		E.ProcessError();
		//End all commit packet
	}
	return S_OK;
}

STDMETHODIMP CDTImage::PrintErrMsg(LONG ErrID, BSTR* ErrMsg)
{
	// TODO: Add your implementation code here

	return S_OK;
}



STDMETHODIMP CDTImage::get_SubFrameHeight(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_SubFrameHeight;
	return S_OK;
}

STDMETHODIMP CDTImage::put_SubFrameHeight(LONG newVal)
{
	// TODO: Add your implementation code here
	m_SubFrameHeight = newVal;
		//Check the SubFrameHeight consistance. If it cannot divided, then reset it same as frame height;


	if( (m_ImageHeight%m_SubFrameHeight) != 0)
	{
		m_SubFrameHeight = m_ImageHeight;
	}
	return S_OK;
}
void CDTImage::ResetAllDTPPacket()
{
	m_DTPPacketFactory.ClearAllPacket();
	//Move the data packet in Queue and Commit queue into wait queue
	if(m_pDTPQueue)
	{
		m_pDTPQueue->ClearQueue();//Clear the buffer of packet and return it to wait queue
	}
	if(m_pDataSrc)
	{
		m_pDataSrc->ResetQueue();
	}
}
void CDTImage::OnDTEvent(BYTE EventID,BYTE EventContent)
{
		//	ATLTRACE("Event ID is %d\n",EventID);
	switch(EventID)
	{
		case DT_EVENT_DATA_LOST:
			Datalost(EventContent);
			break;
	}
};
void CDTImage::OnDTFrameReady(BYTE* pSrc, DWORD Size)
{
	//Ajuadge whther to stop the datasrc
	//m_FrameNum is the total frame number want to take
	//if ==0 menas continues untill user stop
	if(m_revert) {
		RevertConverter converter;
		converter.process(m_pImageObject, 0, m_ImageHeight);
	}

	if(m_dualScanMode) {
			int boardNum = m_ImageWidth/64; //every board have 64 bits
			DualToSingleConverter converter(boardNum, 64);
			converter.process(m_pImageObject, 0, m_ImageHeight);
	}
			//long pBase = 0;
			//m_pImageObject->get_ImageDataAddress(&pBase);
			//ATLTRACE("Frame m_pImageObject is %x\n", pBase );

	if(m_FrameNum>0)//Snap or grab operation with Num
	{
		m_CurFrameCount++;
		if(!m_pDataSrc->GetStopFlag())
		{
			//MessageBox("N1");
			FrameReady(m_ImageHeight);
			
			OnSinkFrameReady(m_ImageHeight);
			
		}
		//ATLASSERT(m_FrameNum >= m_CurFrameCount);
		if(m_CurFrameCount == m_FrameNum)
		{
			//Here cannot use m_pDataSrc->Stop() to stop the thread
			//Because stop() will wait untill the Grabthread end, the grab thread will wait
			// until the Queue Thread End, but this function will be called by queue thread when
			// Frame Ready happen. The result is deadlock if call stop. So use setstop flag as
			// an asynchronize stop method
			m_pDataSrc->SetStopFlag(TRUE);
			SetEvent(m_hAllFrameSended);
		}
	}
	//ATLTRACE("Frame Send\n");
	else//UnEnd grab
	{
		if(!m_pDataSrc->GetStopFlag())
		{//If the flag still not set then post the Frame Read Message
		//else do nothing . It is useful for the last frame. If user have click stop
			//THen the current unfinnish frame should not overwrite the old one

			FrameReady(m_ImageHeight);	
			OnSinkFrameReady(m_ImageHeight);
		}
	}
	//ATLTRACE("Frame Send End");
};
void CDTImage::OnDTSubFrameReady(LONG  RowID, LONG NumLines,BOOL bLastFrame)
{
	//In sub frame ready function cannot use m_pImageObject to process data
	//because m_pImageObject is the current Ready Frame. But the SubFrame Ready
	// is using current processing frame which one frame ahead the Ready frame
		//if(m_dualScanMode) {
		//	int boardNum = m_ImageWidth/64; //every board have 64 bits
		//	DualToSingleConverter converter(boardNum, 64);
		//	converter.process(m_pImageObject, RowID, NumLines);
		//	long pBase = 0;
		//	m_pImageObject->get_ImageDataAddress(&pBase);
		//	ATLTRACE("SubFrame m_pImageObject is %x\n", pBase );
		//}
	//Caclute the Start Line , Numof lines and left blocks, and the lastblock flag
		if(!m_pDataSrc->GetStopFlag())
		{//If the flag still not set then post the Frame Read Message
		//else do nothing . It is useful for the last frame. If user have click stop
			//THen the current unfinnish frame should not overwrite the old one
			LONG LeftBlocks = (m_ImageHeight - RowID)/m_SubFrameHeight - 1;
			//MessageBox("N2");
			SubFrameReady(LeftBlocks,RowID,NumLines,bLastFrame);
			OnSinkSubFrameReady(LeftBlocks,RowID,NumLines,bLastFrame);			
		}
};

STDMETHODIMP CDTImage::Stop(void)
{
	// TODO: Add your implementation code here
	m_LastErrID = EID_SUCCESS;
	if(m_pDataSrc)
	{
		if(m_pDataSrc->IsRunning())
		{
			//m_pFrameBuf->SetImageObject(NULL);
			SendFrameTrigger();//If it is external framer trigger mode,send one trigger to stop
			if(m_pDataSrc->Stop())
			{
			}
			else
			{
				ATLASSERT(0);
			}
		}
	}
	CDTException Err(m_LastErrID);
//	DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	return S_OK;
}

STDMETHODIMP CDTImage::get_IsGrabing(LONG* pbGrab)
{
	// TODO: Add your implementation code here
	if(m_pDataSrc)
	{
		if(m_pDataSrc->IsRunning())
		{
			*pbGrab = TRUE;
		}
		else
		{
			*pbGrab = FALSE;
		}
	}
	else
	{
		*pbGrab = FALSE;
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_ImageObject(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_pImageObject;
	return S_OK;
}

STDMETHODIMP CDTImage::get_BandWidth(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_BandWidth;
	return S_OK;
}

void CDTImage::OnTimer()
{
	// TODO: Add your message handler code here and/or call default
	LONG bGrab=0;
		get_IsGrabing(&bGrab);
		if(bGrab)
		{
			m_BandWidth=m_BytesReceived;
			m_BytesReceived = 0;
		}
		else
		{
			m_BandWidth = 0;
			m_BytesReceived = 0;
		}
	
}
void CDTImage::OnNewDataComimg(ULONG Size)
{
	m_BytesReceived += Size;
}

LRESULT CDTImage::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	OnTimer();
	return 0;
}

void CDTImage::OnSinkFrameReady(LONG NumLines)
{
	for(int i=0;i<SINK_SIZE;i++)
	{
		if(m_SinkArray[i])
			m_SinkArray[i]->OnFrameReady(NumLines);
	}
}
void CDTImage::OnSinkSubFrameReady( LONG NumOfBlockLeft,  LONG StartLine,  LONG NumLines, BYTE bLastBlock)
{
	for(int i=0;i<SINK_SIZE;i++)
	{
		if(m_SinkArray[i])
			m_SinkArray[i]->OnSubFrameReady(NumOfBlockLeft,StartLine,  NumLines, bLastBlock);;
	}
}

void CDTImage::AdviseSink(IDTImageEventSink* pSink,LONG* pCookie)
{
	int i;
	for(i=0;i<SINK_SIZE;i++)
	{
		if(NULL == m_SinkArray[i])
		{
			m_SinkArray[i] = pSink;
			*pCookie = i;
			break;
		}
	}
	if(SINK_SIZE == i)//Not find avalible position
	{
		*pCookie = -1;
	}
}
void CDTImage::UnAdviseSink(LONG Cookie)
{
	if(Cookie > SINK_SIZE)
		return;
	if(Cookie < 0)
		return;
	m_SinkArray[Cookie] = NULL; 
	return;
}
STDMETHODIMP CDTImage::get_ObjectHandle(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	this->QueryInterface(IID_IUnknown,(void**) pVal);
	
	return S_OK;
}

STDMETHODIMP CDTImage::get_TimeOut(LONG* pVal)
{
	// TODO: Add your implementation code here
	if(m_pDataSrc)
		m_pDataSrc->GetTimeOut(pVal);
	else
		*pVal = m_Timeout;
	return S_OK;
}

STDMETHODIMP CDTImage::put_TimeOut(LONG newVal)
{
	// TODO: Add your implementation code here
	m_Timeout = newVal;
	if(m_pDataSrc)
		m_pDataSrc->SetTimeOut(m_Timeout);
	return S_OK;
}

STDMETHODIMP CDTImage::get_ExFrameTrigger(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal =	m_bExFrameTrigger ;
	return S_OK;
}

STDMETHODIMP CDTImage::put_ExFrameTrigger(LONG newVal)
{
	// TODO: Add your implementation code here
	if(newVal)
		m_bExFrameTrigger = 1;
	else
		m_bExFrameTrigger = 0;
	return S_OK;
}


/*STDMETHODIMP CDTImage::Advise(ICallBack* pCallback, long* dwCookie)
{
	// TODO: 在此添加实现代码

	//return S_OK;
}


STDMETHODIMP CDTImage::UnAdvise(long dwCookie)
{
	// TODO: 在此添加实现代码

	return S_OK;
}
*/

STDMETHODIMP CDTImage::get_DualScanMode(LONG* pVal)
{
	// TODO: 在此添加实现代码
	*pVal = m_dualScanMode;
	return S_OK;
}


STDMETHODIMP CDTImage::put_DualScanMode(LONG newVal)
{
	// TODO: 在此添加实现代码
	m_dualScanMode = newVal;
	return S_OK;
}


STDMETHODIMP CDTImage::OpenMemImage(LONG width, LONG height, BYTE* data)
{
	// TODO: 在此添加实现代码

	return S_OK;
}


//STDMETHODIMP CDTImage::Advise(IFrameReadyCallBack* pCallBack, long* cookie)
//{
//	// TODO: 在此添加实现代码
//
//	return S_OK;
//}
//
//
//STDMETHODIMP CDTImage::UnAdvise(LONG cookie)
//{
//	// TODO: 在此添加实现代码
//
//	return S_OK;
//}


STDMETHODIMP CDTImage::get_OffsetEnable(BYTE* pVal)
{
	*pVal = m_bOffsetEnable;
	return S_OK;
}


STDMETHODIMP CDTImage::put_OffsetEnable(BYTE newVal)
{
	m_bOffsetEnable = newVal;
	if(m_bOffsetEnable) {
		m_pFrameBuf->setOffsetProcessor(&m_offsetProcessor);
	} else {
		m_pFrameBuf->setOffsetProcessor(NULL);
	}
	return S_OK;
}


STDMETHODIMP CDTImage::get_GainEnable(BYTE* pVal)
{
	*pVal = m_bGainEnable;
	return S_OK;
}


STDMETHODIMP CDTImage::put_GainEnable(BYTE newVal)
{
	m_bGainEnable = newVal;
	if(m_bGainEnable) {
		m_pFrameBuf->setGainProcessor(&m_gainProcessor);
	} else {
		m_pFrameBuf->setGainProcessor(NULL);
	}
	return S_OK;
}


STDMETHODIMP CDTImage::get_PixelOrderEnable(BYTE* pVal)
{
	*pVal = m_bPixelOrderEnable;
	return S_OK;
}


STDMETHODIMP CDTImage::put_PixelOrderEnable(BYTE newVal)
{
	m_bPixelOrderEnable = newVal;
	if(!m_pFrameBuf)
		return S_OK;
	if(m_bPixelOrderEnable) {
		m_pFrameBuf->setPixelOrderProcessor(&m_pixelOrderProcessor);
	} else {
		m_pFrameBuf->setPixelOrderProcessor(NULL);
	}
	return S_OK;
}


STDMETHODIMP CDTImage::OffsetCalibration(void)
{
	//Shut down x-ray and snap one picture
    long bOk;
	Snap(1,&bOk);
	//get the avg of each col
	long width;
	m_pImageObject->get_Width(&width);
	long pAvg;
	m_pImageObject->DoColStatistic();
	m_pImageObject->ColAverage(&pAvg);
	long i=0;
	for(i=0; i<width;i++)
		m_offsetProcessor.setOffset(((double*)pAvg)[i], i);
	return S_OK;
}


STDMETHODIMP CDTImage::GainCalibration(LONG target)
{
	long bOk;
	put_OffsetEnable(TRUE);
	Snap(1,&bOk);
	long width;
	m_pImageObject->get_Width(&width);
	long i=0;
	long pAvg;
	m_pImageObject->DoColStatistic();
	m_pImageObject->ColAverage(&pAvg);
	double val;
	long flag = target;
	if(0 == flag) {
		target = ((double*)pAvg)[0];
		for(i=0; i < width; i++) {
			val = ((double*)pAvg)[i];
			if (val< target)
				target = val;
		}
	}else if(1 == flag) {
			for(i=0; i < width; i++) {
				val += ((double*)pAvg)[i];
			}
			target = val/width;
	}else if(2 == flag) {
		target = ((double*)pAvg)[0];
		for(i=0; i < width; i++) {
			val = ((double*)pAvg)[i];
			if (val> target)
				target = val;
		}
		target = val/width;
	}

	for(i=0;  i < width; i++) {
		m_gainProcessor.setGain(target/((double*)pAvg)[i], i);
	}
	return S_OK;
}


STDMETHODIMP CDTImage::GainCalSnap(void)
{
	long bOk;
	//put_OffsetEnable(TRUE);
	Snap(1,&bOk);
	m_pImageObject->DoColStatistic();
	long width;
	m_pImageObject->get_Width(&width);
	long pAvg;
	m_pImageObject->ColAverage(&pAvg);

	m_arrayProcessor.addData((double*)pAvg, width);
	return S_OK;
}


STDMETHODIMP CDTImage::GainArrayCal(void)
{
	m_arrayProcessor.reset();
	return S_OK;
}


STDMETHODIMP CDTImage::get_arrayCorrectionEnable(BYTE* pVal)
{
	*pVal = m_arrayCorrectionEnable;

	return S_OK;
}


STDMETHODIMP CDTImage::put_arrayCorrectionEnable(BYTE newVal)
{
	m_arrayCorrectionEnable = newVal;
	if(m_arrayCorrectionEnable) {
		m_pFrameBuf->setArrayProcessor(&m_arrayProcessor);
	} else {
		m_pFrameBuf->setArrayProcessor(NULL);
	}
	return S_OK;
}

STDMETHODIMP CDTImage::get_Revert(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_revert;
	return S_OK;
}

STDMETHODIMP CDTImage::put_Revert(LONG newVal)
{
	m_revert = newVal;
	return S_OK;
}