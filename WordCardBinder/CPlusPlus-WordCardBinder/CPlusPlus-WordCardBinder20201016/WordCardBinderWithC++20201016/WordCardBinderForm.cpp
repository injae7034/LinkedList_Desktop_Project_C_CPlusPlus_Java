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
	this->wordCardBinder = NULL;//NULL�� �ʱ�ȭ��Ŵ.
}


//1. �ܾ�ī��ö �����찡 ������ ��
BOOL WordCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 �ܾ�ī��ö�� �����.(������ȣ��)
	this->wordCardBinder = new WordCardBinder;
	//1.2 ������.
	return FALSE;
}


//2. ������ư�� Ŭ������ ��
void WordCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 ����� ������ �����츦 �����Ѵ�.
	TakingInForm takingInForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "TakingInForm.h" ��������� �ʿ���.
	//2.2 ����� ������ �����츦 ����Ѵ�.
	takingInForm.DoModal();	
}

//3. ã���ư�� Ŭ������ ��
void WordCardBinderForm::OnFindButtonClicked()
{
	//3.1 ã�� ������ �����츦 �����Ѵ�.
	FindingForm findingForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "FindingForm.h" ��������� �ʿ���.
	//3.2 ã�� ������ �����츦 ����Ѵ�.
	findingForm.DoModal();
}

//4. �������ư�� Ŭ������ ��
void WordCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 ������ ������ �����츦 �����Ѵ�.
	TakingOutForm takingOutForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "TakingOutForm.h" ��������� �ʿ���.
	//4.2 ������ ������ �����츦 ����Ѵ�.
	takingOutForm.DoModal();
}

//5. �����ϱ� ��ư�� Ŭ������ ��

//6. ó����ư�� Ŭ������ ��
void WordCardBinderForm::OnFirstButtonClicked()
{
	//6.1 �ܾ�ī��ö���� ó������ �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->First();
	//6.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//7. ������ư�� Ŭ������ ��
void WordCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Previous();
	//7.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//8.������ư�� Ŭ������ ��
void WordCardBinderForm::OnNextButtonClicked()
{
	//8.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Next();
	//8.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//9. ��������ư�� Ŭ������ ��
void WordCardBinderForm::OnLastButtonClicked()
{
	//9.1 �ܾ�ī��ö���� ���������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Last();
	//9.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//10. �ݱ��ư�� Ŭ������ ��
void WordCardBinderForm::OnClose()
{
	//10.1 �ܾ�ī��ö�� �����.
	if (this->wordCardBinder != NULL)
	{
		delete this->wordCardBinder;
	}
	//10.2 �����츦 �ݴ´�.
	EndDialog(0);
}