#ifndef _WORDCARD_H
#define _WORDCARD_H
//STL(Standard Template Class Library)-C++ Class Library
#include "Word.h"
#include<string>
using namespace std;

class WordCard
{
public:
	WordCard();//����Ʈ������
	WordCard(string spellings, string partOfSpeech, string meanings, string example);//�Ű������� 4�� ���� ������
	WordCard(const WordCard& source);//���������
	~WordCard();//�Ҹ���
	//���Լ�
	bool IsEqual(const WordCard& other);
	bool IsNotEqual(const WordCard& other);
	//�������Լ�
	bool operator==(const WordCard& other);
	bool operator!=(const WordCard& other);
	WordCard& operator=(const WordCard& source);//ġȯ������
	//�ζ����Լ�
	string& GetSpellings() const;
	string& GetPartOfSpeech() const;
	string& GetMeanings() const;
	string& GetExample() const;
private:
	Word word;
};

//�ζ����Լ� ����
inline string& WordCard::GetSpellings() const
{
	return const_cast<string&>(this->word.GetSpellings());
}

inline string& WordCard::GetPartOfSpeech() const
{
	return const_cast<string&>(this->word.GetPartOfSpeech());
}
inline string& WordCard::GetMeanings() const
{
	return const_cast<string&>(this->word.GetMeanings());
}
inline string& WordCard::GetExample() const
{
	return const_cast<string&>(this->word.GetExample());
}

#endif // !_WORDCARD_H

