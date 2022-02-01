#include "TakingOutForm.h"
#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "resource.h"
#include<afxwin.h>//CDialog헤더파일

BEGIN_MESSAGE_MAP(TakingOutForm, CDialog)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

TakingOutForm::TakingOutForm(CWnd* parent)
	:CDialog(TakingOutForm::IDD, parent)
{

}

//1. 꺼내기 윈도우가 생성될 때
BOOL TakingOutForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 명함철 프레임 윈도우를 찾는다.
	VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
	//1.2 명함철 프레임 윈도우의 명함철에서 현재명함을 구한다.
	VisitingCard* current = visitingCardBinderForm->visitingCardBinder->GetCurrent();
	//1.3 명함철 프레임 윈도우의 명함철에서 꺼낸다.
	VisitingCard visitingCard = visitingCardBinderForm->visitingCardBinder->TakeOut(current);
	//1.4 꺼낸 명함을 출력한다.
	CString name = CString(visitingCard.GetName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
	CString position = CString(visitingCard.GetPosition().c_str());
	GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
	CString cellularPhoneNumber = CString(visitingCard.GetCellularPhoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
	CString emailAddress = CString(visitingCard.GetEmailAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
	CString companyName = CString(visitingCard.GetCompanyName().c_str());
	GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
	CString address = CString(visitingCard.GetAddress().c_str());
	GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
	CString telephoneNumber = CString(visitingCard.GetTelephoneNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
	CString faxNumber = CString(visitingCard.GetFaxNumber().c_str());
	GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
	CString url = CString(visitingCard.GetUrl().c_str());
	GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
	//1.5 명함을 꺼낸 후에 명함철에 명함이 남아있으면
	current = visitingCardBinderForm->visitingCardBinder->GetCurrent();
	if (current != NULL)
	{
		//1.5.1 명함철 프레임 윈도우에 현재 명함을 출력한다.
		name = CString(current->GetName().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText(name);
		position = CString(current->GetPosition().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText(position);
		cellularPhoneNumber = CString(current->GetCellularPhoneNumber().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText(cellularPhoneNumber);
		emailAddress = CString(current->GetEmailAddress().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText(emailAddress);
		companyName = CString(current->GetCompanyName().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText(companyName);
		address = CString(current->GetAddress().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText(address);
		telephoneNumber = CString(current->GetTelephoneNumber().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText(telephoneNumber);
		faxNumber = CString(current->GetFaxNumber().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText(faxNumber);
		url = CString(current->GetUrl().c_str());
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText(url);
	}
	//1.6 명함철에 명함을 꺼낸 후에 명함이 없으면
	else 
	{
		//1.6.1 명함철 프레임 윈도우에 공란을 출력한다.
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_POSITION)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->SetWindowText("");
		visitingCardBinderForm->GetDlgItem(IDC_STATIC_EDIT_URL)->SetWindowText("");
	}
	//1.7 끝내다.
	return FALSE;
}

//2. 닫기버튼을 클릭했을 때
void TakingOutForm::OnClose()
{
	//2.1 "끼우시겠습니까?" 메세지박스를 출력한다.
	int messageBoxButton = MessageBox("끼우시겠습니까?", "질문", MB_YESNOCANCEL);
	//2.2 "예" 버튼을 클릭했을 때
	if (messageBoxButton == IDYES)
	{
		//2.2.1 명함의 정보를 읽는다.
		CString name;
		GetDlgItem(IDC_STATIC_EDIT_PERSONALNAME)->GetWindowText(name);
		CString position;
		GetDlgItem(IDC_STATIC_EDIT_POSITION)->GetWindowText(position);
		CString cellularPhoneNumber;
		GetDlgItem(IDC_STATIC_EDIT_CELLULARPHONENUMBER)->GetWindowText(cellularPhoneNumber);
		CString emailAddress;
		GetDlgItem(IDC_STATIC_EDIT_EMAILADDRESS)->GetWindowText(emailAddress);
		CString companyName;
		GetDlgItem(IDC_STATIC_EDIT_COMPANYNAME)->GetWindowText(companyName);
		CString address;
		GetDlgItem(IDC_STATIC_EDIT_ADDRESS)->GetWindowText(address);
		CString telephoneNumber;
		GetDlgItem(IDC_STATIC_EDIT_TELEPHONENUMBER)->GetWindowText(telephoneNumber);
		CString faxNumber;
		GetDlgItem(IDC_STATIC_EDIT_FAXNUMBER)->GetWindowText(faxNumber);
		CString url;
		GetDlgItem(IDC_STATIC_EDIT_URL)->GetWindowText(url);
		//2.2.2 visitingCard를 생성한다.
		VisitingCard visitingCard((LPCTSTR)name, (LPCTSTR)position, (LPCTSTR)cellularPhoneNumber, (LPCTSTR)emailAddress,
			(LPCTSTR)companyName, (LPCTSTR)address, (LPCTSTR)telephoneNumber, (LPCTSTR)faxNumber, (LPCTSTR)url);
		//2.2.3 명함철 프레임 윈도우를 찾는다.
		VisitingCardBinderForm* visitingCardBinderForm = (VisitingCardBinderForm*)CWnd::FindWindow("#32770", "명함철");
		//2.2.4 명함철 프레임 윈도우의 명람철에서 끼운다.
		VisitingCard* index = visitingCardBinderForm->visitingCardBinder->TakeIn(visitingCard);
		//2.2.5 명함철 프레임 윈도우에 끼운 명함을 출력한다.
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
		//2.2.6 윈도우를 닫는다.
		EndDialog(0);
	}
	//2.3 "아니오"버튼을 클릭했을 때
	else if (messageBoxButton == IDNO)
	{
		//2.3.1 윈도우를 닫는다.
		EndDialog(0);
	}
}