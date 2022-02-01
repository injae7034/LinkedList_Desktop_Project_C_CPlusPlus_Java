#include "VisitingCardBinder.h"

//�⺻������
VisitingCardBinder::VisitingCardBinder()
{
	this->length = 0;
	this->current = 0;
}

//���������
VisitingCardBinder::VisitingCardBinder(const VisitingCardBinder& source)
	:visitingCards(source.visitingCards)
{
	this->length = source.length;
	this->current = &this->visitingCards.GetCurrent()->GetObject();
}

//�Ҹ���
VisitingCardBinder::~VisitingCardBinder()
{

}

//TakeIn
VisitingCard* VisitingCardBinder::TakeIn(VisitingCard visitingCard)
{
	//1. ������ �Է¹޴´�.
	//2. ������ ���� ��ġ�� ã�´�.
	//3. ������ �ִ´�.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.AppendFromTail(visitingCard);
	//4. ����ö�� ������ �ø���.
	this->length++;
	//5. ����ö�� ���� ��ġ�� �����Ѵ�.
	this->current = &node->GetObject();
	//6. ������ġ�� ����Ѵ�.
	return this->current;
	//7. ������.
}

//Find
void VisitingCardBinder::Find(string name, VisitingCard** (*indexes), Long* count)
{
	*indexes = 0;
	*count = 0;
	//1. �Է¹��� �������� ����ö���� ã�´�.
	LinkedList<VisitingCard>::Node* (*nodes);
	this->visitingCards.LinearSearchDuplicate(&name, &nodes, count, ComparePersonalNames);
	//2. ã�� ������ ������
	if (*count > 0)
	{
		//2.1 ��ġ�� �迭�� �����.
		*indexes = new VisitingCard * [*count];
	}
	//3. ã�� ������ŭ �ݺ��Ѵ�.
	Long i = 0;
	while (i < *count)
	{
		//3.1 ��ġ�� �����Ѵ�.
		(*indexes)[i] = &nodes[i]->GetObject();
		i++;
	}
	//4. �Ҵ������Ѵ�.
	if (nodes != 0)
	{
		delete[] nodes;
	}
	//5. ��ġ��� ������ ����Ѵ�.
	//6. ������.
}

//FindByCompanyName
VisitingCard* VisitingCardBinder::FindByCompanyName(string companyName)
{
	VisitingCard* index = 0;
	//1. ȸ���̸��� �Է¹޴´�.
	//2. ����ö�� �Է¹��� ȸ�簡 �ִ��� ã�´�.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.LinearSearchUnique(&companyName, CompareCompanyNames);
	//3. �Է¹��� ȸ�簡 ����ö�� ������
	if (node != 0)
	{
		//3.1 ��ġ�� �����Ѵ�.
		index = &node->GetObject();
	}
	//4. ��ġ�� ����Ѵ�.
	return index;
	//5. ������.
}

//TakeOut
VisitingCard VisitingCardBinder::TakeOut(VisitingCard* index)
{
	//1. ������ ��ġ�� �Է¹޴´�.
	//2. ������ ��ġ�� node�� ��ġ�� ã�´�.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.LinearSearchUnique(index, CompareVisitingCards);
	//3. ������ ������.
	VisitingCard visitingCard = node->GetObject();
	//4. ������ ���ش�.
	this->visitingCards.Delete(node);
	//5. ����ö�� ������ ���� ������
	if (this->visitingCards.GetCurrent() != 0)
	{
		//5.1 ���� ������ ��ġ�� �����Ѵ�.
		this->current = &this->visitingCards.GetCurrent()->GetObject();
	}
	//6. ����ö�� ������ ������
	else
	{
		this->current = 0;
	}
	//7. ����ö�� ���� ������ ���ҽ�Ų��.
	this->length--;
	//8. ������ ����Ѵ�.
	return visitingCard;
	//9. ������.
}

//Move
VisitingCard* VisitingCardBinder::Move(VisitingCard* index)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. ������ ��ġ�� node�� ��ġ�� ã�´�.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.LinearSearchUnique(index, CompareVisitingCards);
	//3. ���� ��ġ�� �Է¹��� ��ġ�� �ٲ۴�.
	node = this->visitingCards.Move(node);
	//4. node���� ������ ������ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//5. ������ġ�� ����Ѵ�.
	return this->current;
	//6. ������.
}

