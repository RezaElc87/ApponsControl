

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Mar 08 23:26:53 2014
 */
/* Compiler settings for _DTControl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DTControl_h__
#define __DTControl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDTDisplayControl_FWD_DEFINED__
#define __IDTDisplayControl_FWD_DEFINED__
typedef interface IDTDisplayControl IDTDisplayControl;
#endif 	/* __IDTDisplayControl_FWD_DEFINED__ */


#ifndef __IDTDetector_FWD_DEFINED__
#define __IDTDetector_FWD_DEFINED__
typedef interface IDTDetector IDTDetector;
#endif 	/* __IDTDetector_FWD_DEFINED__ */


#ifndef __IDTCommanderF3_FWD_DEFINED__
#define __IDTCommanderF3_FWD_DEFINED__
typedef interface IDTCommanderF3 IDTCommanderF3;
#endif 	/* __IDTCommanderF3_FWD_DEFINED__ */


#ifndef __IImageObject_FWD_DEFINED__
#define __IImageObject_FWD_DEFINED__
typedef interface IImageObject IImageObject;
#endif 	/* __IImageObject_FWD_DEFINED__ */


#ifndef __IDTDisplay_FWD_DEFINED__
#define __IDTDisplay_FWD_DEFINED__
typedef interface IDTDisplay IDTDisplay;
#endif 	/* __IDTDisplay_FWD_DEFINED__ */


#ifndef __IDTImage_FWD_DEFINED__
#define __IDTImage_FWD_DEFINED__
typedef interface IDTImage IDTImage;
#endif 	/* __IDTImage_FWD_DEFINED__ */


#ifndef ___IDTDisplayControlEvents_FWD_DEFINED__
#define ___IDTDisplayControlEvents_FWD_DEFINED__
typedef interface _IDTDisplayControlEvents _IDTDisplayControlEvents;
#endif 	/* ___IDTDisplayControlEvents_FWD_DEFINED__ */


#ifndef __CDTDisplayControl_FWD_DEFINED__
#define __CDTDisplayControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDTDisplayControl CDTDisplayControl;
#else
typedef struct CDTDisplayControl CDTDisplayControl;
#endif /* __cplusplus */

#endif 	/* __CDTDisplayControl_FWD_DEFINED__ */


#ifndef ___IDTDetectorEvents_FWD_DEFINED__
#define ___IDTDetectorEvents_FWD_DEFINED__
typedef interface _IDTDetectorEvents _IDTDetectorEvents;
#endif 	/* ___IDTDetectorEvents_FWD_DEFINED__ */


#ifndef __CDTDetector_FWD_DEFINED__
#define __CDTDetector_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDTDetector CDTDetector;
#else
typedef struct CDTDetector CDTDetector;
#endif /* __cplusplus */

#endif 	/* __CDTDetector_FWD_DEFINED__ */


#ifndef ___IDTCommanderF3Events_FWD_DEFINED__
#define ___IDTCommanderF3Events_FWD_DEFINED__
typedef interface _IDTCommanderF3Events _IDTCommanderF3Events;
#endif 	/* ___IDTCommanderF3Events_FWD_DEFINED__ */


#ifndef __CDTCommanderF3_FWD_DEFINED__
#define __CDTCommanderF3_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDTCommanderF3 CDTCommanderF3;
#else
typedef struct CDTCommanderF3 CDTCommanderF3;
#endif /* __cplusplus */

#endif 	/* __CDTCommanderF3_FWD_DEFINED__ */


#ifndef __CImageObject_FWD_DEFINED__
#define __CImageObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class CImageObject CImageObject;
#else
typedef struct CImageObject CImageObject;
#endif /* __cplusplus */

#endif 	/* __CImageObject_FWD_DEFINED__ */


#ifndef ___IDTDisplayEvents_FWD_DEFINED__
#define ___IDTDisplayEvents_FWD_DEFINED__
typedef interface _IDTDisplayEvents _IDTDisplayEvents;
#endif 	/* ___IDTDisplayEvents_FWD_DEFINED__ */


#ifndef __CDTDisplay_FWD_DEFINED__
#define __CDTDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDTDisplay CDTDisplay;
#else
typedef struct CDTDisplay CDTDisplay;
#endif /* __cplusplus */

#endif 	/* __CDTDisplay_FWD_DEFINED__ */


#ifndef ___IDTImageEvents_FWD_DEFINED__
#define ___IDTImageEvents_FWD_DEFINED__
typedef interface _IDTImageEvents _IDTImageEvents;
#endif 	/* ___IDTImageEvents_FWD_DEFINED__ */


#ifndef __CDTImage_FWD_DEFINED__
#define __CDTImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDTImage CDTImage;
#else
typedef struct CDTImage CDTImage;
#endif /* __cplusplus */

#endif 	/* __CDTImage_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDTDisplayControl_INTERFACE_DEFINED__
#define __IDTDisplayControl_INTERFACE_DEFINED__

