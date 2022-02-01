#include "FindingForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#pragma warning(disable:4996)

// FindingFormProc
BOOL CALLBACK FindingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (message)
	{
	case WM_INITDIALOG: ret = FindingForm_OnInitDialog(hWnd, wParam, lParam); break;
    case WM_COMMAND: ret = FindingForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_CLOSE: ret = FindingForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//OnInitDialog
BOOL FindingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//1. ã�� ������ �����찡 ������ ��
	//1.1 ö�� ������ư�� �����Ѵ�.
	SendMessage(GetDlgItem(hWnd, IDC_RADIO_SPELLINGS), BM_SETCHECK, BST_CHECKED, 0);
	SendMessage(GetDlgItem(hWnd, IDC_RADIO_MEANINGS), BM_SETCHECK, BST_UNCHECKED, 0);

	return TRUE;
}

//OnCommand
BOOL FindingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	BOOL ret;
	switch (LOWORD(wParam))
	{
	case IDC_RADIO_SPELLINGS: ret = FindingForm_OnSpellingsRadioButtonClicked(hWnd, wParam, lParam); break;
	case IDC_RADIO_MEANINGS: ret = FindingForm_OnMeaningsRadioButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIND: ret = FindingForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_CHOOSE: ret = FindingForm_OnChooseButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_FIRST: ret = FindingForm_OnFirstButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_PREVIOUS: ret = FindingForm_OnPreviousButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_NEXT: ret = FindingForm_OnNextButtonClicked(hWnd, wParam, lParam); break;
	case IDC_BUTTON_LAST: ret = FindingForm_OnLastButtonClicked(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

//FindingForm_OnSpellingsRadioButtonClicked
BOOL FindingForm_OnSpellingsRadioButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//2. ö�� ���� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//2.1 �ǹ̿���Ʈ�� �������� �����.
		SendMessage(GetDlgItem(hWnd, IDC_RADIO_MEANINGS), BM_SETCHECK, BST_UNCHECKED, 0);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_STATIC_MEANINGS), WM_SETTEXT, 0, (LPARAM)"");
	}
	return TRUE;
}

//FindingForm_OnMeaningsRadioButtonClicked
BOOL FindingForm_OnMeaningsRadioButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//3. �ǹ� ���� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//3.1 ö�ڿ���Ʈ�� �������� �����.
		SendMessage(GetDlgItem(hWnd, IDC_RADIO_SPELLINGS), BM_SETCHECK, BST_UNCHECKED, 0);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_STATIC_SPELLINGS), WM_SETTEXT, 0, (LPARAM)"");
	}
	return TRUE;
}

//FindingForm_OnFindButtonClicked
BOOL FindingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	TCHAR spellings[64];
	TCHAR meanings[32];
	WordCard* (*indexes) = NULL;
	Long count;
	Long current;
	HWND wordCardBinderForm;
	int spellingsChecked;
	int meaningsChecked;

	//4. ã�� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//4.1 �ܾ�ī��ö ������ �����츦 ã�´�.
		wordCardBinderForm = FindWindow("#32770", "�ܾ�ī��ö");
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		if (indexes != NULL)
		{
			free(indexes);
		}
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		//4.2 ���õ� ���� ��ư�� �д´�.
		spellingsChecked = (int)SendMessage(GetDlgItem(hWnd, IDC_RADIO_SPELLINGS), BM_GETCHECK, 0, 0);
		meaningsChecked = (int)SendMessage(GetDlgItem(hWnd, IDC_RADIO_MEANINGS), BM_GETCHECK, 0, 0);
		//4.3 ö�ڶ�����ư�� ���õǾ� ������
		if (spellingsChecked == BST_CHECKED)
		{
			//4.3.1 ö�ڸ� �Է¹޴´�.
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_STATIC_SPELLINGS), WM_GETTEXT, (WPARAM)64, (LPARAM)spellings);
			//4.3.2 �ܾ�ī��ö �������������� �ܾ�ī��ö���� ã�´�.
			FindBySpellings(wordCardBinder, spellings, &indexes, &count);
		}
		//4.4 �ǹ̶�����ư�� ���õǾ� ������
		else if (meaningsChecked == BST_CHECKED)
		{
			//4.4.1 �ǹ̸� �Է¹޴´�.
			SendMessage(GetDlgItem(hWnd, IDC_EDIT_STATIC_MEANINGS), WM_GETTEXT, (WPARAM)32, (LPARAM)meanings);
			//4.4.2 �ܾ�ī��ö ������������ �ܾ�ī��ö���� ã�´�.
			FindByMeanings(wordCardBinder, meanings, &indexes, &count);
		}
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)indexes);
		SetProp(hWnd, "FINDINGCOUNT", (HANDLE)count);
		//4.5 ã�� �ܾ�ī�尡 ������
		if (count > 0)
		{
			//4.5.1 ã�� �ܾ�ī��� �߿� ù��° �ܾ�ī�带 ����Ѵ�.
			current = 0;
			SetProp(hWnd, "CURRENTPOSITION", (HANDLE)current);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)
				indexes[current]->word.spellings);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0, (LPARAM)
				indexes[current]->word.partOfSpeech);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)
				indexes[current]->word.meanings);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)
				indexes[current]->word.example);
		}
		//4.6 ã�� �ܾ�ī�尡 ������
		else
		{
			//4.6.1 ������ ����Ѵ�.
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0, (LPARAM)"");
		}
	}
	return TRUE;
}

