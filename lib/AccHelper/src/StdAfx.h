#if !defined(AFX_STDAFX_H__41DA4056_C1F9_4AF4_9A59_35F47008AEDD__INCLUDED_)
#define AFX_STDAFX_H__41DA4056_C1F9_4AF4_9A59_35F47008AEDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : 標準のシステム インクルード ファイル、
//            または参照回数が多く、かつあまり変更されない
//            プロジェクト専用のインクルード ファイルを記述します。

#define	WINVER			0x500
#define	_WIN32_WINNT	0x500
#define _WIN32_IE 0x0500
//#define VC_EXTRALEAN	// Windows ヘッダーから使用されていない部分を除外 

#include <afxctl.h>	// MFC の ActiveX  コントロール
#include <afxext.h>	// MFC の拡張部分
#include <afxdtctl.h>	// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>	// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <windows.h>
#include <mmsystem.h>
#include <shellapi.h>

// MFC のデータベース クラスを使用しない場合は、以下の 2 行のインクルード
// ファイルの記述を削除してください。
//#include <afxdb.h>	// MFC のデータベース クラス
//#include <afxdao.h>	// MFC の DAO データベース クラス

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_STDAFX_H__41DA4056_C1F9_4AF4_9A59_35F47008AEDD__INCLUDED_)
