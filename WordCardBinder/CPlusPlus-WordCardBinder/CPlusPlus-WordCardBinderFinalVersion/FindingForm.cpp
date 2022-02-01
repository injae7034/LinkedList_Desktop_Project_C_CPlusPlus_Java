#include "FindingForm.h"
#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "WordCard.h"
#include "resource.h"
#include<afxwin.h>//CDialog �������

BEGIN_MESSAGE_MAP(FindingForm, CDialog)
	ON_BN_CLICKED(IDC_RADIO_SPELLINGS, OnSpellingsRadioButtonClicked)
	ON_BN_CLICKED(IDC_RADIO_MEANINGS, OnMeaningsRadioButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnFindButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSE, OnChooseButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnFirstButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnPreviousButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnNextButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnLastButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

FindingForm::FindingForm(CWnd* parent)
	:CDialog(FindingForm::IDD, parent)
{
	this->indexes = NULL;
	this->count = 0;
	this->current = 0;
}

//1. ã�� �����찡 ������ ��
BOOL FindingForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 ö�ڶ�����ư�� check�Ѵ�.
	((CButton*)GetDlgItem(IDC_RADIO_SPELLINGS))->SetCheck(BST_CHECKED);
	//1.2 �ǹ̶�����ư�� uncheck�Ѵ�.
	((CButton*)GetDlgItem(IDC_RADIO_MEANINGS))->SetCheck(BST_UNCHECKED);
	//1.3 ������.
	return FALSE;
}

//2. ö�ڶ��� ��ư�� Ŭ������ ��
void FindingForm::OnSpellingsRadioButtonClicked()
{
	//2.1 �ǹ̶��� ��ư�� uncheck�Ѵ�.
	((CButton*)GetDlgItem(IDC_RADIO_MEANINGS))->SetCheck(BST_UNCHECKED);
	//2.2 �ǹ̿���Ʈ�� �������� �����.
	GetDlgItem(IDC_EDIT_STATIC_MEANINGS)->SetWindowText("");
}

//3. �ǹ̶��� ��ư�� Ŭ������ ��
void FindingForm::OnMeaningsRadioButtonClicked()
{
	//3.1 ö�ڶ�����ư�� uncheck�Ѵ�.
	((CButton*)GetDlgItem(IDC_RADIO_SPELLINGS))->SetCheck(BST_UNCHECKED);
	//3.2 ö�ڿ���Ʈ�� �������� �����.
	GetDlgItem(IDC_EDIT_STATIC_SPELLINGS)->SetWindowText("");
}

//4. ã�� ��ư�� Ŭ������ ��
void FindingForm::OnFindButtonClicked()
{
	//4.1 �ܾ�ī��ö ������ �����츦 ã�´�.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "�ܾ�ī��ö");
	//�Ҵ�����
	//FindingForm�� ���� ���� ���¿��� ����ؼ� ã�� ��ư�� ���� ��� �޸� ������ ���� �� �ֱ� ������
	//ã���ư�� ���� �� ���� ������ indexes�� �Ҵ��������Ѽ� �޸� ������ ���ƾ���.
	if (this->indexes != NULL)
	{
		delete[]this->indexes;
	}
	//4.2 ���õ� ������ư�� �д´�.
	int spellingsChecked = ((CButton*)GetDlgItem(IDC_RADIO_SPELLINGS))->GetCheck();
	int meaningsChecked = ((CButton*)GetDlgItem(IDC_RADIO_MEANINGS))->GetCheck();
	//4.3 ö�ڶ�����ư�� ���õǾ� ������
	CString spellings;
	if (spellingsChecked == BST_CHECKED)
	{
		//4.3.1 ö�ڸ� �Է¹޴´�.
		GetDlgItem(IDC_EDIT_STATIC_SPELLINGS)->GetWindowText(spellings);
		//4.3.2 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� ö�ڷ� ã�´�.
		wordCardBinderForm->wordCardBinder->FindBySpellings((LPCTSTR)spellings, &this->indexes, &this->count);
	}
	//4.4 �ǹ̶�����ư�� ���õǾ� ������
	CString meanings;
	if (meaningsChecked == BST_CHECKED)
	{
		//4.4.1 �ǹ̸� �Է¹޴´�.
		GetDlgItem(IDC_EDIT_STATIC_MEANINGS)->GetWindowText(meanings);
		//4.4.2 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �ǹ̷� ã�´�.
		wordCardBinderForm->wordCardBinder->FindByMeanings((LPCTSTR)meanings, &this->indexes, &this->count);
	}
	//4.5 ã�� �ܾ ������
	if (this->count > 0)
	{
		//4.5.1 ã�� �ܾ�ī��� �߿��� ù��° �ܾ�ī�带 ����Ѵ�.
		this->current = 0;
		spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
		CString example = CString(this->indexes[this->current]->GetExample().c_str());
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
	}
	//4.6 ã�� �ܾ�尡 ������
	else
	{
		//4.6.1 ������ ����Ѵ�.
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText("");
	}
}

//5. �����ϱ� ��ư�� Ŭ������ ��
void FindingForm::OnChooseButtonClicked()
{
	//5.1 �ܾ�ī��ö ������ �����츦 ã�´�.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "�ܾ�ī��ö");
	//5.2 �ܾ�ī��ö ������ �����쿡 ������ �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(this->indexes[this->current]->GetExample().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
	//5.3 �ܾ�ī��ö ������ �������� �ܾ�ī��ö������ ���� �ܾ�ī�带 ������ �ܾ�ī��� �ٲ۴�.
	wordCardBinderForm->wordCardBinder->Move(this->indexes[this->current]);
	//5.4 �����츦 �ݴ´�.
	EndDialog(0);
}

//6.ó����ư�� Ŭ������ ��
void FindingForm::OnFirstButtonClicked()
{
	//6.1 ã�� �ܾ�ī��� �߿��� ù��° �ܾ�ī�带 ����Ѵ�.
	this->current = 0;
	CString spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(this->indexes[this->current]->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//7. ������ư�� Ŭ������ ��
void FindingForm::OnPreviousButtonClicked()
{
	//7.1 ã�� �ܾ�ī��� �߿��� ���� �ܾ�ī�带 ����Ѵ�.
	this->current--;
	if (this->current < 0)
	{
		this->current = 0;
	}
	CString spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(this->indexes[this->current]->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//8. ���� ��ư�� Ŭ������ ��
void FindingForm::OnNextButtonClicked()
{
	//8.1 ã�� �ܾ�ī��� �߿��� ���� �ܾ�ī�带 ����Ѵ�.
	this->current++;
	if (this->current >= this->count)
	{
		this->current = this->count - 1;
	}
	CString spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(this->indexes[this->current]->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//9. ��������ư�� Ŭ������ ��
void FindingForm::OnLastButtonClicked()
{
	//9.1 ã�� �ܾ�ī��� �߿��� ������ �ܾ�ī�带 ����Ѵ�.
	this->current = this->count - 1;
	CString spellings = CString(this->indexes[this->current]->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(this->indexes[this->current]->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(this->indexes[this->current]->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(this->indexes[this->current]->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//10. �ݱ��ư�� Ŭ������ ��
void FindingForm::OnClose()
{
	//10.1 �ܾ�ī�帵ũ �迭�� ���ش�.
	if (this->indexes != NULL)
	{
		delete[] this->indexes;
	}
	//10.2 �����츦 �ݴ´�.
	EndDialog(0);
}