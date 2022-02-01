#ifndef _VISITINGCARDBINDERFORM_H
#define _VISITINGCARDBINDERFORM_H
#include<afxwin.h>//CDialog �������
#include "resource.h"

class VisitingCard;//�ּҴ� ���漱�� ������ ��� #include�ؼ� header���� �߰�// Insert���� VisitingCard*�� ���̱⶧���� ���漱�����־����!
class VisitingCardBinder;//�ּҴ� ���漱�� ������ ��� #include�ؼ� header���� �߰�
class VisitingCardBinderForm :public CDialog
{
public:
	enum{IDD=IDD_VISITINGCARDBINDERFORM};
public:
	VisitingCardBinderForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	void Load();
	void Save();
	void Insert(VisitingCard* index);
	void Delete(VisitingCard* index);
	CString GetCompanyCode();
	CString GetPersonalCode();
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

