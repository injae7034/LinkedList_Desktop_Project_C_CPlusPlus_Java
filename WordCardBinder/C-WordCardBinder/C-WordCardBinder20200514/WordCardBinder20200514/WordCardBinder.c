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
	WordCard first = { {"apple", "���", "���", "Apples are sweet."}, NULL };
	WordCard second = { {"kind", "�����", "ģ����", "She is so kind."}, NULL };
	WordCard third = { {"flower", "���", "��", "The flowers are beautiful."}, NULL };
	WordCard fourth = { {"very", "�λ�", "�ſ�", "He is very tall."}, NULL };
	WordCard fifth = { {"banana", "���", "�ٳ���", "A banana is very sweet."}, NULL };
	WordCard sixth = { {"coffee", "���", "Ŀ��", "This coffee is good."}, NULL };
	WordCard seventh = { {"kind", "���", "����", "We serve two kinds of tea."}, NULL };

	//�����׽�Ʈ �ó�����
	//1. �ܾ�ī��ö�� �����.
	Create(&wordCardBinder);
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
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//18. ó������ �̵��Ѵ�.
	index = First(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//19. ������ġ�� �̵��Ѵ�.
	index = Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//20. �������� �̵��Ѵ�.
	index = Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//21. ���������� �̵��Ѵ�.
	index = Last(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//22. �������� �̵��Ѵ�.
	index = Next(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	//23. �������� �̵��Ѵ�.
	index = Previous(&wordCardBinder);
	printf("%s %s %s %s\n", index->word.spellings, index->word.partOfSpeech, index->word.meanings,
		index->word.example);
	printf("\n");
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
	//Save
	Save(&wordCardBinder);
	//25. �ܾ�ī��ö�� ���ش�.
	Destroy(&wordCardBinder);

	return 0;
}

//Create
void Create(WordCardBinder* wordCardBinder)
{
	//1. �ܾ�ī��ö�� �����.
	wordCardBinder->first = NULL;
	wordCardBinder->length = 0;
	wordCardBinder->current = NULL;
	//2. ������.
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
		//1.1 ö��, ǰ��, �ǹ�, ���ø� �Է¹޴´�.
		flag = fread(&wordCard.word, sizeof(Word), 1, file);
		//1. ������ ���� �ƴѵ��� �ݺ��Ѵ�.
		while (!feof(file) && flag != 0)
		{
			//1.2 �ܾ�ī�带 �����.
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
	WordCard* previous = NULL;
	WordCard* it;
	
	//1. �ܾ�ī�带 �Է¹޴´�.
	//2. �ܾ�ī�带 ���� ��ġ�� ã�´�.
	it = wordCardBinder->first;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//3. �ܾ�ī�带 �����.
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
	//4. �ܾ�ī��ö�� ������ �ø���.
	wordCardBinder->length++;
	//5. �ܾ�ī���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//6. ������.
}

//FindBySpellings
void FindBySpellings(WordCardBinder* wordCardBinder, char(*spellings), WordCard** (*indexes), Long* count)
{
	WordCard* it;
	Long i = 0;

	*count = 0;
	//1. ö�ڸ� �Է¹޴´�.
	//2. ��ġ�� �迭�� �����.
	*indexes = (WordCard * (*))calloc(wordCardBinder->length, sizeof(WordCard*));
	//3. �ܾ�ī��ö�� ���������� �ݺ��Ѵ�.
	it = wordCardBinder->first;
	while (it != NULL)
	{
		//3.1 �ܾ�ī���� ö�ڿ� �Է¹��� ö�ڰ� ���� ������
		if (strcmp(it->word.spellings, spellings) == 0)
		{
			//3.1.1 ��ġ�� �����Ѵ�.
			(*indexes)[i] = it;
			i++;
			//3.1.2 ������ ����.
			(*count)++;
		}
		it = it->next;
	}
	//4. ��ġ��� ������ ����Ѵ�.
	//5. ������.
}

//FindByMeanings
void FindByMeanings(WordCardBinder* wordCardBinder, char(*meanings), WordCard** (*indexes), Long* count)
{
	WordCard* it;
	Long i = 0;

	*count = 0;
	//1. �ǹ̸� �Է¹޴´�.
	//2. ��ġ�� �迭�� �����.
	*indexes = (WordCard * (*))calloc(wordCardBinder->length, sizeof(WordCard*));
	//3. �ܾ�ī��ö�� ������ �ܾ�ī����� �ݺ��Ѵ�.
	it = wordCardBinder->first;
	while(it != NULL)
	{
		//3.1 �ܾ�ī���� �ǹ̿� �Է¹��� �ǹ̰� ���� ������
		if (strcmp(it->word.meanings, meanings) == 0)
		{
			//3.1.1 ��ġ�� �����Ѵ�.
			(*indexes)[i] = it;
			i++;
			//3.1.2 ������ ����.
			(*count)++;
		}
		it = it->next;
	}
	//4. ��ġ��� ������ ����Ѵ�.
	//5. ������.
}

//TakeOut
WordCard TakeOut(WordCardBinder* wordCardBinder, WordCard* index)
{
	WordCard wordCard;
	WordCard* it;
	WordCard* previous = NULL;

	//1. ��ġ�� �Է¹޴´�.
	//2. ��ġ�� ã�´�.
	it = wordCardBinder->first;
	while (it != index)
	{
		previous = it;
		it = it->next;
	}
	//3. �ܾ�ī�带 ������.
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
	//4. ������ ���ҽ�Ų��.
	wordCardBinder->length--;
	//5. �ܾ�ī�带 ����Ѵ�.
	return wordCard;
	//6. ������.
}

//First
WordCard* First(WordCardBinder* wordCardBinder)
{
	//1. ���� ��ġ�� ó������ �̵���Ų��.
	wordCardBinder->current = wordCardBinder->first;
	//2. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}

//Previous
WordCard* Previous(WordCardBinder* wordCardBinder)
{
	WordCard* previous = NULL;
	WordCard* it;

	//1. ���� ��ġ�� ���� ��ġ�� ã�´�.
	it = wordCardBinder->first;
	while (it != wordCardBinder->current)
	{
		previous = it;
		it = it->next;
	}
	//2. ���� ��ġ�� ���� ��ġ�� �̵���Ų��.
	if (previous != NULL)
	{
		wordCardBinder->current = previous;
	}
	//3. ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//4. ������.
}

//Next
WordCard* Next(WordCardBinder* wordCardBinder)
{
	WordCard* previous;
	
	//1. ���� ��ġ�� ���� ��ġ�� �̵���Ų��.
	previous = wordCardBinder->current;
	wordCardBinder->current = wordCardBinder->current->next;
	if (wordCardBinder->current == NULL)
	{
		wordCardBinder->current = previous;
	}
	//2. ������ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//3. ������.
}

//Last
WordCard* Last(WordCardBinder* wordCardBinder)
{
	WordCard* it;
	WordCard* previous = NULL;

	//1. ������ ��ġ�� ã�´�.
	it = wordCardBinder->current;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//2. ���� ��ġ�� ������ ��ġ�� �̵���Ų��.
	wordCardBinder->current = previous;
	//3. �ܾ�ī��ö�� ���� ��ġ�� ����Ѵ�.
	return wordCardBinder->current;
	//4. ������.
}

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

//Save
Long Save(WordCardBinder* wordCardBinder)
{
	WordCard* it;
	FILE* file;

	file = fopen("WordCard.dat", "wb");
	if (file != NULL)
	{
		//1. �ܾ�ī��ö�� ���� �ƴѵ��� �ݺ��Ѵ�.
		it = wordCardBinder->first;
		while (it != NULL)
		{
			fwrite(&it->word, sizeof(Word), 1, file);
			it = it->next;
		}
		fclose(file);
	}
	//2. ��뷮�� ����Ѵ�.
	return wordCardBinder->length;
	//3.������.
}

//Destroy
void Destroy(WordCardBinder* wordCardBinder)
{
	//1. �ܾ�ī��ö���� �ܾ�ī�带 ������� �����.
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
	//2. ������.
}


