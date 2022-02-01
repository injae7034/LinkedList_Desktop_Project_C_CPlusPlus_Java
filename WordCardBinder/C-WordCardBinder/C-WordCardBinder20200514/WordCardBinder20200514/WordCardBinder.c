#include "WordCardBinder.h"
#include<stdio.h>//printf
#include<stdlib.h>//calloc, malloc, free
#include<string.h>//strcmp, strcpy
#pragma warning(disable:4996)

int main(int argc, char* argv[])
{
	WordCardBinder wordCardBinder;
	WordCard* index;
	WordCard* (*indexes);
	Long count;
	Long i;
	WordCard* previous = NULL;
	WordCard wordCard;
	WordCard first = { {"apple", "명사", "사과", "Apples are sweet."}, NULL };
	WordCard second = { {"kind", "형용사", "친절한", "She is so kind."}, NULL };
	WordCard third = { {"flower", "명사", "꽃", "The flowers are beautiful."}, NULL };
	WordCard fourth = { {"very", "부사", "매우", "He is very tall."}, NULL };
	WordCard fifth = { {"banana", "명사", "바나나", "A banana is very sweet."}, NULL };
	WordCard sixth = { {"coffee", "명사", "커피", "This coffee is good."}, NULL };
	WordCard seventh = { {"kind", "명사", "종류", "We serve two kinds of tea."}, NULL };

	//메인테스트 시나리오
	//1. 단어카드철을 만든다.
	Create(&wordCardBinder);
	//Load
	Load(&wordCardBinder);
	//2. 단어카드(apple, 명사, 사과, Apples are sweet.)을 끼운다.
	index = TakeIn(&wordCardBinder, first);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//3. 단어카드를 꺼낸다.
	wordCard = TakeOut(&wordCardBinder, index);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	printf("\n");
	//4. 단어카드(kind, 형용사, 친절한, She is so kind.)를 끼운다.
	index = TakeIn(&wordCardBinder, second);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//5. 단어카드(flower, 명사, 꽃, The flowers are beautiful.)을 끼운다.
	index = TakeIn(&wordCardBinder, third);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//6. 단어카드(very, 부사, 매우, He is very tall.)을 끼운다.
	index = TakeIn(&wordCardBinder, fourth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//7 단어카드(banana, 명사, 바나나, A banana is very sweet.)을 끼운다.
	index = TakeIn(&wordCardBinder, fifth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//8. 네번째 명함을 꺼낸다.
	wordCard = TakeOut(&wordCardBinder, index);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	printf("\n");
	//9. 단어카드(coffee, 명사, 커피, This coffee is good.)을 끼운다.
	index = TakeIn(&wordCardBinder, sixth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//10. 단어카드(kind, 명사, 종류, We serve two kinds of tea.)를 끼운다.
	index = TakeIn(&wordCardBinder, seventh);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//11. 단어카드(extremely,  부사, 매우, "The mountain is extremely high.)를 끼운다.
	strcpy(wordCard.word.spellings, "extremely");
	strcpy(wordCard.word.partOfSpeech, "부사");
	strcpy(wordCard.word.meanings, "매우");
	strcpy(wordCard.word.example, "The mountain is extremely high.");
	index = TakeIn(&wordCardBinder, wordCard);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//12. coffee를 찾는다.
	FindBySpellings(&wordCardBinder, "coffee", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.spellings, indexes[i]->word.partOfSpeech, 
			indexes[i]->word.meanings, indexes[i]->word.example);
		i++;
	}
	printf("\n");
	//13. coffee 단어카드를 꺼낸다.
	wordCard = TakeOut(&wordCardBinder, indexes[count - 1]);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//14. 꽃을 찾는다.
	FindByMeanings(&wordCardBinder, "꽃", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.meanings, indexes[i]->word.spellings, 
			indexes[i]->word.partOfSpeech, indexes[i]->word.example);
		i++;
	}
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//15. 단어카드(smell,  명사, 냄새, "The smell is good.)를 끼운다.
	strcpy(wordCard.word.spellings, "smell");
	strcpy(wordCard.word.partOfSpeech, "명사");
	strcpy(wordCard.word.meanings, "냄새");
	strcpy(wordCard.word.example, "The smell is good.");
	index = TakeIn(&wordCardBinder, wordCard);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//16. kind를 찾는다.
	FindBySpellings(&wordCardBinder, "kind", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.spellings, indexes[i]->word.partOfSpeech,
			indexes[i]->word.meanings, indexes[i]->word.example);
		i++;
	}
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//17. 매우를 찾는다.
	FindByMeanings(&wordCardBinder, "매우", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.meanings, indexes[i]->word.spellings,
			indexes[i]->word.partOfSpeech, indexes[i]->word.example);
		i++;
	}
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//18. 처음으로 이동한다.
	index = First(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//19. 이전위치로 이동한다.
	index = Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//20. 다음으로 이동한다.
	index = Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//21. 마지막으로 이동한다.
	index = Last(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//22. 다음으로 이동한다.
	index = Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//23. 이전으로 이동한다.
	index = Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	printf("정리하기전\n");
	index = First(&wordCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
			index->word.example);
		previous = index;
		index = Next(&wordCardBinder);
	}
	printf("정리한후\n");
	//24. 철자를 기준으로 정리한다.
	Arrange(&wordCardBinder);
	index = First(&wordCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
			index->word.example);
		previous = index;
		index = Next(&wordCardBinder);
	}
	//Save
	Save(&wordCardBinder);
	//25. 단어카드철을 없앤다.
	Destroy(&wordCardBinder);

	return 0;
}

