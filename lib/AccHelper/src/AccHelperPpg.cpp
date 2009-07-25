// AccHelperPpg.cpp : CAccHelperPropPage プロパティ ページ クラスのインプリメンテーション

#include "stdafx.h"
#include "AccHelper.h"
#include "AccHelperPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAccHelperPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// メッセージ マップ

BEGIN_MESSAGE_MAP(CAccHelperPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAccHelperPropPage)
	// メモ - ClassWizard はこの位置にメッセージ マップのエントリを追加または削除します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// クラス ファクトリ と guid の初期化

IMPLEMENT_OLECREATE_EX(CAccHelperPropPage, "ACCHELPER.AccHelperPropPage.1",
	0xf8792e5b, 0xb1ad, 0x4e31, 0x9f, 0xaf, 0x1c, 0x18, 0x3c, 0xfb, 0x19, 0x37)


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::CAccHelperPropPageFactory::UpdateRegistry -
// CAccHelperPropPage のシステム レジストリのエントリを追加または削除します

BOOL CAccHelperPropPage::CAccHelperPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACCHELPER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::CAccHelperPropPage - コンストラクタ

CAccHelperPropPage::CAccHelperPropPage() :
	COlePropertyPage(IDD, IDS_ACCHELPER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAccHelperPropPage)
	// メモ: ClassWizard はこの位置にメンバの初期化処理を追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::DoDataExchange - ページとプロパティの間でデータの交換を行います

void CAccHelperPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAccHelperPropPage)
	// メモ: ClassWizard はこの位置に DDP、DDX、DDV の呼び出しコードを追加します
	//    この位置に生成されるコードを編集しないでください！
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage メッセージ ハンドラ
