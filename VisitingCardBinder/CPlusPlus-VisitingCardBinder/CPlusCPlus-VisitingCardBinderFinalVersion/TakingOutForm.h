#ifndef _TAKINGOUTFORM_H
#define _TAKINGOUTFORM_H
#include<afxwin.h>//CDialog�������
#include "resource.h"

typedef signed long int Long;
class TakingOutForm :public CDialog
{
public:
	enum{IDD=IDD_TAKINGOUTFORM};
public:
	TakingOutForm(CWnd* parent = NULL);//������, NULL�� ����Ʈ��
	virtual BOOL OnInitDialog();
protected://#
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};
#endif // !_TAKINGOUTFORM_H

