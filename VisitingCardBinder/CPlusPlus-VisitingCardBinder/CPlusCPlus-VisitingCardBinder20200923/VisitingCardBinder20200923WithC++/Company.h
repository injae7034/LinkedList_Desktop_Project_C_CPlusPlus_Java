#ifndef _COMPANY_H
#define _COMPANY_H
//STL(Standard Template Class Library)-C++ Class Library
#include<string>
using namespace std;
class Company
{
public:
	Company();//����Ʈ������
	Company(string companyName, string address, string telephoneNumber, string faxNumber, string url);//�Ű������� ���� ������
	Company(const Company& source);//���������
	~Company();//�Ҹ���
	//���Լ�
	bool IsEqual(const Company& other);
	bool IsNotEqual(const Company& other);
	//�������Լ�
	bool operator==(const Company& other);
	bool operator!=(const Company& other);
	Company& operator=(const Company& source);//ġȯ������
	//�ζ����Լ�
	string& GetCompanyName() const;
	string& GetAddress() const;
	string& GetTelephoneNumber() const;
	string& GetFaxNumber() const;
	string& GetUrl() const;

private:
	string companyName;
	string address;
	string telephoneNumber;
	string faxNumber;
	string url;
};

//�ζ��� �Լ� ����
inline string& Company::GetCompanyName() const
{
	return const_cast<string&>(this->companyName);
}

inline string& Company::GetAddress() const
{
	return const_cast<string&>(this->address);
}

inline string& Company::GetTelephoneNumber() const
{
	return const_cast<string&>(this->telephoneNumber);
}

inline string& Company::GetFaxNumber() const
{
	return const_cast<string&>(this->faxNumber);
}

inline string& Company::GetUrl() const
{
	return const_cast<string&>(this->url);
}

#endif // !_COMPANY_H

