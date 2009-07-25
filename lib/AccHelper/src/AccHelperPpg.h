#if !defined(AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED_)
#define AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AccHelperPpg.h : CAccHelperPropPage プロパティ ページ クラスの宣言を行います

////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage : このクラスの動作の定義に関しては AccHelperPpg.cpp.cpp ファイルを参照してください

class CAccHelperPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAccHelperPropPage)
	DECLARE_OLECREATE_EX(CAccHelperPropPage)

// コンストラクタ
public:
	CAccHelperPropPage();

// ダイアログ データ
	//{{AFX_DATA(CAccHelperPropPage)
	enum { IDD = IDD_PROPPAGE_ACCHELPER };
		// メモ - ClassWizard はこの位置にメンバを追加します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA

// インプリメンテーション
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// メッセージ マップ
protected:
	//{{AFX_MSG(CAccHelperPropPage)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します
		//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED)
