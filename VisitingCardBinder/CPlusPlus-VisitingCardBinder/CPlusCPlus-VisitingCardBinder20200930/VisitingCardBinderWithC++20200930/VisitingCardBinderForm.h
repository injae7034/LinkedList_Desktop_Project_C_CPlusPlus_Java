#ifndef _VISITINGCARDBINDERFORM_H
#define _VISITINGCARDBINDERFORM_H
#include<afxwin.h>//CDialog �������
#include "resource.h"

class VisitingCardBinder;//�ּҴ� ���漱�� ������ ��� #include�ؼ� header���� �߰�
class VisitingCardBinderForm :public CDialog
{
public:
	enum{IDD=IDD_VISITINGCARDBINDERFORM};
public:
	VisitingCardBinderForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	virtual BOOL OnInitDialog();
public:
	VisitingCardBinder* visitingCardBinder;//�ּ�, ���漱���� �ʿ���
protected://#
	afx_msg void OnTakeInButtonClicked();
	afx_msg void OnFindButtonClicked();
	afx_msg void OnTakeOutButtonClicked();
	afx_msg void OnFirstButtonClicked();
	afx_msg void OnPreviousButtonClicked();
	afx_msg void OnNexttButtonClicked();
	afx_msg void OnLastButtonClicked();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};
#endif // !_VISITINGCARDBINDERFORM_H

