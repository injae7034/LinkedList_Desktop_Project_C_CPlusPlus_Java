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
	//1. ����� ������ �����찡 ������ ��
	TCHAR partOfSpeechs[][8] = {
		"���",
		"����",
		"����",
		"�����",
		"�λ�",
		"��ġ��",
		"���ӻ�",
		"��ź��"
	};
	Long i = 0;

	//1.1 ǰ�� �޺��ڽ��� �׸���� �߰��Ѵ�.
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

	//2 ����� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 ö��, ǰ��, �ǹ�, ���ø� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_SPELLINGS), WM_GETTEXT, (WPARAM)64, 
			(LPARAM)wordCard.word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_COMBO_PARTOFSPEECH), WM_GETTEXT, (WPARAM)8,
			(LPARAM)wordCard.word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_MEANINGS), WM_GETTEXT, (WPARAM)32,
			(LPARAM)wordCard.word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EXAMPLE), WM_GETTEXT, (WPARAM)128,
			(LPARAM)wordCard.word.example);
		//2.2 �ܾ�ī��ö ������ �����츦 ã�´�.
		wordCardBinderForm = FindWindow("#32770", "�ܾ�ī��ö");
		//2.3 �ܾ�ī��ö �������������� �ܾ�ī��ö���� �����.
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		index = TakeIn(wordCardBinder, wordCard);
		//2.4 �ܾ�ī��ö ������ �����쿡 ���� �ܾ�ī�带 ����Ѵ�.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)index->word.example);
		//2.5 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}

//OnClose
BOOL TakingInForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. �ݱ� ��ư�� Ŭ������ ��
	//3.1 �����츦 �ݴ´�.
	EndDialog(hWnd, 0);
	return TRUE;
}