#ifndef _FINDINGFORM_H
#define _FINDINGFORM_H
#include<afxwin.h>//CDialog�������
#include "resource.h"//IDD_FINDINGFORM

typedef signed long int Long;

class WordCard;//�ּҰ� ���� ��� ���漱��, ������ ���� ��� #include�ؼ� ������� �߰�
class FindingForm :public CDialog
{
public:
	enum { IDD = IDD_FINDINGFORM };
public:
	FindingForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	virtual BOOL OnInitDialog();
protected://#
	afx_msg void OnSpellingsRadioButtonClicked();
	afx_msg void OnMeaningsRadioButtonClicked();
	afx_msg void OnFindButtonClicked();
	afx_msg void OnChooseButtonClicked();
	afx_msg void OnFirstButtonClicked();
	afx_msg void OnPreviousButtonClicked();
	afx_msg void OnNextButtonClicked();
	afx_msg void OnLastButtonClicked();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
private:
	WordCard* (*indexes);//�ּ��̹Ƿ� ���漱���� �ʿ���.
	Long count;
	Long current;
};

#endif // !_FINDINGFORM_H
