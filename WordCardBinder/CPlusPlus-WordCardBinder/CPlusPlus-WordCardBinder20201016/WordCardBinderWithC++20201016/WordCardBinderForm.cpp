#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"

BEGIN_MESSAGE_MAP(WordCardBinderForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnFindButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_TAKEOUT, OnTakeOutButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnFirstButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnPreviousButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnNextButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnLastButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

	WordCardBinderForm::WordCardBinderForm(CWnd* parent)
	:CDialog(WordCardBinderForm::IDD, parent)
{
	this->wordCardBinder = NULL;//NULL로 초기화시킴.
}


//1. 단어카드철 윈도우가 생성될 때
BOOL WordCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 단어카드철을 만든다.(생성자호출)
	this->wordCardBinder = new WordCardBinder;
	//1.2 끝내다.
	return FALSE;
}


//2. 끼우기버튼을 클릭했을 때
void WordCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 끼우기 프레임 윈도우를 생성한다.
	TakingInForm takingInForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "TakingInForm.h" 헤더파일이 필요함.
	//2.2 끼우기 프레임 윈도우를 출력한다.
	takingInForm.DoModal();	
}

//3. 찾기버튼을 클릭했을 때
void WordCardBinderForm::OnFindButtonClicked()
{
	//3.1 찾기 프레임 윈도우를 생성한다.
	FindingForm findingForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "FindingForm.h" 헤더파일이 필요함.
	//3.2 찾기 프레임 윈도우를 출력한다.
	findingForm.DoModal();
}

//4. 꺼내기버튼을 클릭했을 때
void WordCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 꺼내기 프레임 윈도우를 생성한다.
	TakingOutForm takingOutForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "TakingOutForm.h" 헤더파일이 필요함.
	//4.2 꺼내기 프레임 윈도우를 출력한다.
	takingOutForm.DoModal();
}

//5. 정리하기 버튼을 클릭했을 때

//6. 처음버튼을 클릭했을 때
void WordCardBinderForm::OnFirstButtonClicked()
{
	//6.1 단어카드철에서 처음으로 이동한다.
	WordCard* index = this->wordCardBinder->First();
	//6.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//7. 이전버튼을 클릭했을 때
void WordCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 단어카드철에서 이전으로 이동한다.
	WordCard* index = this->wordCardBinder->Previous();
	//7.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//8.다음버튼을 클릭했을 때
void WordCardBinderForm::OnNextButtonClicked()
{
	//8.1 단어카드철에서 다음으로 이동한다.
	WordCard* index = this->wordCardBinder->Next();
	//8.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//9. 마지막버튼을 클릭했을 때
void WordCardBinderForm::OnLastButtonClicked()
{
	//9.1 단어카드철에서 마지막으로 이동한다.
	WordCard* index = this->wordCardBinder->Last();
	//9.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//10. 닫기버튼을 클릭했을 때
void WordCardBinderForm::OnClose()
{
	//10.1 단어카드철을 지운다.
	if (this->wordCardBinder != NULL)
	{
		delete this->wordCardBinder;
	}
	//10.2 윈도우를 닫는다.
	EndDialog(0);
}