#ifndef _PERSONAL_H
#define _PERSONAL_H
//STL(Standard Template Class Library)-C++ Class Library
using namespace std;
#include<string>

class Personal
{
public:
	Personal();//����Ʈ������
	Personal(string name, string position, string cellularPhoneNumber, string emailAddress);//�Ű������� ���� ������
	Personal(const Personal& source);//���������
	~Personal();//�Ҹ���
	//���Լ�
	bool IsEqual(const Personal& other);
	bool IsNotEqual(const Personal& other);
	//�������Լ�
	bool operator==(const Personal& other);
	bool operator!=(const Personal& other);
	Personal& operator=(const Personal& source);//ġȯ������
	//�ζ����Լ�
	string& GetName() const;
	string& GetPosition() const;
	string& GetCellularPhoneNumber() const;
	string& GetEmailAddress() const;

private:
	string name;
	string position;
	string cellularPhoneNumber;
	string emailAddress;
};

//�ζ��� �Լ� ����
inline string& Personal::GetName() const
{
	return const_cast<string&>(this->name);
}

inline string& Personal::GetPosition() const
{
	return const_cast<string&>(this->position);
}

inline string& Personal::GetCellularPhoneNumber() const
{
	return const_cast<string&>(this->cellularPhoneNumber);
}

inline string& Personal::GetEmailAddress() const
{
	return const_cast<string&>(this->emailAddress);
}

#endif // !_PERSONAL_H