//Create
void Create(WordCardBinder* wordCardBinder)
{
	//1. 단어카드철을 만든다.
	wordCardBinder->first = NULL;
	wordCardBinder->length = 0;
	wordCardBinder->current = NULL;
	//2. 끝내다.
}

//Load
Long Load(WordCardBinder* wordCardBinder)
{
	WordCard wordCard;
	WordCard* previous = NULL;
	int flag;
	FILE* file;

	file = fopen("WordCard.dat", "rb");
	if (file != NULL)
	{
		//1.1 철자, 품사, 의미, 예시를 입력받는다.
		flag = fread(&wordCard.word, sizeof(Word), 1, file);
		//1. 파일의 끝이 아닌동안 반복한다.
		while (!feof(file) && flag != 0)
		{
			//1.2 단어카드를 끼운다.
			wordCard.next = NULL;
			wordCardBinder->current = (WordCard*)malloc(sizeof(WordCard));
			*wordCardBinder->current = wordCard;
			if (previous != NULL)
			{
				previous->next = wordCardBinder->current;
			}
			else
			{
				wordCardBinder->first = wordCardBinder->current;
			}
			wordCardBinder->length++;
			previous = wordCardBinder->current;
			//1.1 철자, 품사, 의미, 예시를 입력받는다.
			flag = fread(&wordCard.word, sizeof(Word), 1, file);
		}
		fclose(file);
	}
	//2. 개수를 출력한다.
	return wordCardBinder->length;
	//3. 끝내다.
}

//TakeIn
WordCard* TakeIn(WordCardBinder* wordCardBinder, WordCard wordCard)
{
	WordCard* previous = NULL;
	WordCard* it;
	
	//1. 단어카드를 입력받는다.
	//2. 단어카드를 끼울 위치를 찾는다.
	it = wordCardBinder->first;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//3. 단어카드를 끼운다.
	wordCardBinder->current = (WordCard*)malloc(sizeof(WordCard));
	*wordCardBinder->current = wordCard;
	if (previous != NULL)
	{
		previous->next = wordCardBinder->current;
	}
	else
	{
		wordCardBinder->first = wordCardBinder->current;
	}
	//4. 단어카드철의 개수를 늘린다.
	wordCardBinder->length++;
	//5. 단어카드의 위치를 출력한다.
	return wordCardBinder->current;
	//6. 끝내다.
}

//FindBySpellings
void FindBySpellings(WordCardBinder* wordCardBinder, char(*spellings), WordCard** (*indexes), Long* count)
{
	WordCard* it;
	Long i = 0;

	*count = 0;
	//1. 철자를 입력받는다.
	//2. 위치들 배열을 만든다.
	*indexes = (WordCard * (*))calloc(wordCardBinder->length, sizeof(WordCard*));
	//3. 단어카드철의 마지막까지 반복한다.
	it = wordCardBinder->first;
	while (it != NULL)
	{
		//3.1 단어카드의 철자와 입력받은 철자가 서로 같으면
		if (strcmp(it->word.spellings, spellings) == 0)
		{
			//3.1.1 위치를 저장한다.
			(*indexes)[i] = it;
			i++;
			//3.1.2 개수를 센다.
			(*count)++;
		}
		it = it->next;
	}
	//4. 위치들과 개수를 출력한다.
	//5. 끝내다.
}

//FindByMeanings
void FindByMeanings(WordCardBinder* wordCardBinder, char(*meanings), WordCard** (*indexes), Long* count)
{
	WordCard* it;
	Long i = 0;

	*count = 0;
	//1. 의미를 입력받는다.
	//2. 위치들 배열을 만든다.
	*indexes = (WordCard * (*))calloc(wordCardBinder->length, sizeof(WordCard*));
	//3. 단어카드철의 마지막 단어카드까지 반복한다.
	it = wordCardBinder->first;
	while(it != NULL)
	{
		//3.1 단어카드의 의미와 입력받은 의미가 서로 같으면
		if (strcmp(it->word.meanings, meanings) == 0)
		{
			//3.1.1 위치를 저장한다.
			(*indexes)[i] = it;
			i++;
			//3.1.2 개수를 센다.
			(*count)++;
		}
		it = it->next;
	}
	//4. 위치들과 개수를 출력한다.
	//5. 끝내다.
}

