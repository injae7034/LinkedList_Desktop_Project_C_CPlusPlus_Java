#include "WordCardBinderForm.h"
#include "WordCardBinder.h"
#include "TakingInForm.h"
#include "FindingForm.h"
#include "TakingOutForm.h"
#include<afxdb.h>//ODBC class

BEGIN_MESSAGE_MAP(WordCardBinderForm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TAKEIN, OnTakeInButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnFindButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_TAKEOUT, OnTakeOutButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnFirstButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnPreviousButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnNextButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnLastButtonClicked)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

WordCardBinderForm::WordCardBinderForm(CWnd* parent)
:CDialog(WordCardBinderForm::IDD, parent)
{
	this->wordCardBinder = NULL;//NULL�� �ʱ�ȭ��Ŵ.
}


//�����ͺ��̽� �������α׷��� ����
//Load
void WordCardBinderForm::Load()
{
		CDatabase db;//Connection, INSERT, DELETE, UPDATE, Disconnection
		CRecordset rs(&db);//SELECT
		CString sql = "SELECT Word.spellings, Word.partOfSpeech, Word.meanings, Word.example FROM Word;";
		db.OpenEx("DSN=WordCardBinder;UID=root;PWD=1q2w3e");//Connection
		rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//Request, Response

		CString spellings;
		CString partOfSpeech;
		CString meanings;
		CString example;
		while (!rs.IsEOF())
		{
			rs.GetFieldValue((short)0, spellings);
			rs.GetFieldValue((short)1, partOfSpeech);
			rs.GetFieldValue((short)2, meanings);
			rs.GetFieldValue((short)3, example);
			//1.2 ���� �����͸� ���� wordCard�� �����Ѵ�.
			WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
			//1.3 ����ö���� �����.
			this->wordCardBinder->TakeIn(wordCard);
			rs.MoveNext();
		}
		//Disconnection
		rs.Close();
		db.Close();
}

//Save
void WordCardBinderForm::Save()
{
		CDatabase db;//Connection, INSERT, DELETE, UPDATE, Disconnection
		CRecordset rs(&db);//SELECT
		CString sql = "SELECT Word.code FROM Word;";
		db.OpenEx("DSN=WordCardBinder;UID=root;PWD=1q2w3e");
		rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//�����ͺ��̽��� �ִ� ���� �����͵��� ����� ���� code���� Recordset�� ������.
		CString sql2 = "DELETE FROM Word;";//�����ͺ��̽��� ���ο� �����͵��� �����ϱ� ���� ������ �����͵��� ��� ����.
		db.ExecuteSQL(sql2);//�����ͺ��̽����� ������ �����͵��� ����� ����� ������.

		CString code;
		CString sql3;
		WordCard* previous = 0;
		WordCard* it = this->wordCardBinder->First();
		while (it != previous)
		{
			rs.GetFieldValue((short)0, code);
			sql3.Format("INSERT INTO Word(code, spellings, partOfSpeech, meanings, example) "
				"VALUES('%s', '%s', '%s', '%s', '%s');", (LPCTSTR)code, it->GetSpellings().c_str(),
				it->GetPartOfSpeech().c_str(), it->GetMeanings().c_str(), it->GetExample().c_str());
			db.ExecuteSQL(sql3);
			rs.MoveNext();
			previous = it;
			it = this->wordCardBinder->Next();
		}
		rs.Close();
		db.Close();
}

//GetCode
CString WordCardBinderForm::GetCode()
{
		CDatabase db;
		CRecordset rs(&db);
		CString sql = "SELECT Word.code FROM Word ORDER BY code DESC;";
		db.OpenEx("DSN=WordCardBinder;UID=root;PWD=1q2w3e");
		rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);
		CString code = "W0000";
		int number;
		if (!rs.IsEOF())//�����ͺ��̽��� ����� �����Ͱ� ������
		{
			rs.GetFieldValue((short)0, code);
		}
		number = _ttoi(code.Right(4));
		number++;
		code.Format("W%04d", number);
		rs.Close();
		db.Close();

		return code;
}

//Insert
void WordCardBinderForm::Insert(WordCard* index)
{
	CDatabase db;
	CString sql;
	CString code = this->GetCode();
	sql.Format("INSERT INTO Word(code, spellings, partOfSpeech, meanings, example) "
		"VALUES('%s', '%s', '%s', '%s', '%s');", (LPCTSTR)code, index->GetSpellings().c_str(),
		index->GetPartOfSpeech().c_str(), index->GetMeanings().c_str(), index->GetExample().c_str());
	db.OpenEx("DSN=WordCardBinder;UID=root;PWD=1q2w3e");
	db.ExecuteSQL(sql);//Request
	db.Close();//Disconnection
}

