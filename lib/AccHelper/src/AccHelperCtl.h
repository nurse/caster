#if !defined(AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED_)
#define AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AccHelperCtl.h : CAccHelperCtrl ActiveX コントロール クラスの宣言

/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl : このクラスの動作の定義に関しては AccHelperCtl.cpp を参照してください

class CAccHelperCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAccHelperCtrl)

// コンストラクタ
public:
	CAccHelperCtrl();

// オーバーライド
	// ClassWizard は仮想関数のオーバライドを生成します
	//{{AFX_VIRTUAL(CAccHelperCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	LPDISPATCH onactivate;
	BOOL topmost;
	DWORD opacity;
	HWND assoc;
	~CAccHelperCtrl();

	DECLARE_OLECREATE_EX(CAccHelperCtrl)   // クラス ファクトリ と guid
	DECLARE_OLETYPELIB(CAccHelperCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAccHelperCtrl)    // プロパティ ページ ID
	DECLARE_OLECTLTYPE(CAccHelperCtrl)     // タイプ名とその他のステータス

// メッセージ マップ
	//{{AFX_MSG(CAccHelperCtrl)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//        この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ディスパッチ マップ
	//{{AFX_DISPATCH(CAccHelperCtrl)
	afx_msg long GetOpacity();
	afx_msg void SetOpacity(long nNewValue);
	afx_msg BOOL GetTopmost();
	afx_msg void SetTopmost(BOOL bNewValue);
	afx_msg void SetOnActivate(LPDISPATCH newValue);
	afx_msg long Init(LPCTSTR title);
	afx_msg void FlashWindow();
	afx_msg void Test(const VARIANT FAR& p1, const VARIANT FAR& p2, const VARIANT FAR& p3, const VARIANT FAR& p4);
	afx_msg long PlaySound(LPCTSTR src);
	afx_msg long GetVersion();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// イベント マップ
	//{{AFX_EVENT(CAccHelperCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// ディスパッチ と イベント ID
public:
	void FlashWindow2(int);
	HRESULT FireOnActivate(DWORD active);
	enum {
	//{{AFX_DISP_ID(CAccHelperCtrl)
	dispidOpacity = 1L,
	dispidTopmost = 2L,
	dispidOnActivate = 3L,
	dispidInit = 4L,
	dispidFlashWindow = 5L,
	dispidTest = 6L,
	dispidPlaySound = 7L,
	dispidGetVersion = 8L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED)
