#include "TakingInForm.h"
#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "WordCard.h"
#include "resource.h"
#include<afxwin.h>//CDialog �������

BEGIN_MESSAGE_MAP(TakingInForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TakingInForm::TakingInForm(CWnd* parent)
	:CDialog(TakingInForm::IDD, parent)
{

}

//1. ����� �����찡 ������ ��
BOOL TakingInForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 ǰ���޺��ڽ��� �׸���� �߰��Ѵ�.
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
	while (i < sizeof(partOfSpeechs) / sizeof(partOfSpeechs[0]))
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_PARTOFSPEECH))->AddString(partOfSpeechs[i]);
		i++;
	}
	//1.2 ������.
	return FALSE;
}

//2. ������ư�� Ŭ������ ��
void TakingInForm::OnTakeInButtonClicked()
{
	//2.1 ö��, ǰ��, �ǹ�, ���ø� �д´�.
	CString spellings;
	GetDlgItem(IDC_EDIT_SPELLINGS)->GetWindowText(spellings);
	CString partOfSpeech;
	GetDlgItem(IDC_COMBO_PARTOFSPEECH)->GetWindowText(partOfSpeech);
	CString meanings;
	GetDlgItem(IDC_EDIT_MEANINGS)->GetWindowText(meanings);
	CString example;
	GetDlgItem(IDC_EDIT_EXAMPLE)->GetWindowText(example);
	//2.2 �ܾ�ī��ö ������ �����츦 ã�´�.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "�ܾ�ī��ö");
	//2.3 ���� ������ wordCard�� �����Ѵ�.
	WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
	//2.4 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �����.
	WordCard* index = wordCardBinderForm->wordCardBinder->TakeIn(wordCard);
	//2.5 �ܾ�ī��ö ������ �����쿡 ���� �ܾ�ī�带 ����Ѵ�.
	spellings = CString(index->GetSpellings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	meanings = CString(index->GetMeanings().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
	example = CString(index->GetExample().c_str());
	wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	//2.6 �����츦 �ݴ´�.
	EndDialog(0);
}

//3. �ݱ��ư�� Ŭ������ ��
void TakingInForm::OnClose()
{
	//3.1 �����츦 �ݴ´�.
	EndDialog(0);
}