#ifndef _WORD_H
#define _WORD_H
//STL(Standard Template Class Library)-C++ Class Library
#include<string>
using namespace std;

class Word
{
public:
	Word();//����Ʈ������
	Word(string spellings, string partOfSpeech, string meanings, string example);//�Ű������� 4�������� ������
	Word(const Word& source);//���������
	~Word();//�Ҹ���
	//���Լ�
	bool IsEqual(const Word& other);
	bool IsNotEqual(const Word& other);
	//�������Լ�
	bool operator==(const Word& other);
	bool operator!=(const Word& other);
	Word& operator=(const Word& source);//ġȯ������
	//�ζ����Լ�
	string& GetSpellings() const;
	string& GetPartOfSpeech() const;
	string& GetMeanings() const;
	string& GetExample() const;
private:
	string spellings;
	string partOfSpeech;
	string meanings;
	string example;
};

//�ζ����Լ� ����
inline string& Word::GetSpellings() const
{
	return const_cast<string&>(this->spellings);
}
inline string& Word::GetPartOfSpeech() const
{
	return const_cast<string&>(this->partOfSpeech);
}
inline string& Word::GetMeanings() const
{
	return const_cast<string&>(this->meanings);
}
inline string& Word::GetExample() const
{
	return const_cast<string&>(this->example);
}

#endif // !_WORD_H

