// AccHelper.cpp : CAccHelperApp クラスのインプリメンテーションおよび DLL の登録を行います。

#include "stdafx.h"
#include "AccHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CAccHelperApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x36ce9e7e, 0xb517, 0x42a6, { 0xb1, 0x44, 0xf0, 0x7, 0xab, 0x3c, 0xb7, 0x73 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


////////////////////////////////////////////////////////////////////////////
// CAccHelperApp::InitInstance - DLL の初期化

BOOL CAccHelperApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();
	if (bInit)
	{
		control=0;
		flashed=0;
		hover=0;
	}
	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CAccHelperApp::ExitInstance - DLL の終了

int CAccHelperApp::ExitInstance()
{
	if(hHook){
		UnhookWindowsHookEx(hHook);
	}
	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - システム レジストリのエントリを追加

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - システム レジストリからのエントリを削除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
