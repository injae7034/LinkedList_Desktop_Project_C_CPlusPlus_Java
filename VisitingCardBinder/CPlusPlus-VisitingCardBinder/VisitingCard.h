#ifndef _VISITINGCARD_H
#define _VISITINGCARD_H
//STL(Standard Template Class Library)-C++ class Library
#include "Personal.h"
#include "Company.h"
#include<string>
using namespace std;

class VisitingCard
{
public:
	VisitingCard();//����Ʈ ������
	VisitingCard(string name, string position, string cellularPhoneNumber, string emailAddress,
		string companyName, string address, string telephoneNumber, string faxNumber, string url);//�Ű������� ���� ������
	VisitingCard(const VisitingCard& source);//���������
	~VisitingCard();//�Ҹ���

	//���Լ�
	bool IsEqual(const VisitingCard& other);
	bool IsNotEqual(const VisitingCard& other);
	//�������Լ�
	bool operator==(const VisitingCard& other);
	bool operator!=(const VisitingCard& other);
	VisitingCard& operator=(const VisitingCard& source);//ġȯ������

	//�ζ����Լ�
	string& GetName() const;
	string& GetPosition() const;
	string& GetCellularPhoneNumber() const;
	string& GetEmailAddress() const;
	string& GetCompanyName() const;
	string& GetAddress() const;
	string& GetTelephoneNumber() const;
	string& GetFaxNumber() const;
	string& GetUrl() const;

private:
	Personal personal;
	Company company;
};

//�ζ����Լ� ����
inline string& VisitingCard::GetName() const
{
	return const_cast<string&>(this->personal.GetName());
}

inline string& VisitingCard::GetPosition() const
{
	return const_cast<string&>(this->personal.GetPosition());
}

inline string& VisitingCard::GetCellularPhoneNumber() const
{
	return const_cast<string&>(this->personal.GetCellularPhoneNumber());
}

inline string& VisitingCard::GetEmailAddress() const
{
	return const_cast<string&>(this->personal.GetEmailAddress());
}

inline string& VisitingCard::GetCompanyName() const
{
	return const_cast<string&>(this->company.GetCompanyName());
}

inline string& VisitingCard::GetAddress() const
{
	return const_cast<string&>(this->company.GetAddress());
}

inline string& VisitingCard::GetTelephoneNumber() const
{
	return const_cast<string&>(this->company.GetTelephoneNumber());
}

inline string& VisitingCard::GetFaxNumber() const
{
	return const_cast<string&>(this->company.GetFaxNumber());
}

inline string& VisitingCard::GetUrl() const
{
	return const_cast<string&>(this->company.GetUrl());
}

#endif // !_VISITINGCARD_H

