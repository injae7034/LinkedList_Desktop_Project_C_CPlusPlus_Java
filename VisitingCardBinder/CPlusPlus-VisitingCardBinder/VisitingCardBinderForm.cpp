#include "VisitingCardBinderForm.h"
#include "VisitingCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include "resource.h"
#include<afxwin.h>//CDialog�������
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
	this->visitingCardBinder = NULL;//NULL�� �ʱ�ȭ��Ŵ.
}

//�����ͺ��̽� �������α׷��� ����

//Load
void VisitingCardBinderForm::Load()
{
	CDatabase db;//connection, INSERT, DELETE, Disconnection
	CRecordset rs(&db);//SELECT
	CString sql = "SELECT Company.name, Company.address, Company.telephoneNumber, Company.faxNumber, Company.url,"
		"Personal.name, Personal.position, Personal.cellularPhoneNumber, Personal.emailAddress "
		"FROM Company INNER JOIN Personal ON Company.companyCode=Personal.companyCode ORDER BY Personal.code;";
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");//Connection // ������Ʈ �Ӽ� ���� ��޿��� ��������->��������, MFC���-> ����DLL���� MFC������� �ٲ���.
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
	//1. �����Ͱ� ���� �ƴѵ��� �ݺ��Ѵ�.
	while (!rs.IsEOF())
	{
		//1.1 rs�� ����� �������� �� ��ҵ��� �д´�.
		rs.GetFieldValue((short)0, companyName);
		rs.GetFieldValue((short)1, address);
		rs.GetFieldValue((short)2, telephoneNumber);
		rs.GetFieldValue((short)3, faxNumber);
		rs.GetFieldValue((short)4, url);
		rs.GetFieldValue((short)5, name);
		rs.GetFieldValue((short)6, position);
		rs.GetFieldValue((short)7, cellularPhoneNumber);
		rs.GetFieldValue((short)8, emailAddress);
		//1.2 ���� �����͸� ���� visitingCard�� �����Ѵ�.
		VisitingCard visitingCard((LPCTSTR)name, (LPCTSTR)position, (LPCTSTR)cellularPhoneNumber, (LPCTSTR)emailAddress,
			(LPCTSTR)companyName, (LPCTSTR)address, (LPCTSTR)telephoneNumber, (LPCTSTR)faxNumber, (LPCTSTR)url);
		//1.3 ����ö���� ������ visitingCard�� �����.
		this->visitingCardBinder->TakeIn(visitingCard);
		//1.4 ���� �����ͷ� �̵��Ѵ�.
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
	db.OpenEx("DSN=VisitingCardBinder;UID=root;PWD=1q2w3e");//Connection // ������Ʈ �Ӽ� ���� ��޿��� ��������->��������, MFC���-> ����DLL���� MFC������� �ٲ���.
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//Request, Response
	CString sql2 = "DELETE FROM Personal;";
	db.ExecuteSQL(sql2);
	sql2 = "DELETE FROM Company;"; //Company�� Personal�� ���� �� �������������� ���������. ���� Personal�� ���� ��������.
	db.ExecuteSQL(sql2);

	CString companyCode;
	CString code;
	CString sql3;
	CString sql4;
	CString sql5;

	VisitingCard* previous = 0;
	VisitingCard* it = this->visitingCardBinder->First();
	//1. ����ö ������ ���������� �ݺ��Ѵ�.
	while (it != previous)
	{
		//1.1 ȸ���ڵ带 �д´�.
		rs.GetFieldValue((short)0, companyCode);
		//1.2 �����ͺ��̽����� ȸ���ڵ�� ã�´�.
		sql3.Format("SELECT Company.name FROM Company WHERE companyCode='%s';", (LPCTSTR)companyCode);
		rs2.Open(AFX_DB_USE_DEFAULT_TYPE, sql3);
		//1.3 �����ͺ��̽��� ã�� �����Ͱ� ������
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
	//1. �����ͺ��̽��� ã���� �ϴ� �����Ͱ� ����Ǿ� ������(�ߺ��� ������)
	if (!rs.IsEOF())
	{
		//1.1 ã�� �������� ȸ���ڵ带 �д´�.
		rs.GetFieldValue((short)0, companyCode);
	}
	//2. �����ͺ��̽��� ã���� �ϴ� �����Ͱ� ������(�ߺ��� ������)
	if (rs.IsEOF())
	{
		//2.1 ���ο� ȸ���ڵ带 �����.
		companyCode = this->GetCompanyCode();
		//2.2 �����ͺ��̽��� ���ο� ȸ�������� �����Ѵ�.
		sql2.Format("INSERT INTO Company(name, address, telephoneNumber, faxNumber, url, companyCode) "
			"VALUES('%s', '%s', '%s', '%s', '%s', '%s');", index->GetCompanyName().c_str(), index->GetAddress().c_str(),
			index->GetTelephoneNumber().c_str(), index->GetFaxNumber().c_str(), index->GetUrl().c_str(),
			(LPCTSTR)companyCode);
		db.ExecuteSQL(sql2);
	}
	//3. ������ ������ �����ͺ��̽��� �����Ѵ�.
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
	//1. �����ͺ��̽��� ����� �����Ͱ� ������ 
	if (!rs.IsEOF())
	{
		//1.1 ����� �������� ȸ���ڵ带 �д´�.
		rs.GetFieldValue((short)0, companyCode);
	}
	//2. ȸ���ڵ带 �����ʿ��� 4�ڸ� �߶� ������ ������ش�.
	number = _ttoi(companyCode.Right(4));
	//3. number�� 1 �������Ѽ� �ٽ� ȸ���ڵ�� ������ش�.
	number++;
	companyCode.Format("C%04d", number);
	//4. �����ͺ��̽��� ������ �и��Ѵ�.
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
	//1. �����ͺ��̽��� ����� �����Ͱ� ������ 
	if (!rs.IsEOF())
	{
		//1.1 ����� �������� �����ڵ带 �д´�.
		rs.GetFieldValue((short)0, code);
	}
	//2. �����ڵ带 �����ʿ��� 4�ڸ� �߶� ������ ������ش�.
	number = _ttoi(code.Right(4));
	//3. number�� 1 �������Ѽ� �ٽ� �����ڵ�� ������ش�.
	number++;
	code.Format("P%04d", number);
	//4. �����ͺ��̽��� ������ �и��Ѵ�.
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

//�����ͺ��̽� �������α׷��� ��

//1. ����ö �����찡 ������ ��
BOOL VisitingCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 ����ö�� �����.(������ ȣ��)
	this->visitingCardBinder = new VisitingCardBinder;
	//1.2 �����ͺ��̽��� ����� �����͵��� ����ö�� �����Ѵ�.
	this->Load();
	//1.3 ����ö���� ����� ������ ������ 0���� �ƴϸ�
	if (this->visitingCardBinder->GetLength() != 0)
	{
		//1.3.1 ����ö���� ó������ �̵��Ѵ�.
		VisitingCard* index = this->visitingCardBinder->First();
		//1.3.2 ����ö�� ���� ������ ����ö ������ �����쿡 ����Ѵ�.
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
	//1.4 ������.
	return FALSE;
}

//2. ����� ��ư�� Ŭ������ ��
void VisitingCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 ����� ������ �����츦 �����Ѵ�.
	TakingInForm takingInForm;//����O, �ּ�X
	//2.2 ����� ������ �����츦 ����Ѵ�.
	takingInForm.DoModal();
}

//3. ã���ư�� Ŭ������ ��
void VisitingCardBinderForm::OnFindButtonClicked()
{
	//3.1 ã�������� �����츦 �����Ѵ�.
	FindingForm findingForm;
	//3.2 ã�������� �����츦 ����Ѵ�.
	findingForm.DoModal();
}
//4. �������ư�� Ŭ������ ��
void VisitingCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 ������������ �����츦 �����Ѵ�.
	TakingOutForm takingOutForm;
	//4.2 ������ ������ �����츦 ����Ѵ�.
	takingOutForm.DoModal();
}

//5. �����ϱ��ư�� Ŭ������ ��

//6. ó����ư�� Ŭ������ ��
void VisitingCardBinderForm::OnFirstButtonClicked()
{
	//6.1 ����ö���� ó������ �̵��Ѵ�.
	VisitingCard* index = this->visitingCardBinder->First();
	//6.2 ����ö�� ���� ������ ����ö ������ �����쿡 ����Ѵ�.
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

//7. ������ư�� Ŭ������ ��
void VisitingCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 ����ö���� �������� �̵��Ѵ�.
	VisitingCard* index = this->visitingCardBinder->Previous();
	//7.2  ����ö�� ���� ������ ����ö ������ �����쿡 ����Ѵ�.
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

//8. ������ư�� Ŭ������ ��
void VisitingCardBinderForm::OnNexttButtonClicked()
{
	//8.1 ����ö���� �������� �̵��Ѵ�.
	VisitingCard* index = this->visitingCardBinder->Next();
	//8.2 ����ö�� ���� ������ ����ö ������ �����쿡 ����Ѵ�.
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

//9. ��������ư�� Ŭ������ ��
void VisitingCardBinderForm::OnLastButtonClicked()
{
	//9.1 ����ö���� ���������� �̵��Ѵ�.
	VisitingCard* index = this->visitingCardBinder->Last();
	//9.2 ����ö�� ���� ������ ����ö ������ �����쿡 ����Ѵ�.
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

//10. �ݱ��ư�� Ŭ������ ��
void VisitingCardBinderForm::OnClose()
{
	//10.1 ����ö�� ������
	if (this->visitingCardBinder != NULL)
	{
		//10.1.1 ����ö�� ������ �����ͺ��̽��� �����Ѵ�.
		this->Save();
		//10.1.2 ����ö�� �����.
		delete this->visitingCardBinder;
	}
	//10.2 �����츦 �ݴ´�.
	EndDialog(0);
}
