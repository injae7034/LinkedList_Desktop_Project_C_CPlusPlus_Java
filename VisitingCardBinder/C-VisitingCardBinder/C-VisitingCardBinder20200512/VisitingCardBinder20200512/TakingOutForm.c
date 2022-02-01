#include "TakingOutForm.h"
#include "VisitingCardBinder.h"
#include "resource.h"
#pragma warning(disable:4996)

BOOL CALLBACK TakingOutFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (message)
	{
	case WM_INITDIALOG: ret = TakingOutForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_CLOSE: ret = TakingOutForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//TakingOutForm_OnInitDialog
BOOL TakingOutForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. ������ ������ �����찡 ������ ��
	VisitingCardBinder* visitingCardBinder;
	HWND visitingCardBinderForm;
	VisitingCard visitingCard;
	VisitingCard* current;

	//1.1 ����ö ������ �����츦 ã�´�.
	visitingCardBinderForm = FindWindow("#32770", "����ö");
	//1.2 ����ö ������ �������� ����ö�ּ� ���� ������ ��ġ�� �д´�.
	visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
	//1.3 ����ö ������ �������� ����ö���� ������.
	visitingCard = TakeOut(visitingCardBinder, visitingCardBinder->current);
	//1.4 ���� ������ ����Ѵ�.
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
		(LPARAM)visitingCard.personal.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
		(LPARAM)visitingCard.personal.position);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
		(LPARAM)visitingCard.personal.cellularPhoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
		(LPARAM)visitingCard.personal.emailAddress);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
		(LPARAM)visitingCard.company.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
		(LPARAM)visitingCard.company.address);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
		(LPARAM)visitingCard.company.telephoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
		(LPARAM)visitingCard.company.faxNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
		(LPARAM)visitingCard.company.url);
	//1.5 ������ ���� �Ŀ� ����ö�� ������ ����������
	current = visitingCardBinder->current;
	if (current != NULL)
	{
		//1.5.1 ����ö ������ �����쿡 ����ö�� ���� ������ ����Ѵ�.
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)current->personal.name);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)current->personal.position);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)current->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)current->personal.emailAddress);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)current->company.name);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)current->company.address);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)current->company.telephoneNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)current->company.faxNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)current->company.url);
	}
	//1.6 ������ ���� �Ŀ� ����ö�� ������ �ϳ��� ������
	else
	{
		//1.6.1 ����ö ������ �����쿡 ������ ����Ѵ�.
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0, 
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)"");
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)"");
	}
	return TRUE;
}


//TakingOutForm_OnClose
BOOL TakingOutForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//2. �ݱ� ��ư�� Ŭ������ ��
	VisitingCardBinder* visitingCardBinder;
	HWND visitingCardBinderForm;
	VisitingCard visitingCard;
	VisitingCard* index;
	int messageBoxButton;

	//2.1 "����ðڽ��ϱ�?" �޼��� �ڽ��� ����Ѵ�.
	messageBoxButton = MessageBox(hWnd, "����ðڽ��ϱ�?", "����", MB_YESNOCANCEL);
	//2.2 "��" ��ư�� Ŭ������ ��
	if (messageBoxButton == IDYES)
	{
		//2.2.1 ����, ��å, �޴�����ȣ, �̸����ּ�, ��ȣ, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, URL�� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)11,
			(LPARAM)visitingCard.personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_GETTEXT, (WPARAM)8,
			(LPARAM)visitingCard.personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)32,
			(LPARAM)visitingCard.personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_GETTEXT, (WPARAM)32,
			(LPARAM)visitingCard.company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)64,
			(LPARAM)visitingCard.company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_GETTEXT, (WPARAM)32,
			(LPARAM)visitingCard.company.url);
		//2.2.2 ����ö ������ �����츦 ã�´�.
		visitingCardBinderForm = FindWindow("#32770", "����ö");
		//2.2.3 ����ö ������ �������� ����ö���� �����.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
		visitingCard.next = NULL;
		index = TakeIn(visitingCardBinder, visitingCard);
		//2.2.4 ����ö ������ ���ο쿡 ���� ������ ����Ѵ�.
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(visitingCardBinderForm, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
		//2.2.5 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	//2.3 "�ƴϿ�" ��ư�� Ŭ������ ��
	else if (messageBoxButton == IDNO)
	{
		//2.3.1 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}
