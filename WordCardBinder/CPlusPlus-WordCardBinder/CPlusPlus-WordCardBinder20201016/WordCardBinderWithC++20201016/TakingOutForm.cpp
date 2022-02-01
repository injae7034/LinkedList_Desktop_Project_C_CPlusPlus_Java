#include "TakingOutForm.h"
#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#include<afxwin.h>//CDialog헤더파일


BEGIN_MESSAGE_MAP(TakingOutForm, CDialog)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TakingOutForm::TakingOutForm(CWnd* parent)
	:CDialog(TakingOutForm::IDD, parent)
{

}

//1. 꺼내기 윈도우가 생성될 때
BOOL TakingOutForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 단어카드철 프레임 윈도우를 찾는다.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "단어카드철");
	//1.2 단어카드철 프레임 윈도우의 단어카드철에서 현재 단어카드의 위치를 읽는다.
	WordCard* current = wordCardBinderForm->wordCardBinder->GetCurrent();
	//1.3 단어카드철 프레임 윈도우의 단어카드철에서 꺼낸다.
	WordCard wordCard = wordCardBinderForm->wordCardBinder->TakeOut(current);
	//1.4 꺼낸 단어카드를 출력한다.
	CString spellings = CString(wordCard.GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(wordCard.GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(wordCard.GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(wordCard.GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	//1.5 단어카드철 프레임 윈도우의 단어카드청에 단어카드가 남아있으면
	current = wordCardBinderForm->wordCardBinder->GetCurrent();
	if (current != NULL)
	{
		//1.5.1 단어카드철 프레임 윈도우에 현재 단어카드를 출력한다.
		spellings = CString(current->GetSpellings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		partOfSpeech = CString(current->GetPartOfSpeech().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		meanings = CString(current->GetMeanings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
		example = CString(current->GetExample().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	}
	//1.6 단어카드철 프레임 윈도우의 단어카드청에 남아있는 단어카드가 없으면
	else
	{
		//1.6.1 단어카드철 프레임 윈도우에 공란을 출력한다.
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText("");
	}
	return FALSE;
}

//2. 닫기버튼을 클릭했을 때
void TakingOutForm::OnClose()
{
	//2.1 "끼우시겠습니까?" 메세지박스를 출력한다.
	int messageBoxButton = MessageBox("끼우시겠습니까?", "질문", MB_YESNOCANCEL);
	//2.2 "예" 버튼을 클릭했을 때
	if (messageBoxButton == IDYES)
	{
		//2.2.1 단어카드의 정보를 읽는다.
		CString spellings;
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->GetWindowText(spellings);
		CString partOfSpeech;
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->GetWindowText(partOfSpeech);
		CString meanings;
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->GetWindowText(meanings);
		CString example;
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->GetWindowText(example);
		//2.2.2 읽은 정보로 wordCard를 생성한다.
		WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
		//2.2.3 단어카드철 프레임 윈도우를 찾는다.
		WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "단어카드철");
		//2.2.4 단어카드철 프레임 윈도우의 단어카드철에서 끼운다.
		WordCard* index = wordCardBinderForm->wordCardBinder->TakeIn(wordCard);
		//2.2.5 단어카드철 프레임 윈도우에 끼운 단어카드를 출력한다.
		spellings = CString(index->GetSpellings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		partOfSpeech = CString(index->GetPartOfSpeech().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		meanings = CString(index->GetMeanings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
		example = CString(index->GetExample().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
		//2.2.6 윈도우를 닫는다.
		EndDialog(0);
	}
	//2.3 "아니오"버튼을 클릭했을 때
	if (messageBoxButton == IDNO)
	{
		//2.3.1 윈도우를 닫는다.
		EndDialog(0);
	}
}