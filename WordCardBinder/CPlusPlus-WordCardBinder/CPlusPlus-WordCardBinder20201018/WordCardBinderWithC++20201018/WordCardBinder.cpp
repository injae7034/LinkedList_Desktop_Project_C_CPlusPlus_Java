#include "WordCardBinder.h"

//디폴트생성자
WordCardBinder::WordCardBinder()
{
	this->length = 0;
	this->current = 0;
}

//복사생성자
WordCardBinder::WordCardBinder(const WordCardBinder& source)
	:wordCards(source.wordCards)
{
	this->length = source.length;
	this->current = &this->wordCards.GetCurrent()->GetObject();
}

//소멸자
WordCardBinder::~WordCardBinder()
{

}

//TakeIn
WordCard* WordCardBinder::TakeIn(WordCard wordCard)
{
	//1. 단어카드를 입력받는다.
	//2. 단어카드를 끼운다.
	LinkedList<WordCard>::Node* node = this->wordCards.AppendFromTail(wordCard);
	//3. 단어카드철의 단어카드 개수를 늘린다.
	this->length++;
	//4. 단어카드철의 현재 단어카드를 변경한다.
	this->current = &node->GetObject();
	//5. 현재 위치를 츨력한다.
	return this->current;
	//6. 끝내다.
}

//FindBySpellings
void WordCardBinder::FindBySpellings(string spellings, WordCard** (*indexes), Long* count)
{
	//초기화
	*indexes = 0;
	*count = 0;
	//1. 철자를 입력받는다.
	//2. 단어카드철에서 철자로 단어를 찾는다.
	LinkedList<WordCard>::Node* (*nodes);
	this->wordCards.LinearSearchDuplicate(&spellings, &nodes, count, CompareSpellings);
	//3. 찾은 성명이 있으면
	if (*count > 0)
	{
		//3.1 단어카드링크 배열을 만든다.
		*indexes = new WordCard* [*count];
	}
	//4. 찾은 단어카드개수만큼 반복한다.
	Long i = 0;
	while (i < *count)
	{
		//4.1 단어카드링크배열에 찾은 단어카드들의 위치를 저장한다.
		(*indexes)[i] = &nodes[i]->GetObject();
		i++;
	}
	//5. 할당해제한다.
	if (nodes != 0)
	{
		delete[] nodes;
	}
	//6. 위치들과 개수를 출력한다.
	//7. 끝내다.
}

//FindBymeanings
void WordCardBinder::FindByMeanings(string meanings, WordCard** (*indexes), Long* count)
{
	//초기화
	*indexes = 0;
	*count = 0;
	//1. 의미를 입력받는다.
	//2. 단어카드청에서 의미로 단어카드를 찾는다.
	LinkedList<WordCard>::Node* (*nodes);
	this->wordCards.LinearSearchDuplicate(&meanings, &nodes, count, CompareMeanings);
	//3. 찾은 단어가 있으면
	if (*count > 0)
	{
		//3.1 단어카드링크 배열을 만든다.
		*indexes = new WordCard * [*count];
	}
	//4. 찾은 단어카드개수만큼 반복한다.
	Long i = 0;
	while (i < *count)
	{
		//4.1 단어카드링크배열에 찾은 단어카드들의 위치를 저장한다.
		(*indexes)[i] = &nodes[i]->GetObject();
		i++;
	}
	//5. 할당해제한다.
	if (nodes != 0)
	{
		delete[] nodes;
	}
	//6. 위치들과 개수를 출력한다.
	//7. 끝내다.
}

//TakeOut
WordCard WordCardBinder::TakeOut(WordCard* index)
{
	//1. 꺼낼 단어카드의 위치를 입력받는다.
	//2. 꺼낼 단어카드를 찾는다.
	LinkedList<WordCard>::Node* node = this->wordCards.LinearSearchUnique(index, CompareWordCards);
	//3. node에서 단어카드를 꺼낸다.
	WordCard wordCard = node->GetObject();
	//4. 단어카드철에서 단어카드를 없앤다.
	this->wordCards.Delete(node);
	//5. 단어카드철에 단어가 남아있으면
	if (this->wordCards.GetCurrent() != 0)
	{
		//5.1 단어카드철의 현재카드 위치를 변경한다.
		this->current = &this->wordCards.GetCurrent()->GetObject();
	}
	//6. 단어카드철에 남아있는 단어카드가 없으면
	else
	{
		this->current = 0;
	}
	//7. 단어카드철의 단어카드 개수를 감소시킨다.
	this->length--;
	//8. 단어카드를 출력한다.
	return wordCard;
	//9. 끝내다.
}

//Move
WordCard* WordCardBinder::Move(WordCard* index)
{
	//1. 위치를 입력받는다.
	//2. 단어카드의 위치로 node를 찾는다.
	LinkedList<WordCard>::Node* node = this->wordCards.LinearSearchUnique(index, CompareWordCards);
	//3. 현재 node위치를 이동한다.
	node = this->wordCards.Move(node);
	//4. 현재 단어카드를 구한다.
	this->current = &node->GetObject();
	//5. 현재 위치를 출력한다.
	return this->current;
	//6. 끝내다.
}

//First
WordCard* WordCardBinder::First()
{
	//1. 현재위치를 처음으로 이동시킨다.
	LinkedList<WordCard>::Node* node = this->wordCards.First();
	//2. 현재 단어카드 위치를 구한다.
	this->current = &node->GetObject();
	//3. 현재위치를 출력한다.
	return this->current;
	//4. 끝내다.
}

