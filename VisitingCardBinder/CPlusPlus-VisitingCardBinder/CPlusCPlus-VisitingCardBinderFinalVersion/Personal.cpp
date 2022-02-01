#include "Personal.h"

//����Ʈ������
Personal::Personal()
	:name(""), position(""), cellularPhoneNumber(""), emailAddress("")
{

}

//�Ű������� ���� ������
Personal::Personal(string name, string position, string cellularPhoneNumber, string emailAddress)
	:name(name), position(position), cellularPhoneNumber(cellularPhoneNumber), emailAddress(emailAddress)
{

}

//���������
Personal::Personal(const Personal& source)
	:name(source.name), position(source.position), 
	cellularPhoneNumber(source.cellularPhoneNumber), emailAddress(source.emailAddress)
{

}

//�Ҹ���
Personal::~Personal()
{

}

//���Լ�
bool Personal::IsEqual(const Personal& other)
{
	bool ret = false;
	if (this->name.compare(other.name) == 0 && this->position.compare(other.position) == 0 &&
		this->cellularPhoneNumber.compare(other.cellularPhoneNumber) == 0 
		&& this->emailAddress.compare(other.emailAddress) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Personal::IsNotEqual(const Personal& other)
{
	bool ret = false;
	if (this->name.compare(other.name) != 0 || this->position.compare(other.position) != 0 ||
		this->cellularPhoneNumber.compare(other.cellularPhoneNumber) != 0 ||
		this->emailAddress.compare(other.emailAddress) != 0)
	{
		ret = true;
	}
	return ret;
}

//�������Լ�
bool Personal::operator==(const Personal& other)
{
	bool ret = false;
	if (this->name.compare(other.name) == 0 && this->position.compare(other.position) == 0 &&
		this->cellularPhoneNumber.compare(other.cellularPhoneNumber) == 0
		&& this->emailAddress.compare(other.emailAddress) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Personal::operator!=(const Personal& other)
{
	bool ret = false;
	if (this->name.compare(other.name) != 0 || this->position.compare(other.position) != 0 ||
		this->cellularPhoneNumber.compare(other.cellularPhoneNumber) != 0 ||
		this->emailAddress.compare(other.emailAddress) != 0)
	{
		ret = true;
	}
	return ret;
}

//ġȯ������
Personal& Personal::operator=(const Personal& source)
{
	this->name = source.name;
	this->position = source.position;
	this->cellularPhoneNumber = source.cellularPhoneNumber;
	this->emailAddress = source.emailAddress;

	return *this;
}

//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

#if 0
int main(int argc, char* argv[])
{
	//1. Personal�� �����.
	Personal personal;
	//2. �Ű������� ������ �����ڸ� �����.
	Personal other = Personal("ȫ�浿", "����", "01099823847", "Hong@naver.com");
	cout << other.GetName() << ","
		<< other.GetPosition() << ","
		<< other.GetCellularPhoneNumber() << ","
		<< other.GetEmailAddress() << endl;
	//3. ��������ڸ� �����.
	Personal theOther(other);
	cout << theOther.GetName() << ","
		<< theOther.GetPosition() << ","
		<< theOther.GetCellularPhoneNumber() << ","
		<< theOther.GetEmailAddress() << endl;
	//4. other�� theOther�� ������ ���Ѵ�.
	bool answer = other.IsEqual(theOther);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = other==theOther;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//5. personal�� other�� �ٸ��� ���Ѵ�.
	answer = personal.IsNotEqual(other);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = personal!=other;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//6. ġȯ�����ڷ� personal�� other�� �����Ѵ�.
	personal = other;
	cout << personal.GetName() << ","
		<< personal.GetPosition() << ","
		<< personal.GetCellularPhoneNumber() << ","
		<< personal.GetEmailAddress() << endl;
	
	//7. ������.
	return 0;
}
#endif

