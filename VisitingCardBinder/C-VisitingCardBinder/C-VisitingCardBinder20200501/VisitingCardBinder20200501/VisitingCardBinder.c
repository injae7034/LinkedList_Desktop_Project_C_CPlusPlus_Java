#include "VisitingCardBinder.h"
#include<stdio.h>//printf
#include<stdlib.h>//calloc, malloc, free
#include<string.h>//strcpy, strcmp
#pragma warning(disable:4996)

int main(int argc, char* argv[])
{
	VisitingCardBinder visitingCardBinder;
	VisitingCard* index;
	VisitingCard* (*indexes);
	VisitingCard* previous = NULL;
	Long count;
	Long i;

	VisitingCard first = { {"���浿", "�븮", "01024367967", "Jung@naver.com"}, {"�Ｚ����", "��⵵ ����",
	"0313692447", "0312245674", "Samsung.com"}, NULL };
	VisitingCard second = { {"ȫ�浿", "�븮", "01036937428", "Hong@naver.com"}, {"��������", "���� �߱�",
	"023798872", "023347713", "Shinhan.com"}, NULL };
	VisitingCard third = { {"���浿", "����", "01036925571", "Cha@naver.com"}, {"��������", "��⵵ ����",
	"0312397871", "0313392468", "LG.com"}, NULL };
	VisitingCard fourth = { {"��浿", "����", "01036901127", "Kim@naver.com"}, {"�����ڵ���", "��� �ϱ�",
	"0524379702", "0524479981", "Hyundai.com"}, NULL };
	VisitingCard fifth = { {"���浿", "���", "01036928827", "Na@naver.com"}, {"SK���̴н�", "��⵵ ��õ",
	"0317789548", "0313692258", "SK.com"}, NULL };
	VisitingCard sixth = { {"��浿", "����", "01044287990", "Jang@naver.com"}, {"���ǳ��", "���� �߱�",
	"025578899", "029912970", "Yellow.com"}, NULL };
	VisitingCard visitingCard;

	//�����׽�Ʈ �ó�����
	//1. ����ö�� �����.
	Create(&visitingCardBinder);
	//2. ����ö�� ������ �����.
	index = TakeIn(&visitingCardBinder, first);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//3. ����ö���� ������ ������.
	visitingCard = TakeOut(&visitingCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", visitingCard.personal.name, visitingCard.personal.position,
		visitingCard.personal.cellularPhoneNumber, visitingCard.personal.emailAddress, visitingCard.company.name,
		visitingCard.company.address, visitingCard.company.telephoneNumber, visitingCard.company.faxNumber,
		visitingCard.company.url);
	printf("\n");
	//4. ����ö�� ������ �����.
	index = TakeIn(&visitingCardBinder, second);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//5. ����ö�� ������ �����.
	index = TakeIn(&visitingCardBinder, third);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//6. ����ö�� ������ �����.
	index = TakeIn(&visitingCardBinder, fourth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//7. ����ö���� �� ��° ������ ������.
	visitingCard = TakeOut(&visitingCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", visitingCard.personal.name, visitingCard.personal.position,
		visitingCard.personal.cellularPhoneNumber, visitingCard.personal.emailAddress, visitingCard.company.name,
		visitingCard.company.address, visitingCard.company.telephoneNumber, visitingCard.company.faxNumber,
		visitingCard.company.url);
	printf("\n");
	//8. ����ö�� ������ �����.
	index = TakeIn(&visitingCardBinder, fifth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//9. ����ö���� ���浿�� ã�´�.
	Find(&visitingCardBinder, "���浿", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s %s %s %s %s %s\n", indexes[i]->personal.name, indexes[i]->personal.position,
			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress, 
			indexes[i]->company.name, indexes[i]->company.address, indexes[i]->company.telephoneNumber, 
			indexes[i]->company.faxNumber, indexes[i]->company.url);
		i++;
	}
	printf("\n");
	//10. ���浿�� ������ ����ö���� ������.
	visitingCard = TakeOut(&visitingCardBinder, indexes[count-1]);
	printf("%s %s %s %s %s %s %s %s %s\n", visitingCard.personal.name, visitingCard.personal.position,
		visitingCard.personal.cellularPhoneNumber, visitingCard.personal.emailAddress, visitingCard.company.name,
		visitingCard.company.address, visitingCard.company.telephoneNumber, visitingCard.company.faxNumber,
		visitingCard.company.url);
	printf("\n");
	if (indexes != NULL)
	{
		free(indexes);
	}
	//11. ����ö���� ������ �����.
	index = TakeIn(&visitingCardBinder, sixth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//12. ����ö���� ������ �����.
	strcpy(visitingCard.personal.name, "ȫ�浿");
	strcpy(visitingCard.personal.position, "�̻�");
	strcpy(visitingCard.personal.cellularPhoneNumber, "01098721234");
	strcpy(visitingCard.personal.emailAddress, "Hong@gmail.com");
	strcpy(visitingCard.company.name, "�ƽþƳ��װ�");
	strcpy(visitingCard.company.address, "���� �߱�");
	strcpy(visitingCard.company.telephoneNumber, "028711297");
	strcpy(visitingCard.company.faxNumber, "023978819");
	strcpy(visitingCard.company.url, "Asiana.com");
	index = TakeIn(&visitingCardBinder, visitingCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//13. ����ö���� ȫ�浿�� ã�´�.
	Find(&visitingCardBinder, "ȫ�浿", &indexes, &count);
	i = 0;
	while (i < count)
	{
		printf("%s %s %s %s %s %s %s %s %s\n", indexes[i]->personal.name, indexes[i]->personal.position,
			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress,
			indexes[i]->company.name, indexes[i]->company.address, indexes[i]->company.telephoneNumber,
			indexes[i]->company.faxNumber, indexes[i]->company.url);
		i++;
	}
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
	//14. ����ö���� ó������ �̵��Ѵ�.
	index = First(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//15. ����ö���� �������� �̵��Ѵ�.
	index = Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//16. ����ö���� �������� �̵��Ѵ�.
	index = Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//17. ����ö���� ���������� �̵��Ѵ�.
	index = Last(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//18. ����ö���� �������� �̵��Ѵ�.
	index = Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//19. ����ö���� �������� �̵��Ѵ�.
	index = Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("�����ϱ���\n");
	//20. ������ ������ �������� �Ͽ� �ڸ��������� ����ö�� �����Ѵ�.
	index = First(&visitingCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
			index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
			index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
		previous = index;
		index = Next(&visitingCardBinder);
	}
	printf("��������\n");
	Arrange(&visitingCardBinder);
	index = First(&visitingCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
			index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
			index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
		previous = index;
		index = Next(&visitingCardBinder);
	}

	//21. ����ö�� ���ش�.
	Destroy(&visitingCardBinder);

	return 0;
}

//Create
void Create(VisitingCardBinder* visitingCardBinder)
{
	//1. ������ �����.
	visitingCardBinder->first = NULL;
	visitingCardBinder->length = 0;
	visitingCardBinder->current = NULL;
	//2. ������.
}

//TakeIn
VisitingCard* TakeIn(VisitingCardBinder* visitingCardBinder, VisitingCard visitingCard)
{
	VisitingCard* previous = NULL;
	VisitingCard* it;

	//1. ������ �Է¹޴´�.
	//2. ������ ���� ��ġ�� ã�´�.
	it = visitingCardBinder->first;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//3. ������ �ִ´�.
	visitingCardBinder->current = (VisitingCard*)malloc(sizeof(VisitingCard));
	*visitingCardBinder->current = visitingCard;
	if (previous != NULL)
	{
		previous->next = visitingCardBinder->current;
	}
	else
	{
		visitingCardBinder->first = visitingCardBinder->current;
	}
	//4. ����ö���� ������ �ø���.
	visitingCardBinder->length++;
	//5. ����ö�� ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//6. ������.
}

//Find
void Find(VisitingCardBinder* visitingCardBinder, char(*name), VisitingCard** (*indexes), Long* count)
{
	VisitingCard* it;
	Long i = 0;

	*count = 0;
	//1. ������ �Է¹޴´�.
	//2. ��ġ�� �迭�� �����.
	*indexes = (VisitingCard * (*))calloc(visitingCardBinder->length, sizeof(VisitingCard*));
	//3. ������ ���������� �ݺ��Ѵ�.
	it = visitingCardBinder->first;
	while (it != NULL)
	{
		//3.1 ������ ����� �Է¹��� ������ ������
		if (strcmp(it->personal.name, name) == 0)
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
VisitingCard TakeOut(VisitingCardBinder* visitingCardBinder, VisitingCard* index)
{
	VisitingCard visitingCard;
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. ������ ��ġ�� �Է¹޴´�.
	//2. ��ġ�� ã�´�.
	it = visitingCardBinder->first;
	while (it != index)
	{
		previous = it;
		it = it->next;
	}
	//3. ������ ������.
	if (previous != NULL)
	{
		previous->next = index->next;
	}
	else
	{
		visitingCardBinder->first = index->next;
	}
	if (index->next != NULL)
	{
		visitingCardBinder->current = previous;
	}
	visitingCard = *index;
	visitingCard.next = NULL;
	if (index != NULL)
	{
		free(index);
	}
	//4. ������ ���ҽ�Ų��.
	visitingCardBinder->length--;
	//5. ������ ����Ѵ�.
	return visitingCard;
	//6. ������.
}

//First
VisitingCard* First(VisitingCardBinder* visitingCardBinder)
{
	//1. ���� ��ġ�� ó������ �̵���Ų��.
	visitingCardBinder->current = visitingCardBinder->first;
	//2. ������ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.
}

//Previous
VisitingCard* Previous(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. ���� ��ġ�� ���� ��ġ�� ã�´�.
	it = visitingCardBinder->first;
	while (it != visitingCardBinder->current)
	{
		previous = it;
		it = it->next;
	}
	//2. ���� ��ġ�� ���� ��ġ�� �̵���Ų��.
	if (previous != NULL)
	{
		visitingCardBinder->current = previous;
	}
	//3. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//4. ������.
}

//Next
VisitingCard* Next(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* previous;
	
	//1. ���� ��ġ�� ���� ��ġ�� �̵���Ų��.
	previous = visitingCardBinder->current;
	visitingCardBinder->current = visitingCardBinder->current->next;
	if (visitingCardBinder->current == NULL)
	{
		visitingCardBinder->current = previous;
	}
	//2. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.
}

//Last
VisitingCard* Last(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. ������ ������ ��ġ�� ã�´�.
	it = visitingCardBinder->current;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//2. ���� ��ġ�� ���������� �̵���Ų��.
	visitingCardBinder->current = previous;
	//3. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//4. ������.

}

//Arrange
void Arrange(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* previous;
	VisitingCard* next;
	Long i;
	Long j;
	Boolean flag = TRUE;

	//1. ����ö�� ���Ե��� ������ �������� �ڸ��������� �����Ѵ�.
	i = visitingCardBinder->length - 1;
	while (i >= 1 && flag == TRUE)
	{
		previous = NULL;
		visitingCardBinder->current = visitingCardBinder->first;
		next = visitingCardBinder->current->next;
		flag = FALSE;
		j = 1;
		while (j <= i)
		{
			if (strcmp(visitingCardBinder->current->personal.name, next->personal.name) > 0)
			{
				visitingCardBinder->current->next = next->next;
				next->next = visitingCardBinder->current;
				if (previous != NULL)
				{
					previous->next = next;
				}
				else
				{
					visitingCardBinder->first = next;
				}
				previous = next;
				next = visitingCardBinder->current->next;
				flag = TRUE;
			}
			else
			{
				previous = visitingCardBinder->current;
				visitingCardBinder->current = next;
				next = visitingCardBinder->current->next;
			}
			j++;
		}
		i--;
	}
	//2. ������.
}

//Destroy
void Destroy(VisitingCardBinder* visitingCardBinder)
{
	//1. ����ö���� ������� ������ �����.
	visitingCardBinder->current = visitingCardBinder->first;
	while (visitingCardBinder->current != NULL)
	{
		visitingCardBinder->first = visitingCardBinder->current->next;
		if (visitingCardBinder->current != NULL)
		{
			free(visitingCardBinder->current);
		}
		visitingCardBinder->current = visitingCardBinder->first;
	}
	//2. ������.
}
