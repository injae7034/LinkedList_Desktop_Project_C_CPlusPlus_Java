#include "TakingOutForm.h"
#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "resource.h"
#include<afxwin.h>//CDialog�������


BEGIN_MESSAGE_MAP(TakingOutForm, CDialog)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TakingOutForm::TakingOutForm(CWnd* parent)
	:CDialog(TakingOutForm::IDD, parent)
{

}

//1. ������ �����찡 ������ ��
BOOL TakingOutForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 �ܾ�ī��ö ������ �����츦 ã�´�.
	WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "�ܾ�ī��ö");
	//1.2 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� ���� �ܾ�ī���� ��ġ�� �д´�.
	WordCard* current = wordCardBinderForm->wordCardBinder->GetCurrent();
	//1.3 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� ������.
	WordCard wordCard = wordCardBinderForm->wordCardBinder->TakeOut(current);
	//1.4 ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(wordCard.GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(wordCard.GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(wordCard.GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(wordCard.GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	//1.5 �ܾ�ī��ö ������ �������� �ܾ�ī��û�� �ܾ�ī�尡 ����������
	current = wordCardBinderForm->wordCardBinder->GetCurrent();
	if (current != NULL)
	{
		//1.5.1 �ܾ�ī��ö ������ �����쿡 ���� �ܾ�ī�带 ����Ѵ�.
		spellings = CString(current->GetSpellings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		partOfSpeech = CString(current->GetPartOfSpeech().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		meanings = CString(current->GetMeanings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
		example = CString(current->GetExample().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
	}
	//1.6 �ܾ�ī��ö ������ �������� �ܾ�ī��û�� �����ִ� �ܾ�ī�尡 ������
	else
	{
		//1.6.1 �ܾ�ī��ö ������ �����쿡 ������ ����Ѵ�.
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText("");
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText("");
	}
	return FALSE;
}

//2. �ݱ��ư�� Ŭ������ ��
void TakingOutForm::OnClose()
{
	//2.1 "����ðڽ��ϱ�?" �޼����ڽ��� ����Ѵ�.
	int messageBoxButton = MessageBox("����ðڽ��ϱ�?", "����", MB_YESNOCANCEL);
	//2.2 "��" ��ư�� Ŭ������ ��
	if (messageBoxButton == IDYES)
	{
		//2.2.1 �ܾ�ī���� ������ �д´�.
		CString spellings;
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->GetWindowText(spellings);
		CString partOfSpeech;
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->GetWindowText(partOfSpeech);
		CString meanings;
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->GetWindowText(meanings);
		CString example;
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->GetWindowText(example);
		//2.2.2 ���� ������ wordCard�� �����Ѵ�.
		WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
		//2.2.3 �ܾ�ī��ö ������ �����츦 ã�´�.
		WordCardBinderForm* wordCardBinderForm = (WordCardBinderForm*)CWnd::FindWindow("#32770", "�ܾ�ī��ö");
		//2.2.4 �ܾ�ī��ö ������ �������� �ܾ�ī��ö���� �����.
		WordCard* index = wordCardBinderForm->wordCardBinder->TakeIn(wordCard);
		//2.2.5 �ܾ�ī��ö ������ �����쿡 ���� �ܾ�ī�带 ����Ѵ�.
		spellings = CString(index->GetSpellings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		partOfSpeech = CString(index->GetPartOfSpeech().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		meanings = CString(index->GetMeanings().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_MEANINGS)->SetWindowText(meanings);
		example = CString(index->GetExample().c_str());
		wordCardBinderForm->GetDlgItem(IDC_STATIC_EDIIT_EXAMPLE)->SetWindowText(example);
		//2.2.6 �����츦 �ݴ´�.
		EndDialog(0);
	}
	//2.3 "�ƴϿ�"��ư�� Ŭ������ ��
	if (messageBoxButton == IDNO)
	{
		//2.3.1 �����츦 �ݴ´�.
		EndDialog(0);
	}
}