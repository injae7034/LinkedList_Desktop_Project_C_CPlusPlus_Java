#ifndef _TAKINGINFORM_H
#define _TAKINGINFORM_H
#include<afxwin.h>//CDialog �������
#include "resource.h"//IDD_TAKINGINFORM������ �ʿ���

class TakingInForm :public CDialog
{
public:
	enum{IDD=IDD_TAKINGINFORM};
public:
	TakingInForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	virtual BOOL OnInitDialog();
protected://#
	afx_msg void OnTakeInButtonClicked();
	afx_msg void OnCompanyNameKillFocus();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};
#endif // !_TAKINGINFORM_H