//Delete
void WordCardBinderForm::Delete(WordCard* index)
{
	CDatabase db;//Connection, INSERT, DELETE, UPDATE, Disconnection
	CRecordset rs(&db);//SELECT
	CString sql;
	sql.Format("SELECT Word.code FROM Word WHERE spellings='%s' AND partOfSpeech='%s' AND meanings='%s' AND example='%s';",
		index->GetSpellings().c_str(), index->GetPartOfSpeech().c_str(), index->GetMeanings().c_str(), index->GetExample().c_str());
	db.OpenEx("DSN=WordCardBinder;UID=root;PWD=1q2w3e");
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);

	CString code;
	rs.GetFieldValue((short)0, code);
	sql.Format("DELETE FROM Word WHERE code='%s';", (LPCTSTR)code);
	db.ExecuteSQL(sql);
	rs.Close();
	db.Close();
}

//1. �ܾ�ī��ö �����찡 ������ ��
BOOL WordCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 �ܾ�ī��ö�� �����.(������ȣ��)
	this->wordCardBinder = new WordCardBinder;
	//1.2 �����ͺ��̽��� ����� �����͵��� �ܾ�ī��ö�� �����Ѵ�.
	this->Load();
	//1.3 �ܾ�ī��ö�� ����� �ܾ�ī���� ������ 0���� �ƴϸ�
	if (this->wordCardBinder->GetLength() != 0)
	{
		//1.3.1 �ܾ�ī��ö���� ù��° ��ġ�� �̵��Ѵ�.
		WordCard* index = this->wordCardBinder->First();
		//1.3.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
		CString spellings = CString(index->GetSpellings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		CString meanings = CString(index->GetMeanings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
		CString example = CString(index->GetExample().c_str());
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
	}
	//1.4 ������.
	return FALSE;
}


//2. ������ư�� Ŭ������ ��
void WordCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 ����� ������ �����츦 �����Ѵ�.
	TakingInForm takingInForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "TakingInForm.h" ��������� �ʿ���.
	//2.2 ����� ������ �����츦 ����Ѵ�.
	takingInForm.DoModal();	
}

//3. ã���ư�� Ŭ������ ��
void WordCardBinderForm::OnFindButtonClicked()
{
	//3.1 ã�� ������ �����츦 �����Ѵ�.
	FindingForm findingForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "FindingForm.h" ��������� �ʿ���.
	//3.2 ã�� ������ �����츦 ����Ѵ�.
	findingForm.DoModal();
}

//4. �������ư�� Ŭ������ ��
void WordCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 ������ ������ �����츦 �����Ѵ�.
	TakingOutForm takingOutForm;//����O, �ּ�X, ���� ���漱���� �ƴ϶� #include "TakingOutForm.h" ��������� �ʿ���.
	//4.2 ������ ������ �����츦 ����Ѵ�.
	takingOutForm.DoModal();
}

//5. �����ϱ� ��ư�� Ŭ������ ��

//6. ó����ư�� Ŭ������ ��
void WordCardBinderForm::OnFirstButtonClicked()
{
	//6.1 �ܾ�ī��ö���� ó������ �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->First();
	//6.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//7. ������ư�� Ŭ������ ��
void WordCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Previous();
	//7.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//8.������ư�� Ŭ������ ��
void WordCardBinderForm::OnNextButtonClicked()
{
	//8.1 �ܾ�ī��ö���� �������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Next();
	//8.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//9. ��������ư�� Ŭ������ ��
void WordCardBinderForm::OnLastButtonClicked()
{
	//9.1 �ܾ�ī��ö���� ���������� �̵��Ѵ�.
	WordCard* index = this->wordCardBinder->Last();
	//9.2 �ܾ�ī��ö�� ���� �ܾ�ī�带 ����Ѵ�.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//10. �ݱ��ư�� Ŭ������ ��
void WordCardBinderForm::OnClose()
{
	//10.1 �ܾ�ī��ö�� ������
	if (this->wordCardBinder != NULL)
	{
		//10.1.1 �ܾ�ī��ö�� ������ �����ͺ��̽��� �����Ѵ�.
		this->Save();
		//10.1.2 �ܾ�ī��ö�� �����.
		delete this->wordCardBinder;
	}
	//10.2 �����츦 �ݴ´�.
	EndDialog(0);
}