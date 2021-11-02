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
	this->wordCardBinder = NULL;//NULL로 초기화시킴.
}


//데이터베이스 응용프로그래밍 시작
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
			//1.2 읽은 데이터를 통해 wordCard를 생성한다.
			WordCard wordCard((LPCTSTR)spellings, (LPCTSTR)partOfSpeech, (LPCTSTR)meanings, (LPCTSTR)example);
			//1.3 명함철에서 끼운다.
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
		rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);//데이터베이스에 있는 기존 데이터들을 지우기 전에 code들을 Recordset에 저장함.
		CString sql2 = "DELETE FROM Word;";//데이터베이스에 새로운 데이터들을 저장하기 전에 기존에 데이터들을 모두 지움.
		db.ExecuteSQL(sql2);//데이터베이스에서 기존의 데이터들을 지우는 명령을 실행함.

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
		if (!rs.IsEOF())//데이터베이스에 저장된 데이터가 있으면
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

//1. 단어카드철 윈도우가 생성될 때
BOOL WordCardBinderForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	//1.1 단어카드철을 만든다.(생성자호출)
	this->wordCardBinder = new WordCardBinder;
	//1.2 데이터베이스에 저장된 데이터들을 단어카드철에 적재한다.
	this->Load();
	//1.3 단어카드철에 적재된 단어카드의 개수가 0개가 아니면
	if (this->wordCardBinder->GetLength() != 0)
	{
		//1.3.1 단어카드철에서 첫번째 위치로 이동한다.
		WordCard* index = this->wordCardBinder->First();
		//1.3.2 단어카드철의 현재 단어카드를 출력한다.
		CString spellings = CString(index->GetSpellings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
		CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
		GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
		CString meanings = CString(index->GetMeanings().c_str());
		GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
		CString example = CString(index->GetExample().c_str());
		GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
	}
	//1.4 끝내다.
	return FALSE;
}


//2. 끼우기버튼을 클릭했을 때
void WordCardBinderForm::OnTakeInButtonClicked()
{
	//2.1 끼우기 프레임 윈도우를 생성한다.
	TakingInForm takingInForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "TakingInForm.h" 헤더파일이 필요함.
	//2.2 끼우기 프레임 윈도우를 출력한다.
	takingInForm.DoModal();	
}

//3. 찾기버튼을 클릭했을 때
void WordCardBinderForm::OnFindButtonClicked()
{
	//3.1 찾기 프레임 윈도우를 생성한다.
	FindingForm findingForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "FindingForm.h" 헤더파일이 필요함.
	//3.2 찾기 프레임 윈도우를 출력한다.
	findingForm.DoModal();
}

//4. 꺼내기버튼을 클릭했을 때
void WordCardBinderForm::OnTakeOutButtonClicked()
{
	//4.1 꺼내기 프레임 윈도우를 생성한다.
	TakingOutForm takingOutForm;//내용O, 주소X, 따라서 전방선언이 아니라 #include "TakingOutForm.h" 헤더파일이 필요함.
	//4.2 꺼내기 프레임 윈도우를 출력한다.
	takingOutForm.DoModal();
}

//5. 정리하기 버튼을 클릭했을 때

//6. 처음버튼을 클릭했을 때
void WordCardBinderForm::OnFirstButtonClicked()
{
	//6.1 단어카드철에서 처음으로 이동한다.
	WordCard* index = this->wordCardBinder->First();
	//6.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//7. 이전버튼을 클릭했을 때
void WordCardBinderForm::OnPreviousButtonClicked()
{
	//7.1 단어카드철에서 이전으로 이동한다.
	WordCard* index = this->wordCardBinder->Previous();
	//7.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//8.다음버튼을 클릭했을 때
void WordCardBinderForm::OnNextButtonClicked()
{
	//8.1 단어카드철에서 다음으로 이동한다.
	WordCard* index = this->wordCardBinder->Next();
	//8.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//9. 마지막버튼을 클릭했을 때
void WordCardBinderForm::OnLastButtonClicked()
{
	//9.1 단어카드철에서 마지막으로 이동한다.
	WordCard* index = this->wordCardBinder->Last();
	//9.2 단어카드철의 현재 단어카드를 출력한다.
	CString spellings = CString(index->GetSpellings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_SPELLINGS)->SetWindowText(spellings);
	CString partOfSpeech = CString(index->GetPartOfSpeech().c_str());
	GetDlgItem(IDC_STATIC_EDIT_PARTOFSPEECH)->SetWindowText(partOfSpeech);
	CString meanings = CString(index->GetMeanings().c_str());
	GetDlgItem(IDC_STATIC_EDIT_MEANINGS)->SetWindowText(meanings);
	CString example = CString(index->GetExample().c_str());
	GetDlgItem(IDC_STATIC_EDIT_EXAMPLE)->SetWindowText(example);
}

//10. 닫기버튼을 클릭했을 때
void WordCardBinderForm::OnClose()
{
	//10.1 단어카드철이 있으면
	if (this->wordCardBinder != NULL)
	{
		//10.1.1 단어카드철의 내용을 데이터베이스에 저장한다.
		this->Save();
		//10.1.2 단어카드철을 지운다.
		delete this->wordCardBinder;
	}
	//10.2 윈도우를 닫는다.
	EndDialog(0);
}