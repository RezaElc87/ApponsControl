#include "StdAfx.h"
#include ".\dtpqueue.h"
#include "EventManagerIF.h"
#include ".\dtexception.h"
#include "DTImage.h"
#include <process.h>
CDTPQueue::CDTPQueue(void):
m_pTail(NULL),
m_pHead(NULL),
m_pDataSrc(NULL),
m_pEventManager(NULL),
m_pFrameBUF(NULL),
m_ImageCounter(1)
{
	m_bThreadStop;//Thread stop flag
	m_hThread = NULL;//Thread Handle
	m_hThreadEndEvent = CreateEvent(NULL,TRUE,FALSE,NULL);////Flag to indicate that the thread is runing
	SetEvent(m_hThreadEndEvent);
	m_hPacketReady = CreateEvent(NULL,TRUE,FALSE,NULL);
	ResetEvent(m_hPacketReady);//At first there is no packet
	InitializeCriticalSection(&m_TailCR);
	m_ThreadID = 0;
	ResetHeader();
	m_bThreadStop = TRUE;
}

CDTPQueue::~CDTPQueue(void)
{
	CloseHandle(m_hThreadEndEvent);
	CloseHandle(m_hPacketReady);
	DeleteCriticalSection(&m_TailCR);
}
void CDTPQueue:: ResetImageCounter()
{
	m_ImageCounter = 0;
}
		// Called when a Datasrc packet ready, add the packet to the end of queue and check is there any finnished packet
//AddTail is Called By DataSrc Thread to update the m_Tail Pointer
void CDTPQueue::AddTail(CDTPPacketIF* pDTPacket)
{
	//Append the new packet to the end of queue
	//Should set the pDTPacket->next as NULL because 
	//currently there is no relation between this packet and the datasrc list
	EnterCriticalSection(&m_TailCR);
	pDTPacket->SetNext(NULL);
	if(m_pHead == NULL)
	{
		m_pHead = pDTPacket;
		m_pTail = m_pHead;
	}
	else
	{
		m_pTail->SetNext(pDTPacket);
		m_pTail = m_pTail->GetNext();
	}
/*	m_hTraceFile = fopen( "D:\\TracePacket.txt", "a" );
		fprintf(m_hTraceFile,"\n++++++++++++\n");
		m_pTail->Trace(m_hTraceFile);
		fclose( m_hTraceFile);
		*/
//	ATLTRACE("Add packet\n");
	if(GetCurDTPLen() == 0)
	{//if cur len =0 that means the len bytes still notcp to the array
		//Move the first 6 bytes to header
		MoveHeader();//cp len bytes to array
	}
	ATLASSERT(m_pTail == pDTPacket);
	SetEvent(m_hPacketReady);
	LeaveCriticalSection(&m_TailCR);

}

