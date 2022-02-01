#include "TakingInForm.h"
#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "WordCard.h"
#include "resource.h"
#include<afxwin.h>//CDialog 헤더파일

BEGIN_MESSAGE_MAP(TakingInForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TakingInForm::TakingInForm(CWnd* parent)
	:CDialog(TakingInForm::IDD, parent)
{

}

//1. 끼우기 윈도우가 생성될 때
BOOL TakingInForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 품사콤보박스에 항목들을 추가한다.
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
	while (i < sizeof(partOfSpeechs) / sizeof(partOfSpeechs[0]))
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_PARTOFSPEECH))->AddString(partOfSpeechs[i]);
		i++;
	}
	//1.2 끝내다.
	return FALSE;
}

//2. 끼우기버튼을 클릭했을 때
void TakingInForm::OnTakeInButtonClicked()
{
	//2.1 철자, 품사, 의미, 예시를 읽는다.
	CString spellings;
	GetDlgItem(IDC_EDIT_SPELLINGS)->GetWindowText(spellings);
	CString partOfSpeech;
	GetDlgItem(IDC_COMBO_PARTOFSPEECH)->GetWindowText(partOfSpeech);
	CString meanings;
	GetDlgItem(IDC_EDIT_MEANINGS)->GetWindowText(meanings);
	CString example;
	GetDlgItem(IDC_EDIT_EXAMPLE)->GetWindowText(example);
	//2.2 단어카드철 프레임 윈도우를 찾는다.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "단어카드철");
	//2.3 읽은 정보로 wordCard를 생성한다.
	WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
	//2.4 단어카드철 프레임 윈도우의 단어카드철에서 끼운다.
	WordCard* index = wordCardBinderForm->wordCardBinder->TakeIn(wordCard);
	//2.5 단어카드철 프레임 윈도우에 끼운 단어카드를 출력한다.
	spellings = CString(index->GetSpellings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	meanings = CString(index->GetMeanings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
	example = CString(index->GetExample().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	//2.6 윈도우를 닫는다.
	EndDialog(0);
}

//3. 닫기버튼을 클릭했을 때
void TakingInForm::OnClose()
{
	//3.1 윈도우를 닫는다.
	EndDialog(0);
}