#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include<stdlib.h>//malloc, free
#pragma warning(disable:4996)

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmelLine, int nShowCmd)
{
	int response;

	response = DialogBox(hInstance, MAKEINTRESOURCE(IDD_WORDCARDBINDERFORM), NULL, WordCardBinderFormProc);

	return response;
}

// WordCardBinderFormProc
BOOL CALLBACK WordCardBinderFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (message)
	{
	case WM_INITDIALOG: ret = WordCardBinderForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_COMMAND: ret = WordCardBinderForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_CLOSE: ret = WordCardBinderForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//OnInitDialog
BOOL WordCardBinderForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. 윈도우가 생성될 때
	WordCardBinder* wordCardBinder;
	WordCard* index;
	Long count;

	//1.1 단어카드철을 만든다.
	wordCardBinder = (WordCardBinder*)malloc(sizeof(WordCardBinder));
	Create(wordCardBinder);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)wordCardBinder);
	//1.2 단어카드철에 적재한다.
	count = Load(wordCardBinder);
	//1.3 단어카드철에 적재된 단어카드의 개수가 0보다 크면
	if (count > 0)
	{
		//1.3.1 단어카드철에서 처음으로 이동한다.
		index = First(wordCardBinder);
		//1.3.2 단어카드철의 첫번째 단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;
}

//OnCommand
BOOL WordCardBinderForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_TAKEIN: ret = WordCardBinderForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIND: ret = WordCardBinderForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_TAKEOUT: ret = WordCardBinderForm_OnTakeOutButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_ARRANGE: ret = WordCardBinderForm_OnArrangeButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIRST: ret = WordCardBinderForm_OnFirstButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_PREVIOUS: ret = WordCardBinderForm_OnPreviousButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_NEXT: ret = WordCardBinderForm_OnNextButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_LAST: ret = WordCardBinderForm_OnLastButtonClicked(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

// WordCardBinderForm_OnTakeInButtonClicked
BOOL WordCardBinderForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
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

//WordCardBinderForm_OnFindButtonClicked
BOOL WordCardBinderForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. 찾기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//3.1 찾기프레임 윈도우를 출력한다.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), NULL,
			FindingFormProc);
	}
	return TRUE;
}

// WordCardBinderForm_OnTakeOutButtonClicked
BOOL WordCardBinderForm_OnTakeOutButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//4. 꺼내기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//4.1 꺼내기 프레임 윈도우를 출력한다.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGOUTFORM), NULL,
			TakingOutFormProc);
	}
	return TRUE;
}

//WordCardBinderForm_OnArrangeButtonClicked
BOOL WordCardBinderForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* index;
	//5. 정리하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//5.1 단어카드철에서 정리한다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(wordCardBinder);
		//5.2 단어카드철에서 처음으로 이동한다.
		index = First(wordCardBinder);
		//5.3 단어카드철의 현재 단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;
}

//WordCardBinderForm_OnFirstButtonClicked
BOOL WordCardBinderForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* index;

	//6. 처음으로 이동하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//6.1 단어카드철에서 처음으로 이동한다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = First(wordCardBinder);
		//6.2 단어카드철의 현재 단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0, 
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;	
}

// WordCardBinderForm_OnPreviousButtonClicked
BOOL WordCardBinderForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* index;

	//7. 이전으로 이동하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//7.1 단어카드철에서 이전으로 이동한다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Previous(wordCardBinder);
		//7.2 단어카드철의 현재단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;
}

// WordCardBinderForm_OnNextButtonClicked
BOOL WordCardBinderForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* index;
	//8. 다음으로 이동하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//8.1 단어카드철에서 다음으로 이동한다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Next(wordCardBinder);
		//8.2 단어카드철의 현재 단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;
}

//WordCardBinderForm_OnLastButtonClicked
BOOL WordCardBinderForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* index;

	//9. 마지막으로 이동하기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//9.1 단어카드철에서 마지막으로 이동한다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Last(wordCardBinder);
		//9.2 단어카드철의 현재단어카드를 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)index->word.example);
	}
	return TRUE;
}

//OnClose
BOOL WordCardBinderForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//10. 닫기 버튼을 클릭했을 때
	WordCardBinder* wordCardBinder;

	wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
	if (wordCardBinder != NULL)
	{
		//10.1 단어카드철을 저장한다.
		Save(wordCardBinder);
		//10.2 단어카드철을 없앤다.
		Destroy(wordCardBinder);
		free(wordCardBinder);
	}
	//10.3 윈도우를 닫는다.
	EndDialog(hWnd, 0);
	
	return TRUE;
}