//FindingForm_OnChooseButtonClicked
BOOL FindingForm_OnChooseButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	WordCardBinder* wordCardBinder;
	WordCard* (*indexes);
	Long current;
	HWND wordCardBinderForm;

	//5. �����ϱ� ��ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//5.1 �ܾ�ī���� ��ġ�� �д´�.
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		current = (Long)GetProp(hWnd, "CURRENTPOSITION");
		//5.2 �ܾ�ī��ö ������ �����츦 ã�´�.
		wordCardBinderForm = FindWindow("#32770", "�ܾ�ī��ö");
		//5.3 �ܾ�ī��ö ������ �����쿡 ������ �ܾ�ī�带 ����Ѵ�.
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.spellings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.partOfSpeech);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.meanings);
		SendMessage(GetDlgItem(wordCardBinderForm, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.example);
		//5.4 �ܾ�ī��ö �������������� �ܾ�ī��ö���� ����ܾ�ī�带 ������ �ܾ�ī��� �ٲ۴�.
		wordCardBinder = (WordCardBinder*)GetWindowLong(wordCardBinderForm, GWL_USERDATA);
		WordCardBinder_Move(wordCardBinder, indexes[current]);
		//5.5 �����츦 �ݴ´�.
		if (indexes != NULL)
		{
			free(indexes);
		}
		RemoveProp(hWnd, "FINDINGCOUNT");
		RemoveProp(hWnd, "CURRENTPOSITION");
		EndDialog(hWnd, 0);
	}
	return TRUE;
}

//FindingForm_OnFirstButtonClicked
BOOL FindingForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Long current;
	WordCard* (*indexes);
	//6. ó����ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//6.1 ã�� �ܾ�ī�� �� ù��° �ܾ�ī�带 ����Ѵ�.
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		current = 0;
		SetProp(hWnd, "CURRENTPOSITION", (HANDLE)current);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.example);
	}
	return TRUE;
}

//FindingForm_OnPreviousButtonClicked
BOOL FindingForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Long current;
	WordCard* (*indexes);
	//7. ������ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//7.1 ã�� �ܾ�ī�� �� ���� �ܾ�ī���� ���� �ܾ�ī�带 ����Ѵ�.
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		current = (Long)GetProp(hWnd, "CURRENTPOSITION");
		current--;
		if (current < 0)
		{
			current = 0;
		}
		SetProp(hWnd, "CURRENTPOSITION", (HANDLE)current);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.example);
	}
	return TRUE;
}

// FindingForm_OnNextButtonClicked
BOOL FindingForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Long current;
	Long count;
	WordCard* (*indexes);
	//8. ������ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//8.1 ã�� �ܾ�ī�� �� ���� �ܾ�ī���� ���� �ܾ�ī�带 ����Ѵ�.
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		current = (Long)GetProp(hWnd, "CURRENTPOSITION");
		count = (Long)GetProp(hWnd, "FINDINGCOUNT");
		current++;
		if (current >= count)
		{
			current = count - 1;
		}
		SetProp(hWnd, "CURRENTPOSITION", (HANDLE)current);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.example);
	}
	return TRUE;
}

//FindingForm_OnLastButtonClicked
BOOL FindingForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Long current;
	Long count;
	WordCard* (*indexes);
	//9. ��������ư�� Ŭ������ ��
	if (HIWORD(wParam) == BN_CLICKED)
	{
		//9.1 ã�� �ܾ�ī�� �� ������ �ܾ�ī�带 ����Ѵ�.
		indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
		count = (Long)GetProp(hWnd, "FINDINGCOUNT");
		current = count - 1;
		SetProp(hWnd, "CURRENTPOSITION", (HANDLE)current);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_SPELLINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.spellings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_PARTOFSPEECH), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.partOfSpeech);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_MEANINGS), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.meanings);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_EDIT_EXAMPLE), WM_SETTEXT, 0,
			(LPARAM)indexes[current]->word.example);
	}
	return TRUE;
}

//OnClose
BOOL FindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//10. �ݱ� ��ư�� Ŭ������ ��
	WordCard* (*indexes);

	//10.1 �����츦 �ݴ´�.
	indexes = (WordCard * (*))GetWindowLong(hWnd, GWL_USERDATA);
	if (indexes != NULL)
	{
		free(indexes);
	}
	RemoveProp(hWnd, "FINDINGCOUNT");
	RemoveProp(hWnd, "CURRENTPOSITION");
	EndDialog(hWnd, 0);

	return TRUE;
}