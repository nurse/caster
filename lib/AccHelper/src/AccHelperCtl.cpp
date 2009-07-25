// AccHelperCtl.cpp : CAccHelperCtrl ActiveX �R���g���[�� �N���X�̃C���v�������e�[�V����

#include "stdafx.h"
#include "AccHelper.h"
#include "AccHelperCtl.h"
#include "AccHelperPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CAccHelperCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CAccHelperCtrl, COleControl)
	//{{AFX_MSG_MAP(CAccHelperCtrl)
	// ���� - ClassWizard �̓��b�Z�[�W �}�b�v�̃G���g����ǉ��܂��͍폜���܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �f�B�X�p�b�` �}�b�v

BEGIN_DISPATCH_MAP(CAccHelperCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAccHelperCtrl)
	DISP_PROPERTY_EX(CAccHelperCtrl, "opacity", GetOpacity, SetOpacity, VT_I2)
	DISP_PROPERTY_EX(CAccHelperCtrl, "topmost", GetTopmost, SetTopmost, VT_BOOL)
	DISP_PROPERTY_EX(CAccHelperCtrl, "onactivate", GetNotSupported, SetOnActivate, VT_DISPATCH)
	DISP_FUNCTION(CAccHelperCtrl, "Init", Init, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CAccHelperCtrl, "FlashWindow", FlashWindow, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CAccHelperCtrl, "Test", Test, VT_EMPTY, VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CAccHelperCtrl, "PlaySound", PlaySound, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CAccHelperCtrl, "GetVersion", GetVersion, VT_I4, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// �C�x���g �}�b�v

BEGIN_EVENT_MAP(CAccHelperCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAccHelperCtrl)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// �v���p�e�B �y�[�W

// TODO: �v���p�e�B �y�[�W��ǉ����āABEGIN �s�̍Ō�ɂ���J�E���g�𑝂₵�Ă��������B
BEGIN_PROPPAGEIDS(CAccHelperCtrl, 1)
	PROPPAGEID(CAccHelperPropPage::guid)
END_PROPPAGEIDS(CAccHelperCtrl)


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g���� guid �����������܂�

IMPLEMENT_OLECREATE_EX(CAccHelperCtrl, "ACCHELPER.AccHelperCtrl.1",
//	0x8ab190d5, 0x6a7f, 0x4648, 0x9f, 0xce, 0x93, 0xc4, 0x29, 0x1c, 0x26, 0x82)
	0xd172c6e0, 0xcb85, 0x11da, 0xa9, 0x4d, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66)


/////////////////////////////////////////////////////////////////////////////
// �^�C�v ���C�u���� ID �ƃo�[�W����

IMPLEMENT_OLETYPELIB(CAccHelperCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// �C���^�[�t�F�C�X ID

const IID BASED_CODE IID_DAccHelper =
		{ 0xf542c698, 0x2bcb, 0x43eb, { 0x8d, 0x24, 0xee, 0x82, 0x77, 0x2, 0x9, 0xa5 } };
const IID BASED_CODE IID_DAccHelperEvents =
		{ 0x12d4edc3, 0x55ab, 0x490f, { 0x97, 0x95, 0xb0, 0x57, 0x47, 0xa6, 0x92, 0 } };


/////////////////////////////////////////////////////////////////////////////
// �R���g���[���̌^���̐���

static const DWORD BASED_CODE _dwAccHelperOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAccHelperCtrl, IDS_ACCHELPER, _dwAccHelperOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::CAccHelperCtrlFactory::UpdateRegistry -
// CAccHelperCtrl �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂� 

BOOL CAccHelperCtrl::CAccHelperCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: �R���g���[�����A�p�[�g�����g ���f���̃X���b�h�����̋K���ɏ]���Ă��邱�Ƃ�
	// �m�F���Ă��������B�ڍׂɂ��Ă� MFC �̃e�N�j�J�� �m�[�g 64 ���Q�Ƃ��Ă��������B
	// �A�p�[�g�����g ���f���̃X���b�h�����̋K���ɏ]��Ȃ��R���g���[���̏ꍇ�́A6 �Ԗ�
	// �̃p�����[�^���ȉ��̂悤�ɕύX���Ă��������B
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ACCHELPER,
			IDB_ACCHELPER,
			afxRegApartmentThreading,
			_dwAccHelperOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::CAccHelperCtrl - �R���X�g���N�^

CAccHelperCtrl::CAccHelperCtrl()
{
	InitializeIIDs(&IID_DAccHelper, &IID_DAccHelperEvents);

	// TODO: ���̈ʒu�ɃR���g���[���̃C���X�^���X �f�[�^�̏�����������ǉ����Ă�������
	theApp.control=this;
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::~CAccHelperCtrl - �f�X�g���N�^

CAccHelperCtrl::~CAccHelperCtrl()
{
	// TODO: ���̈ʒu�ɃR���g���[���̃C���X�^���X �f�[�^�̌㏈���p�̃R�[�h��ǉ����Ă�������
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::OnDraw - �`��֐�

void CAccHelperCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: �ȉ��̃R�[�h��`��p�̃R�[�h�ɒu�������Ă�������
#if 0
	pdc->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(LTGRAY_BRUSH)));
	pdc->FillRect(rcBounds,pdc->GetCurrentBrush());
//	pdc->DrawText(TEXT("AccHelper OCX Control"),-1,(LPRECT)rcBounds,DT_LEFT );
	pdc->Ellipse(rcBounds);
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::DoPropExchange - �i�����̃T�|�[�g

void CAccHelperCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �p���\�����������e�J�X�^�� �v���p�e�B�p�� PX_ �֐��̌Ăяo����ǉ����Ă�������

}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::GetControlFlags -
// MFC �� ActiveX �R���g���[���̃C���v�������e�[�V�����̃J�X�^�}�C�Y�p�t���O
//
// �����̃t���O�̎g�����ɂ��Ă� MFC �̃e�N�j�J�� �m�[�g "ActiveX �R���g���[���̍œK��"
// ���Q�Ƃ��Ă��������B
DWORD CAccHelperCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// �R���g���[���̓E�B���h�E���쐬�����ɃA�N�e�B�x�[�g�\�ł��B
	// TODO: �R���g���[���̃��b�Z�[�W �n���h�����쐬����ꍇ�Am_hWnd
	//		 �����o�ϐ��̒l�� NULL �ȊO�ł��邱�Ƃ��ŏ��Ɋm�F
	//		���Ă���g�p���Ă��������B
	dwFlags |= windowlessActivate;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::OnResetState - �R���g���[���̃v���p�e�B�l�����Z�b�g

void CAccHelperCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange ���Ăяo���ăf�t�H���g�l�Ƀ��Z�b�g

	// ���̈ʒu�ɃR���g���[���̏�Ԃ����Z�b�g���鏈����ǉ����Ă�������
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl ���b�Z�[�W �n���h��

#pragma data_seg(".sharedata")
HHOOK hHook=NULL;
#pragma data_seg()

LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam){
	if(code==HC_ACTION){
		CWPSTRUCT msg=*(CWPSTRUCT*)lParam;
//		MSG msg=*(MSG*)lParam;
		switch(msg.message){
		case WM_ACTIVATE:
			switch(LOWORD(msg.wParam)){
			case WA_ACTIVE:
			case WA_CLICKACTIVE:
				//SetWindowText(msg.hwnd,TEXT("active"));
				{
					if(theApp.flashed){
						theApp.control->FlashWindow2(0);
					}
					if(theApp.control){
						theApp.control->FireOnActivate(1);
					}
				}
				break;
			case WA_INACTIVE:
				//SetWindowText(msg.hwnd,TEXT("inactive"));
				if(theApp.control){
					theApp.control->FireOnActivate(0);
				}
				break;
			}
			break;
		}
	}
	return CallNextHookEx(hHook,code,wParam,lParam);
}


long CAccHelperCtrl::Init(LPCTSTR title) {
	assoc=::FindWindow(NULL,title);
	if(!assoc){ return 1; }
	hHook = ::SetWindowsHookEx(WH_CALLWNDPROC,(HOOKPROC)HookProc,theApp.m_hInstance,::GetWindowThreadProcessId(assoc,NULL));
//	hHook = ::SetWindowsHookEx(WH_GETMESSAGE,(HOOKPROC)HookProc,theApp.m_hInstance,::GetWindowThreadProcessId(assoc,NULL));
	SetOpacity(256);
	::SetActiveWindow(assoc);
	return 0;
}

void CAccHelperCtrl::FlashWindow() {
	FlashWindow2(1);
}

void CAccHelperCtrl::FlashWindow2(int count) {
	if(assoc){
		theApp.flashed=count;
		if(count){
			FLASHWINFO info;
			ZeroMemory(&info,sizeof(info));
			info.cbSize=sizeof(info);
			info.hwnd=assoc;
			info.dwFlags=FLASHW_ALL|FLASHW_TIMERNOFG;
			info.uCount=count;
			::FlashWindowEx(&info);
		}else{
			FLASHWINFO info;
			ZeroMemory(&info,sizeof(info));
			info.cbSize=sizeof(info);
			info.hwnd=assoc;
			info.dwFlags=FLASHW_STOP;
			::FlashWindowEx(&info);
			const int sz_buff=0x1000;
			TCHAR buff[sz_buff];
			::GetWindowText(assoc,buff,sz_buff);
			::SetWindowText(assoc,buff);
		}
	}
}

long CAccHelperCtrl::GetOpacity() {
	return opacity;
}

void CAccHelperCtrl::SetOpacity(long nNewValue) {
	if(assoc){
		if(nNewValue<0 || nNewValue>0xFF){
			opacity=0x100;
			::SetWindowLong(assoc,GWL_EXSTYLE,GetWindowLong(assoc,GWL_EXSTYLE) & ~WS_EX_LAYERED);
		}else{
			opacity=nNewValue;
			::SetWindowLong(assoc,GWL_EXSTYLE,GetWindowLong(assoc,GWL_EXSTYLE) | WS_EX_LAYERED);
			::SetLayeredWindowAttributes(assoc,NULL,(BYTE)opacity,LWA_ALPHA);
		}
	}
	SetModifiedFlag();
}

BOOL CAccHelperCtrl::GetTopmost() {
	return topmost;
}

void CAccHelperCtrl::SetTopmost(BOOL bNewValue) {
	if(assoc){
		topmost=bNewValue;
		::SetWindowPos(assoc,bNewValue?HWND_TOPMOST:HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	}
	SetModifiedFlag();
}

void CAccHelperCtrl::Test(const VARIANT FAR& p1, const VARIANT FAR& p2, const VARIANT FAR& p3, const VARIANT FAR& p4) {
}

void CAccHelperCtrl::SetOnActivate(LPDISPATCH newValue) {
	onactivate=newValue;
	SetModifiedFlag();
}

HRESULT CAccHelperCtrl::FireOnActivate(DWORD active) {
	if(onactivate){
		VARIANT v;
		v.vt=VT_I4;
		v.lVal=active;
		DISPPARAMS p;
		p.cArgs=1;
		p.cNamedArgs=0;
		p.rgvarg=&v;
		return onactivate->Invoke(0,IID_NULL,LOCALE_USER_DEFAULT,DISPATCH_METHOD,&p,NULL,NULL,NULL);
	}else{
		return -1;
	}
}

long CAccHelperCtrl::PlaySound(LPCTSTR src) 
{
	::PlaySound(src,0,SND_FILENAME | SND_ASYNC);
	// TODO: �������ި��߯� ����� ���ނ�ǉ����Ă��������B
	return 0;
}


#define	MY_NOTIFYICON	(WM_USER+100)

long CAccHelperCtrl::GetVersion() 
{

	NOTIFYICONDATA nid;

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = assoc ;
	nid.uID = 0;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = MY_NOTIFYICON;
	nid.hIcon = HICON(::SendMessage(assoc, WM_GETICON, ICON_SMALL, NULL));
	lstrcpy(nid.szTip, TEXT("�[�邿����"));
	Shell_NotifyIcon(NIM_ADD, &nid);

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.uFlags = NIF_INFO;
	nid.hWnd = assoc;
	lstrcpy(nid.szInfoTitle, TEXT("���������ρ[���X�V����܂���"));
	lstrcpy(nid.szInfo, TEXT("�˂� > ���w�����������̂͏��w���܂ł���ˁ["));
	nid.dwInfoFlags = 3;
	Shell_NotifyIcon(NIM_MODIFY, &nid);

	return (long)assoc;
}
