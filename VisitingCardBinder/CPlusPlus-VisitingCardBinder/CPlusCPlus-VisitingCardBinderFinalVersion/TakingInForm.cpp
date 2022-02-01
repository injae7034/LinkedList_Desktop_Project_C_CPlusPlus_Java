#include "TakingInForm.h"
#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "resource.h"
#include<afxwin.h>//CDialog 헤더파일

BEGIN_MESSAGE_MAP(TakingInForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_EN_KILLFOCUS(IDC_EDIT_COMPANYNAME, OnCompanyNameKillFocus)
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
	//1.1 직책콤보박스에 항목들을 추가한다.
	TCHAR positions[][8] = {
		"사원",
		"주임",
		"대리",
		"과장",
		"차장",
		"부장",
		"이사",
		"상무",
		"전무",
		"부사장",
		"사장"
	};
	Long i = 0;
	while (i < sizeof(positions) / sizeof(positions[0]))
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_POSITION))->AddString(positions[i]);
		i++;
	}
	//1.2 이메일콤보박스에 항목들을 추가한다.
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

//2. 상호에디트가 포커스를 잃을 때
void TakingInForm::OnCompanyNameKillFocus()
{
	//2.1 상호명을 입력받는다.
	CString companyName;
	GetDlgItem(IDC_EDIT_COMPANYNAME)->GetWindowText(companyName);
	//2.2 명함철 프레임 윈도우를 찾는다.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
	//2.3 명함철 프레임 윈도우의 명함철에서 회사를 찾는다.
	VisitingCard* index = visitingCardBinderForm->visitingCardBinder->FindByCompanyName((LPCTSTR)companyName);
	//2.4 찾은 회사가 있으면
	if (index != 0)
	{
		//2.4.1 찾은 회사의 주소, 전화번호, 팩스번호, URL을 출력한다.
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

//3. 끼우기버튼을 클릭했을 때
void TakingInForm::OnTakeInButtonClicked()
{
	//3.1 성명, 직책, 휴대폰번호, 이메일주소, 상호, 주소, 전화번호, 팩스번호, URL을 읽는다.
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
	//3.2 명함철 프레임 윈도우를 찾는다.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
	//3.3 입력받은 정보로 visitingCard를 생성한다.
	VisitingCard visitingCard((LPCTSTR)name, (LPCTSTR)position, (LPCTSTR)cellularPhoneNumber, (LPCTSTR)emailAddress, 
		(LPCTSTR)companyName, (LPCTSTR)address, (LPCTSTR)telephoneNumber, (LPCTSTR)faxNumber, (LPCTSTR)url);
	//3.4 명함철 프레임 윈도우의 명함에서 끼운다.
	VisitingCard* index = visitingCardBinderForm->visitingCardBinder->TakeIn(visitingCard);
	//3.5 데이터베이스에 끼운 명함을 저장한다.
	visitingCardBinderForm->Insert(index);
	//3.5 명함철 프레임 윈도우에 끼운 명함을 출력한다.
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
	//3.6 윈도우를 닫는다.
	EndDialog(0);
}

//4. 닫기버튼을 클릭했을 때
void TakingInForm::OnClose()
{
	//4.1 윈도우를 닫는다.
	EndDialog(0);
}


