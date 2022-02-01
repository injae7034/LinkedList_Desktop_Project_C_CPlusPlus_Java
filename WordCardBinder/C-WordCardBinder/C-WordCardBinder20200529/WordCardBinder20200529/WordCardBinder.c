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
	//WordCard* previous = NULL;
	WordCard wordCard;
	WordCard first = { {"apple", "���", "���", "Apples are sweet."}};
	WordCard second = { {"kind", "�����", "ģ����", "She is so kind."}};
	WordCard third = { {"flower", "���", "��", "The flowers are beautiful."}};
	WordCard fourth = { {"very", "�λ�", "�ſ�", "He is very tall."}};
	WordCard fifth = { {"banana", "���", "�ٳ���", "A banana is very sweet."}};
	WordCard sixth = { {"coffee", "���", "Ŀ��", "This coffee is good."}};
	WordCard seventh = { {"kind", "���", "����", "We serve two kinds of tea."}};

	//�����׽�Ʈ �ó�����
	//1. �ܾ�ī��ö�� �����.
	WordCardBinder_Create(&wordCardBinder);
	//Load
	Load(&wordCardBinder);
	//2. �ܾ�ī��(apple, ���, ���, Apples are sweet.)�� �����.
	index = TakeIn(&wordCardBinder, first);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//3. �ܾ�ī�带 ������.
	wordCard = TakeOut(&wordCardBinder, index);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	printf("\n");
	//4. �ܾ�ī��(kind, �����, ģ����, She is so kind.)�� �����.
	index = TakeIn(&wordCardBinder, second);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//5. �ܾ�ī��(flower, ���, ��, The flowers are beautiful.)�� �����.
	index = TakeIn(&wordCardBinder, third);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//6. �ܾ�ī��(very, �λ�, �ſ�, He is very tall.)�� �����.
	index = TakeIn(&wordCardBinder, fourth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//7 �ܾ�ī��(banana, ���, �ٳ���, A banana is very sweet.)�� �����.
	index = TakeIn(&wordCardBinder, fifth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//8. �׹�° ������ ������.
	wordCard = TakeOut(&wordCardBinder, index);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	printf("\n");
	//9. �ܾ�ī��(coffee, ���, Ŀ��, This coffee is good.)�� �����.
	index = TakeIn(&wordCardBinder, sixth);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//10. �ܾ�ī��(kind, ���, ����, We serve two kinds of tea.)�� �����.
	index = TakeIn(&wordCardBinder, seventh);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//11. �ܾ�ī��(extremely,  �λ�, �ſ�, "The mountain is extremely high.)�� �����.
	strcpy(wordCard.word.spellings, "extremely");
	strcpy(wordCard.word.partOfSpeech, "�λ�");
	strcpy(wordCard.word.meanings, "�ſ�");
	strcpy(wordCard.word.example, "The mountain is extremely high.");
	index = TakeIn(&wordCardBinder, wordCard);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//12. coffee�� ã�´�.
	FindBySpellings(&wordCardBinder, "coffee", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.spellings, indexes[i]->word.partOfSpeech, 
			indexes[i]->word.meanings, indexes[i]->word.example);
		i++;
	}
	printf("\n");
	//13. coffee �ܾ�ī�带 ������.
	wordCard = TakeOut(&wordCardBinder, indexes[count - 1]);
	printf("%s %s %s %s\n", wordCard.word.spellings, wordCard.word.partOfSpeech, wordCard.word.meanings,
		wordCard.word.example);
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//14. ���� ã�´�.
	FindByMeanings(&wordCardBinder, "��", &indexes, &count);
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
	//15. �ܾ�ī��(smell,  ���, ����, "The smell is good.)�� �����.
	strcpy(wordCard.word.spellings, "smell");
	strcpy(wordCard.word.partOfSpeech, "���");
	strcpy(wordCard.word.meanings, "����");
	strcpy(wordCard.word.example, "The smell is good.");
	index = TakeIn(&wordCardBinder, wordCard);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
	//16. kind�� ã�´�.
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
	//17. �ſ츦 ã�´�.
	FindByMeanings(&wordCardBinder, "�ſ�", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s\n", indexes[i]->word.meanings, indexes[i]->word.spellings,
			indexes[i]->word.partOfSpeech, indexes[i]->word.example);
		i++;
	}
	//Move
	i = 1;
	index = WordCardBinder_Move(&wordCardBinder, indexes[i]);
	printf("Move\n");
	printf("%s %s %s %s\n", indexes[i]->word.spellings, indexes[i]->word.partOfSpeech, indexes[i]->word.meanings,
		indexes[i]->word.example);
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//18. ó������ �̵��Ѵ�.
	index = WordCardBinder_First(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//19. ������ġ�� �̵��Ѵ�.
	index = WordCardBinder_Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//20. �������� �̵��Ѵ�.
	index = WordCardBinder_Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//21. ���������� �̵��Ѵ�.
	index = WordCardBinder_Last(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//22. �������� �̵��Ѵ�.
	index = WordCardBinder_Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//23. �������� �̵��Ѵ�.
	index = WordCardBinder_Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
#if 0
	printf("�����ϱ���\n");
	index = First(&wordCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
			index->word.example);
		previous = index;
		index = Next(&wordCardBinder);
	}
	printf("��������\n");
	//24. ö�ڸ� �������� �����Ѵ�.
	Arrange(&wordCardBinder);
	index = First(&wordCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
			index->word.example);
		previous = index;
		index = Next(&wordCardBinder);
	}
