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
	//1. 끼우기 프레임 윈도우가 생성될 때
	TCHAR positions[][8] = {
		"사원",
		"주임",
		"대리",
		"과장",
		"차장",
		"부장",
		"이사",
		"상무",
		"전무",
		"부사장",
		"사장"
	};
	TCHAR emailAddresses[][32] = {
		"naver.com",
		"gmail.com",
		"daum.com",
		"nate.com",
		"hanmail.com"
	};
	Long i = 0;

	//1.1 직책 콤보박스에 항목들들 추가한다.
	while (i < sizeof(positions) / sizeof(positions[0]))
	{
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_POSITION), CB_ADDSTRING, 0, (LPARAM)positions[i]);
		i++;
	}
	//1.2 이메일 콤보박스에 항목들을 추가한다.
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

	//2. 상호 에디트가 포커스를 잃을 때
	if (HIWORD(wParam) == EN_KILLFOCUS)
	{
		//2.1 상호명을 입력받는다.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_COMPANYNAME), WM_GETTEXT, (WPARAM)32, (LPARAM)companyName);
		//2.2 명함철 프레임 윈도우를 찾는다.
		visitingCardBinderForm = FindWindow("#32770", "명함철");
		//2.3 명함철 프레임 윈도우의 명함철에서 회사를 찾는다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
		index = FindByCompanyName(visitingCardBinder, companyName);
		//2.4 찾은 회사가 있는지 확인한다.
		if (index != NULL)
		{
			//2.5 찾은 회사의 주소, 전화번호, 팩스번호, URL을 출력한다.
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

	//3. 끼우기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//3.1 성명, 직책, 휴대폰번호, 이메일주소, 상호, 주소, 전화번호, 팩스번호, URL을 읽는다.
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
		//3.2 명함철 프레임 윈도우를 찾는다.
		visitingCardBinderForm = FindWindow("#32770", "명함철");
		//3.3 명함철 프레임 윈도우의 명함철에서 끼운다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(visitingCardBinderForm, GWL_USERDATA);
		index = TakeIn(visitingCardBinder, visitingCard);
		//3.4 명함철 프레임 윈도우의 명함에 끼운 명함을 출력한다.
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
		//3.5 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}

//TakingInForm_OnClose
BOOL TakingInForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//4. 닫기 버튼을 클릭했을 때
	//4.1 윈도우를 닫는다.
	EndDialog(hWnd, 0);
	return TRUE;
}