//Previous
WordCard* WordCardBinder::Previous()
{
	//1. 현재위치를 처음으로 이동시킨다.
	LinkedList<WordCard>::Node* node = this->wordCards.Previous();
	//2. 현재 단어카드 위치를 구한다.
	this->current = &node->GetObject();
	//3. 현재위치를 출력한다.
	return this->current;
	//4. 끝내다.
}

//Next
WordCard* WordCardBinder::Next()
{
	//1. 현재위치를 처음으로 이동시킨다.
	LinkedList<WordCard>::Node* node = this->wordCards.Next();
	//2. 현재 단어카드 위치를 구한다.
	this->current = &node->GetObject();
	//3. 현재위치를 출력한다.
	return this->current;
	//4. 끝내다.
}

//Last
WordCard* WordCardBinder::Last()
{
	//1. 현재위치를 처음으로 이동시킨다.
	LinkedList<WordCard>::Node* node = this->wordCards.Last();
	//2. 현재 단어카드 위치를 구한다.
	this->current = &node->GetObject();
	//3. 현재위치를 출력한다.
	return this->current;
	//4. 끝내다.
}

//치환연산자
WordCardBinder& WordCardBinder::operator=(const WordCardBinder& source)
{
	this->wordCards = source.wordCards;
	this->length = source.length;
	this->current = &this->wordCards.GetCurrent()->GetObject();

	return *this;
}

//첨자연산자
WordCard& WordCardBinder::operator[](Long index)
{
	return this->wordCards[index];
}

//메인테스트시나리오
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//1. wordCardBinder를 생성한다.
	WordCardBinder wordCardBinder;
	//2. 단어카드철에 단어카드를 끼운다.
	WordCard first("apple", "명사", "사과", "The apples are sweet.");
	WordCard* index = wordCardBinder.TakeIn(first);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//3. 단어카드철에서 단어카드를 꺼낸다.
	WordCard wordCard = wordCardBinder.TakeOut(index);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//4. 단어카드철에서 단어카드를 끼운다.
	WordCard second("kind", "형용사", "친절한", "She is so kind.");
	index = wordCardBinder.TakeIn(second);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//5. 단어카드철에서 단어카드를 끼운다.
	WordCard third("flower", "명사", "꽃", "The flowers are beautiful.");
	index = wordCardBinder.TakeIn(third);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//6. 단어카드철에서 단어카드를 끼운다.
	WordCard fourth("very", "부사", "매우", "He is very tall.");
	index = wordCardBinder.TakeIn(fourth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//7. 단어카드철에서 단어카드를 끼운다.
	WordCard fifth("banana", "명사", "바나나", "A banana is so sweet.");
	index = wordCardBinder.TakeIn(fifth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//8. 마지막 단어카드를 꺼낸다.
	wordCard = wordCardBinder.TakeOut(index);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//9. 단어카드철에서 단어카드를 끼운다.
	WordCard sixth("coffee", "명사", "커피", "This coffee is so good.");
	index = wordCardBinder.TakeIn(sixth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//10. 단어카드철에서 단어카드를 끼운다.
	WordCard seventh("kind", "명사", "종류", "We serve two kinds of tea.");
	index = wordCardBinder.TakeIn(seventh);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//11. 단어카드철에서 단어카드를 끼운다.
	WordCard eighth("extremely", "부사", "매우", "The mountain is extremely high.");
	index = wordCardBinder.TakeIn(eighth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//12. coffee를 찾는다.
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
	//13. 단어카드를 꺼낸다.
	wordCard = wordCardBinder.TakeOut(indexes[0]);
	cout << wordCard.GetSpellings() << ", "
		<< wordCard.GetPartOfSpeech() << ", "
		<< wordCard.GetMeanings() << ", "
		<< wordCard.GetExample() << endl;
	//할당해제
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//14. "꽃"을 찾는다.
	wordCardBinder.FindByMeanings("꽃", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//할당해제
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//15. 단어카드철에 단어카드를 끼운다.
	WordCard nineth("smell", "명사", "냄새", "The smell is good.");
	index = wordCardBinder.TakeIn(nineth);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//16. "kind"를 찾는다.
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
	//17. 찾은 "kind" 단어카드 중에서 두번째 kind단어카드로 이동한다.
	index = wordCardBinder.Move(indexes[count - 1]);
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//할당해제
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//18. "매우"를 찾는다.
	wordCardBinder.FindByMeanings("매우", &indexes, &count);
	i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetSpellings() << ", "
			<< indexes[i]->GetPartOfSpeech() << ", "
			<< indexes[i]->GetMeanings() << ", "
			<< indexes[i]->GetExample() << endl;
		i++;
	}
	//할당해제
	if (indexes != 0)
	{
		delete[] indexes;
	}
	//19. 처음으로 이동한다.
	index = wordCardBinder.First();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//20. 이전으로 이동한다.
	index = wordCardBinder.Previous();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//21. 다음으로 이동한다.
	index = wordCardBinder.Next();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//22. 마지막으로 이동한다.
	index = wordCardBinder.Last();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//23. 다음으로 이동한다.
	index = wordCardBinder.Next();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//24. 이전으로 이동한다.
	index = wordCardBinder.Previous();
	cout << index->GetSpellings() << ", "
		<< index->GetPartOfSpeech() << ", "
		<< index->GetMeanings() << ", "
		<< index->GetExample() << endl;
	//25. 복사생성자
	cout << "복사생성자" << endl;
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
	//26. 치환연산자
	cout << "치환연산자" << endl;
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
	//27. 첨자연산자
	cout << "첨자연산자" << endl;
	cout << theOther[2].GetSpellings() << ", "
		<< theOther[2].GetPartOfSpeech() << ", "
		<< theOther[2].GetMeanings() << ", "
		<< theOther[2].GetExample() << endl;
	//28. 끝내다.(소멸자)
	return 0;
}

//함수포인터 정의
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