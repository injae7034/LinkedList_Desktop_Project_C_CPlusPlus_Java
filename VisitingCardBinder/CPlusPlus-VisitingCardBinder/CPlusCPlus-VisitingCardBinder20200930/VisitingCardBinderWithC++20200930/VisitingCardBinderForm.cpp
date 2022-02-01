#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include "resource.h"
#include<afxwin.h>//CDialog헤더파일
BEGIN_MESSAGE_MAP(VisitingCardBinderForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnFindButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_TAKEOUT, OnTakeOutButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnFirstButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnPreviousButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnNexttButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnLastButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

VisitingCardBinderForm::VisitingCardBinderForm(CWnd* parent)
	:CDialog(VisitingCardBinderForm::IDD, parent)
{
	this->visitingCardBinder = NULL;//NULL로 초기화시킴.
}

//1. 명함철 윈도우가 생성될 때
BOOL VisitingCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 명함철을 만든다.(생성자 호출)
	this->visitingCardBinder = new VisitingCardBinder;
	//1.2 끝내다.
	return FALSE;
}

//2. 끼우기 버튼을 클릭했을 때
void VisitingCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 끼우기 프레임 윈도우를 생성한다.
	TakingInForm takingInForm;//내용O, 주소X
	//2.2 끼우기 프레임 윈도우를 출력한다.
	takingInForm.DoModal();
}

//3. 찾기버튼을 클릭했을 때
void VisitingCardBinderForm::OnFindButtonClicked()
{
	//3.1 찾기프레임 윈도우를 생성한다.
	FindingForm findingForm;
	//3.2 찾기프레임 윈도우를 출력한다.
	findingForm.DoModal();
}
//4. 꺼내기버튼을 클릭했을 때
void VisitingCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 꺼내기프레임 윈도우를 생성한다.
	TakingOutForm takingOutForm;
	//4.2 꺼내기 프레임 윈도우를 출력한다.
	takingOutForm.DoModal();
}

//5. 정리하기버튼을 클릭했을 때

//6. 처음버튼을 클릭했을 때
void VisitingCardBinderForm::OnFirstButtonClicked()
{
	//6.1 명함철에서 처음으로 이동한다.
	VisitingCard* index = this->visitingCardBinder->First();
	//6.2 명함철의 현재 명함을 명함철 프레임 윈도우에 출력한다.
	CString name = CString(index->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(index->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(index->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(index->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(index->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(index->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(index->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(index->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(index->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//7. 이전버튼을 클릭했을 때
void VisitingCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 명함철에서 이전으로 이동한다.
	VisitingCard* index = this->visitingCardBinder->Previous();
	//7.2  명함철의 현재 명함을 명함철 프레임 윈도우에 출력한다.
	CString name = CString(index->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(index->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(index->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(index->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(index->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(index->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(index->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(index->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(index->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//8. 다음버튼을 클릭했을 때
void VisitingCardBinderForm::OnNexttButtonClicked()
{
	//8.1 명함철에서 다음으로 이동한다.
	VisitingCard* index = this->visitingCardBinder->Next();
	//8.2 명함철의 현재 명함을 명함철 프레임 윈도우에 출력한다.
	CString name = CString(index->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(index->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(index->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(index->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(index->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(index->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(index->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(index->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(index->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//9. 마지막버튼을 클릭했을 때
void VisitingCardBinderForm::OnLastButtonClicked()
{
	//9.1 명함철에서 마지막으로 이동한다.
	VisitingCard* index = this->visitingCardBinder->Last();
	//9.2 명함철의 현재 명함을 명함철 프레임 윈도우에 출력한다.
	CString name = CString(index->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(index->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(index->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(index->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(index->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(index->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(index->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(index->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(index->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//10. 닫기버튼을 클릭했을 때
void VisitingCardBinderForm::OnClose()
{
	//10.1 명함철을 지운다.
	if (this->visitingCardBinder != NULL)
	{
		delete this->visitingCardBinder;
	}
	//10.2 윈도우를 닫는다.
	EndDialog(0);
}
