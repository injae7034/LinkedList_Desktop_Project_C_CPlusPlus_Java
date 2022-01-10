#ifndef _VISITINGCARDBINDER_H
#define _VISITINGCARDBINDER_H
//STL(Standard Template Class Library)-C++ Class Librabry
#include "LinkedList.h"
#include "VisitingCard.h"
#include<string>
using namespace std;

typedef signed long int Long;

class VisitingCardBinder
{
public:
	VisitingCardBinder();//����Ʈ������
	VisitingCardBinder(const VisitingCardBinder& source);//���������
	~VisitingCardBinder();//�Ҹ���
	VisitingCard* TakeIn(VisitingCard visitingCard);
	void Find(string name, VisitingCard** (*indexes), Long* count);
	VisitingCard* FindByCompanyName(string companyName);
	VisitingCard TakeOut(VisitingCard* index);
	VisitingCard* Move(VisitingCard* index);
	VisitingCard* First();
	VisitingCard* Previous();
	VisitingCard* Next();
	VisitingCard* Last();
	VisitingCardBinder& operator=(const VisitingCardBinder& source);//ġȯ������
	VisitingCard& operator[](Long index);
	//�ζ����Լ�
	Long GetLength() const;
	VisitingCard* GetCurrent() const;
	
private:
	LinkedList<VisitingCard> visitingCards;//�̷��� �����ϸ� ���߿� �⺻�����ڿ��� ȣ��� �� LinkedList�⺻�����ڸ� ȣ����.
	Long length;
	VisitingCard* current;
};

//�ζ����Լ� ����
inline Long VisitingCardBinder::GetLength() const
{
	return this->length;
}

inline VisitingCard* VisitingCardBinder::GetCurrent() const
{
	return const_cast<VisitingCard*>(this->current);
}

//�Լ������ͼ���
int ComparePersonalNames(void* one, void* other);
int CompareCompanyNames(void* one, void* other);
int CompareVisitingCards(void* one, void* other);

#endif // !_VISITINGCARDBINDER_H
