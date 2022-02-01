#ifndef _VISITINGCARDBINDERFORM_H
#define _VISITINGCARDBINDERFORM_H
#include<afxwin.h>//CDialog 헤더파일
#include "resource.h"

class VisitingCardBinder;//주소는 전방선언 내용일 경우 #include해서 header파일 추가
class VisitingCardBinderForm :public CDialog
{
public:
	enum{IDD=IDD_VISITINGCARDBINDERFORM};
public:
	VisitingCardBinderForm(CWnd* parent = NULL);//생성자, NULL이 디폴트값
	virtual BOOL OnInitDialog();
public:
	VisitingCardBinder* visitingCardBinder;//주소, 전방선언이 필요함
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