//TakeOut
WordCard TakeOut(WordCardBinder* wordCardBinder, WordCard* index)
{
	WordCard wordCard;
	WordCard* it;
	WordCard* previous = NULL;

	//1. 위치를 입력받는다.
	//2. 위치를 찾는다.
	it = wordCardBinder->first;
	while (it != index)
	{
		previous = it;
		it = it->next;
	}
	//3. 단어카드를 꺼낸다.
	if (previous != NULL)
	{
		previous->next = index->next;
	}
	else
	{
		wordCardBinder->first = index->next;
	}
	if (index->next != NULL)
	{
		wordCardBinder->current = index->next;
	}
	else
	{
		wordCardBinder->current = previous;
	}
	wordCard = *index;
	wordCard.next = NULL;
	if (index != NULL)
	{
		free(index);
	}
	//4. 개수를 감소시킨다.
	wordCardBinder->length--;
	//5. 단어카드를 출력한다.
	return wordCard;
	//6. 끝내다.
}

//First
WordCard* First(WordCardBinder* wordCardBinder)
{
	//1. 현재 위치를 처음으로 이동시킨다.
	wordCardBinder->current = wordCardBinder->first;
	//2. 현재 위치를 출력한다.
	return wordCardBinder->current;
	//3. 끝내다.
}

//Previous
WordCard* Previous(WordCardBinder* wordCardBinder)
{
	WordCard* previous = NULL;
	WordCard* it;

	//1. 현재 위치의 이전 위치를 찾는다.
	it = wordCardBinder->first;
	while (it != wordCardBinder->current)
	{
		previous = it;
		it = it->next;
	}
	//2. 현재 위치를 이전 위치로 이동시킨다.
	if (previous != NULL)
	{
		wordCardBinder->current = previous;
	}
	//3. 현재 위치를 출력한다.
	return wordCardBinder->current;
	//4. 끝내다.
}

//Next
WordCard* Next(WordCardBinder* wordCardBinder)
{
	WordCard* previous;
	
	//1. 현재 위치를 다음 위치로 이동시킨다.
	previous = wordCardBinder->current;
	wordCardBinder->current = wordCardBinder->current->next;
	if (wordCardBinder->current == NULL)
	{
		wordCardBinder->current = previous;
	}
	//2. 현재위치를 출력한다.
	return wordCardBinder->current;
	//3. 끝내다.
}

//Last
WordCard* Last(WordCardBinder* wordCardBinder)
{
	WordCard* it;
	WordCard* previous = NULL;

	//1. 마지막 위치를 찾는다.
	it = wordCardBinder->current;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//2. 현재 위치를 마지막 위치로 이동시킨다.
	wordCardBinder->current = previous;
	//3. 단어카드철의 현재 위치를 출력한다.
	return wordCardBinder->current;
	//4. 끝내다.
}

//Arrange
void Arrange(WordCardBinder* wordCardBinder)
{
	WordCard* previous;
	WordCard* next;
	Long i;
	Long j;
	Boolean flag = _TRUE;

	//1. 단어들을 철자를 기준으로 하여 오름차순으로 정렬한다.
	i = wordCardBinder->length - 1;
	while (i >= 1 && flag == _TRUE)
	{
		previous = NULL;
		wordCardBinder->current = wordCardBinder->first;
		next = wordCardBinder->current->next;
		flag = _FALSE;
		j = 1;
		while (j <= i)
		{
			if (strcmp(wordCardBinder->current->word.spellings, next->word.spellings) > 0)
			{
				if (previous != NULL)
				{
					previous->next = next;
				}
				else
				{
					wordCardBinder->first = next;
				}
				wordCardBinder->current->next = next->next;
				next->next = wordCardBinder->current;
				previous = next;
				next = wordCardBinder->current->next;flag = _TRUE;
			}
			else
			{
				previous = wordCardBinder->current;
				wordCardBinder->current = next;
				next = wordCardBinder->current->next;
			}
			j++;
		}
		i--;
	}
	//2. 끝내다.
}

//Save
Long Save(WordCardBinder* wordCardBinder)
{
	WordCard* it;
	FILE* file;

	file = fopen("WordCard.dat", "wb");
	if (file != NULL)
	{
		//1. 단어카드철의 끝이 아닌동안 반복한다.
		it = wordCardBinder->first;
		while (it != NULL)
		{
			fwrite(&it->word, sizeof(Word), 1, file);
			it = it->next;
		}
		fclose(file);
	}
	//2. 사용량을 출력한다.
	return wordCardBinder->length;
	//3.끝내다.
}

//Destroy
void Destroy(WordCardBinder* wordCardBinder)
{
	//1. 단어카드철에서 단어카드를 순서대로 지운다.
	wordCardBinder->current = wordCardBinder->first;
	while (wordCardBinder->current != NULL)
	{
		wordCardBinder->first = wordCardBinder->current->next;
		if (wordCardBinder->current != NULL)
		{
			free(wordCardBinder->current);
		}
		wordCardBinder->current = wordCardBinder->first;
	}
	//2. 끝내다.
}


