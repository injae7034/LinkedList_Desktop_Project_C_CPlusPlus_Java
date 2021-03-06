#ifndef _WORDCARDBINDERFORM_H
#define _WORDCARDBINDERFORM_H
#include<afxwin.h>//CDialog 헤더파일
#include "resource.h"

class WordCardBinder;//전방선언
class WordCardBinderForm :public CDialog
{
public:
	enum { IDD = IDD_WORDCARDBINDERFORM };
public:
	WordCardBinderForm(CWnd* parent = NULL);//생성자, NULL이 디폴트값
	virtual BOOL OnInitDialog();
public://WordCardBinder는 WordCardBinderForm과 관계를 맺고 있기 때문에 public임!
	WordCardBinder* wordCardBinder;//주소는 전방선언이 필요, 내용일 경우 헤더파일을 include해줘야함. 

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
