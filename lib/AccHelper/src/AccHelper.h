#if !defined(AFX_ACCHELPER_H__83BDE31D_8173_4C2B_836F_67F6E9C2CB29__INCLUDED_)
#define AFX_ACCHELPER_H__83BDE31D_8173_4C2B_836F_67F6E9C2CB29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AccHelper.h : ACCHELPER.DLL �̃��C�� �w�b�_�[ �t�@�C���ł�

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // ���C�� �V���{��
#include "AccHelperCtl.h"	// ClassView �ɂ���Ēǉ�����܂����B

/////////////////////////////////////////////////////////////////////////////
// CAccHelperApp : ���̃N���X�̓���̒�`�Ɋւ��Ă� AccHelper.cpp �t�@�C�����Q�Ƃ��Ă�������

class CAccHelperApp : public COleControlModule
{
public:
	CAccHelperCtrl* control;
	BOOL flashed;
	BOOL hover;
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

extern	HHOOK hHook;
extern	CAccHelperApp NEAR	theApp;
typedef BOOL (WINAPI *slayer)(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ACCHELPER_H__83BDE31D_8173_4C2B_836F_67F6E9C2CB29__INCLUDED)
