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
	//1. ������ ������ �����찡 ������ ��
	WordCardBinder* wordCardBinder;
	HWND wordCardBinderForm;
	WordCard wordCard;
	WordCard* current;
	//1.1 �ܾ�ī��ö ������ �����츦 ã�´�.
	wordCardBinderForm = FindWindow("#32770", "�ܾ�ī��ö");
	//1.2 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� ���� �ܾ�ī���� ��ġ�� �˾Ƴ���.
	wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
	//1.3 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� ������.
	wordCard = TakeOut(wordCardBinder, wordCardBinder->current);
	//1.4 ���� �ܾ�ī�带 ����Ѵ�.
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.spellings);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.partOfSpeech);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.meanings);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
		(LPARAM)wordCard.word.example);
	//1.5 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �ܾ�ī�带 ���� �Ŀ� �ܾ�ī�尡 ���� ������
	current = wordCardBinder->current;
	if (current != NULL)
	{
		//1.5.1 �ܾ�ī��ö ������ �����쿡 ���� �ܾ�ī�带 ����Ѵ�.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)current->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)current->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)current->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)current->word.example);
	}
	//1.6 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �ܾ�ī�带 ���� �Ŀ� �����ִ� �ܾ�ī�尡 ������
	else
	{
		//1.6.1 �ܾ�ī��ö �����������쿡 ������ ����Ѵ�.
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
	//2. �ݱ��ư�� Ŭ������ ��
	WordCardBinder* wordCardBinder;
	WordCard wordCard;
	WordCard* index;
	HWND wordCardBinderForm;
	int messageBoxbutton;

	//2.1 "����ðڽ��ϱ�?" �޼��� �ڽ��� ����Ѵ�.
	messageBoxbutton = MessageBox(hWnd, "����ðڽ��ϱ�?", "����", MB_YESNOCANCEL);
	//2.2 "��" ��ư�� Ŭ������ ��
	if (messageBoxbutton == IDYES)
	{
		//2.2.1 ö��, ǰ��, �ǹ�, ���ø� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_GETTEXT, (WPARAM)64,
			(LPARAM)wordCard.word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_GETTEXT, (WPARAM)8,
			(LPARAM)wordCard.word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_GETTEXT, (WPARAM)32,
			(LPARAM)wordCard.word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_GETTEXT, (WPARAM)128,
			(LPARAM)wordCard.word.example);
	    //2.2.2 �ܾ�ī��ö ������ �����츦 ã�´�.
		wordCardBinderForm = FindWindow("#32770", "�ܾ�ī��ö");
	    //2.2.3 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �����.
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		index = TakeIn(wordCardBinder, wordCard);
	    //2.2.4 �ܾ�ī��ö ������ �����쿡 ���� �ܾ ����Ѵ�.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)index->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)index->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)index->word.example);
	    //2.2.5 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	//2.3 "�ƴϿ�" ��ư�� Ŭ������ ��
	else if (messageBoxbutton == IDNO)
	{
		//2.3.1 �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return TRUE;
}