/* interface IDTDisplayControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDTDisplayControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A79B1CB-FF34-4F4F-A394-4972066A5763")
    IDTDisplayControl : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTDisplayControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTDisplayControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTDisplayControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTDisplayControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTDisplayControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTDisplayControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTDisplayControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTDisplayControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            IDTDisplayControl * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            IDTDisplayControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderVisible )( 
            IDTDisplayControl * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderVisible )( 
            IDTDisplayControl * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IDTDisplayControl * This,
            /* [retval][out] */ IUnknown **pVal);
        
        END_INTERFACE
    } IDTDisplayControlVtbl;

    interface IDTDisplayControl
    {
        CONST_VTBL struct IDTDisplayControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTDisplayControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTDisplayControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTDisplayControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTDisplayControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTDisplayControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTDisplayControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTDisplayControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDTDisplayControl_put_AutoSize(This,vbool)	\
    ( (This)->lpVtbl -> put_AutoSize(This,vbool) ) 

#define IDTDisplayControl_get_AutoSize(This,pbool)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pbool) ) 

#define IDTDisplayControl_put_BorderVisible(This,vbool)	\
    ( (This)->lpVtbl -> put_BorderVisible(This,vbool) ) 

#define IDTDisplayControl_get_BorderVisible(This,pbool)	\
    ( (This)->lpVtbl -> get_BorderVisible(This,pbool) ) 

#define IDTDisplayControl_get_Object(This,pVal)	\
    ( (This)->lpVtbl -> get_Object(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTDisplayControl_INTERFACE_DEFINED__ */


#ifndef __IDTDetector_INTERFACE_DEFINED__
#define __IDTDetector_INTERFACE_DEFINED__

/* interface IDTDetector */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDTDetector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C13A54F-69C0-4F51-A48D-F55CE086F72D")
    IDTDetector : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CmdPort( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CmdPort( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerialPort( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerialPort( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectHandle( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsOpened( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChannelType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaudRate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BaudRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CmdTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CmdTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ BSTR bstrCmd,
            /* [out] */ BSTR *bstrRTMsg,
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintErrMsg( 
            /* [in] */ LONG ErrID,
            /* [out] */ BSTR *ErrMsg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommandA( 
            /* [in] */ CHAR *Cmd,
            /* [out] */ CHAR *pRT,
            /* [retval][out] */ LONG *bOK) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTDetectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTDetector * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTDetector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTDetector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTDetector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTDetector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTDetector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTDetector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPAddress )( 
            IDTDetector * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IPAddress )( 
            IDTDetector * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CmdPort )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CmdPort )( 
            IDTDetector * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerialPort )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerialPort )( 
            IDTDetector * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectHandle )( 
            IDTDetector * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsOpened )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrID )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelType )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChannelType )( 
            IDTDetector * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaudRate )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BaudRate )( 
            IDTDetector * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CmdTimeOut )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CmdTimeOut )( 
            IDTDetector * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IDTDetector * This,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IDTDetector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IDTDetector * This,
            /* [in] */ BSTR bstrCmd,
            /* [out] */ BSTR *bstrRTMsg,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintErrMsg )( 
            IDTDetector * This,
            /* [in] */ LONG ErrID,
            /* [out] */ BSTR *ErrMsg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCommandA )( 
            IDTDetector * This,
            /* [in] */ CHAR *Cmd,
            /* [out] */ CHAR *pRT,
            /* [retval][out] */ LONG *bOK);
        
        END_INTERFACE
    } IDTDetectorVtbl;

    interface IDTDetector
    {
        CONST_VTBL struct IDTDetectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTDetector_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTDetector_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTDetector_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTDetector_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTDetector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTDetector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTDetector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDTDetector_get_IPAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_IPAddress(This,pVal) ) 

#define IDTDetector_put_IPAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_IPAddress(This,newVal) ) 

#define IDTDetector_get_CmdPort(This,pVal)	\
    ( (This)->lpVtbl -> get_CmdPort(This,pVal) ) 

#define IDTDetector_put_CmdPort(This,newVal)	\
    ( (This)->lpVtbl -> put_CmdPort(This,newVal) ) 

#define IDTDetector_get_SerialPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SerialPort(This,pVal) ) 

#define IDTDetector_put_SerialPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SerialPort(This,newVal) ) 

#define IDTDetector_get_ObjectHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ObjectHandle(This,pVal) ) 

#define IDTDetector_get_IsOpened(This,pVal)	\
    ( (This)->lpVtbl -> get_IsOpened(This,pVal) ) 

#define IDTDetector_get_LastErrID(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrID(This,pVal) ) 

#define IDTDetector_get_ChannelType(This,pVal)	\
    ( (This)->lpVtbl -> get_ChannelType(This,pVal) ) 

#define IDTDetector_put_ChannelType(This,newVal)	\
    ( (This)->lpVtbl -> put_ChannelType(This,newVal) ) 

#define IDTDetector_get_BaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_BaudRate(This,pVal) ) 

#define IDTDetector_put_BaudRate(This,newVal)	\
    ( (This)->lpVtbl -> put_BaudRate(This,newVal) ) 

#define IDTDetector_get_CmdTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_CmdTimeOut(This,pVal) ) 

#define IDTDetector_put_CmdTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_CmdTimeOut(This,newVal) ) 

#define IDTDetector_Open(This,bOK)	\
    ( (This)->lpVtbl -> Open(This,bOK) ) 

#define IDTDetector_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IDTDetector_SendCommand(This,bstrCmd,bstrRTMsg,bOK)	\
    ( (This)->lpVtbl -> SendCommand(This,bstrCmd,bstrRTMsg,bOK) ) 

#define IDTDetector_PrintErrMsg(This,ErrID,ErrMsg)	\
    ( (This)->lpVtbl -> PrintErrMsg(This,ErrID,ErrMsg) ) 

#define IDTDetector_SendCommandA(This,Cmd,pRT,bOK)	\
    ( (This)->lpVtbl -> SendCommandA(This,Cmd,pRT,bOK) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTDetector_INTERFACE_DEFINED__ */


#ifndef __IDTCommanderF3_INTERFACE_DEFINED__
#define __IDTCommanderF3_INTERFACE_DEFINED__

/* interface IDTCommanderF3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDTCommanderF3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A164B205-1A1E-4345-A6F6-38D4715EC7FB")
    IDTCommanderF3 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DetectorObject( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DetectorObject( 
            /* [in] */ IUnknown *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OffBoardCalibration( 
            /* [in] */ LONG CalibrationType,
            /* [in] */ IUnknown *pImgObject,
            /* [in] */ LONG StartPixel,
            /* [in] */ LONG EndPixel,
            /* [in] */ LONG TargetValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gain( 
            /* [in] */ LONG Index,
            /* [retval][out] */ FLOAT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gain( 
            /* [in] */ LONG Index,
            /* [in] */ FLOAT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Offset( 
            /* [in] */ LONG Index,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Offset( 
            /* [in] */ LONG Index,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CorrectionGain( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CorrectionGain( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CorrectionOffset( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CorrectionOffset( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CorrectionBaseline( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CorrectionBaseline( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Baseline( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Baseline( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IntegrationTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IntegrationTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AverageFilter( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AverageFilter( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataPattern( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataPattern( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameTrigger( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameTrigger( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LineTrigger( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LineTrigger( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LONG Mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveOffset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveGain( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadOffset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadGain( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendExFrameTrigger( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageOutputType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageOutputType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SensitivityLevel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SensitivityLevel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SumLines( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SumLines( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDataPattern( 
            /* [in] */ LONG Base,
            /* [in] */ LONG Step) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsOpened( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleTypeName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveCurrentStatus( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PixelSize( 
            /* [retval][out] */ FLOAT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PixelNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModuleType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxIntTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinIntTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverallGain( 
            /* [retval][out] */ FLOAT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverallGain( 
            /* [in] */ FLOAT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartPixel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartPixel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EndPixel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EndPixel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBoardOffsetCalibration( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBoardGainCalibration( 
            /* [in] */ LONG TargetValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetGain( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetOffset( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FPGA_Version( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FPGA_Build( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MCU_Version( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RetrieveSysinfo( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTCommanderF3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTCommanderF3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTCommanderF3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTCommanderF3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTCommanderF3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTCommanderF3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTCommanderF3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTCommanderF3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetectorObject )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DetectorObject )( 
            IDTCommanderF3 * This,
            /* [in] */ IUnknown *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OffBoardCalibration )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG CalibrationType,
            /* [in] */ IUnknown *pImgObject,
            /* [in] */ LONG StartPixel,
            /* [in] */ LONG EndPixel,
            /* [in] */ LONG TargetValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gain )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ FLOAT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gain )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index,
            /* [in] */ FLOAT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Offset )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Offset )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CorrectionGain )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CorrectionGain )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CorrectionOffset )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CorrectionOffset )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CorrectionBaseline )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CorrectionBaseline )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Baseline )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Baseline )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IntegrationTime )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IntegrationTime )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AverageFilter )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AverageFilter )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataPattern )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataPattern )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameTrigger )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameTrigger )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineTrigger )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineTrigger )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveOffset )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveGain )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadOffset )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadGain )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputBits )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputBits )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendExFrameTrigger )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameOut )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameOut )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageOutputType )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageOutputType )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SensitivityLevel )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SensitivityLevel )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SumLines )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SumLines )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDataPattern )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG Base,
            /* [in] */ LONG Step);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsOpened )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleTypeName )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveCurrentStatus )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PixelSize )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ FLOAT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PixelNumber )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModuleType )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxIntTime )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinIntTime )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverallGain )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ FLOAT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverallGain )( 
            IDTCommanderF3 * This,
            /* [in] */ FLOAT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartPixel )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartPixel )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EndPixel )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EndPixel )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBoardOffsetCalibration )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBoardGainCalibration )( 
            IDTCommanderF3 * This,
            /* [in] */ LONG TargetValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetGain )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetOffset )( 
            IDTCommanderF3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FPGA_Version )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FPGA_Build )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MCU_Version )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            IDTCommanderF3 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveSysinfo )( 
            IDTCommanderF3 * This);
        
        END_INTERFACE
    } IDTCommanderF3Vtbl;

    interface IDTCommanderF3
    {
        CONST_VTBL struct IDTCommanderF3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTCommanderF3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTCommanderF3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTCommanderF3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTCommanderF3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTCommanderF3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTCommanderF3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTCommanderF3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDTCommanderF3_get_DetectorObject(This,pVal)	\
    ( (This)->lpVtbl -> get_DetectorObject(This,pVal) ) 

#define IDTCommanderF3_put_DetectorObject(This,newVal)	\
    ( (This)->lpVtbl -> put_DetectorObject(This,newVal) ) 

#define IDTCommanderF3_OffBoardCalibration(This,CalibrationType,pImgObject,StartPixel,EndPixel,TargetValue)	\
    ( (This)->lpVtbl -> OffBoardCalibration(This,CalibrationType,pImgObject,StartPixel,EndPixel,TargetValue) ) 

#define IDTCommanderF3_get_Gain(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Gain(This,Index,pVal) ) 

#define IDTCommanderF3_put_Gain(This,Index,newVal)	\
    ( (This)->lpVtbl -> put_Gain(This,Index,newVal) ) 

#define IDTCommanderF3_get_Offset(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Offset(This,Index,pVal) ) 

#define IDTCommanderF3_put_Offset(This,Index,newVal)	\
    ( (This)->lpVtbl -> put_Offset(This,Index,newVal) ) 

#define IDTCommanderF3_get_CorrectionGain(This,pVal)	\
    ( (This)->lpVtbl -> get_CorrectionGain(This,pVal) ) 

#define IDTCommanderF3_put_CorrectionGain(This,newVal)	\
    ( (This)->lpVtbl -> put_CorrectionGain(This,newVal) ) 

#define IDTCommanderF3_get_CorrectionOffset(This,pVal)	\
    ( (This)->lpVtbl -> get_CorrectionOffset(This,pVal) ) 

#define IDTCommanderF3_put_CorrectionOffset(This,newVal)	\
    ( (This)->lpVtbl -> put_CorrectionOffset(This,newVal) ) 

#define IDTCommanderF3_get_CorrectionBaseline(This,pVal)	\
    ( (This)->lpVtbl -> get_CorrectionBaseline(This,pVal) ) 

#define IDTCommanderF3_put_CorrectionBaseline(This,newVal)	\
    ( (This)->lpVtbl -> put_CorrectionBaseline(This,newVal) ) 

#define IDTCommanderF3_get_Baseline(This,pVal)	\
    ( (This)->lpVtbl -> get_Baseline(This,pVal) ) 

#define IDTCommanderF3_put_Baseline(This,newVal)	\
    ( (This)->lpVtbl -> put_Baseline(This,newVal) ) 

#define IDTCommanderF3_get_IntegrationTime(This,pVal)	\
    ( (This)->lpVtbl -> get_IntegrationTime(This,pVal) ) 

#define IDTCommanderF3_put_IntegrationTime(This,newVal)	\
    ( (This)->lpVtbl -> put_IntegrationTime(This,newVal) ) 

#define IDTCommanderF3_get_AverageFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_AverageFilter(This,pVal) ) 

#define IDTCommanderF3_put_AverageFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_AverageFilter(This,newVal) ) 

#define IDTCommanderF3_get_DataPattern(This,pVal)	\
    ( (This)->lpVtbl -> get_DataPattern(This,pVal) ) 

#define IDTCommanderF3_put_DataPattern(This,newVal)	\
    ( (This)->lpVtbl -> put_DataPattern(This,newVal) ) 

#define IDTCommanderF3_get_FrameTrigger(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameTrigger(This,pVal) ) 

#define IDTCommanderF3_put_FrameTrigger(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameTrigger(This,newVal) ) 

#define IDTCommanderF3_get_LineTrigger(This,pVal)	\
    ( (This)->lpVtbl -> get_LineTrigger(This,pVal) ) 

#define IDTCommanderF3_put_LineTrigger(This,newVal)	\
    ( (This)->lpVtbl -> put_LineTrigger(This,newVal) ) 

#define IDTCommanderF3_Initialize(This,Mode)	\
    ( (This)->lpVtbl -> Initialize(This,Mode) ) 

#define IDTCommanderF3_SaveOffset(This)	\
    ( (This)->lpVtbl -> SaveOffset(This) ) 

#define IDTCommanderF3_SaveGain(This,Index)	\
    ( (This)->lpVtbl -> SaveGain(This,Index) ) 

#define IDTCommanderF3_LoadOffset(This)	\
    ( (This)->lpVtbl -> LoadOffset(This) ) 

#define IDTCommanderF3_LoadGain(This,Index)	\
    ( (This)->lpVtbl -> LoadGain(This,Index) ) 

#define IDTCommanderF3_get_OutputBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputBits(This,pVal) ) 

#define IDTCommanderF3_put_OutputBits(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputBits(This,newVal) ) 

#define IDTCommanderF3_SendExFrameTrigger(This)	\
    ( (This)->lpVtbl -> SendExFrameTrigger(This) ) 

#define IDTCommanderF3_get_FrameOut(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameOut(This,pVal) ) 

#define IDTCommanderF3_put_FrameOut(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameOut(This,newVal) ) 

#define IDTCommanderF3_get_ImageOutputType(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageOutputType(This,pVal) ) 

#define IDTCommanderF3_put_ImageOutputType(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageOutputType(This,newVal) ) 

#define IDTCommanderF3_get_SensitivityLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_SensitivityLevel(This,pVal) ) 

#define IDTCommanderF3_put_SensitivityLevel(This,newVal)	\
    ( (This)->lpVtbl -> put_SensitivityLevel(This,newVal) ) 

#define IDTCommanderF3_get_SumLines(This,pVal)	\
    ( (This)->lpVtbl -> get_SumLines(This,pVal) ) 

#define IDTCommanderF3_put_SumLines(This,newVal)	\
    ( (This)->lpVtbl -> put_SumLines(This,newVal) ) 

#define IDTCommanderF3_WriteDataPattern(This,Base,Step)	\
    ( (This)->lpVtbl -> WriteDataPattern(This,Base,Step) ) 

#define IDTCommanderF3_get_IsOpened(This,pVal)	\
    ( (This)->lpVtbl -> get_IsOpened(This,pVal) ) 

#define IDTCommanderF3_get_ModuleTypeName(This,pVal)	\
    ( (This)->lpVtbl -> get_ModuleTypeName(This,pVal) ) 

#define IDTCommanderF3_SaveCurrentStatus(This)	\
    ( (This)->lpVtbl -> SaveCurrentStatus(This) ) 

#define IDTCommanderF3_get_PixelSize(This,pVal)	\
    ( (This)->lpVtbl -> get_PixelSize(This,pVal) ) 

#define IDTCommanderF3_get_PixelNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_PixelNumber(This,pVal) ) 

#define IDTCommanderF3_get_ModuleType(This,pVal)	\
    ( (This)->lpVtbl -> get_ModuleType(This,pVal) ) 

#define IDTCommanderF3_get_MaxIntTime(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxIntTime(This,pVal) ) 

#define IDTCommanderF3_get_MinIntTime(This,pVal)	\
    ( (This)->lpVtbl -> get_MinIntTime(This,pVal) ) 

#define IDTCommanderF3_get_OverallGain(This,pVal)	\
    ( (This)->lpVtbl -> get_OverallGain(This,pVal) ) 

#define IDTCommanderF3_put_OverallGain(This,newVal)	\
    ( (This)->lpVtbl -> put_OverallGain(This,newVal) ) 

#define IDTCommanderF3_get_StartPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_StartPixel(This,pVal) ) 

#define IDTCommanderF3_put_StartPixel(This,newVal)	\
    ( (This)->lpVtbl -> put_StartPixel(This,newVal) ) 

#define IDTCommanderF3_get_EndPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_EndPixel(This,pVal) ) 

#define IDTCommanderF3_put_EndPixel(This,newVal)	\
    ( (This)->lpVtbl -> put_EndPixel(This,newVal) ) 

#define IDTCommanderF3_OnBoardOffsetCalibration(This)	\
    ( (This)->lpVtbl -> OnBoardOffsetCalibration(This) ) 

#define IDTCommanderF3_OnBoardGainCalibration(This,TargetValue)	\
    ( (This)->lpVtbl -> OnBoardGainCalibration(This,TargetValue) ) 

#define IDTCommanderF3_ResetGain(This)	\
    ( (This)->lpVtbl -> ResetGain(This) ) 

#define IDTCommanderF3_ResetOffset(This)	\
    ( (This)->lpVtbl -> ResetOffset(This) ) 

#define IDTCommanderF3_get_FPGA_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_FPGA_Version(This,pVal) ) 

#define IDTCommanderF3_get_FPGA_Build(This,pVal)	\
    ( (This)->lpVtbl -> get_FPGA_Build(This,pVal) ) 

#define IDTCommanderF3_get_MCU_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_MCU_Version(This,pVal) ) 

#define IDTCommanderF3_get_SerialNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_SerialNumber(This,pVal) ) 

#define IDTCommanderF3_RetrieveSysinfo(This)	\
    ( (This)->lpVtbl -> RetrieveSysinfo(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTCommanderF3_INTERFACE_DEFINED__ */


#ifndef __IImageObject_INTERFACE_DEFINED__
#define __IImageObject_INTERFACE_DEFINED__

/* interface IImageObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IImageObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("564FBD53-2CF3-47D8-AD62-670840E804BE")
    IImageObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageDataAddress( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageDataAddress( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BytesPerPixel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pixel( 
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pixel( 
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ LONG BytesPerPixel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageLineAddress( 
            /* [in] */ LONG LineIndex,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ColAverage( 
            /* [out] */ LONG *pAvg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ColMax( 
            /* [out] */ LONG *pMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ColMin( 
            /* [out] */ LONG *pMin) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RowMin( 
            /* [out] */ LONG *pMin) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RowMax( 
            /* [out] */ LONG *pMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RowAverage( 
            /* [in] */ LONG *pAvg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ColNoise( 
            /* [out] */ FLOAT *pNoise) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RowNoise( 
            /* [out] */ FLOAT *pNoise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImageObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImageObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImageObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImageObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageDataAddress )( 
            IImageObject * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageDataAddress )( 
            IImageObject * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IImageObject * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IImageObject * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BytesPerPixel )( 
            IImageObject * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pixel )( 
            IImageObject * This,
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pixel )( 
            IImageObject * This,
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IImageObject * This,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ LONG BytesPerPixel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageLineAddress )( 
            IImageObject * This,
            /* [in] */ LONG LineIndex,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ColAverage )( 
            IImageObject * This,
            /* [out] */ LONG *pAvg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ColMax )( 
            IImageObject * This,
            /* [out] */ LONG *pMax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ColMin )( 
            IImageObject * This,
            /* [out] */ LONG *pMin);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RowMin )( 
            IImageObject * This,
            /* [out] */ LONG *pMin);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RowMax )( 
            IImageObject * This,
            /* [out] */ LONG *pMax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RowAverage )( 
            IImageObject * This,
            /* [in] */ LONG *pAvg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ColNoise )( 
            IImageObject * This,
            /* [out] */ FLOAT *pNoise);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RowNoise )( 
            IImageObject * This,
            /* [out] */ FLOAT *pNoise);
        
        END_INTERFACE
    } IImageObjectVtbl;

    interface IImageObject
    {
        CONST_VTBL struct IImageObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImageObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImageObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImageObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImageObject_get_ImageDataAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageDataAddress(This,pVal) ) 

#define IImageObject_put_ImageDataAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageDataAddress(This,newVal) ) 

#define IImageObject_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IImageObject_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IImageObject_get_BytesPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BytesPerPixel(This,pVal) ) 

#define IImageObject_get_Pixel(This,X,Y,pVal)	\
    ( (This)->lpVtbl -> get_Pixel(This,X,Y,pVal) ) 

#define IImageObject_put_Pixel(This,X,Y,newVal)	\
    ( (This)->lpVtbl -> put_Pixel(This,X,Y,newVal) ) 

#define IImageObject_Open(This,Width,Height,BytesPerPixel)	\
    ( (This)->lpVtbl -> Open(This,Width,Height,BytesPerPixel) ) 

#define IImageObject_get_ImageLineAddress(This,LineIndex,pVal)	\
    ( (This)->lpVtbl -> get_ImageLineAddress(This,LineIndex,pVal) ) 

#define IImageObject_ColAverage(This,pAvg)	\
    ( (This)->lpVtbl -> ColAverage(This,pAvg) ) 

#define IImageObject_ColMax(This,pMax)	\
    ( (This)->lpVtbl -> ColMax(This,pMax) ) 

#define IImageObject_ColMin(This,pMin)	\
    ( (This)->lpVtbl -> ColMin(This,pMin) ) 

#define IImageObject_RowMin(This,pMin)	\
    ( (This)->lpVtbl -> RowMin(This,pMin) ) 

#define IImageObject_RowMax(This,pMax)	\
    ( (This)->lpVtbl -> RowMax(This,pMax) ) 

#define IImageObject_RowAverage(This,pAvg)	\
    ( (This)->lpVtbl -> RowAverage(This,pAvg) ) 

#define IImageObject_ColNoise(This,pNoise)	\
    ( (This)->lpVtbl -> ColNoise(This,pNoise) ) 

#define IImageObject_RowNoise(This,pNoise)	\
    ( (This)->lpVtbl -> RowNoise(This,pNoise) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageObject_INTERFACE_DEFINED__ */


#ifndef __IDTDisplay_INTERFACE_DEFINED__
#define __IDTDisplay_INTERFACE_DEFINED__

/* interface IDTDisplay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDTDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C22B30FA-860F-4565-8BDC-FC90EFC56F96")
    IDTDisplay : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImgWidth( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImgWidth( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImgHeight( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImgHeight( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gamma( 
            /* [retval][out] */ FLOAT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gamma( 
            /* [in] */ FLOAT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MapStart( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MapStart( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MapEnd( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MapEnd( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataSource( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataSource( 
            /* [in] */ IUnknown *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayControl( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayControl( 
            /* [in] */ IUnknown *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RefreshMode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RefreshMode( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RefreshRate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RefreshRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageObject( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayScale( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayScale( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OrgPoint_X( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OrgPoint_X( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OrgPoint_Y( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OrgPoint_Y( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR FilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR FilePath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectHandle( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Repaint( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTDisplay * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImgWidth )( 
            IDTDisplay * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImgWidth )( 
            IDTDisplay * This,
            /* [in] */ ULONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImgHeight )( 
            IDTDisplay * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImgHeight )( 
            IDTDisplay * This,
            /* [in] */ ULONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gamma )( 
            IDTDisplay * This,
            /* [retval][out] */ FLOAT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gamma )( 
            IDTDisplay * This,
            /* [in] */ FLOAT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MapStart )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MapStart )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MapEnd )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MapEnd )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataSource )( 
            IDTDisplay * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataSource )( 
            IDTDisplay * This,
            /* [in] */ IUnknown *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayControl )( 
            IDTDisplay * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayControl )( 
            IDTDisplay * This,
            /* [in] */ IUnknown *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IDTDisplay * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RefreshMode )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RefreshMode )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RefreshRate )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RefreshRate )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageObject )( 
            IDTDisplay * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScale )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScale )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IDTDisplay * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OrgPoint_X )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OrgPoint_X )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OrgPoint_Y )( 
            IDTDisplay * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OrgPoint_Y )( 
            IDTDisplay * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IDTDisplay * This,
            /* [in] */ BSTR FilePath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IDTDisplay * This,
            /* [in] */ BSTR FilePath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectHandle )( 
            IDTDisplay * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Repaint )( 
            IDTDisplay * This);
        
        END_INTERFACE
    } IDTDisplayVtbl;

    interface IDTDisplay
    {
        CONST_VTBL struct IDTDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDTDisplay_get_ImgWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_ImgWidth(This,pVal) ) 

#define IDTDisplay_put_ImgWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_ImgWidth(This,newVal) ) 

#define IDTDisplay_get_ImgHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_ImgHeight(This,pVal) ) 

#define IDTDisplay_put_ImgHeight(This,newVal)	\
    ( (This)->lpVtbl -> put_ImgHeight(This,newVal) ) 

#define IDTDisplay_get_Gamma(This,pVal)	\
    ( (This)->lpVtbl -> get_Gamma(This,pVal) ) 

#define IDTDisplay_put_Gamma(This,newVal)	\
    ( (This)->lpVtbl -> put_Gamma(This,newVal) ) 

#define IDTDisplay_get_MapStart(This,pVal)	\
    ( (This)->lpVtbl -> get_MapStart(This,pVal) ) 

#define IDTDisplay_put_MapStart(This,newVal)	\
    ( (This)->lpVtbl -> put_MapStart(This,newVal) ) 

#define IDTDisplay_get_MapEnd(This,pVal)	\
    ( (This)->lpVtbl -> get_MapEnd(This,pVal) ) 

#define IDTDisplay_put_MapEnd(This,newVal)	\
    ( (This)->lpVtbl -> put_MapEnd(This,newVal) ) 

#define IDTDisplay_get_DataSource(This,pVal)	\
    ( (This)->lpVtbl -> get_DataSource(This,pVal) ) 

#define IDTDisplay_put_DataSource(This,newVal)	\
    ( (This)->lpVtbl -> put_DataSource(This,newVal) ) 

#define IDTDisplay_get_DisplayControl(This,pVal)	\
    ( (This)->lpVtbl -> get_DisplayControl(This,pVal) ) 

#define IDTDisplay_put_DisplayControl(This,newVal)	\
    ( (This)->lpVtbl -> put_DisplayControl(This,newVal) ) 

#define IDTDisplay_Open(This,bOK)	\
    ( (This)->lpVtbl -> Open(This,bOK) ) 

#define IDTDisplay_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IDTDisplay_get_RefreshMode(This,pVal)	\
    ( (This)->lpVtbl -> get_RefreshMode(This,pVal) ) 

#define IDTDisplay_put_RefreshMode(This,newVal)	\
    ( (This)->lpVtbl -> put_RefreshMode(This,newVal) ) 

#define IDTDisplay_get_RefreshRate(This,pVal)	\
    ( (This)->lpVtbl -> get_RefreshRate(This,pVal) ) 

#define IDTDisplay_put_RefreshRate(This,newVal)	\
    ( (This)->lpVtbl -> put_RefreshRate(This,newVal) ) 

#define IDTDisplay_get_ImageObject(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageObject(This,pVal) ) 

#define IDTDisplay_get_DisplayScale(This,pVal)	\
    ( (This)->lpVtbl -> get_DisplayScale(This,pVal) ) 

#define IDTDisplay_put_DisplayScale(This,newVal)	\
    ( (This)->lpVtbl -> put_DisplayScale(This,newVal) ) 

#define IDTDisplay_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IDTDisplay_get_OrgPoint_X(This,pVal)	\
    ( (This)->lpVtbl -> get_OrgPoint_X(This,pVal) ) 

#define IDTDisplay_put_OrgPoint_X(This,newVal)	\
    ( (This)->lpVtbl -> put_OrgPoint_X(This,newVal) ) 

#define IDTDisplay_get_OrgPoint_Y(This,pVal)	\
    ( (This)->lpVtbl -> get_OrgPoint_Y(This,pVal) ) 

#define IDTDisplay_put_OrgPoint_Y(This,newVal)	\
    ( (This)->lpVtbl -> put_OrgPoint_Y(This,newVal) ) 

#define IDTDisplay_Load(This,FilePath)	\
    ( (This)->lpVtbl -> Load(This,FilePath) ) 

#define IDTDisplay_Save(This,FilePath)	\
    ( (This)->lpVtbl -> Save(This,FilePath) ) 

#define IDTDisplay_get_ObjectHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ObjectHandle(This,pVal) ) 

#define IDTDisplay_Repaint(This)	\
    ( (This)->lpVtbl -> Repaint(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTDisplay_INTERFACE_DEFINED__ */


#ifndef __IDTImage_INTERFACE_DEFINED__
#define __IDTImage_INTERFACE_DEFINED__

/* interface IDTImage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDTImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05A512FA-9E1F-4F7D-BE82-6FBECE81A17D")
    IDTImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImgHeight( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImgHeight( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImgWidth( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImgWidth( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BytesPerPixel( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BytesPerPixel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChannelType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImagePort( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImagePort( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DetectorObject( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DetectorObject( 
            /* [in] */ IUnknown *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsOpened( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Grab( 
            /* [in] */ LONG FrameNum,
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snap( 
            /* [in] */ LONG FrameNum,
            /* [retval][out] */ LONG *bOK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintErrMsg( 
            /* [in] */ LONG ErrID,
            /* [out] */ BSTR *ErrMsg) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubFrameHeight( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubFrameHeight( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsGrabing( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageObject( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BandWidth( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectHandle( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExFrameTrigger( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExFrameTrigger( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DualScanMode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DualScanMode( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenMemImage( 
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ BYTE *data) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTImage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImgHeight )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImgHeight )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImgWidth )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImgWidth )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BytesPerPixel )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BytesPerPixel )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelType )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChannelType )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImagePort )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImagePort )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetectorObject )( 
            IDTImage * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DetectorObject )( 
            IDTImage * This,
            /* [in] */ IUnknown *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsOpened )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrID )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IDTImage * This,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IDTImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Grab )( 
            IDTImage * This,
            /* [in] */ LONG FrameNum,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Snap )( 
            IDTImage * This,
            /* [in] */ LONG FrameNum,
            /* [retval][out] */ LONG *bOK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PrintErrMsg )( 
            IDTImage * This,
            /* [in] */ LONG ErrID,
            /* [out] */ BSTR *ErrMsg);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubFrameHeight )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubFrameHeight )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IDTImage * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsGrabing )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageObject )( 
            IDTImage * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BandWidth )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectHandle )( 
            IDTImage * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeOut )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeOut )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExFrameTrigger )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExFrameTrigger )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DualScanMode )( 
            IDTImage * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DualScanMode )( 
            IDTImage * This,
            /* [in] */ LONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenMemImage )( 
            IDTImage * This,
            /* [in] */ LONG width,
            /* [in] */ LONG height,
            /* [in] */ BYTE *data);
        
        END_INTERFACE
    } IDTImageVtbl;

    interface IDTImage
    {
        CONST_VTBL struct IDTImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDTImage_get_ImgHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_ImgHeight(This,pVal) ) 

