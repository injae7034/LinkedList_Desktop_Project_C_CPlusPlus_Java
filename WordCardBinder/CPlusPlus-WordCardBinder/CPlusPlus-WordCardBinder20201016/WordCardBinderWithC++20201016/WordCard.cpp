#include "WordCard.h"

//����Ʈ������
WordCard::WordCard()
{

}

//�Ű������� ���� ������
WordCard::WordCard(string spellings, string partOfSpeech, string meanings, string example)
	:word(spellings, partOfSpeech, meanings, example)
{

}

//���������
WordCard::WordCard(const WordCard& source)
	:word(source.word)
{

}

//�Ҹ���
WordCard::~WordCard()
{

}

//���Լ�
//IsEqual
bool WordCard::IsEqual(const WordCard& other)
{
	bool ret = false;
	if (this->word.IsEqual(other.word) == true)
	{
		ret = true;
	}
	return ret;
}
//IsNotEqual
bool WordCard::IsNotEqual(const WordCard& other)
{
	bool ret = false;
	if (this->word.IsNotEqual(other.word) == true)
	{
		ret = true;
	}
	return ret;
}

//�������Լ�
//operator==
bool WordCard::operator==(const WordCard& other)
{
	bool ret = false;
	if (this->word.IsEqual(other.word) == true)
	{
		ret = true;
	}
	return ret;
}
//operator!=
bool WordCard::operator!=(const WordCard& other)
{
	bool ret = false;
	if (this->word.IsNotEqual(other.word) == true)
	{
		ret = true;
	}
	return ret;
}
//ġȯ������
//operator=
WordCard& WordCard::operator=(const WordCard& source)
{
	this->word = source.word;

	return *this;
}

#if 0
//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. wordCard�� �����Ѵ�.
	WordCard wordCard;
	//2. �Ű������� ������ �����ڸ� �����.
	WordCard other = WordCard("kind", "�����", "ģ����", "She is so kind.");
	cout << other.GetSpellings() << ", "
		<< other.GetPartOfSpeech() << ", "
		<< other.GetMeanings() << ", "
		<< other.GetExample() << endl;
	//3. ��������ڸ� �����.
	WordCard theOther(other);
	cout << other.GetSpellings() << ", "
		<< other.GetPartOfSpeech() << ", "
		<< other.GetMeanings() << ", "
		<< other.GetExample() << endl;
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
	//5. wordCard�� other�� �ٸ��� ���Ѵ�.
	answer = wordCard.IsNotEqual(other);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = wordCard != other;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//6. ġȯ�����ڷ� wordCard�� other�� �����Ѵ�.
	wordCard = other;
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//7.������.
	return 0;
}
#endif