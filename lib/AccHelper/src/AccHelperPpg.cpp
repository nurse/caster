// AccHelperPpg.cpp : CAccHelperPropPage �v���p�e�B �y�[�W �N���X�̃C���v�������e�[�V����

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
// ���b�Z�[�W �}�b�v

BEGIN_MESSAGE_MAP(CAccHelperPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAccHelperPropPage)
	// ���� - ClassWizard �͂��̈ʒu�Ƀ��b�Z�[�W �}�b�v�̃G���g����ǉ��܂��͍폜���܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// �N���X �t�@�N�g�� �� guid �̏�����

IMPLEMENT_OLECREATE_EX(CAccHelperPropPage, "ACCHELPER.AccHelperPropPage.1",
	0xf8792e5b, 0xb1ad, 0x4e31, 0x9f, 0xaf, 0x1c, 0x18, 0x3c, 0xfb, 0x19, 0x37)


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::CAccHelperPropPageFactory::UpdateRegistry -
// CAccHelperPropPage �̃V�X�e�� ���W�X�g���̃G���g����ǉ��܂��͍폜���܂�

BOOL CAccHelperPropPage::CAccHelperPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACCHELPER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::CAccHelperPropPage - �R���X�g���N�^

CAccHelperPropPage::CAccHelperPropPage() :
	COlePropertyPage(IDD, IDS_ACCHELPER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAccHelperPropPage)
	// ����: ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage::DoDataExchange - �y�[�W�ƃv���p�e�B�̊ԂŃf�[�^�̌������s���܂�

void CAccHelperPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAccHelperPropPage)
	// ����: ClassWizard �͂��̈ʒu�� DDP�ADDX�ADDV �̌Ăяo���R�[�h��ǉ����܂�
	//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage ���b�Z�[�W �n���h��
