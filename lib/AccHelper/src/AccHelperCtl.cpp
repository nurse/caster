// AccHelperCtl.cpp : CAccHelperCtrl ActiveX コントロール クラスのインプリメンテーション

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
// メッセージ マップ

BEGIN_MESSAGE_MAP(CAccHelperCtrl, COleControl)
	//{{AFX_MSG_MAP(CAccHelperCtrl)
	// メモ - ClassWizard はメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ディスパッチ マップ

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
// イベント マップ

BEGIN_EVENT_MAP(CAccHelperCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAccHelperCtrl)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// プロパティ ページ

// TODO: プロパティ ページを追加して、BEGIN 行の最後にあるカウントを増やしてください。
BEGIN_PROPPAGEIDS(CAccHelperCtrl, 1)
	PROPPAGEID(CAccHelperPropPage::guid)
END_PROPPAGEIDS(CAccHelperCtrl)


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリと guid を初期化します

IMPLEMENT_OLECREATE_EX(CAccHelperCtrl, "ACCHELPER.AccHelperCtrl.1",
//	0x8ab190d5, 0x6a7f, 0x4648, 0x9f, 0xce, 0x93, 0xc4, 0x29, 0x1c, 0x26, 0x82)
	0xd172c6e0, 0xcb85, 0x11da, 0xa9, 0x4d, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66)


/////////////////////////////////////////////////////////////////////////////
// タイプ ライブラリ ID とバージョン

IMPLEMENT_OLETYPELIB(CAccHelperCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// インターフェイス ID

const IID BASED_CODE IID_DAccHelper =
		{ 0xf542c698, 0x2bcb, 0x43eb, { 0x8d, 0x24, 0xee, 0x82, 0x77, 0x2, 0x9, 0xa5 } };
const IID BASED_CODE IID_DAccHelperEvents =
		{ 0x12d4edc3, 0x55ab, 0x490f, { 0x97, 0x95, 0xb0, 0x57, 0x47, 0xa6, 0x92, 0 } };


/////////////////////////////////////////////////////////////////////////////
// コントロールの型情報の制御

static const DWORD BASED_CODE _dwAccHelperOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAccHelperCtrl, IDS_ACCHELPER, _dwAccHelperOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::CAccHelperCtrlFactory::UpdateRegistry -
// CAccHelperCtrl のシステム レジストリのエントリを追加または削除します 

BOOL CAccHelperCtrl::CAccHelperCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: コントロールがアパートメント モデルのスレッド処理の規則に従っていることを
	// 確認してください。詳細については MFC のテクニカル ノート 64 を参照してください。
	// アパートメント モデルのスレッド処理の規則に従わないコントロールの場合は、6 番目
	// のパラメータを以下のように変更してください。
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
// CAccHelperCtrl::CAccHelperCtrl - コンストラクタ

CAccHelperCtrl::CAccHelperCtrl()
{
	InitializeIIDs(&IID_DAccHelper, &IID_DAccHelperEvents);

	// TODO: この位置にコントロールのインスタンス データの初期化処理を追加してください
	theApp.control=this;
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::~CAccHelperCtrl - デストラクタ

CAccHelperCtrl::~CAccHelperCtrl()
{
	// TODO: この位置にコントロールのインスタンス データの後処理用のコードを追加してください
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::OnDraw - 描画関数

void CAccHelperCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: 以下のコードを描画用のコードに置き換えてください
#if 0
	pdc->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(LTGRAY_BRUSH)));
	pdc->FillRect(rcBounds,pdc->GetCurrentBrush());
//	pdc->DrawText(TEXT("AccHelper OCX Control"),-1,(LPRECT)rcBounds,DT_LEFT );
	pdc->Ellipse(rcBounds);
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::DoPropExchange - 永続性のサポート

void CAccHelperCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 継続表示属性を持つ各カスタム プロパティ用の PX_ 関数の呼び出しを追加してください

}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::GetControlFlags -
// MFC の ActiveX コントロールのインプリメンテーションのカスタマイズ用フラグ
//
// これらのフラグの使い方については MFC のテクニカル ノート "ActiveX コントロールの最適化"
// を参照してください。
DWORD CAccHelperCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// コントロールはウィンドウを作成せずにアクティベート可能です。
	// TODO: コントロールのメッセージ ハンドラを作成する場合、m_hWnd
	//		 メンバ変数の値が NULL 以外であることを最初に確認
	//		してから使用してください。
	dwFlags |= windowlessActivate;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl::OnResetState - コントロールのプロパティ値をリセット

void CAccHelperCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange を呼び出してデフォルト値にリセット

	// この位置にコントロールの状態をリセットする処理を追加してください
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl メッセージ ハンドラ

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
	// TODO: ここにﾃﾞｨｽﾊﾟｯﾁ ﾊﾝﾄﾞﾗ ｺｰﾄﾞを追加してください。
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
	lstrcpy(nid.szTip, TEXT("つーるちっぷ"));
	Shell_NotifyIcon(NIM_ADD, &nid);

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.uFlags = NIF_INFO;
	nid.hWnd = assoc;
	lstrcpy(nid.szInfoTitle, TEXT("あじゃらっぱーが更新されました"));
	lstrcpy(nid.szInfo, TEXT("ねり > 小学生が許されるのは小学生までだよねー"));
	nid.dwInfoFlags = 3;
	Shell_NotifyIcon(NIM_MODIFY, &nid);

	return (long)assoc;
}