#define IDTImage_put_ImgHeight(This,newVal)	\
    ( (This)->lpVtbl -> put_ImgHeight(This,newVal) ) 

#define IDTImage_get_ImgWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_ImgWidth(This,pVal) ) 

#define IDTImage_put_ImgWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_ImgWidth(This,newVal) ) 

#define IDTImage_get_BytesPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BytesPerPixel(This,pVal) ) 

#define IDTImage_put_BytesPerPixel(This,newVal)	\
    ( (This)->lpVtbl -> put_BytesPerPixel(This,newVal) ) 

#define IDTImage_get_ChannelType(This,pVal)	\
    ( (This)->lpVtbl -> get_ChannelType(This,pVal) ) 

#define IDTImage_put_ChannelType(This,newVal)	\
    ( (This)->lpVtbl -> put_ChannelType(This,newVal) ) 

#define IDTImage_get_ImagePort(This,pVal)	\
    ( (This)->lpVtbl -> get_ImagePort(This,pVal) ) 

#define IDTImage_put_ImagePort(This,newVal)	\
    ( (This)->lpVtbl -> put_ImagePort(This,newVal) ) 

#define IDTImage_get_DetectorObject(This,pVal)	\
    ( (This)->lpVtbl -> get_DetectorObject(This,pVal) ) 

