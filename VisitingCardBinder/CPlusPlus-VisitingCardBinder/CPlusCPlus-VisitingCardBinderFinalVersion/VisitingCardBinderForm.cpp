#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include "resource.h"
#include<afxwin.h>//CDialog헤더파일
#include<afxdb.h>//ODBC class

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

//데이터베이스 응용프로그래밍 시작

//Load
void VisitingCardBinderForm::Load()
{
	CDatabase db;//connection, INSERT, DELETE, Disconnection
	CRecordset rs(&db);//SELECT
	CString sql = "SELECT Company.name, Company.address, Company.telephoneNumber, Company.faxNumber, Company.url,"
		"Personal.name, Personal.position, Personal.cellularPhoneNumber, Personal.emailAddress "
		"FROM Company INNER JOIN Personal ON Company.companyCode=Personal.companyCode ORDER BY Personal.code;";
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");//Connection // 프로젝트 속성 들어가서 고급에서 문자집합->설정안함, MFC사용-> 공유DLL에서 MFC사용으로 바꿔줌.
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//Request, Response

	CString companyName;
	CString address;
	CString telephoneNumber;
	CString faxNumber;
	CString url;
	CString name;
	CString position;
	CString cellularPhoneNumber;
	CString emailAddress;
	//1. 데이터가 끝이 아닌동안 반복한다.
	while (!rs.IsEOF())
	{
		//1.1 rs에 저장된 데이터의 각 요소들을 읽는다.
		rs.GetFieldValue((short)0, companyName);
		rs.GetFieldValue((short)1, address);
		rs.GetFieldValue((short)2, telephoneNumber);
		rs.GetFieldValue((short)3, faxNumber);
		rs.GetFieldValue((short)4, url);
		rs.GetFieldValue((short)5, name);
		rs.GetFieldValue((short)6, position);
		rs.GetFieldValue((short)7, cellularPhoneNumber);
		rs.GetFieldValue((short)8, emailAddress);
		//1.2 읽은 데이터를 통해 visitingCard를 생성한다.
		VisitingCard visitingCard((LPCTSTR)name, (LPCTSTR)position, (LPCTSTR)cellularPhoneNumber, (LPCTSTR)emailAddress,
			(LPCTSTR)companyName, (LPCTSTR)address, (LPCTSTR)telephoneNumber, (LPCTSTR)faxNumber, (LPCTSTR)url);
		//1.3 명함철에서 생선한 visitingCard를 끼운다.
		this->visitingCardBinder->TakeIn(visitingCard);
		//1.4 다음 에디터로 이동한다.
		rs.MoveNext();
	}
	//Disconnection
	rs.Close();
	db.Close();
}

//Save
void VisitingCardBinderForm::Save()
{
	CDatabase db;
	CRecordset rs(&db);
	CRecordset rs2(&db);
	CString sql = "SELECT Company.companyCode, Personal.code FROM Company INNER JOIN Personal "
		"ON Company.companyCode=Personal.companyCode ORDER BY Personal.code;";
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");//Connection // 프로젝트 속성 들어가서 고급에서 문자집합->설정안함, MFC사용-> 공유DLL에서 MFC사용으로 바꿔줌.
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//Request, Response
	CString sql2 = "DELETE FROM Personal;";
	db.ExecuteSQL(sql2);
	sql2 = "DELETE FROM Company;"; //Company는 Personal이 먼저 다 지워지기전에는 지울수없음. 따라서 Personal을 먼저 지워야함.
	db.ExecuteSQL(sql2);

	CString companyCode;
	CString code;
	CString sql3;
	CString sql4;
	CString sql5;

	VisitingCard* previous = 0;
	VisitingCard* it = this->visitingCardBinder->First();
	//1. 명함철 명함의 마지막까지 반복한다.
	while (it != previous)
	{
		//1.1 회사코드를 읽는다.
		rs.GetFieldValue((short)0, companyCode);
		//1.2 데이터베이스에서 회사코드로 찾는다.
		sql3.Format("SELECT Company.name FROM Company WHERE companyCode='%s';", (LPCTSTR)companyCode);
		rs2.Open(AFX_DB_USE_DEFAULT_TYPE, sql3);
		//1.3 데이터베이스에 찾는 데이터가 없으면
		if (rs2.IsEOF())
		{
			sql4.Format("INSERT INTO Company(name, address, telephoneNumber, faxNumber, url, companyCode) "
				"VALUES('%s', '%s', '%s', '%s', '%s', '%s');", it->GetCompanyName().c_str(), it->GetAddress().c_str(),
				it->GetTelephoneNumber().c_str(), it->GetFaxNumber().c_str(), it->GetUrl().c_str(), (LPCTSTR)companyCode);
			db.ExecuteSQL(sql4);
		}
		rs.GetFieldValue((short)1, code);
		sql5.Format("INSERT INTO Personal(name, position, cellularPhoneNumber, emailAddress, code, companyCode) "
			"VALUES('%s', '%s', '%s', '%s', '%s', '%s');", it->GetName().c_str(), it->GetPosition().c_str(),
			it->GetCellularPhoneNumber().c_str(), it->GetEmailAddress().c_str(), (LPCTSTR)code, (LPCTSTR)companyCode);
		db.ExecuteSQL(sql5);
		rs.MoveNext();
		rs2.Close();
		previous = it;
		it = this->visitingCardBinder->Next();	
	}
	rs.Close();
	db.Close();
}

