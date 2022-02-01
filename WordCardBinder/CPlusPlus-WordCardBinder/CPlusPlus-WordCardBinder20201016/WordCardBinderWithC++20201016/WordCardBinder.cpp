#include "WordCardBinder.h"

//����Ʈ������
WordCardBinder::WordCardBinder()
{
	this->length = 0;
	this->current = 0;
}

//���������
WordCardBinder::WordCardBinder(const WordCardBinder& source)
	:wordCards(source.wordCards)
{
	this->length = source.length;
	this->current = &this->wordCards.GetCurrent()->GetObject();
}

//�Ҹ���
WordCardBinder::~WordCardBinder()
{

}

//TakeIn
WordCard* WordCardBinder::TakeIn(WordCard wordCard)
{
	//1. �ܾ�ī�带 �Է¹޴´�.
	//2. �ܾ�ī�带 �����.
	LinkedList<WordCard>::Node* node = this->wordCards.AppendFromTail(wordCard);
	//3. �ܾ�ī��ö�� �ܾ�ī�� ������ �ø���.
	this->length++;
	//4. �ܾ�ī��ö�� ���� �ܾ�ī�带 �����Ѵ�.
	this->current = &node->GetObject();
	//5. ���� ��ġ�� �����Ѵ�.
	return this->current;
	//6. ������.
}

//FindBySpellings
void WordCardBinder::FindBySpellings(string spellings, WordCard** (*indexes), Long* count)
{
	//�ʱ�ȭ
	*indexes = 0;
	*count = 0;
	//1. ö�ڸ� �Է¹޴´�.
	//2. �ܾ�ī��ö���� ö�ڷ� �ܾ ã�´�.
	LinkedList<WordCard>::Node* (*nodes);
	this->wordCards.LinearSearchDuplicate(&spellings, &nodes, count, CompareSpellings);
	//3. ã�� ������ ������
	if (*count > 0)
	{
		//3.1 �ܾ�ī�帵ũ �迭�� �����.
		*indexes = new WordCard* [*count];
	}
	//4. ã�� �ܾ�ī�尳����ŭ �ݺ��Ѵ�.
	Long i = 0;
	while (i < *count)
	{
		//4.1 �ܾ�ī�帵ũ�迭�� ã�� �ܾ�ī����� ��ġ�� �����Ѵ�.
		(*indexes)[i] = &nodes[i]->GetObject();
		i++;
	}
	//5. �Ҵ������Ѵ�.
	if (nodes != 0)
	{
		delete[] nodes;
	}
	//6. ��ġ��� ������ ����Ѵ�.
	//7. ������.
}

//FindBymeanings
void WordCardBinder::FindByMeanings(string meanings, WordCard** (*indexes), Long* count)
{
	//�ʱ�ȭ
	*indexes = 0;
	*count = 0;
	//1. �ǹ̸� �Է¹޴´�.
	//2. �ܾ�ī��û���� �ǹ̷� �ܾ�ī�带 ã�´�.
	LinkedList<WordCard>::Node* (*nodes);
	this->wordCards.LinearSearchDuplicate(&meanings, &nodes, count, CompareMeanings);
	//3. ã�� �ܾ ������
	if (*count > 0)
	{
		//3.1 �ܾ�ī�帵ũ �迭�� �����.
		*indexes = new WordCard * [*count];
	}
	//4. ã�� �ܾ�ī�尳����ŭ �ݺ��Ѵ�.
	Long i = 0;
	while (i < *count)
	{
		//4.1 �ܾ�ī�帵ũ�迭�� ã�� �ܾ�ī����� ��ġ�� �����Ѵ�.
		(*indexes)[i] = &nodes[i]->GetObject();
		i++;
	}
	//5. �Ҵ������Ѵ�.
	if (nodes != 0)
	{
		delete[] nodes;
	}
	//6. ��ġ��� ������ ����Ѵ�.
	//7. ������.
}

