#include "Company.h"

//�⺻������
Company::Company()
	:companyName(""), address(""), telephoneNumber(""), faxNumber(""), url("")
{

}

//�Ű������� ���� ������
Company::Company(string companyName, string address, string telephoneNumber, string faxNumber, string url)
	:companyName(companyName), address(address), telephoneNumber(telephoneNumber), faxNumber(faxNumber), url(url)
{

}

//���������
Company::Company(const Company& source)
	:companyName(source.companyName), address(source.address), telephoneNumber(source.telephoneNumber),
	faxNumber(source.faxNumber), url(source.url)
{

}

//�Ҹ���
Company::~Company()
{

}

//���Լ�
bool Company::IsEqual(const Company& other)
{
	bool ret = false;
	if (this->companyName.compare(other.companyName) == 0 && this->address.compare(other.address) == 0 &&
		this->telephoneNumber.compare(other.telephoneNumber) == 0 && this->faxNumber.compare(other.faxNumber) == 0 &&
		this->url.compare(other.url) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Company::IsNotEqual(const Company& other)
{
	bool ret = false;
	if (this->companyName.compare(other.companyName) != 0 || this->address.compare(other.address) != 0 ||
		this->telephoneNumber.compare(other.telephoneNumber) != 0 || this->faxNumber.compare(other.faxNumber) != 0 ||
		this->url.compare(other.url) != 0)
	{
		ret = true;
	}
	return ret;
}

//�������Լ�
bool Company::operator==(const Company& other)
{
	bool ret = false;
	if (this->companyName.compare(other.companyName) == 0 && this->address.compare(other.address) == 0 &&
		this->telephoneNumber.compare(other.telephoneNumber) == 0 && this->faxNumber.compare(other.faxNumber) == 0 &&
		this->url.compare(other.url) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Company::operator!=(const Company& other)
{
	bool ret = false;
	if (this->companyName.compare(other.companyName) != 0 || this->address.compare(other.address) != 0 ||
		this->telephoneNumber.compare(other.telephoneNumber) != 0 || this->faxNumber.compare(other.faxNumber) != 0 ||
		this->url.compare(other.url) != 0)
	{
		ret = true;
	}
	return ret;
}

//ġȯ������
Company& Company::operator=(const Company& source)
{
	this->companyName = source.companyName;
	this->address = source.address;
	this->telephoneNumber = source.telephoneNumber;
	this->faxNumber = source.faxNumber;
	this->url = source.url;

	return *this;
}

#if 0
//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. company�� �����.
	Company company;
	//2. �Ű������� ������ �����ڸ� �����.
	Company other = Company("�Ｚ����", "����� ���ʱ�", "023456789", "023456780", "Samsung.com");
	cout << other.GetCompanyName() << ","
		<< other.GetAddress() << ","
		<< other.GetTelephoneNumber() << ","
		<< other.GetFaxNumber() << ","
		<< other.GetUrl() << endl;
	//3. ��������ڸ� �����.
	Company theOther(other);
	cout << other.GetCompanyName() << ","
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
	//5. company�� other�� �ٸ��� ���Ѵ�.
	answer = company.IsNotEqual(other);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = company != other;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//6. ġȯ�����ڷ� company�� other�� �����Ѵ�.
	company = other;
	cout << other.GetCompanyName() << ","
		<< other.GetAddress() << ","
		<< other.GetTelephoneNumber() << ","
		<< other.GetFaxNumber() << ","
		<< other.GetUrl() << endl;
	//7.������
	return 0;
}
#endif