//Insert
void VisitingCardBinderForm::Insert(VisitingCard* index)
{
	CDatabase db;
	CRecordset rs(&db);
	CString sql;
	CString companyCode;
	CString code = this->GetPersonalCode();
	CString sql2;
	CString sql3;

	sql.Format("SELECT Company.companyCode FROM Company WHERE name='%s' AND address='%s' AND "
		"telephoneNumber='%s' AND faxNumber='%s' AND url='%s';", index->GetCompanyName().c_str(),
		index->GetAddress().c_str(), index->GetTelephoneNumber().c_str(), index->GetFaxNumber().c_str(),
		index->GetUrl().c_str());

	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");//Connection
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//Request, Response
	//1. 데이터베이스에 찾고자 하는 데이터가 저장되어 있으면(중복이 있으면)
	if (!rs.IsEOF())
	{
		//1.1 찾은 데이터의 회사코드를 읽는다.
		rs.GetFieldValue((short)0, companyCode);
	}
	//2. 데이터베이스에 찾고자 하는 데이터가 없으면(중복이 없으면)
	if (rs.IsEOF())
	{
		//2.1 새로운 회사코드를 만든다.
		companyCode = this->GetCompanyCode();
		//2.2 데이터베이스에 새로운 회사정보를 저장한다.
		sql2.Format("INSERT INTO Company(name, address, telephoneNumber, faxNumber, url, companyCode) "
			"VALUES('%s', '%s', '%s', '%s', '%s', '%s');", index->GetCompanyName().c_str(), index->GetAddress().c_str(),
			index->GetTelephoneNumber().c_str(), index->GetFaxNumber().c_str(), index->GetUrl().c_str(),
			(LPCTSTR)companyCode);
		db.ExecuteSQL(sql2);
	}
	//3. 개인의 정보를 데이터베이스에 저장한다.
	sql3.Format("INSERT INTO Personal(name, position, cellularPhoneNumber, emailAddress, code, companyCode) "
		"VALUES('%s', '%s', '%s', '%s', '%s', '%s');", index->GetName().c_str(), index->GetPosition().c_str(),
		index->GetCellularPhoneNumber().c_str(), index->GetEmailAddress().c_str(), 
		(LPCTSTR)code, (LPCTSTR)companyCode);
	db.ExecuteSQL(sql3);
	rs.Close();
	db.Close();
}

//GetCompanyCode
CString VisitingCardBinderForm::GetCompanyCode()
{
	CDatabase db;
	CRecordset rs(&db);
	CString sql = "SELECT Company.companyCode FROM Company ORDER BY companyCode DESC;";
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	CString companyCode = "C0000";
	int number;
	//1. 데이터베이스에 저장된 데이터가 있으면 
	if (!rs.IsEOF())
	{
		//1.1 저장된 데이터의 회사코드를 읽는다.
		rs.GetFieldValue((short)0, companyCode);
	}
	//2. 회사코드를 오른쪽에서 4자리 잘라서 정수로 만들어준다.
	number = _ttoi(companyCode.Right(4));
	//3. number를 1 증가시켜서 다시 회사코드로 만들어준다.
	number++;
	companyCode.Format("C%04d", number);
	//4. 데이터베이스와 연결을 분리한다.
	rs.Close();
	db.Close();

	return companyCode;
}