//TakeOut
WordCard WordCardBinder::TakeOut(WordCard* index)
{
	//1. ���� �ܾ�ī���� ��ġ�� �Է¹޴´�.
	//2. ���� �ܾ�ī�带 ã�´�.
	LinkedList<WordCard>::Node* node = this->wordCards.LinearSearchUnique(index, CompareWordCards);
	//3. node���� �ܾ�ī�带 ������.
	WordCard wordCard = node->GetObject();
	//4. �ܾ�ī��ö���� �ܾ�ī�带 ���ش�.
	this->wordCards.Delete(node);
	//5. �ܾ�ī��ö�� �ܾ ����������
	if (this->wordCards.GetCurrent() != 0)
	{
		//5.1 �ܾ�ī��ö�� ����ī�� ��ġ�� �����Ѵ�.
		this->current = &this->wordCards.GetCurrent()->GetObject();
	}
	//6. �ܾ�ī��ö�� �����ִ� �ܾ�ī�尡 ������
	else
	{
		this->current = 0;
	}
	//7. �ܾ�ī��ö�� �ܾ�ī�� ������ ���ҽ�Ų��.
	this->length--;
	//8. �ܾ�ī�带 ����Ѵ�.
	return wordCard;
	//9. ������.
}

//Move
WordCard* WordCardBinder::Move(WordCard* index)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. �ܾ�ī���� ��ġ�� node�� ã�´�.
	LinkedList<WordCard>::Node* node = this->wordCards.LinearSearchUnique(index, CompareWordCards);
	//3. ���� node��ġ�� �̵��Ѵ�.
	node = this->wordCards.Move(node);
	//4. ���� �ܾ�ī�带 ���Ѵ�.
	this->current = &node->GetObject();
	//5. ���� ��ġ�� ����Ѵ�.
	return this->current;
	//6. ������.
}