void CDTPQueue::CheckDTP()
{
	//Curretly already add on packet 
	//The Len maybe 0 or not zero
	CDTPPacketIF* pCurPacket = NULL;
	ULONG DataLen = 0;
	while(!m_bThreadStop)
	{
	/*	if(!m_pDataSrc->IsRunning())
		{
			break;
		}*/
		if(GetQueueSize() == 0)//THere is no packet in Queue
		{
			ResetEvent(m_hPacketReady);
	//		ATLTRACE("DTPQueue Wait\n");
			WaitForSingleObject(m_hPacketReady,500);
	//		ATLTRACE("DTPQueue Continue\n");
				//If Time out, Therad will check the stop flag
		}
		else if(GetCurDTPLen() == 0)
		{//if the header is empty.  Two Possible reasons:
			//1 Current m_Tail is NULL, 2 Current m_Tail Packet Length < 6

			ResetEvent(m_hPacketReady);
	//		ATLTRACE("DTPQueue Wait\n");
			if(m_bThreadStop)
				break;
			WaitForSingleObject(m_hPacketReady,300);
		//	ATLTRACE("DTPQueue Continue\n");
		}
		else if(GetQueueSize() <(GetCurDTPLen()-DTP_HEAD_LEN))
		{  // The Queue Length is not big enough to finnish a DTP packet
			ResetEvent(m_hPacketReady);
		//	ATLTRACE("DTPQueue Wait\n");
			WaitForSingleObject(m_hPacketReady,300);
	//		ATLTRACE("DTPQueue Continue\n");
		}
		else//handling data
		{
			//Here the Header should be already copyed
			ATLASSERT(GetCurDTPLen()>0);
			BYTE PacketType = GetCurType();
			if((PacketType == DT_IMG)||(PacketType == DT_DUMY))
			{
					if(m_ImageCounter != m_Header[3])
					{
						int LostLinesNum = 0;
						if(m_Header[3]> m_ImageCounter)
							LostLinesNum = m_Header[3] - m_ImageCounter;
						else
							LostLinesNum = m_Header[3]+0xFF - m_ImageCounter;
						//Raise Datalost Event
						ATLTRACE("Data Lost %d\n",LostLinesNum);
						OnDataLostEvent(LostLinesNum);
						m_ImageCounter = m_Header[3];
					}
					m_ImageCounter++;
					pCurPacket = m_pHead;
					DataLen = GetCurDTPLen()-DTP_HEAD_LEN;//len is just the img length
					do
					{
						//Get avalible data length from the current packet
						unsigned int CurLen = pCurPacket->GetDTPLen();
				//		ATLTRACE("CurLen is %d\n",CurLen);
						if(CurLen < DataLen)
						{//if CurLen<DataLen then means one line(DTPPacket is copose by serveral usbpacket
								m_pHead = pCurPacket->GetNext();//Move to next packet
								if(PacketType == DT_IMG)
									m_pFrameBUF->AddOneFrameLine(pCurPacket->GetBuf(),CurLen,FALSE);						
								//Return the use DTPPacket to DataSrc
								pCurPacket->Reset();//Need reset the offset and buf size to be reuse
								
								m_pDataSrc->AddDTPPacket(pCurPacket);
								
						}
						else if(CurLen == DataLen)
						{
							m_pHead = pCurPacket->GetNext();//move to handle next packet
							if(PacketType == DT_IMG)
								m_pFrameBUF->AddOneFrameLine(pCurPacket->GetBuf(),CurLen,TRUE);
							//Return the use DTPPacket to DataSrc
							pCurPacket->Reset();//Need reset the offset and buf size to be reuse
							m_pDataSrc->AddDTPPacket(pCurPacket);
						}
						else//Curlen > dataLen
						{	
							CurLen = DataLen;
							if(PacketType == DT_IMG)//if it is dumy data then just ignore
								m_pFrameBUF->AddOneFrameLine(pCurPacket->GetBuf(),CurLen,TRUE);
							//Update the pCurPacket content;
							pCurPacket->MoveFirstToWithOffset(CurLen);
						}
						DataLen -= CurLen;
						pCurPacket = m_pHead;
						ATLASSERT(DataLen >= 0);
					}while(DataLen > 0);
			}//End DT_IMG
			else //DT Event
			{//DTEvent P{acke tshould be not so long
				//So it is impossible to occupy 3 packet or More. At most take 2 packet.
				//And
					BYTE EventID = PacketType;
					BYTE EventContent = GetCurContent();
					m_pEventManager->OnDTEvent(EventID,EventContent);
					ULONG DataLen = GetCurDTPLen()-DTP_HEAD_LEN;//len is just the img length
					m_pHead->MoveFirstToWithOffset(DataLen);
					//A bug: If the event data is not in one packet will cause error
					//if(m_pHead->GetDTPLen() == 0)
					//m_pHead = m_pHead->GetNext();
			}
			//Move Header to update len
			MoveHeader();
		}
	}
}
void CDTPQueue::OnDataLostEvent(BYTE LostNum)
{
	m_pEventManager->OnDTEvent(DT_EVENT_DATA_LOST,LostNum);
}
void CDTPQueue::ClearQueue()
{
//Move all DTPPacket to the Data Src Wait Queue
	CDTPPacketIF* pPacket;
	ResetHeader();
	while(m_pHead)
	{
		pPacket = m_pHead;
		m_pHead = m_pHead->GetNext();
		pPacket->Reset();
		if(m_pDataSrc)
		{
			m_pDataSrc->AddDTPPacket(pPacket);
		}
	}
}
void CDTPQueue::MoveHeader()
{
	EnterCriticalSection(&m_TailCR);
	ULONG QueueSize = GetQueueSize();
/*				FILE*  hTraceFile = fopen( "D:\\TracePacket.txt", "a" );
				fprintf(hTraceFile,"\nQueueLen is %d\n", QueueSize);
				fclose( hTraceFile);*/
	if(QueueSize>DTP_HEAD_LEN)
	{
		CDTPPacketIF* pCurPacket = m_pHead;
		int len = pCurPacket->GetDTPLen();
		int i=0;
		 len = (len> DTP_HEAD_LEN)?DTP_HEAD_LEN:len;
		memcpy(m_Header,pCurPacket->GetBuf(),len);//Copy Header
		pCurPacket->MoveFirstToWithOffset(len);
		if(pCurPacket->GetDTPLen()==0)//if the pCurPacket is empty then maybe the Header is not copy totally
		{
			ATLASSERT((DTP_HEAD_LEN - len)>=0);
			m_pHead = pCurPacket->GetNext();
			//Return pCurPacket to DataSrc
			pCurPacket->Reset();
			m_pDataSrc->AddDTPPacket(pCurPacket);
		}
		if((DTP_HEAD_LEN - len)>0)
		{
			memcpy(m_Header+len,m_pHead->GetBuf(),DTP_HEAD_LEN - len);//Copy the rest part
			m_pHead->MoveFirstToWithOffset(DTP_HEAD_LEN - len);
		}
	
	}
	else
	{
		ResetHeader();//Set header to zero
	}
	LeaveCriticalSection(&m_TailCR);
//	GetCurDTPLen();
}
BYTE CDTPQueue::GetCurContent()	
{
	BYTE Content;
	CDTPPacketIF* pCurPacket = m_pHead;
	Content = *pCurPacket->GetBuf();
	
	return Content;
}
ULONG CDTPQueue::GetCurDTPLen()
{
	if((*m_Header) != 0)
	{
		FILE* hTraceFile = fopen( "D:\\ErrorPacket.txt", "a" );
		m_pTail->Trace(hTraceFile);
		fclose( hTraceFile);
		throw CDTException(EID_PACKET_LEN_ERROR);
	}
	WORD Len = *(m_Header+1);
	Len <<= 8;
	Len |= *(m_Header+2);
/*	if(!((Len==1030)||(Len==8)||(Len == 0)))//Here check the XTP packet len, if len is not the correct one, then record the packet for analysis
	{
		FILE* hTraceFile = fopen( "D:\\ErrorPacket.txt", "a" );
		m_pTail->Trace(hTraceFile);
		fclose( hTraceFile);
		throw CDTException(ID_PACKET_LEN_ERROR);
	};*/
//	ATLTRACE("Len is %d\n",Len);
	return Len;
}
BYTE CDTPQueue::GetCurType()
{
	return m_Header[4];
}

