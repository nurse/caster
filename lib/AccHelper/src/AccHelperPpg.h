#if !defined(AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED_)
#define AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AccHelperPpg.h : CAccHelperPropPage �v���p�e�B �y�[�W �N���X�̐錾���s���܂�

////////////////////////////////////////////////////////////////////////////
// CAccHelperPropPage : ���̃N���X�̓���̒�`�Ɋւ��Ă� AccHelperPpg.cpp.cpp �t�@�C�����Q�Ƃ��Ă�������

class CAccHelperPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAccHelperPropPage)
	DECLARE_OLECREATE_EX(CAccHelperPropPage)

// �R���X�g���N�^
public:
	CAccHelperPropPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAccHelperPropPage)
	enum { IDD = IDD_PROPPAGE_ACCHELPER };
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o��ǉ����܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_DATA

// �C���v�������e�[�V����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ���b�Z�[�W �}�b�v
protected:
	//{{AFX_MSG(CAccHelperPropPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ACCHELPERPPG_H__D1C1294C_3665_403E_B24F_813554037006__INCLUDED)
