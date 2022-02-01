#ifndef _WORDCARDBINDERFORM_H
#define _WORDCARDBINDERFORM_H
#include<afxwin.h>//CDialog �������
#include "resource.h"

class WordCard;//���漱��
class WordCardBinder;//���漱��
class WordCardBinderForm :public CDialog
{
public:
	enum { IDD = IDD_WORDCARDBINDERFORM };
public:
	WordCardBinderForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	void Load();
	void Save();
	void Insert(WordCard* index);
	void Delete(WordCard* index);
	CString GetCode();
	virtual BOOL OnInitDialog();
public://WordCardBinder�� WordCardBinderForm�� ���踦 �ΰ� �ֱ� ������ public��!
	WordCardBinder* wordCardBinder;//�ּҴ� ���漱���� �ʿ�, ������ ��� ��������� include�������. 

protected://#
	afx_msg void OnTakeInButtonClicked();
	afx_msg void OnFindButtonClicked();
	afx_msg void OnTakeOutButtonClicked();
	afx_msg void OnFirstButtonClicked();
	afx_msg void OnPreviousButtonClicked();
	afx_msg void OnNextButtonClicked();
	afx_msg void OnLastButtonClicked();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()

};

#endif // !_WORDCARDBINDERFORM_H
