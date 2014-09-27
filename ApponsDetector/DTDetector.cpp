// DTDetector.cpp : Implementation of CDTDetector
#include "stdafx.h"
#include "DTDetector.h"
#include ".\dtdetector.h"
#include "DTException.h"
#include <comutil.h>

// CDTDetector

STDMETHODIMP CDTDetector::get_IPAddress(BSTR* pVal)
{
	CComBSTR bstrRT(m_RemoteIP);
	// Convert the string to uppercase
	// Return a copy of the string.
	bstrRT.CopyTo(pVal);	
	return S_OK;
}

STDMETHODIMP CDTDetector::put_IPAddress(BSTR newVal)
{
	// TODO: Add your implementation code here
	memset(m_RemoteIP,0,20);
	CHAR* tempbuf = _com_util::ConvertBSTRToString(newVal);
	strncpy((CHAR*)m_RemoteIP,tempbuf,19);
	delete [] tempbuf;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_CmdPort(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_CmdPort;
	return S_OK;
}

STDMETHODIMP CDTDetector::put_CmdPort(LONG newVal)
{
	// TODO: Add your implementation code here
	m_CmdPort = newVal;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_SerialPort(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_SerialPortNum;
	return S_OK;
}

STDMETHODIMP CDTDetector::put_SerialPort(LONG newVal)
{
	// TODO: Add your implementation code here
	m_SerialPortNum = newVal;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_ObjectHandle(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	this->QueryInterface(IID_IUnknown,(void**)pVal); 
	return S_OK;
}

STDMETHODIMP CDTDetector::get_IsOpened(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_bIsOpened;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_LastErrID(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_LastErrID;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_ChannelType(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_CardType;
	return S_OK;
}

STDMETHODIMP CDTDetector::put_ChannelType(LONG newVal)
{
	// TODO: Add your implementation code here
	m_CardType = newVal;
	return S_OK;
}

STDMETHODIMP CDTDetector::Open(LONG* bOK)
{
	CString strPort;
	LONG RT;
	m_LastErrID = EID_SUCCESS;
	BOOL bPortOpened = FALSE;
	int iCount=0;
	UCHAR ucUSBPort=0;
	if(m_bIsOpened)
	{
		Close();
	}
		switch(m_CardType)
		{
			case DT_SERIAL:
				
				strPort.Format(_T("COM%d"), m_SerialPortNum);
				RT = m_Serial.Open(strPort) ;
				if(RT != ERROR_SUCCESS)
				{	
					m_LastErrID = EID_SERIAL_CMD_OPEN_FAILED;
					//m_LastErrID = m_Serial.GetLastError();
					
					bPortOpened = FALSE;
				}
				else
				{
					bPortOpened = TRUE;
					switch(m_BaudRate)
					{
					case 4800:
						m_Serial.Setup(CSerial::EBaud4800);
							break;
					case 9600:
						m_Serial.Setup(CSerial::EBaud9600);
						break;
					case 19200:
						//m_Serial.Setup(CSerial::EBaud19200,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);
						m_Serial.Setup(CSerial::EBaud19200);
						break;
					default:
						m_Serial.Setup(CSerial::EBaud4800,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);
					}
					m_Serial.SetupHandshaking(CSerial::EHandshakeOff);
				}

				break;
			case DT_USB:
				ucUSBPort=m_SerialPortNum;
				if (m_DTUSBDevice.DeviceCount()  && !m_DTUSBDevice.Open(ucUSBPort)) 
				{ 
					m_DTUSBDevice.Reset(); 
					m_DTUSBDevice.Open(ucUSBPort); 
					m_DTUSBDevice.ReConnect();//RE enumerate
				} 
				if (!m_DTUSBDevice.IsOpen()) 
				{
					m_LastErrID = EID_USB_IMG_CHANEL_OPEN_FAILED;
					bPortOpened =FALSE;
				}
				else
				{
					m_pCtlEndPt = m_DTUSBDevice.ControlEndPt;    
					bPortOpened = TRUE;
				}
				break;
			case DT_NET:
				if(m_Socket.Connect((BYTE*)m_RemoteIP,(WORD)m_CmdPort))
				{
					bPortOpened = TRUE;
				}
				else
				{
					m_LastErrID  = EID_NET_CMD_CONNECT_FAILED;
					bPortOpened = FALSE;
				}
				break;
			default:
				m_LastErrID  = EID_UNKNOWN_CMD_CHANNEL;
				bPortOpened = FALSE;
		}
/*		if(bPortOpened)
		{
			if(TestConnection())
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
			*bOK = FALSE;
		}*/
		*bOK = bPortOpened;
	if(*bOK)
	{
		m_bIsOpened = TRUE;
	}
	else
	{
		m_bIsOpened = FALSE;
	}
	CDTException Err(m_LastErrID);
	DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	return S_OK;
}

STDMETHODIMP CDTDetector::Close(void)
{
	// TODO: Add your implementation code here
	m_LastErrID = EID_SUCCESS;
	switch(m_CardType)
	{
	case DT_SERIAL:
		m_Serial.Close();
		break;
	case DT_USB:
		m_DTUSBDevice.Close();
		break;
	case DT_NET:
		m_Socket.DisConnect();
		break;
	}

	m_bIsOpened = FALSE;
	return S_OK;
}

STDMETHODIMP CDTDetector::SendCommand(BSTR bstrCmd, BSTR* bstrRTMsg, LONG* bOK)
{
	// TODO: Add your implementation code here
	m_LastErrID = EID_SUCCESS;
	CHAR REVBUF[REV_BUF_SIZE];
	memset(REVBUF,0,REV_BUF_SIZE);
	CHAR* CMDBUF = _com_util::ConvertBSTRToString(bstrCmd);
	SendCommandA(CMDBUF, REVBUF,bOK);
	CComBSTR bstrRT(REVBUF);
	// Convert the string to uppercase
	// Return a copy of the string.
	bstrRT.CopyTo(bstrRTMsg);
	delete [] CMDBUF;
	CDTException Err(m_LastErrID);
	DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	return S_OK;
}
STDMETHODIMP CDTDetector::SendCommandA(CHAR* pSendCmd, CHAR* pRTBuffer,LONG* pbSuccess)
{
	m_LastErrID = EID_SUCCESS;
	if(m_bIsOpened)
	{
		switch(m_CardType)
		{
		case DT_SERIAL:
			SendSerialData(pSendCmd);
			Sleep(m_TimeOut);
			if(RevSerialData(pRTBuffer)>0)
			{
				if(pRTBuffer[2] == '0')
				{
						*pbSuccess = TRUE;
						char* end = strrchr(pRTBuffer,']');
						if(end)
							*(end+1) = 0;

				}
				else
				{
						m_LastErrID = EID_CMDCHANEL_RT_ERROR;
						*pbSuccess = FALSE;
				}
			}
			else
			{
						m_LastErrID = EID_SERIAL_RT_TIMEOUT;
						*pbSuccess = FALSE;
			};
			break;
		case DT_USB:
			if(SendUSBData(pSendCmd))
			{
				//Sleep(100);//Here the firmware have bug, if send 2 USB command too fast, the 
				//MCU buffer management maybe mess.
				if(RevUSBData(pRTBuffer))
				{
					char* end = strrchr(pRTBuffer,']');
					if(end)
						*(end+1) = 0;
					if(pRTBuffer[2] == '0')
					{
						*pbSuccess = TRUE;
						//Cut the unuseful string after ']'
					}
					else
					{
						m_LastErrID = EID_CMDCHANEL_RT_ERROR;
						*pbSuccess = FALSE;
					}
				}
				else
				{
					m_LastErrID = EID_USB_CMD_REV_FAIL;
					*pbSuccess = FALSE;
				}
			}
			else
			{
				*pbSuccess = FALSE;
			}
			break;
		case DT_NET:
			int len =0;
			int Retry=0;
			len = SendNETData(pSendCmd);
			if(len == strlen(pSendCmd))
			{
REV:			Sleep(m_TimeOut);
				len = RevNETData(pRTBuffer);
				if(len > 0)
				{
					if(pRTBuffer[2] == '0')
					{
						*pbSuccess = TRUE;
						char* end = strrchr(pRTBuffer,']');
						if(end)
							*(end+1) = 0;
					}
					else
					{
						m_LastErrID = EID_CMDCHANEL_RT_ERROR;
						*pbSuccess = FALSE;
					}
				}
				else
				{
					m_LastErrID = EID_NET_CMD_REV_FAILED;
					*pbSuccess = FALSE;
					Retry++;
					int ErrID = WSAGetLastError();
					//if((ErrID  == WSAETIMEDOUT)&&(Retry>10))
					if(Retry<10)
						goto REV;
				}
			}
			else
			{
				m_LastErrID = EID_NET_CMD_SEND_FAILED;
				*pbSuccess = FALSE;
			}
			break;
		}
	}
	else
	{
		m_LastErrID = EID_NO_CMD_CHANEL;
		*pbSuccess = FALSE;
	}
	if(!(*pbSuccess))
	{
		CDTException Err(m_LastErrID);
		DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	}
	CDTException Err(m_LastErrID);
	DTError(Err.m_ERROR_ID,Err.m_ERROR_INFO);
	return S_OK;
}

STDMETHODIMP CDTDetector::PrintErrMsg(LONG ErrID, BSTR* ErrMsg)
{
	CDTException Err(ErrID);
	*ErrMsg = Err.m_ERROR_INFO;
	return S_OK;
}
BOOL CDTDetector::SendUSBData(CHAR* pStrCmd)
{
	m_pCtlEndPt->Target    = TGT_DEVICE;  

	m_pCtlEndPt->ReqType   = REQ_VENDOR;  

	m_pCtlEndPt->Direction = DIR_TO_DEVICE;   

	m_pCtlEndPt->ReqCode   = 0xB0;    

	m_pCtlEndPt->Value     = 1;   

	m_pCtlEndPt->Index     = 0;   

	long temp = (long)strlen(pStrCmd);
	if(!m_pCtlEndPt->XferData((PUCHAR)pStrCmd,temp))
	{
		m_LastErrID = EID_USB_CMD_SEND_FAIL;
		return FALSE;
	};  
	//Todo check here the Count is equal to XTPLength
	if(temp != strlen(pStrCmd))
	{
		m_LastErrID = EID_USB_CMD_SEND_FAIL;
		return FALSE;
	};
	return TRUE;

}
BOOL CDTDetector::RevUSBData(CHAR* pStrRT)
{
	const int MAX_REV_SIZE = 64;
	BOOL bStart = FALSE;
	BOOL bEnd = FALSE;
	BYTE PacketBuf[64];
	memset(PacketBuf,0,64);
	m_pCtlEndPt->Target    = TGT_DEVICE;  

	m_pCtlEndPt->ReqType   = REQ_VENDOR;  

	m_pCtlEndPt->Direction = DIR_FROM_DEVICE;   

	m_pCtlEndPt->ReqCode   = 0xB0;    

	m_pCtlEndPt->Value     = 1;   

	m_pCtlEndPt->Index     = 0;   

	long RevSize = 64;//The size of every transfer
	WORD BufCounter = 0;
	while(!bEnd)
	{
		if(!m_pCtlEndPt->XferData((PUCHAR)PacketBuf, RevSize))
		{
			m_LastErrID = EID_USB_CMD_REV_FAIL;
			return FALSE;
		}
		if(RevSize == 0)
		{
			m_LastErrID = EID_USB_CMD_REV_FAIL;
			return FALSE;
		}
		for(int i = 0; i< RevSize; i++)
		{
			if(PacketBuf[i] == STX)
			{
				bStart = TRUE;
			}

			if(bStart)
			{
				pStrRT[BufCounter] = PacketBuf[i];
				BufCounter++;
				if(BufCounter > MAX_REV_SIZE)//
				{
					m_LastErrID = EID_USB_CMD_REV_FAIL;
					return FALSE;
				}
			}
			if(PacketBuf[i] == ETX)
			{
				bEnd = TRUE;
				break;
			}
		}
	}
	return TRUE;
};
int CDTDetector::SendNETData(CHAR* pStrCmd)
{
	return m_Socket.SendData((BYTE*)pStrCmd,strlen(pStrCmd));
};
int CDTDetector::RevNETData(CHAR* pRT,WORD BuffSize)
{
	int len = 0;
	int Index = 0;
	BYTE Buf[64];
	BOOL StartCpy = FALSE;
	while(1)
	{
		if(!m_Socket.IsConnected())	
		{
			*pRT = 0;
			return 0;
		}
		if(m_Socket.IsCanRead())
			len = m_Socket.ReceiveData(Buf,64);
		else
			break;
		for(int i = 0; i<len;i++)
		{
			if(StartCpy)
			{
				pRT[Index] = Buf[i];
				if(pRT[Index] == ETX)
				{
					return Index;
				}
				Index++;
			}
			else
			{
				if(Buf[i] == STX)
				{
					StartCpy = TRUE;
					pRT[Index] = Buf[i];
					Index++;
				}			
			}
		}
	};
	return Index;
};
int CDTDetector::SendSerialData(CHAR* pStrCmd)
{
	DWORD len;
	m_Serial.Write(pStrCmd,strlen(pStrCmd),&len);
	return len;
	
};
int CDTDetector::RevSerialData(CHAR* pRT,WORD BuffSize)
{
	DWORD len;
	m_Serial.Read(pRT,BuffSize,&len);
	return len;
};
BOOL CDTDetector::TestConnection()
{
	CHAR REVBUF[REV_BUF_SIZE];
	CHAR CMDBUF[10];	
	memset(REVBUF,0,REV_BUF_SIZE);
	LONG bOK;
	sprintf(CMDBUF,"[RI]");
	switch(m_CardType)
	{
		case DT_SERIAL:
			SendSerialData(CMDBUF);
			Sleep(m_TimeOut);
			RevSerialData(REVBUF);
			break;
		case DT_USB:
			if(SendUSBData(CMDBUF))
			{
				//Sleep(m_TimeOut);
				RevUSBData(REVBUF);
			}
			break;
		case DT_NET:
			int len =0;
			len = SendNETData(CMDBUF);
			Sleep(m_TimeOut);
			len = RevNETData(REVBUF);
			break;
	}

	if(strchr(REVBUF,'['))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}
STDMETHODIMP CDTDetector::get_BaudRate(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_BaudRate;
	return S_OK;
}

STDMETHODIMP CDTDetector::put_BaudRate(LONG newVal)
{
	// TODO: Add your implementation code here
	m_BaudRate = newVal;
	return S_OK;
}

STDMETHODIMP CDTDetector::get_CmdTimeOut(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_TimeOut;
	return S_OK;
}

STDMETHODIMP CDTDetector::put_CmdTimeOut(LONG newVal)
{
	// TODO: Add your implementation code here
	m_TimeOut = newVal;
	return S_OK;
}
