#include "TakingInForm.h"
#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "resource.h"
#include<afxwin.h>//CDialog �������

BEGIN_MESSAGE_MAP(TakingInForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_EN_KILLFOCUS(IDC_EDIT_COMPANYNAME, OnCompanyNameKillFocus)
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
	//1.1 ��å�޺��ڽ��� �׸���� �߰��Ѵ�.
	TCHAR positions[][8] = {
		"���",
		"����",
		"�븮",
		"����",
		"����",
		"����",
		"�̻�",
		"��",
		"����",
		"�λ���",
		"����"
	};
	Long i = 0;
	while (i < sizeof(positions) / sizeof(positions[0]))
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_POSITION))->AddString(positions[i]);
		i++;
	}
	//1.2 �̸����޺��ڽ��� �׸���� �߰��Ѵ�.
	TCHAR emailAddresses[][32] = {
		"naver.com",
		"gmail.com",
		"daum.net",
		"nate.com",
		"hanmail.com"
	};
	i = 0;
	while (i < sizeof(emailAddresses) / sizeof(emailAddresses[0]))
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_EMAILADDRESS))->AddString(emailAddresses[i]);
		i++;
	}
	return FALSE;
}

//2. ��ȣ����Ʈ�� ��Ŀ���� ���� ��
void TakingInForm::OnCompanyNameKillFocus()
{
	//2.1 ��ȣ���� �Է¹޴´�.
	CString companyName;
	GetDlgItem(IDC_EDIT_COMPANYNAME)->GetWindowText(companyName);
	//2.2 ����ö ������ �����츦 ã�´�.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "����ö");
	//2.3 ����ö ������ �������� ����ö���� ȸ�縦 ã�´�.
	VisitingCard* index = visitingCardBinderForm->visitingCardBinder->FindByCompanyName((LPCTSTR)companyName);
	//2.4 ã�� ȸ�簡 ������
	if (index != 0)
	{
		//2.4.1 ã�� ȸ���� �ּ�, ��ȭ��ȣ, �ѽ���ȣ, URL�� ����Ѵ�.
		CString address = CString(index->GetAddress().c_str());
		GetDlgItem(IDC_EDIT_ADDRESS)->SetWindowText(address);
		CString telephoneNumber = CString(index->GetTelephoneNumber().c_str());
		GetDlgItem(IDC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
		CString faxNumber = CString(index->GetFaxNumber().c_str());
		GetDlgItem(IDC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
		CString url = CString(index->GetUrl().c_str());
		GetDlgItem(IDC_EDIT_URL)->SetWindowText(url);
	}
}

//3. ������ư�� Ŭ������ ��
void TakingInForm::OnTakeInButtonClicked()
{
	//3.1 ����, ��å, �޴�����ȣ, �̸����ּ�, ��ȣ, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, URL�� �д´�.
	CString name;
	GetDlgItem(IDC_EDIT_PERSONALNAME)->GetWindowText(name);
	CString position;
	GetDlgItem(IDC_COMBO_POSITION)->GetWindowText(position);
	CString cellularPhoneNumber;
	GetDlgItem(IDC_EDIT_CELLULARPHONENUMBER)->GetWindowText(cellularPhoneNumber);
	CString emailAddress;
	GetDlgItem(IDC_EDIT_EMAILADDRESS)->GetWindowText(emailAddress);
	CString emailAddressDomain;
	GetDlgItem(IDC_COMBO_EMAILADDRESS)->GetWindowText(emailAddressDomain);
	emailAddress.Format("%s@%s", (LPCTSTR)emailAddress, (LPCTSTR)emailAddressDomain);
	CString companyName;
	GetDlgItem(IDC_EDIT_COMPANYNAME)->GetWindowText(companyName);
	CString address;
	GetDlgItem(IDC_EDIT_ADDRESS)->GetWindowText(address);
	CString telephoneNumber;
	GetDlgItem(IDC_EDIT_TELEPHONENUMBER)->GetWindowText(telephoneNumber);
	CString faxNumber;
	GetDlgItem(IDC_EDIT_FAXNUMBER)->GetWindowText(faxNumber);
	CString url;
	GetDlgItem(IDC_EDIT_URL)->GetWindowText(url);
	//3.2 ����ö ������ �����츦 ã�´�.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "����ö");
	//3.3 �Է¹��� ������ visitingCard�� �����Ѵ�.
	VisitingCard visitingCard((LPCTSTR)name, (LPCTSTR)position, (LPCTSTR)cellularPhoneNumber, (LPCTSTR)emailAddress, 
		(LPCTSTR)companyName, (LPCTSTR)address, (LPCTSTR)telephoneNumber, (LPCTSTR)faxNumber, (LPCTSTR)url);
	//3.4 ����ö ������ �������� ���Կ��� �����.
	VisitingCard* index = visitingCardBinderForm->visitingCardBinder->TakeIn(visitingCard);
	//3.5 �����ͺ��̽��� ���� ������ �����Ѵ�.
	visitingCardBinderForm->Insert(index);
	//3.5 ����ö ������ �����쿡 ���� ������ ����Ѵ�.
	name = CString(index->GetName().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	position = CString(index->GetPosition().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	cellularPhoneNumber = CString(index->GetCellularPhoneNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	emailAddress = CString(index->GetEmailAddress().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	companyName = CString(index->GetCompanyName().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	address = CString(index->GetAddress().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	telephoneNumber = CString(index->GetTelephoneNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	faxNumber = CString(index->GetFaxNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	url = CString(index->GetUrl().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
	//3.6 �����츦 �ݴ´�.
	EndDialog(0);
}

//4. �ݱ��ư�� Ŭ������ ��
void TakingInForm::OnClose()
{
	//4.1 �����츦 �ݴ´�.
	EndDialog(0);
}


