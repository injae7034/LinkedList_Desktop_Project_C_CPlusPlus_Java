#include "Word.h"

//����Ʈ������
Word::Word()
	:spellings(""), partOfSpeech(""), meanings(""), example("")
{

}

//�Ű������� ���� ������
Word::Word(string spellings, string partOfSpeech, string meanings, string example)
	:spellings(spellings), partOfSpeech(partOfSpeech), meanings(meanings), example(example)
{

}

//���������
Word::Word(const Word& source)
	:spellings(source.spellings), partOfSpeech(source.partOfSpeech), meanings(source.meanings), example(source.example)
{

}

//���Լ�
//IsEqual
bool Word::IsEqual(const Word& other)
{
	bool ret = false;
	if (this->spellings.compare(other.spellings) == 0 && this->partOfSpeech.compare(other.partOfSpeech) == 0 &&
		this->meanings.compare(other.meanings) == 0 && this->example.compare(other.example) == 0)
	{
		ret = true;
	}
	return ret;
}
//IsNotEqual
bool Word::IsNotEqual(const Word& other)
{
	bool ret = false;
	if (this->spellings.compare(other.spellings) != 0 || this->partOfSpeech.compare(other.partOfSpeech) != 0 ||
		this->meanings.compare(other.meanings) != 0 || this->example.compare(other.example) != 0)
	{
		ret = true;
	}
	return ret;
}

//�������Լ�
//operator==
bool Word::operator==(const Word& other)
{
	bool ret = false;
	if (this->spellings.compare(other.spellings) == 0 && this->partOfSpeech.compare(other.partOfSpeech) == 0 &&
		this->meanings.compare(other.meanings) == 0 && this->example.compare(other.example) == 0)
	{
		ret = true;
	}
	return ret;
}
//operator!=
bool Word::operator!=(const Word& other)
{
	bool ret = false;
	if (this->spellings.compare(other.spellings) != 0 || this->partOfSpeech.compare(other.partOfSpeech) != 0 ||
		this->meanings.compare(other.meanings) != 0 || this->example.compare(other.example) != 0)
	{
		ret = true;
	}
	return ret;
}
//ġȯ������
//operator=
Word& Word::operator=(const Word& source)
{
	this->spellings = source.spellings;
	this->partOfSpeech = source.partOfSpeech;
	this->meanings = source.meanings;
	this->example = source.example;

	return *this;
}

//�Ҹ���
Word::~Word()
{

}

#if 0
//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. Word�� �����.
	Word word;
	//2. �Ű������� ������ �����ڸ� �����.
	Word other = Word("kind", "�����", "ģ����", "She is so kind.");
	cout << other.GetSpellings() << ", "
		<< other.GetPartOfSpeech() << ", "
		<< other.GetMeanings() << ", "
		<< other.GetExample() << endl;
	//3. ��������ڸ� �����.
	Word theOther(other);
	cout << theOther.GetSpellings() << ", "
		<< theOther.GetPartOfSpeech() << ", "
		<< theOther.GetMeanings() << ", "
		<< theOther.GetExample() << endl;
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
	//5. word�� other�� �ٸ��� ���Ѵ�.
	answer = word.IsNotEqual(other);
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	answer = word != other;
	if (answer == true)
	{
		cout << "���Դϴ�." << endl;
	}
	//6. ġȯ�����ڷ� word�� other�� �����Ѵ�.
	word = other;
	cout << word.GetSpellings() << ", "
		<< word.GetPartOfSpeech() << ", "
		<< word.GetMeanings() << ", "
		<< word.GetExample() << endl;
	//7. ������.
	return 0;
}
#endif