//GetPersonalCode
CString VisitingCardBinderForm::GetPersonalCode()
{
	CDatabase db;
	CRecordset rs(&db);
	CString sql = "SELECT Personal.code FROM Personal ORDER BY code DESC;";
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	CString code = "P0000";
	int number;
	//1. 데이터베이스에 저장된 데이터가 있으면 
	if (!rs.IsEOF())
	{
		//1.1 저장된 데이터의 개인코드를 읽는다.
		rs.GetFieldValue((short)0, code);
	}
	//2. 개인코드를 오른쪽에서 4자리 잘라서 정수로 만들어준다.
	number = _ttoi(code.Right(4));
	//3. number를 1 증가시켜서 다시 개인코드로 만들어준다.
	number++;
	code.Format("P%04d", number);
	//4. 데이터베이스와 연결을 분리한다.
	rs.Close();
	db.Close();

	return code;
}

//Delete
void VisitingCardBinderForm::Delete(VisitingCard* index)
{
	CDatabase db;
	CRecordset rs(&db);
	CRecordset rs2(&db);

	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");
	CString sql;
	sql.Format("SELECT Company.companyCode, Personal.code FROM Company INNER JOIN Personal ON "
		"Company.companyCode=Personal.companyCode WHERE Company.name='%s' AND Company.address='%s' AND "
		"Company.telephoneNumber='%s' AND Company.faxNumber='%s' AND Company.url='%s' AND Personal.name='%s' AND "
		"Personal.position = '%s' AND Personal.cellularPhoneNumber='%s' AND Personal.emailAddress='%s';",
		index->GetCompanyName().c_str(), index->GetAddress().c_str(), index->GetTelephoneNumber().c_str(),
		index->GetFaxNumber().c_str(), index->GetUrl().c_str(), index->GetName().c_str(), index->GetPosition().c_str(),
		index->GetCellularPhoneNumber().c_str(), index->GetEmailAddress().c_str());
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	CString code;
	rs.GetFieldValue((short)1, code);
	CString sql2;
	sql2.Format("DELETE FROM Personal WHERE code='%s';", (LPCTSTR)code);
	db.ExecuteSQL(sql2);
	CString companyCode;
	rs.GetFieldValue((short)0, companyCode);
	CString sql3;
	sql3.Format("SELECT Personal.name FROM Personal WHERE companyCode='%s';", (LPCTSTR)companyCode);
	rs2.Open(AFX_DB_USE_DEFAULT_TYPE, sql3);
	if (rs2.IsEOF())
	{
		CString sql4;
		sql4.Format("DELETE FROM Company WHERE companyCode='%s';", (LPCTSTR)companyCode);
		db.ExecuteSQL(sql4);
	}
	rs2.Close();
	rs.Close();
	db.Close();
}

//데이터베이스 응용프로그래밍 끝

//1. 명함철 윈도우가 생성될 때
BOOL VisitingCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 명함철을 만든다.(생성자 호출)
	this->visitingCardBinder = new VisitingCardBinder;
	//1.2 데이터베이스에 저장된 데이터들을 명함철에 적재한다.
	this->Load();
	//1.3 명함철에서 적재된 명함의 개수가 0개가 아니면
	if (this->visitingCardBinder->GetLength() != 0)
	{
		//1.3.1 명함철에서 처음으로 이동한다.
		VisitingCard* index = this->visitingCardBinder->First();
		//1.3.2 명함철의 현재 명함을 명함철 프레임 윈도우에 출력한다.
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
	//1.4 끝내다.
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
	//10.1 명함철이 있으면
	if (this->visitingCardBinder != NULL)
	{
		//10.1.1 명함철의 내용을 데이터베이스에 저장한다.
		this->Save();
		//10.1.2 명함철을 지운다.
		delete this->visitingCardBinder;
	}
	//10.2 윈도우를 닫는다.
	EndDialog(0);
}
