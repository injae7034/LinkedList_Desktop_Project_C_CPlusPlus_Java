#include "TakingInForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#pragma warning(disable:4996)

// TakingInFormProc
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

//OnInitDialog
BOOL TakingInForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. 끼우기 프레임 윈도우가 생성될 때
	TCHAR partOfSpeechs[][8] = {
		"명사",
		"대명사",
		"동사",
		"형용사",
		"부사",
		"전치사",
		"접속사",
		"감탄사"
	};
	Long i = 0;

	//1.1 품사 콤보박스에 항목들을 추가한다.
	while (i < sizeof(partOfSpeechs) / sizeof(partOfSpeechs[0]))
	{
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_PARTOFSPEECH), CB_ADDSTRING, 0, (LPARAM)partOfSpeechs[i]);
		i++;
	}
	return TRUE;
}

//OnCommand
BOOL TakingInForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_TAKEIN: ret = TakingInForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

// TakingInForm_OnTakeInButtonClicked
BOOL TakingInForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard wordCard;
	HWND wordCardBinderForm;
	WordCard* index;

	//2 끼우기 버튼을 클릭했을 때
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 철자, 품사, 의미, 예시를 읽는다.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_SPELLINGS), WM_GETTEXT, (WPARAM)64, 
			(LPARAM)wordCard.word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_PARTOFSPEECH), WM_GETTEXT, (WPARAM)8,
			(LPARAM)wordCard.word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_MEANINGS), WM_GETTEXT, (WPARAM)32,
			(LPARAM)wordCard.word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EXAMPLE), WM_GETTEXT, (WPARAM)128,
			(LPARAM)wordCard.word.example);
		//2.2 단어카드철 프레임 윈도우를 찾는다.
		wordCardBinderForm = FindWindow("#32770", "단어카드철");
		//2.3 단어카드철 프레임윈도우의 단어카드철에서 끼운다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		index = TakeIn(wordCardBinder, wordCard);
		//2.4 단어카드철 프레임 윈도우에 끼운 단어카드를 출력한다.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)index->word.example);
		//2.5 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}

//OnClose
BOOL TakingInForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. 닫기 버튼을 클릭했을 때
	//3.1 윈도우를 닫는다.
	EndDialog(hWnd, 0);
	return TRUE;
}