//First
WordCard* WordCardBinder::First()
{
	//1. ������ġ�� ó������ �̵���Ų��.
	LinkedList<WordCard>::Node* node = this->wordCards.First();
	//2. ���� �ܾ�ī�� ��ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Previous
WordCard* WordCardBinder::Previous()
{
	//1. ������ġ�� ó������ �̵���Ų��.
	LinkedList<WordCard>::Node* node = this->wordCards.Previous();
	//2. ���� �ܾ�ī�� ��ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Next
WordCard* WordCardBinder::Next()
{
	//1. ������ġ�� ó������ �̵���Ų��.
	LinkedList<WordCard>::Node* node = this->wordCards.Next();
	//2. ���� �ܾ�ī�� ��ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//Last
WordCard* WordCardBinder::Last()
{
	//1. ������ġ�� ó������ �̵���Ų��.
	LinkedList<WordCard>::Node* node = this->wordCards.Last();
	//2. ���� �ܾ�ī�� ��ġ�� ���Ѵ�.
	this->current = &node->GetObject();
	//3. ������ġ�� ����Ѵ�.
	return this->current;
	//4. ������.
}

//ġȯ������
WordCardBinder& WordCardBinder::operator=(const WordCardBinder& source)
{
	this->wordCards = source.wordCards;
	this->length = source.length;
	this->current = &this->wordCards.GetCurrent()->GetObject();

	return *this;
}

//÷�ڿ�����
WordCard& WordCardBinder::operator[](Long index)
{
	return this->wordCards[index];
}

//�����׽�Ʈ�ó�����
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. wordCardBinder�� �����Ѵ�.
	WordCardBinder wordCardBinder;
	//2. �ܾ�ī��ö�� �ܾ�ī�带 �����.
	WordCard first("apple", "���", "���", "The apples are sweet.");
	WordCard* index = wordCardBinder.TakeIn(first);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//3. �ܾ�ī��ö���� �ܾ�ī�带 ������.
	WordCard wordCard = wordCardBinder.TakeOut(index);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//4. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard second("kind", "�����", "ģ����", "She is so kind.");
	index = wordCardBinder.TakeIn(second);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//5. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard third("flower", "���", "��", "The flowers are beautiful.");
	index = wordCardBinder.TakeIn(third);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//6. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard fourth("very", "�λ�", "�ſ�", "He is very tall.");
	index = wordCardBinder.TakeIn(fourth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//7. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard fifth("banana", "���", "�ٳ���", "A banana is so sweet.");
	index = wordCardBinder.TakeIn(fifth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//8. ������ �ܾ�ī�带 ������.
	wordCard = wordCardBinder.TakeOut(index);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//9. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard sixth("coffee", "���", "Ŀ��", "This coffee is so good.");
	index = wordCardBinder.TakeIn(sixth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//10. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard seventh("kind", "���", "����", "We serve two kinds of tea.");
	index = wordCardBinder.TakeIn(seventh);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//11. �ܾ�ī��ö���� �ܾ�ī�带 �����.
	WordCard eighth("extremely", "�λ�", "�ſ�", "The mountain is extremely high.");
	index = wordCardBinder.TakeIn(eighth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//12. coffee�� ã�´�.
	WordCard* (*indexes);
	Long count;
	wordCardBinder.FindBySpellings("coffee", &indexes, &count);
	Long i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//13. �ܾ�ī�带 ������.
	wordCard = wordCardBinder.TakeOut(indexes[0]);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//�Ҵ�����
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//14. "��"�� ã�´�.
	wordCardBinder.FindByMeanings("��", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//�Ҵ�����
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//15. �ܾ�ī��ö�� �ܾ�ī�带 �����.
	WordCard nineth("smell", "���", "����", "The smell is good.");
	index = wordCardBinder.TakeIn(nineth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//16. "kind"�� ã�´�.
	wordCardBinder.FindBySpellings("kind", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//17. ã�� "kind" �ܾ�ī�� �߿��� �ι�° kind�ܾ�ī��� �̵��Ѵ�.
	index = wordCardBinder.Move(indexes[count - 1]);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//�Ҵ�����
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//18. "�ſ�"�� ã�´�.
	wordCardBinder.FindByMeanings("�ſ�", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//�Ҵ�����
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//19. ó������ �̵��Ѵ�.
	index = wordCardBinder.First();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//20. �������� �̵��Ѵ�.
	index = wordCardBinder.Previous();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//21. �������� �̵��Ѵ�.
	index = wordCardBinder.Next();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//22. ���������� �̵��Ѵ�.
	index = wordCardBinder.Last();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//23. �������� �̵��Ѵ�.
	index = wordCardBinder.Next();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//24. �������� �̵��Ѵ�.
	index = wordCardBinder.Previous();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//25. ���������
	cout << "���������" << endl;
	WordCardBinder other(wordCardBinder);
	WordCard* previous = 0;
	WordCard* it = other.First();
	while (it != previous)
	{
		cout << it->GetSpellings() << ", "
			<< it->GetPartOfSpeech() << ", "
			<< it->GetMeanings() << ", "
			<< it->GetExample() << endl;
		previous = it;
		it = other.Next();
	}
	//26. ġȯ������
	cout << "ġȯ������" << endl;
	WordCardBinder theOther = other;
	previous = 0;
	it = theOther.First();
	while (it != previous)
	{
		cout << it->GetSpellings() << ", "
			<< it->GetPartOfSpeech() << ", "
			<< it->GetMeanings() << ", "
			<< it->GetExample() << endl;
		previous = it;
		it = theOther.Next();
	}
	//27. ÷�ڿ�����
	cout << "÷�ڿ�����" << endl;
	cout << theOther[2].GetSpellings() << ", "
		<< theOther[2].GetPartOfSpeech() << ", "
		<< theOther[2].GetMeanings() << ", "
		<< theOther[2].GetExample() << endl;
	//28. ������.(�Ҹ���)
	return 0;
}

//�Լ������� ����
//CompareSpellings
int CompareSpellings(void* one, void* other)
{
	WordCard* one_ = (WordCard*)one;
	string* other_ = (string*)other;

	return (one_->GetSpellings().compare(*other_));
}
//CompareMeanings
int CompareMeanings(void* one, void* other)
{
	WordCard* one_ = (WordCard*)one;
	string* other_ = (string*)other;

	return (one_->GetMeanings().compare(*other_));
}
//CompareWordCards
int CompareWordCards(void* one, void* other)
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