#define IDTImage_put_DetectorObject(This,newVal)	\
    ( (This)->lpVtbl -> put_DetectorObject(This,newVal) ) 

#define IDTImage_get_IsOpened(This,pVal)	\
    ( (This)->lpVtbl -> get_IsOpened(This,pVal) ) 

#define IDTImage_get_LastErrID(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrID(This,pVal) ) 

#define IDTImage_Open(This,bOK)	\
    ( (This)->lpVtbl -> Open(This,bOK) ) 

#define IDTImage_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IDTImage_Grab(This,FrameNum,bOK)	\
    ( (This)->lpVtbl -> Grab(This,FrameNum,bOK) ) 

#define IDTImage_Snap(This,FrameNum,bOK)	\
    ( (This)->lpVtbl -> Snap(This,FrameNum,bOK) ) 

#define IDTImage_PrintErrMsg(This,ErrID,ErrMsg)	\
    ( (This)->lpVtbl -> PrintErrMsg(This,ErrID,ErrMsg) ) 

#define IDTImage_get_SubFrameHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_SubFrameHeight(This,pVal) ) 

#define IDTImage_put_SubFrameHeight(This,newVal)	\
    ( (This)->lpVtbl -> put_SubFrameHeight(This,newVal) ) 

#define IDTImage_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IDTImage_get_IsGrabing(This,pVal)	\
    ( (This)->lpVtbl -> get_IsGrabing(This,pVal) ) 

