

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Mar 29 01:43:20 2010
 */
/* Compiler settings for src\TOOLS\VSPE_COMSERVER\VSPE_ComServer.idl:
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

#ifndef __VSPE_ComServer_h__
#define __VSPE_ComServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVSPE_FWD_DEFINED__
#define __IVSPE_FWD_DEFINED__
typedef interface IVSPE IVSPE;
#endif 	/* __IVSPE_FWD_DEFINED__ */


#ifndef __VSPEApi_FWD_DEFINED__
#define __VSPEApi_FWD_DEFINED__

#ifdef __cplusplus
typedef class VSPEApi VSPEApi;
#else
typedef struct VSPEApi VSPEApi;
#endif /* __cplusplus */

#endif 	/* __VSPEApi_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IVSPE_INTERFACE_DEFINED__
#define __IVSPE_INTERFACE_DEFINED__

/* interface IVSPE */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVSPE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4350205d-80d8-429e-ac0c-0fc64dc42180")
    IVSPE : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_activate( 
            /* [in] */ BSTR key,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_initialize( 
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_loadConfiguration( 
            /* [in] */ BSTR name,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_saveConfiguration( 
            /* [in] */ BSTR name,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_createDevice( 
            /* [in] */ BSTR name,
            /* [in] */ BSTR initString,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_destroyDevice( 
            /* [in] */ LONG deviceId,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_reinitializeDevice( 
            /* [in] */ LONG deviceId,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_destroyAllDevices( 
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_startEmulation( 
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_stopEmulation( 
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_release( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_getDevicesCount( 
            /* [retval][out] */ LONG *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_getDeviceIdByIdx( 
            /* [in] */ LONG idx,
            /* [retval][out] */ LONG *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_getDeviceInfo( 
            /* [in] */ LONG deviceId,
            /* [out] */ BSTR *name,
            /* [out] */ BSTR *initString,
            /* [out] */ LONG *ok,
            /* [out] */ LONG *used,
            /* [retval][out] */ BOOL *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_getVersionInformation( 
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vspe_getDeviceIdByComPortIndex( 
            /* [in] */ LONG ComPortIdx,
            /* [retval][out] */ LONG *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVSPEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVSPE * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVSPE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVSPE * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVSPE * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVSPE * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVSPE * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVSPE * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_activate )( 
            IVSPE * This,
            /* [in] */ BSTR key,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_initialize )( 
            IVSPE * This,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_loadConfiguration )( 
            IVSPE * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_saveConfiguration )( 
            IVSPE * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_createDevice )( 
            IVSPE * This,
            /* [in] */ BSTR name,
            /* [in] */ BSTR initString,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_destroyDevice )( 
            IVSPE * This,
            /* [in] */ LONG deviceId,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_reinitializeDevice )( 
            IVSPE * This,
            /* [in] */ LONG deviceId,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_destroyAllDevices )( 
            IVSPE * This,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_startEmulation )( 
            IVSPE * This,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_stopEmulation )( 
            IVSPE * This,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_release )( 
            IVSPE * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_getDevicesCount )( 
            IVSPE * This,
            /* [retval][out] */ LONG *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_getDeviceIdByIdx )( 
            IVSPE * This,
            /* [in] */ LONG idx,
            /* [retval][out] */ LONG *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_getDeviceInfo )( 
            IVSPE * This,
            /* [in] */ LONG deviceId,
            /* [out] */ BSTR *name,
            /* [out] */ BSTR *initString,
            /* [out] */ LONG *ok,
            /* [out] */ LONG *used,
            /* [retval][out] */ BOOL *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_getVersionInformation )( 
            IVSPE * This,
            /* [retval][out] */ BSTR *result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vspe_getDeviceIdByComPortIndex )( 
            IVSPE * This,
            /* [in] */ LONG ComPortIdx,
            /* [retval][out] */ LONG *result);
        
        END_INTERFACE
    } IVSPEVtbl;

    interface IVSPE
    {
        CONST_VTBL struct IVSPEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVSPE_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVSPE_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVSPE_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVSPE_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVSPE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVSPE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVSPE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVSPE_vspe_activate(This,key,Result)	\
    ( (This)->lpVtbl -> vspe_activate(This,key,Result) ) 

#define IVSPE_vspe_initialize(This,Result)	\
    ( (This)->lpVtbl -> vspe_initialize(This,Result) ) 

#define IVSPE_vspe_loadConfiguration(This,name,Result)	\
    ( (This)->lpVtbl -> vspe_loadConfiguration(This,name,Result) ) 

#define IVSPE_vspe_saveConfiguration(This,name,Result)	\
    ( (This)->lpVtbl -> vspe_saveConfiguration(This,name,Result) ) 

#define IVSPE_vspe_createDevice(This,name,initString,Result)	\
    ( (This)->lpVtbl -> vspe_createDevice(This,name,initString,Result) ) 

#define IVSPE_vspe_destroyDevice(This,deviceId,Result)	\
    ( (This)->lpVtbl -> vspe_destroyDevice(This,deviceId,Result) ) 

#define IVSPE_vspe_reinitializeDevice(This,deviceId,Result)	\
    ( (This)->lpVtbl -> vspe_reinitializeDevice(This,deviceId,Result) ) 

#define IVSPE_vspe_destroyAllDevices(This,Result)	\
    ( (This)->lpVtbl -> vspe_destroyAllDevices(This,Result) ) 

#define IVSPE_vspe_startEmulation(This,Result)	\
    ( (This)->lpVtbl -> vspe_startEmulation(This,Result) ) 

#define IVSPE_vspe_stopEmulation(This,Result)	\
    ( (This)->lpVtbl -> vspe_stopEmulation(This,Result) ) 

#define IVSPE_vspe_release(This)	\
    ( (This)->lpVtbl -> vspe_release(This) ) 

#define IVSPE_vspe_getDevicesCount(This,Result)	\
    ( (This)->lpVtbl -> vspe_getDevicesCount(This,Result) ) 

#define IVSPE_vspe_getDeviceIdByIdx(This,idx,Result)	\
    ( (This)->lpVtbl -> vspe_getDeviceIdByIdx(This,idx,Result) ) 

#define IVSPE_vspe_getDeviceInfo(This,deviceId,name,initString,ok,used,Result)	\
    ( (This)->lpVtbl -> vspe_getDeviceInfo(This,deviceId,name,initString,ok,used,Result) ) 

#define IVSPE_vspe_getVersionInformation(This,result)	\
    ( (This)->lpVtbl -> vspe_getVersionInformation(This,result) ) 

#define IVSPE_vspe_getDeviceIdByComPortIndex(This,ComPortIdx,result)	\
    ( (This)->lpVtbl -> vspe_getDeviceIdByComPortIndex(This,ComPortIdx,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVSPE_INTERFACE_DEFINED__ */



#ifndef __VSPELib_LIBRARY_DEFINED__
#define __VSPELib_LIBRARY_DEFINED__

/* library VSPELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_VSPELib;

EXTERN_C const CLSID CLSID_VSPEApi;

#ifdef __cplusplus

class DECLSPEC_UUID("bf32160d-8fa7-408b-8a3c-cbfbfc19caa6")
VSPEApi;
#endif
#endif /* __VSPELib_LIBRARY_DEFINED__ */

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


