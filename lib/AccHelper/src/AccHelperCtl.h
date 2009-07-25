#if !defined(AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED_)
#define AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AccHelperCtl.h : CAccHelperCtrl ActiveX �R���g���[�� �N���X�̐錾

/////////////////////////////////////////////////////////////////////////////
// CAccHelperCtrl : ���̃N���X�̓���̒�`�Ɋւ��Ă� AccHelperCtl.cpp ���Q�Ƃ��Ă�������

class CAccHelperCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAccHelperCtrl)

// �R���X�g���N�^
public:
	CAccHelperCtrl();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CAccHelperCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	LPDISPATCH onactivate;
	BOOL topmost;
	DWORD opacity;
	HWND assoc;
	~CAccHelperCtrl();

	DECLARE_OLECREATE_EX(CAccHelperCtrl)   // �N���X �t�@�N�g�� �� guid
	DECLARE_OLETYPELIB(CAccHelperCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAccHelperCtrl)    // �v���p�e�B �y�[�W ID
	DECLARE_OLECTLTYPE(CAccHelperCtrl)     // �^�C�v���Ƃ��̑��̃X�e�[�^�X

// ���b�Z�[�W �}�b�v
	//{{AFX_MSG(CAccHelperCtrl)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂�
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������I
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// �f�B�X�p�b�` �}�b�v
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

// �C�x���g �}�b�v
	//{{AFX_EVENT(CAccHelperCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// �f�B�X�p�b�` �� �C�x���g ID
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ACCHELPERCTL_H__4FC246CB_F4CC_4888_AD7D_DCBAEB2A4222__INCLUDED)
