#ifndef _WORDCARDBINDER_H
#define _WORDCARDBINDER_H
//STL(Standard Template Class Library)-C++ Class Library
#include "LinkedList.h"
#include "WordCard.h"
#include "Word.h"
#include<string>
using namespace std;

typedef signed long int Long;

class WordCardBinder
{
public:
	WordCardBinder();//����Ʈ������
	WordCardBinder(const WordCardBinder& source);//���������
	~WordCardBinder();//�Ҹ���
	WordCard* TakeIn(WordCard wordCard);
	void FindBySpellings(string spellings, WordCard** (*indexes), Long* count);
	void FindByMeanings(string meanings, WordCard** (*indexes), Long* count);
	WordCard TakeOut(WordCard* index);
	WordCard* Move(WordCard* index);
	WordCard* First();
	WordCard* Previous();
	WordCard* Next();
	WordCard* Last();
	WordCardBinder& operator=(const WordCardBinder& source);//ġȯ������
	WordCard& operator[](Long index);//÷�ڿ�����
	//�ζ����Լ�
	Long GetLength() const;
	WordCard* GetCurrent() const;
private:
	LinkedList<WordCard> wordCards;
	Long length;
	WordCard* current;
};

//�ζ����Լ� ����
inline Long WordCardBinder::GetLength() const
{
	return this->length;
}
inline WordCard* WordCardBinder::GetCurrent() const
{
	return const_cast<WordCard*>(this->current);
}

//�Լ������� ����
int CompareSpellings(void* one, void* other);
int CompareMeanings(void* one, void* other);
int CompareWordCards(void* one, void* other);

#endif // !_WORDCARDBINDER_H