#endif
	//Save
	Save(&wordCardBinder);
	//25. �ܾ�ī��ö�� ���ش�.
	WordCardBinder_Destroy(&wordCardBinder);

	return 0;
}


//Create
void WordCardBinder_Create(WordCardBinder* wordCardBinder)
{
	//1. �ܾ�ī��ö�� �����.
	Create(&wordCardBinder->wordCards);
	wordCardBinder->length = 0;
	wordCardBinder->current = NULL;
	//2. ������.
}

//Load
Long Load(WordCardBinder* wordCardBinder)
{
	WordCard wordCard;
	Node* node;
	int flag;
	FILE* file;

	file = fopen("WordCard.dat", "rb");
	if (file != NULL)
	{
		//1.1 ö��, ǰ��, �ǹ�, ���ø� �Է¹޴´�.
		flag = fread(&wordCard.word, sizeof(Word), 1, file);
		//1. ������ ���� �ƴѵ��� �ݺ��Ѵ�.
		while (!feof(file) && flag != 0)
		{
			//1.2 �ܾ�ī�带 �����.
			node = AppendFromTail(&wordCardBinder->wordCards, &wordCard, sizeof(WordCard));
			wordCardBinder->length++;
			wordCardBinder->current = (WordCard*)(node + 1);
			//1.1 ö��, ǰ��, �ǹ�, ���ø� �Է¹޴´�.
			flag = fread(&wordCard.word, sizeof(Word), 1, file);
		}
		fclose(file);
	}
	//2. ������ ����Ѵ�.
	return wordCardBinder->length;
	//3. ������.
}

//TakeIn
WordCard* TakeIn(WordCardBinder* wordCardBinder, WordCard wordCard)
{
	Node* node;
	
	//1. �ܾ�ī�带 �Է¹޴´�.
	//2. �ܾ�ī�带 �����.
	node = AppendFromTail(&wordCardBinder->wordCards, &wordCard, sizeof(WordCard));
	//3. �ܾ�ī��ö�� ������ �ø���.
	wordCardBinder->length++;
	//4. �ܾ�ī���� ���� ��ġ�� �����Ѵ�.
	wordCardBinder->current = (WordCard*)(node + 1);
	//5. ������ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//6. ������.
}

//FindBySpellings
void FindBySpellings(WordCardBinder* wordCardBinder, char(*spellings), WordCard** (*indexes), Long* count)
{
	Node* (*nodes);
	Long i = 0;

	*indexes = NULL;
	*count = 0;
	//1. ö�ڸ� �Է¹޴´�.
	//2. �ܾ�ī��ö�� ã���� �ϴ� �ܾ �ִ��� ã�´�.
	LinearSearchDuplicate(&wordCardBinder->wordCards, spellings, &nodes, count, CompareSpellings);
	//3. ã�� �ܾ ������
	if (*count > 0)
	{
		//3.1  ��ġ�� �迭�� �����.
		*indexes = (WordCard * (*))calloc(*count, sizeof(WordCard*));
	}
	//4. ã�� �ܾ����ŭ �ݺ��Ѵ�.
	while (i < *count)
	{
		//4.1 ã�� �ܾ��� ��ġ�� �����Ѵ�.
		(*indexes)[i] = (WordCard*)(nodes[i] + 1);
		i++;
	}
	//5. �Ҵ������Ѵ�.
	if (nodes != NULL)
	{
		free(nodes);
	}
	//6. ��ġ��� ������ ����Ѵ�.
	//7. ������.
}

//FindByMeanings
void FindByMeanings(WordCardBinder* wordCardBinder, char(*meanings), WordCard** (*indexes), Long* count)
{
	Node* (*nodes);
	Long i = 0;

	*indexes = NULL;
	*count = 0;
	//1. �ǹ̸� �Է¹޴´�.
	//2. �ܾ�ī��ö�� ã���� �ϴ� �ܾ �ִ��� ã�´�.
	LinearSearchDuplicate(&wordCardBinder->wordCards, meanings, &nodes, count, CompareMeanings);
	//3. ã�� �ܾ ������
	if (*count > 0)
	{
		//3.1  ��ġ�� �迭�� �����.
		*indexes = (WordCard * (*))calloc(*count, sizeof(WordCard*));
	}
	//4. ã�� �ܾ����ŭ �ݺ��Ѵ�.
	while (i < *count)
	{
		//4.1 ã�� �ܾ��� ��ġ�� �����Ѵ�.
		(*indexes)[i] = (WordCard*)(nodes[i] + 1);
		i++;
	}
	//5. �Ҵ������Ѵ�.
	if (nodes != NULL)
	{
		free(nodes);
	}
	//6. ��ġ��� ������ ����Ѵ�.
	//7. ������.
}

