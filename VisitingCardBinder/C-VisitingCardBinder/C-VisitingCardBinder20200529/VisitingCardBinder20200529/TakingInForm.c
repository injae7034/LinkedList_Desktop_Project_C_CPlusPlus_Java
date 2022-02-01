#include "TakingInForm.h"
#include "VisitingCardBinder.h"
#include "resource.h"
#include<stdio.h>//sprintf
#pragma warning(disable:4996)

//TakingInFormProc
BOOL CALLBACK TakingInFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (message)
	{
	case WM_INITDIALOG: ret = TakingInForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_COMMAND: ret = TakingInForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_CLOSE: ret = TakingInForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//TakingInForm_OnInitDialog
BOOL TakingInForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. ����� ������ �����찡 ������ ��
	TCHAR positions[][8] = {
		"���",
		"����",
		"�븮",
		"����",
		"����",
		"����",
		"�̻�",
		"��",
		"����",
		"�λ���",
		"����"
	};
	TCHAR emailAddresses[][32] = {
		"naver.com",
		"gmail.com",
		"daum.com",
		"nate.com",
		"hanmail.com"
	};
	Long i = 0;

	//1.1 ��å �޺��ڽ��� �׸��� �߰��Ѵ�.
	while (i < sizeof(positions) / sizeof(positions[0]))
	{
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_POSITION), CB_ADDSTRING, 0, (LPARAM)positions[i]);
		i++;
	}
	//1.2 �̸��� �޺��ڽ��� �׸���� �߰��Ѵ�.
	i = 0;
	while (i < sizeof(emailAddresses) / sizeof(emailAddresses[0]))
	{
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_EMAILADDRESS), CB_ADDSTRING, 0, (LPARAM)emailAddresses[i]);
		i++;
	}
	return TRUE;
}

//TakingInForm_OnCommand
BOOL TakingInForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_TAKEIN: ret = TakingInForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
	case IDC_EDIT_COMPANYNAME: ret = TakingInForm_OnCompanyNameKillFocus(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//TakingInForm_OnCompanyNameKillFocus
BOOL TakingInForm_OnCompanyNameKillFocus(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	TCHAR companyName[32];
	VisitingCard* index;
	HWND visitingCardBinderForm;

	//2. ��ȣ ����Ʈ�� ��Ŀ���� ���� ��
	if (HIWORD(wParam) == EN_KILLFOCUS)
	{
		//2.1 ��ȣ���� �Է¹޴´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_COMPANYNAME), WM_GETTEXT, (WPARAM)32, (LPARAM)companyName);
		//2.2 ����ö ������ �����츦 ã�´�.
		visitingCardBinderForm = FindWindow("#32770", "����ö");
		//2.3 ����ö ������ �������� ����ö���� ȸ�縦 ã�´�.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
		index = FindByCompanyName(visitingCardBinder, companyName);
		//2.4 ã�� ȸ�簡 �ִ��� Ȯ���Ѵ�.
		if (index != NULL)
		{
			//2.5 ã�� ȸ���� �ּ�, ��ȭ��ȣ, �ѽ���ȣ, URL�� ����Ѵ�.
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_SETTEXT, 0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0, 
				(LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_FAXNUMBER), WM_SETTEXT, 0, (LPARAM)index->company.faxNumber);
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_URL), WM_SETTEXT, 0, (LPARAM)index->company.url);
		}
		return TRUE;
	}
}

//TakingInForm_OnTakeInButtonClicked
BOOL TakingInForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard visitingCard;
	HWND visitingCardBinderForm;
	VisitingCard* index;
	char emailAddressDomain[12];

	//3. ����� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//3.1 ����, ��å, �޴�����ȣ, �̸����ּ�, ��ȣ, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, URL�� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)11,
			(LPARAM)visitingCard.personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_POSITION), WM_GETTEXT, (WPARAM)8,
			(LPARAM)visitingCard.personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_CELLULARPHONENUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)20,
			(LPARAM)visitingCard.personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_EMAILADDRESS), WM_GETTEXT, (WPARAM)12,
			(LPARAM)emailAddressDomain);
		sprintf(visitingCard.personal.emailAddress, "%s@%s", visitingCard.personal.emailAddress,
			emailAddressDomain);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_COMPANYNAME), WM_GETTEXT, (WPARAM)32,
			(LPARAM)visitingCard.company.name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)64,
			(LPARAM)visitingCard.company.address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_FAXNUMBER), WM_GETTEXT, (WPARAM)12,
			(LPARAM)visitingCard.company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_URL), WM_GETTEXT, (WPARAM)32,
			(LPARAM)visitingCard.company.url);
		//3.2 ����ö ������ �����츦 ã�´�.
		visitingCardBinderForm = FindWindow("#32770", "����ö");
		//3.3 ����ö ������ �������� ����ö���� �����.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
		index = TakeIn(visitingCardBinder, visitingCard);
		//3.4 ����ö ������ �������� ���Կ� ���� ������ ����Ѵ�.
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
		//3.5 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}

//TakingInForm_OnClose
BOOL TakingInForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//4. �ݱ� ��ư�� Ŭ������ ��
	//4.1 �����츦 �ݴ´�.
	EndDialog(hWnd, 0);
	return TRUE;
}