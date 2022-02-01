#include "VistingCard.h"

//�⺻������
VisitingCard::VisitingCard()
{

}

//�Ű������� ���� ������
VisitingCard::VisitingCard(string name, string position, string cellularPhoneNumber, string emailAddress,
	string companyName, string address, string telephoneNumber, string faxNumber, string url)
	:personal(name, position, cellularPhoneNumber, emailAddress),
	company(companyName, address, telephoneNumber, faxNumber, url)
{

}

//���������
VisitingCard::VisitingCard(const VisitingCard& source)
	:personal(source.personal), company(source.company)
{

}

//�Ҹ���
VisitingCard::~VisitingCard()
{

}

//���Լ�
bool VisitingCard::IsEqual(const VisitingCard& other)
{
	bool ret = false;
	if (this->personal.IsEqual(other.personal) == true && this->company.IsEqual(other.company) == true)
	{
		ret = true;
	}
	return ret;
}

bool VisitingCard::IsNotEqual(const VisitingCard& other)
{
	bool ret = false;
	if (this->personal.IsNotEqual(other.personal) == true || this->company.IsNotEqual(other.company) == true)
	{
		ret = true;
	}
	return ret;
}

//�������Լ�
bool VisitingCard::operator==(const VisitingCard& other)
{
	bool ret = false;
	if (this->personal.IsEqual(other.personal) == true && this->company.IsEqual(other.company) == true)
	{
		ret = true;
	}
	return ret;
}

bool VisitingCard::operator!=(const VisitingCard& other)
{
	bool ret = false;
	if (this->personal.IsNotEqual(other.personal) == true || this->company.IsNotEqual(other.company) == true)
	{
		ret = true;
	}
	return ret;
}

//ġȯ������
VisitingCard& VisitingCard::operator=(const VisitingCard& source)
{
	this->personal = source.personal;
	this->company = source.company;

	return *this;
}
#if 0
//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. visitingCard�� �����Ѵ�.
	VisitingCard visitingCard;
	//2. �Ű������� ������ �����ڸ� �����.
	VisitingCard other = VisitingCard("ȫ�浿", "����", "01099823847", "Hong@naver.com",
		"�Ｚ����", "����� ���ʱ�", "023456789", "023456780", "Samsung.com");
	cout << other.GetName() << ","
		<< other.GetPosition() << ","
		<< other.GetCellularPhoneNumber() << ","
		<< other.GetEmailAddress() << ","
		<< other.GetCompanyName() << ","
		<< other.GetAddress() << ","
		<< other.GetTelephoneNumber() << ","
		<< other.GetFaxNumber() << ","
		<< other.GetUrl() << endl;
	//3. ��������ڸ� �����.
	VisitingCard theOther(other);
	cout << other.GetName() << ","
		<< other.GetPosition() << ","
		<< other.GetCellularPhoneNumber() << ","
		<< other.GetEmailAddress() << ","
		<< other.GetCompanyName() << ","
		<< other.GetAddress() << ","
		<< other.GetTelephoneNumber() << ","
		<< other.GetFaxNumber() << ","
		<< other.GetUrl() << endl;
	//4. other�� theOther�� ������ ���Ѵ�.
	bool answer = other.IsEqual(theOther);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = other == theOther;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//5. visitingCard�� other�� �ٸ��� ���Ѵ�.
	answer = visitingCard.IsNotEqual(other);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = visitingCard != other;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//6. ġȯ�����ڷ� visitingCard�� other�� �����Ѵ�.
	visitingCard = other;
	cout << visitingCard.GetName() << ","
		<< visitingCard.GetPosition() << ","
		<< visitingCard.GetCellularPhoneNumber() << ","
		<< visitingCard.GetEmailAddress() << ","
		<< visitingCard.GetCompanyName() << ","
		<< visitingCard.GetAddress() << ","
		<< visitingCard.GetTelephoneNumber() << ","
		<< visitingCard.GetFaxNumber() << ","
		<< visitingCard.GetUrl() << endl;
	//�Ҹ���
	return 0;
}
#endif