#define IDTImage_get_ImageObject(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageObject(This,pVal) ) 

#define IDTImage_get_BandWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_BandWidth(This,pVal) ) 

#define IDTImage_get_ObjectHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ObjectHandle(This,pVal) ) 

#define IDTImage_get_TimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_TimeOut(This,pVal) ) 

#define IDTImage_put_TimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_TimeOut(This,newVal) ) 

#define IDTImage_get_ExFrameTrigger(This,pVal)	\
    ( (This)->lpVtbl -> get_ExFrameTrigger(This,pVal) ) 

#define IDTImage_put_ExFrameTrigger(This,newVal)	\
    ( (This)->lpVtbl -> put_ExFrameTrigger(This,newVal) ) 

#define IDTImage_get_DualScanMode(This,pVal)	\
    ( (This)->lpVtbl -> get_DualScanMode(This,pVal) ) 

#define IDTImage_put_DualScanMode(This,newVal)	\
    ( (This)->lpVtbl -> put_DualScanMode(This,newVal) ) 

#define IDTImage_OpenMemImage(This,width,height,data)	\
    ( (This)->lpVtbl -> OpenMemImage(This,width,height,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTImage_INTERFACE_DEFINED__ */



#ifndef __DTControl_LIBRARY_DEFINED__
#define __DTControl_LIBRARY_DEFINED__

/* library DTControl */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_DTControl;

#ifndef ___IDTDisplayControlEvents_DISPINTERFACE_DEFINED__
#define ___IDTDisplayControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDTDisplayControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDTDisplayControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("51F345B5-044F-49F2-A824-59B2869CEF23")
    _IDTDisplayControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDTDisplayControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDTDisplayControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDTDisplayControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDTDisplayControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDTDisplayControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDTDisplayControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDTDisplayControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDTDisplayControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDTDisplayControlEventsVtbl;

    interface _IDTDisplayControlEvents
    {
        CONST_VTBL struct _IDTDisplayControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDTDisplayControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDTDisplayControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDTDisplayControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDTDisplayControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDTDisplayControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDTDisplayControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDTDisplayControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDTDisplayControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDTDisplayControl;

#ifdef __cplusplus

class DECLSPEC_UUID("14B6C482-806F-4171-AEA4-FB424E07A758")
CDTDisplayControl;
#endif

#ifndef ___IDTDetectorEvents_DISPINTERFACE_DEFINED__
#define ___IDTDetectorEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDTDetectorEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDTDetectorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B3E172CD-8F54-4910-AA06-61B8D3ECD986")
    _IDTDetectorEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDTDetectorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDTDetectorEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDTDetectorEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDTDetectorEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDTDetectorEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDTDetectorEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDTDetectorEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDTDetectorEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDTDetectorEventsVtbl;

    interface _IDTDetectorEvents
    {
        CONST_VTBL struct _IDTDetectorEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDTDetectorEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDTDetectorEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDTDetectorEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDTDetectorEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDTDetectorEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDTDetectorEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDTDetectorEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDTDetectorEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDTDetector;

#ifdef __cplusplus

class DECLSPEC_UUID("81B889F3-33FC-40CD-A98B-4487723F5A3B")
CDTDetector;
#endif

#ifndef ___IDTCommanderF3Events_DISPINTERFACE_DEFINED__
#define ___IDTCommanderF3Events_DISPINTERFACE_DEFINED__

/* dispinterface _IDTCommanderF3Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDTCommanderF3Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3F2A6451-EC6C-4948-9C07-7764FA64A894")
    _IDTCommanderF3Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDTCommanderF3EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDTCommanderF3Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDTCommanderF3Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDTCommanderF3Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDTCommanderF3Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDTCommanderF3Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDTCommanderF3Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDTCommanderF3Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDTCommanderF3EventsVtbl;

    interface _IDTCommanderF3Events
    {
        CONST_VTBL struct _IDTCommanderF3EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDTCommanderF3Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDTCommanderF3Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDTCommanderF3Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDTCommanderF3Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDTCommanderF3Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDTCommanderF3Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDTCommanderF3Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDTCommanderF3Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDTCommanderF3;

#ifdef __cplusplus

class DECLSPEC_UUID("B08859A2-D75E-4B6D-8C13-A80DAD7BA087")
CDTCommanderF3;
#endif

EXTERN_C const CLSID CLSID_CImageObject;

#ifdef __cplusplus

class DECLSPEC_UUID("25874CDE-5C8A-486D-855D-C8DE1FFBEE8A")
CImageObject;
#endif

#ifndef ___IDTDisplayEvents_DISPINTERFACE_DEFINED__
#define ___IDTDisplayEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDTDisplayEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDTDisplayEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CD1AAF81-A669-47B7-94A0-5A2A1FBA4439")
    _IDTDisplayEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDTDisplayEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDTDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDTDisplayEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDTDisplayEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDTDisplayEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDTDisplayEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDTDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDTDisplayEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDTDisplayEventsVtbl;

    interface _IDTDisplayEvents
    {
        CONST_VTBL struct _IDTDisplayEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDTDisplayEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDTDisplayEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDTDisplayEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDTDisplayEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDTDisplayEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDTDisplayEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDTDisplayEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDTDisplayEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDTDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("F984B792-41DB-4D78-95A7-1C80E40938FD")
CDTDisplay;
#endif

#ifndef ___IDTImageEvents_DISPINTERFACE_DEFINED__
#define ___IDTImageEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDTImageEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDTImageEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("41BE7653-30F4-461F-87A1-4BAB1F8C8B33")
    _IDTImageEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDTImageEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDTImageEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDTImageEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDTImageEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDTImageEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDTImageEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDTImageEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDTImageEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDTImageEventsVtbl;

    interface _IDTImageEvents
    {
        CONST_VTBL struct _IDTImageEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDTImageEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDTImageEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDTImageEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDTImageEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDTImageEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDTImageEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDTImageEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDTImageEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDTImage;

#ifdef __cplusplus

class DECLSPEC_UUID("137E0C10-17BC-4F16-BFFE-5C1E7725C8EA")
CDTImage;
#endif
#endif /* __DTControl_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


