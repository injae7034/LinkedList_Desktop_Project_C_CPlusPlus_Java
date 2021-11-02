#ifndef _FINDINGFORM_H
#define _FINDINGFORM_H
#include<afxwin.h>//CDialog�������
#include "resource.h"//IDD_FINIDINGFORM�� ����ϱ� ���� �ʿ���

typedef signed long int Long;

class VisitingCard;//�ּҴ� ���漱�� ������ ��� #include�ؼ� header���� �߰�
class FindingForm :public CDialog
{
public:
	enum { IDD = IDD_FINDINGFORM };
public:
	FindingForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
protected://#
	afx_msg void OnFindButtonClicked();
	afx_msg void OnChooseButtonClicked();
	afx_msg void OnFirstButtonClicked();
	afx_msg void OnPreviousButtonClicked();
	afx_msg void OnNextButtonClicked();
	afx_msg void OnLastButtonClicked();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
private:
	VisitingCard* (*indexes);//�ּ��̹Ƿ� ���漱���� �ʿ���.
	Long count;
	Long current;
};
#endif // !_FINDINGFORM_H