//TakeOut
WordCard TakeOut(WordCardBinder* wordCardBinder, WordCard* index)
{
	WordCard wordCard;
	Node* node;

	//1. ��ġ�� �Է¹޴´�.
	//2. ��ġ�� ã�´�.
	node = LinearSearchUnique(&wordCardBinder->wordCards, index, CompareWordCards);
	//3. �ܾ�ī�带 ������.
	GetAt(&wordCardBinder->wordCards, node, &wordCard, sizeof(WordCard));
	//4. �ܾ�ī�带 ���ش�.
	Delete(&wordCardBinder->wordCards, node);
	//5. �ܾ�ī��ö�� �ܾ ����������
	if (wordCardBinder->wordCards.current != NULL)
	{
		wordCardBinder->current = (WordCard*)(wordCardBinder->wordCards.current + 1);
	}
	//6. �ܾ�ī��ö�� �ܾ ������
	else
	{
		wordCardBinder->current = NULL;
	}
	//7. �ܾ�ī�尳���� ���ҽ�Ų��.
	wordCardBinder->length--;
	//8. �ܾ�ī�带 ����Ѵ�.
	return wordCard;
	//9. ������.
}

//Move
WordCard* WordCardBinder_Move(WordCardBinder* wordCardBinder, WordCard* index)
{
	Node* node;
	//1. ��ġ�� �Է¹޴´�.
	//2. ���� ��ġ�� �Է¹��� ��ġ�� �ٲ۴�.
	node = LinearSearchUnique(&wordCardBinder->wordCards, index, CompareWordCards);
	node = Move(&wordCardBinder->wordCards, node);
	wordCardBinder->current = (WordCard*)(node + 1);
	//3. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//4. ������.
}

//First
WordCard* WordCardBinder_First(WordCardBinder* wordCardBinder)
{
	Node* node;
	//1. ���� ��ġ�� ó������ �̵���Ų��.
	node = First(&wordCardBinder->wordCards);
	wordCardBinder->current = (WordCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}

//Previous
WordCard* WordCardBinder_Previous(WordCardBinder* wordCardBinder)
{
	Node* node;
	//1. ���� ��ġ�� �������� �̵���Ų��.
	node = Previous(&wordCardBinder->wordCards);
	wordCardBinder->current = (WordCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}

//Next
WordCard* WordCardBinder_Next(WordCardBinder* wordCardBinder)
{
	Node* node;
	//1. ���� ��ġ�� �������� �̵���Ų��.
	node = Next(&wordCardBinder->wordCards);
	wordCardBinder->current = (WordCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}

//Last
WordCard* WordCardBinder_Last(WordCardBinder* wordCardBinder)
{
	Node* node;
	//1. ���� ��ġ�� ���������� �̵���Ų��.
	node = Last(&wordCardBinder->wordCards);
	wordCardBinder->current = (WordCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}
#if 0
//Arrange
void Arrange(WordCardBinder* wordCardBinder)
{
	WordCard* previous;
	WordCard* next;
	Long i;
	Long j;
	Boolean flag = _TRUE;

	//1. �ܾ���� ö�ڸ� �������� �Ͽ� ������������ �����Ѵ�.
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
	//2. ������.
}
#endif

//Save
Long Save(WordCardBinder* wordCardBinder)
{
	WordCard wordCard;
	Node* it;
	Node* previous = NULL;
	FILE* file;

	file = fopen("WordCard.dat", "wb");
	if (file != NULL)
	{
		//1. �ܾ�ī��ö�� ���� �ƴѵ��� �ݺ��Ѵ�.
		it = First(&wordCardBinder->wordCards);
		while (it != previous)
		{
			GetAt(&wordCardBinder->wordCards, it, &wordCard, sizeof(WordCard));
			fwrite(&wordCard.word, sizeof(Word), 1, file);
			previous = it;
			it = Next(&wordCardBinder->wordCards);
		}
		fclose(file);
	}
	//2. ��뷮�� ����Ѵ�.
	return wordCardBinder->length;
	//3.������.
}

//Destroy
void WordCardBinder_Destroy(WordCardBinder* wordCardBinder)
{
	//1. �ܾ�ī��ö���� �ܾ�ī�带 ������� �����.
	Destroy(&wordCardBinder->wordCards);
	//2. ������.
}

//CompareSpellings
int CompareSpellings(void* one, void* other)
{
	WordCard* one_ = (WordCard*)one;
	char(*other_) = (char(*))other;

	return strcmp(one_->word.spellings, other_);
}

//CompareMeanings
int CompareMeanings(void* one, void* other)
{
	WordCard* one_ = (WordCard*)one;
	char(*other_) = (char(*))other;

	return strcmp(one_->word.meanings, other_);
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