DWORD CDTPQueue::GetQueueSize()
{
	CDTPPacketIF* pPacket = m_pHead;
	DWORD QueueLen = 0;
	EnterCriticalSection(&m_TailCR);
	while(pPacket != NULL)
	{
		QueueLen += pPacket->GetDTPLen();
		pPacket = pPacket->GetNext();
	}
	LeaveCriticalSection(&m_TailCR);
	return QueueLen;
};

// Set the data source to input data top returnt the used DTPacket
void CDTPQueue::SetDataSrc(CDTDataSrcIF* pDataSrc)
{
	m_pDataSrc = pDataSrc;
}
	//Set evenmanager to accept DTEvent
void CDTPQueue::SetEventManager(CEventManagerIF *pEventManager)
{
	m_pEventManager = pEventManager;
}
	//Set Frame buf to output the Frame data
void CDTPQueue::SetFrameBuf(CDTFrameBufIF* pFrameBuf)
{
	m_pFrameBUF = pFrameBuf;
}

DWORD WINAPI CDTPQueue::ThreadFunc(LPVOID param)
{
	CDTPQueue* pSrc = (CDTPQueue*) param;
	return pSrc->ThreadMemberFunc();
}
DWORD CDTPQueue::ThreadMemberFunc()
{
		//MessageBox(NULL,"Queue Running",NULL,MB_OK);
		ResetEvent(m_hThreadEndEvent);//Indicate the Thread Running
		try
		{
			CheckDTP();
		}
		catch (CDTException E)
		{
			LeaveCriticalSection(&m_TailCR);
			//E.PrintErrInfo();
			E.ProcessError();
			((CDTImage*)m_pEventManager)->DTError(E.m_ERROR_ID,E.m_ERROR_INFO);
//			m_pDataSrc->Stop();
		}
		ReturnAllPacket();
		ATLTRACE("Set Queue m_hThreadEndEvent\n" );
		SetEvent(m_hThreadEndEvent);
		ResetHeader();//When stop the grab, need reset the header for next time receive
						//When start grab, the header maybe operatate by DataSrc. So when start just reserve the header value
		return 0;
}
void  CDTPQueue::Start()
{
	if(IsRunning())
	{
		return ;
	}
	m_bThreadStop = FALSE;
	m_hThread = (HANDLE)_beginthreadex(NULL,0,(PBEGINTHREADEX_THREADFUNC)CDTPQueue::ThreadFunc,(LPVOID)this,0,(PBEGINTHREADEX_THREADID)&m_ThreadID);
};
BOOL CDTPQueue::IsRunning()
{
	if(WaitForSingleObject(m_hThreadEndEvent,0) == WAIT_TIMEOUT)
	{//Event Not Set So the Thread is Runing
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void  CDTPQueue::Stop()
{
	if(m_hThread)
	{
		//Do some action to stop thread.
		if(IsRunning())
		{
			m_bThreadStop = TRUE;
			SetEvent(m_hPacketReady);
			 ATLTRACE("Wait Queue m_hThreadEndEvent\n" );
			WaitForSingleObject(m_hThreadEndEvent,INFINITE);
			CloseHandle(m_hThread);
			m_hThread = NULL;
		}
	}
};
void CDTPQueue::ReturnAllPacket()
{
	while(m_pHead)
	{
		m_pHead->Reset();//Need reset the offset and buf size to be reuse
		m_pDataSrc->AddDTPPacket(m_pHead);
		m_pHead = m_pHead->GetNext();
	}
	ResetHeader();
}
void CDTPQueue::ResetHeader()
{
	memset(m_Header,0,DTP_HEAD_LEN);
}
