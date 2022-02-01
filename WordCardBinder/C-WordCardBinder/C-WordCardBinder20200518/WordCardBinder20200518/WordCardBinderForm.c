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
	//1. �����찡 ������ ��
	WordCardBinder* wordCardBinder;
	WordCard* index;
	Long count;

	//1.1 �ܾ�ī��ö�� �����.
	wordCardBinder = (WordCardBinder*)malloc(sizeof(WordCardBinder));
	Create(wordCardBinder);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)wordCardBinder);
	//1.2 �ܾ�ī��ö�� �����Ѵ�.
	count = Load(wordCardBinder);
	//1.3 �ܾ�ī��ö�� ����� �ܾ�ī���� ������ 0���� ũ��
	if (count > 0)
	{
		//1.3.1 �ܾ�ī��ö���� ó������ �̵��Ѵ�.
		index = First(wordCardBinder);
		//1.3.2 �ܾ�ī��ö�� ù��° �ܾ�ī�带 ����Ѵ�.
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
	//2. ����� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 ����� ������ �����츦 ����Ѵ�.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGINFORM), NULL,
			TakingInFormProc);
	}
	return TRUE;
}

//WordCardBinderForm_OnFindButtonClicked
BOOL WordCardBinderForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. ã�� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//3.1 ã�������� �����츦 ����Ѵ�.
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), NULL,
			FindingFormProc);
	}
	return TRUE;
}

// WordCardBinderForm_OnTakeOutButtonClicked
BOOL WordCardBinderForm_OnTakeOutButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//4. ������ ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//4.1 ������ ������ �����츦 ����Ѵ�.
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
	//5. �����ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//5.1 �ܾ�ī��ö���� �����Ѵ�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(wordCardBinder);
		//5.2 �ܾ�ī��ö���� ó������ �̵��Ѵ�.
		index = First(wordCardBinder);
		//5.3 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
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

	//6. ó������ �̵��ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//6.1 �ܾ�ī��ö���� ó������ �̵��Ѵ�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = First(wordCardBinder);
		//6.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
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

	//7. �������� �̵��ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//7.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Previous(wordCardBinder);
		//7.2 �ܾ�ī��ö�� ����ܾ�ī�带 ����Ѵ�.
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
	//8. �������� �̵��ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//8.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Next(wordCardBinder);
		//8.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
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

	//9. ���������� �̵��ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//9.1 �ܾ�ī��ö���� ���������� �̵��Ѵ�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = Last(wordCardBinder);
		//9.2 �ܾ�ī��ö�� ����ܾ�ī�带 ����Ѵ�.
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
	//10. �ݱ� ��ư�� Ŭ������ ��
	WordCardBinder* wordCardBinder;

	wordCardBinder = (WordCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
	if (wordCardBinder != NULL)
	{
		//10.1 �ܾ�ī��ö�� �����Ѵ�.
		Save(wordCardBinder);
		//10.2 �ܾ�ī��ö�� ���ش�.
		Destroy(wordCardBinder);
		free(wordCardBinder);
	}
	//10.3 �����츦 �ݴ´�.
	EndDialog(hWnd, 0);
	
	return TRUE;
}