//First
VisitingCard* VisitingCardBinder::First()
{
	//1. ������ġ�� ó������ �̵���Ų��.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.First();
	//2. ������ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Previous
VisitingCard* VisitingCardBinder::Previous()
{
	//1. ������ġ�� �������� �̵���Ų��.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.Previous();
	//2. ������ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Next
VisitingCard* VisitingCardBinder::Next()
{
	//1. ������ġ�� �������� �̵���Ų��.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.Next();
	//2. ������ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Last
VisitingCard* VisitingCardBinder::Last()
{
	//1. ������ġ�� ���������� �̵���Ų��.
	LinkedList<VisitingCard>::Node* node = this->visitingCards.Last();
	//2. ������ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//ġȯ������
VisitingCardBinder& VisitingCardBinder::operator=(const VisitingCardBinder& source)
{
	this->visitingCards = source.visitingCards;
	this->length = source.length;
	this->current = &this->visitingCards.GetCurrent()->GetObject();

	return *this;
}

//÷�ڿ�����
VisitingCard& VisitingCardBinder::operator[](Long index)
{
	return this->visitingCards[index];
}


//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. visitingCardBinder�� �����Ѵ�.
	VisitingCardBinder visitingCardBinder;
	//2. ����ö�� ������ �����.
	VisitingCard first("���浿", "�븮", "01024367967", "Jung@naver.com", "�Ｚ����", "����� ���ʱ�", "023692447",
		"023692448", "Samsung.com");
	VisitingCard* index = visitingCardBinder.TakeIn(first);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//3. ������ ������.
	VisitingCard vistingCard = visitingCardBinder.TakeOut(index);
	cout << vistingCard.GetName() << ","
		<< vistingCard.GetPosition() << ","
		<< vistingCard.GetCellularPhoneNumber() << ","
		<< vistingCard.GetEmailAddress() << ","
		<< vistingCard.GetCompanyName() << ","
		<< vistingCard.GetAddress() << ","
		<< vistingCard.GetTelephoneNumber() << ","
		<< vistingCard.GetFaxNumber() << ","
		<< vistingCard.GetUrl() << endl;
	//4. ����ö�� ������ �����.
	VisitingCard second("ȫ�浿", "�븮", "01036937428", "Hong@naver.com", "��������", "���� �߱�",
		"023347714", "023347715", "Shinhan.com");
	index = visitingCardBinder.TakeIn(second);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//5. ����ö�� ������ �����.
	VisitingCard third("���浿", "����", "01036925571", "Cha@naver.com", "��������", "����� ������",
		"022397821", "022397822", "LG.com");
	index = visitingCardBinder.TakeIn(third);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//6. ����ö�� ������ �����.
	VisitingCard fourth("��浿", "����", "01036901127", "Kim@naver.comn", "�����ڵ���", "��� �ϱ�",
		"0524379702", "0524379701", "Hyundai.com");
	index = visitingCardBinder.TakeIn(fourth);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//7. ����ö���� ������ ������ ������.
	vistingCard = visitingCardBinder.TakeOut(index);
	cout << vistingCard.GetName() << ","
		<< vistingCard.GetPosition() << ","
		<< vistingCard.GetCellularPhoneNumber() << ","
		<< vistingCard.GetEmailAddress() << ","
		<< vistingCard.GetCompanyName() << ","
		<< vistingCard.GetAddress() << ","
		<< vistingCard.GetTelephoneNumber() << ","
		<< vistingCard.GetFaxNumber() << ","
		<< vistingCard.GetUrl() << endl;
	//8. ����ö���� ������ �����.
	VisitingCard fifth("���浿", "���", "01036928827", "Na@naver.com", "SK���̴н�", "��⵵ ��õ",
		"-0313692248", "0313692249", "SK.com");
	index = visitingCardBinder.TakeIn(fifth);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//9. ����ö���� ���浿�� ã�´�.
	VisitingCard* (*indexes);
	Long count;
	visitingCardBinder.Find("���浿", &indexes, &count);
	Long i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetName() << ","
			<< indexes[i]->GetPosition() << ","
			<< indexes[i]->GetCellularPhoneNumber() << ","
			<< indexes[i]->GetEmailAddress() << ","
			<< indexes[i]->GetCompanyName() << ","
			<< indexes[i]->GetAddress() << ","
			<< indexes[i]->GetTelephoneNumber() << ","
			<< indexes[i]->GetFaxNumber() << ","
			<< indexes[i]->GetUrl() << endl;
		i++;
	}
	//10. ���浿�� ������ ����ö���� ������.
	vistingCard = visitingCardBinder.TakeOut(indexes[count-1]);
	cout << vistingCard.GetName() << ","
		<< vistingCard.GetPosition() << ","
		<< vistingCard.GetCellularPhoneNumber() << ","
		<< vistingCard.GetEmailAddress() << ","
		<< vistingCard.GetCompanyName() << ","
		<< vistingCard.GetAddress() << ","
		<< vistingCard.GetTelephoneNumber() << ","
		<< vistingCard.GetFaxNumber() << ","
		<< vistingCard.GetUrl() << endl;
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//11. ����ö�� ������ �����.
	VisitingCard sixth("��浿", "����", "01044287990", "Jang@naver.com", "���ǳ��", "���� �߱�",
		"029912970", "029912971", "Yellow.com");
	index = visitingCardBinder.TakeIn(sixth);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//12. ����ö�� ������ �����.
	VisitingCard seventh("ȫ�浿", "�̻�", "01098712341", "Hong@gmail.com", "�ƽþƳ��װ�", "���� ���α�",
		"028711297", "028711298", "Asiana.com");
	index = visitingCardBinder.TakeIn(seventh);
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//13. ����ö���� ȫ�浿�� ã�´�.
	visitingCardBinder.Find("ȫ�浿", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetName() << ","
			<< indexes[i]->GetPosition() << ","
			<< indexes[i]->GetCellularPhoneNumber() << ","
			<< indexes[i]->GetEmailAddress() << ","
			<< indexes[i]->GetCompanyName() << ","
			<< indexes[i]->GetAddress() << ","
			<< indexes[i]->GetTelephoneNumber() << ","
			<< indexes[i]->GetFaxNumber() << ","
			<< indexes[i]->GetUrl() << endl;
		i++;
	}
	//14. ���� ������ ��ġ�� ù ��° ȫ�浿 �������� �ű��.
	index = visitingCardBinder.Move(indexes[0]);
	cout << indexes[0]->GetName() << ","
		<< indexes[0]->GetPosition() << ","
		<< indexes[0]->GetCellularPhoneNumber() << ","
		<< indexes[0]->GetEmailAddress() << ","
		<< indexes[0]->GetCompanyName() << ","
		<< indexes[0]->GetAddress() << ","
		<< indexes[0]->GetTelephoneNumber() << ","
		<< indexes[0]->GetFaxNumber() << ","
		<< indexes[0]->GetUrl() << endl;
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//15. ȸ��� "���ǳ��"�� ã�´�.
	index = visitingCardBinder.FindByCompanyName("���ǳ��");
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//16. ����ö���� ó������ �̵��Ѵ�.
	index = visitingCardBinder.First();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//17. ����ö���� �������� �̵��Ѵ�.
	index = visitingCardBinder.Previous();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//18. ����ö���� �������� �̵��Ѵ�.
	index = visitingCardBinder.Next();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//19. ����ö���� ���������� �̵��Ѵ�.
	index = visitingCardBinder.Last();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//20. ����ö���� �������� �̵��Ѵ�.
	index = visitingCardBinder.Next();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//21. ����ö���� �������� �̵��Ѵ�.
	index = visitingCardBinder.Previous();
	cout << index->GetName() << ","
		<< index->GetPosition() << ","
		<< index->GetCellularPhoneNumber() << ","
		<< index->GetEmailAddress() << ","
		<< index->GetCompanyName() << ","
		<< index->GetAddress() << ","
		<< index->GetTelephoneNumber() << ","
		<< index->GetFaxNumber() << ","
		<< index->GetUrl() << endl;
	//22. ġȯ������
	cout << "ġȯ������" << endl;
	VisitingCardBinder other;
	other = visitingCardBinder;
	VisitingCard* previous = 0;
	VisitingCard* it = other.First();
	while (it!=previous)
	{
		cout << it->GetName() << ","
			<< it->GetPosition() << ","
			<< it->GetCellularPhoneNumber() << ","
			<< it->GetEmailAddress() << ","
			<< it->GetCompanyName() << ","
			<< it->GetAddress() << ","
			<< it->GetTelephoneNumber() << ","
			<< it->GetFaxNumber() << ","
			<< it->GetUrl() << endl;
		previous = it;
		it = other.Next();
	}
	//23. ÷�ڿ�����
	cout << "÷�ڿ�����" << endl;
	cout << other[2].GetName() << ","
		<< other[2].GetPosition() << ","
		<< other[2].GetCellularPhoneNumber() << ","
		<< other[2].GetEmailAddress() << ","
		<< other[2].GetCompanyName() << ","
		<< other[2].GetAddress() << ","
		<< other[2].GetTelephoneNumber() << ","
		<< other[2].GetFaxNumber() << ","
		<< other[2].GetUrl() << endl;
	//24. ����ö�� ���ش�.
	return 0;
}

//�Լ������� ����
int ComparePersonalNames(void* one, void* other)
{
	VisitingCard* one_ = (VisitingCard*)one;
	string* other_ = (string*)other;

	return (one_->GetName().compare(*other_));
}

int CompareCompanyNames(void* one, void* other)
{
	VisitingCard* one_ = (VisitingCard*)one;
	string* other_ = (string*)other;

	return (one_->GetCompanyName().compare(*other_));
}

int CompareVisitingCards(void* one, void* other)
{
	int ret;
	if (one == other)
	{
		ret = 0;
	}
	else
	{
		ret = 1;
	}
	return ret;
}