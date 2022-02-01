#include "FindingForm.h"
#include "VisitingCardBinderForm.h"
#include "resource.h"
#include "VisitingCard.h"
#include "VisitingCardBinder.h"
#include<afxwin.h>//CDialog 헤더파일

BEGIN_MESSAGE_MAP(FindingForm, CDialog)
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

//1. 찾기버튼을 클릭했을 때
void FindingForm::OnFindButtonClicked()
{
	//1.1 성명을 입력받는다.
	CString name;
	GetDlgItem(IDC_EDIT_PERSONALNAME)->GetWindowText(name);
	//1.2 명함철 프레임 윈도우를 찾는다.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
	//1.3 명함철프레임윈도우의 명함철에서 명함을 찾는다.
	if (this->indexes != NULL)
	{
		delete[] this->indexes;
	}
	visitingCardBinderForm->visitingCardBinder->Find((LPCTSTR)name, &this->indexes, &this->count);
	//1.4 찾은 명함이 있으면
	if (this->count > 0)
	{
		//1.4.1 찾은 명함들 중에 첫번째 명함을 출력한다.
		this->current = 0;
		name = CString(this->indexes[this->current]->GetName().c_str());
		GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
		CString position = CString(this->indexes[this->current]->GetPosition().c_str());
		GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
		CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
		GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
		CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
		GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
		CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
		GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
		CString address = CString(this->indexes[this->current]->GetAddress().c_str());
		GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
		CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
		GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
		CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
		GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
		CString url = CString(this->indexes[this->current]->GetUrl().c_str());
		GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
	}
	//1.5 찾은 명함이 없으면
	else
	{
		//1.5.1 공란으로 만들어준다.
		GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText("");
		GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText("");
	}
}

//2. 선택하기 버튼을 클릭했을 때
void FindingForm::OnChooseButtonClicked()
{
	//2.1 명함철 프레임 윈도우를 찾는다.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
	//2.2 명함철 프레임 윈도우에 선택한 명함을 츨력한다.
	CString name = CString(this->indexes[this->current]->GetName().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(this->indexes[this->current]->GetPosition().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(this->indexes[this->current]->GetAddress().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(this->indexes[this->current]->GetUrl().c_str());
	visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
	//2.3 명함철 프레임 윈도우의 명함철에서 현재 위치를 선택한 명함의 위치로 바꾼다.
	visitingCardBinderForm->visitingCardBinder->Move(this->indexes[this->current]);
	//2.4 윈도우를 닫는다.
	if (this->indexes != NULL)
	{
		delete[] this->indexes;
	}
	EndDialog(0);
}

//3. 처음버튼을 클릭했을 때
void FindingForm::OnFirstButtonClicked()
{
	//3.1 찾은 명함들 중에서 첫번째 명함을 출력한다.
	this->current = 0;
	CString name = CString(this->indexes[this->current]->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(this->indexes[this->current]->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(this->indexes[this->current]->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(this->indexes[this->current]->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//4. 이전버튼을 클릭했을 때
void FindingForm::OnPreviousButtonClicked()
{
	//4.1 찾은 명함들 중에서 이전 명함을 출력한다.
	this->current--;
	if (this->current < 0)
	{
		this->current = 0;
	}
	CString name = CString(this->indexes[this->current]->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(this->indexes[this->current]->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(this->indexes[this->current]->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(this->indexes[this->current]->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//5. 다음버튼을 클릭했을 때
void FindingForm::OnNextButtonClicked()
{
	//5.1 찾은 명함들 중에서 다음 명함을 출력한다.
	this->current++;
	if (this->current >= this->count)
	{
		this->current = this->count - 1;
	}
	CString name = CString(this->indexes[this->current]->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(this->indexes[this->current]->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(this->indexes[this->current]->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(this->indexes[this->current]->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//6. 마지막버튼을 클릭했을 때
void FindingForm::OnLastButtonClicked()
{
	//6.1 찾은 명함들 중에서 마지막 명함을 출력한다.
	this->current = this->count - 1;
	CString name = CString(this->indexes[this->current]->GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(this->indexes[this->current]->GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(this->indexes[this->current]->GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(this->indexes[this->current]->GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(this->indexes[this->current]->GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(this->indexes[this->current]->GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(this->indexes[this->current]->GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(this->indexes[this->current]->GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(this->indexes[this->current]->GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
}

//7.닫기버튼을 클릭했을 때
void FindingForm::OnClose()
{
	//7.1 명함링크배열을 없앤다.
	if (this->indexes != NULL)
	{
		delete[]this->indexes;
	}
	//7.2 윈도우를 닫는다.
	EndDialog(0);
}