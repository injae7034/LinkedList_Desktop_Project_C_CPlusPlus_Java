#include "TakingOutForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#pragma warning(disable:4996)

// TakingOutFormProc
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
	//1. 꺼내기 프레임 윈도우가 생성될 때
	WordCardBinder* wordCardBinder;
	HWND wordCardBinderForm;
	WordCard wordCard;
	WordCard* current;
	//1.1 단어카드철 프레임 윈도우를 찾는다.
	wordCardBinderForm = FindWindow("#32770", "단어카드철");
	//1.2 단어카드철 프레임 윈도우의 단어카드철에서 현재 단어카드의 위치를 알아낸다.
	wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
	//1.3 단어카드철 프레임 윈도우의 단어카드철에서 꺼낸다.
	wordCard = TakeOut(wordCardBinder, wordCardBinder->current);
	//1.4 꺼낸 단어카드를 출력한다.
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.spellings);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.partOfSpeech);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.meanings);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.example);
	//1.5 단어카드철 프레임 윈도우의 단어카드철에서 단어카드를 꺼낸 후에 단어카드가 남아 있으면
	current = wordCardBinder->current;
	if (current != NULL)
	{
		//1.5.1 단어카드철 프레임 윈도우에 현재 단어카드를 출력한다.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)current->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)current->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)current->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)current->word.example);
	}
	//1.6 단어카드철 프레임 윈도우의 단어카드철에서 단어카드를 꺼낸 후에 남아있는 단어카드가 없으면
	else
	{
		//1.6.1 단어카드철 프레임윈도우에 공란을 출력한다.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)"");
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0, (LPARAM)"");
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)"");
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)"");
	}

	return TRUE;
}

//OnClose
BOOL TakingOutForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//2. 닫기버튼을 클릭했을 때
	WordCardBinder* wordCardBinder;
	WordCard wordCard;
	WordCard* index;
	HWND wordCardBinderForm;
	int messageBoxbutton;

	//2.1 "끼우시겠습니까?" 메세지 박스를 출력한다.
	messageBoxbutton = MessageBox(hWnd, "끼우시겠습니까?", "질문", MB_YESNOCANCEL);
	//2.2 "예" 버튼을 클릭했을 때
	if (messageBoxbutton == IDYES)
	{
		//2.2.1 철자, 품사, 의미, 예시를 읽는다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_GETTEXT, (WPARAM)64,
			(LPARAM)wordCard.word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_GETTEXT, (WPARAM)8,
			(LPARAM)wordCard.word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_GETTEXT, (WPARAM)32,
			(LPARAM)wordCard.word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_GETTEXT, (WPARAM)128,
			(LPARAM)wordCard.word.example);
	    //2.2.2 단어카드철 프레임 윈도우를 찾는다.
		wordCardBinderForm = FindWindow("#32770", "단어카드철");
	    //2.2.3 단어카드철 츠레임 윈도우의 단어카드철에서 끼운다.
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		index = TakeIn(wordCardBinder, wordCard);
	    //2.2.4 단어카드철 프레임 윈도우에 끼울 단어를 출력한다.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)index->word.example);
	    //2.2.5 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	//2.3 "아니오" 버튼을 클릭했을 때
	else if (messageBoxbutton == IDNO)
	{
		//2.3.1 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}