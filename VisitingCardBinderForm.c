#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include "resource.h"
#include<stdlib.h>
#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmelLine, int nShowCmd)
{
	int response;
	response = DialogBox(hInstance, MAKEINTRESOURCE(IDD_VISITINGCARDBINDERFORM), NULL,
		VisitingCardBinderFormProc);
	return response;
}

BOOL CALLBACK VisitingCardBinderFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (message)
	{
	case WM_INITDIALOG: ret = VisitingCardBinderForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_COMMAND: ret = VisitingCardBinderForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_CLOSE: ret = VisitingCardBinderForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//VisitingCardBinderForm_OnInitDialog
BOOL VisitingCardBinderForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. 윈도우가 생성될 때
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;
	Long count;

	//1.1 명함철을 만든다.
	visitingCardBinder = (VisitingCardBinder*)malloc(sizeof(VisitingCardBinder));
	VisitingCardBinder_Create(visitingCardBinder);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)visitingCardBinder);
	//1.2 명함철에서 적재한다.
	count = Load(visitingCardBinder);
	//1.3 명함철에서 적재된 명함의 개수가 0개가 아니면
	if (count != 0)
	{
		//1.3.1 명함철에서 첫번째 위치로 이동한다.
		index = VisitingCardBinder_First(visitingCardBinder);
		//1.3.2 명함철의 첫번째 명함을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0, (LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0, (LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0, 
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0, (LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0, (LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0, 
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0, 
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0, (LPARAM)index->company.url);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnCommand
BOOL VisitingCardBinderForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_TAKEIN: ret = VisitingCardBinderForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIND: ret = VisitingCardBinderForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_TAKEOUT: ret = VisitingCardBinderForm_OnTakeOutButtonClicked(hWnd, wParam, lParam); break;
	//case IDC_BUTTON_ARRANGE: ret = VisitingCardBinderForm_OnArrangeButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIRST: ret = VisitingCardBinderForm_OnFirstButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_PREVIOUS: ret = VisitingCardBinderForm_OnPreviousButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_NEXT: ret = VisitingCardBinderForm_OnNextButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_LAST: ret = VisitingCardBinderForm_OnLastButtonClicked(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//VisitingCardBinderForm_OnTakeInButtonClicked
BOOL VisitingCardBinderForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//2. 끼우기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 끼우기 프레임 윈도우를 출력한다.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGINFORM), NULL,
			TakingInFormProc);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnFindButtonClicked
BOOL VisitingCardBinderForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. 찾기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 끼우기 프레임 윈도우를 출력한다.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), NULL,
			FindingFormProc);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnTakeOutButtonClicked
BOOL VisitingCardBinderForm_OnTakeOutButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//4. 꺼내기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 끼우기 프레임 윈도우를 출력한다.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGOUTFORM), NULL,
			TakingOutFormProc);
	}
	return TRUE;
}
#if 0
//VisitingCardBinderForm_OnArrangeButtonClicked
BOOL VisitingCardBinderForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;

	//5. 정리하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//5.1 명함철에서 정리한다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(visitingCardBinder);
		//5.2 명함철에서 처음 위치로 이동한다.
		index = First(visitingCardBinder);
		//5.3 명함철의 현재 명함을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
	}
	return TRUE;
}
#endif
//VisitingCardBinderForm_OnFirstButtonClicked
BOOL VisitingCardBinderForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;

	//6. 처음버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//6.1 명함철에서 처음 위치로 이동한다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = VisitingCardBinder_First(visitingCardBinder);
		//6.2 명함철의 현재 명함을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnPreviousButtonClicked
BOOL VisitingCardBinderForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;

	//7. 이전 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//7.1 명함철에서 이전으로 이동한다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = VisitingCardBinder_Previous(visitingCardBinder);
		//7.2 명함철의 현재 명함을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnNextButtonClicked
BOOL VisitingCardBinderForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;

	//8. 다음 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//8.1 명함철에서 다음위치로 이동한다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = VisitingCardBinder_Next(visitingCardBinder);
		//8.2 명함철의 현재 방향을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
	}
	return TRUE;
}

// VisitingCardBinderForm_OnLastButtonClicked
BOOL VisitingCardBinderForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	VisitingCardBinder* visitingCardBinder;
	VisitingCard* index;

	//8. 마지막 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//8.1 명함철에서 마지막 위치로 이동한다.
		visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = VisitingCardBinder_Last(visitingCardBinder);
		//8.2 명함철의 현재 명함을 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PERSONALNAME), WM_SETTEXT, 0,
			(LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_POSITION), WM_SETTEXT, 0,
			(LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_CELLULARPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EMAILADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_COMPANYNAME), WM_SETTEXT, 0,
			(LPARAM)index->company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_ADDRESS), WM_SETTEXT, 0,
			(LPARAM)index->company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_TELEPHONENUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_FAXNUMBER), WM_SETTEXT, 0,
			(LPARAM)index->company.faxNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_URL), WM_SETTEXT, 0,
			(LPARAM)index->company.url);
	}
	return TRUE;
}

//VisitingCardBinderForm_OnClose
BOOL VisitingCardBinderForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//10. 닫기 버튼을 클릭했을 떄
	VisitingCardBinder* visitingCardBinder;

	visitingCardBinder = (VisitingCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
	if (visitingCardBinder != NULL)
	{
		//10.1 명함철을 저장한다.
		Save(visitingCardBinder);
		//10.2 명함철을 없앤다.
		VisitingCardBinder_Destroy(visitingCardBinder);
		free(visitingCardBinder);
	}
	//10.3 윈도우를 닫는다.
	EndDialog(hWnd, 0);
	return TRUE;
}