#include "VisitingCardBinder.h"
#include<stdio.h>//printf, feof
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
	//Load
	Load(&visitingCardBinder);
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
	visitingCard = TakeOut(&visitingCardBinder, indexes[count - 1]);
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
	printf("\n");
#if 0
	// ���� ������ ��ġ�� �ٲ۴�.
	index = Move(&visitingCardBinder, indexes[0]);
	printf("%s %s %s %s %s %s %s %s %s\n", indexes[0]->personal.name, indexes[0]->personal.position,
		indexes[0]->personal.cellularPhoneNumber, indexes[0]->personal.emailAddress,
		indexes[0]->company.name, indexes[0]->company.address, indexes[0]->company.telephoneNumber,
		indexes[0]->company.faxNumber, indexes[0]->company.url);
	printf("\n");
#endif
	if (indexes != NULL)
	{
		free(indexes);
	}
	printf("\n");
#if 0
	//�Ｚ���ڸ� ã�´�.
	index = FindByCompanyName(&visitingCardBinder, "�Ｚ����");
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
#endif
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
	//Save
	Save(&visitingCardBinder);
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

//Load
Long Load(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard visitingCard;
	VisitingCard* previous = NULL;
	Long i;
	Long index;
	int flag;
	FILE* personalFile;
	FILE* companyFile;

	personalFile = fopen("PersonalVisitingCard.dat", "rb");
	companyFile = fopen("CompanyVisitingCard.dat", "rb");
	if (personalFile != NULL && companyFile != NULL)
	{
		//1.1 ȸ�� ��ġ, ������ ����, ��å, �޴�����ȣ, �̸����ּҸ� �Է¹޴´�.
		fread(&index, sizeof(Long), 1, personalFile);
		flag = fread(&visitingCard.personal, sizeof(Personal), 1, personalFile);
		//1. ������ ���� �ƴѵ��� �ݺ��Ѵ�.
		while (!feof(personalFile) && flag != 0)
		{
			//1.2.1 ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� �Է¹޴´�.
			fseek(companyFile, 0L, SEEK_SET);
			i = 1;
			flag = fread(&visitingCard.company, sizeof(Company), 1, companyFile);
			//1.2 ȸ���� ��ġ�� ã�´�.
			while (!feof(companyFile) && flag != 0 && i < index)
			{
				i++;
				//1.2.1 ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� �Է¹޴´�.
				flag = fread(&visitingCard.company, sizeof(Company), 1, companyFile);
			}
			//1.3 ������ �����.
			visitingCard.next = NULL;
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
			visitingCardBinder->length++;
			previous = visitingCardBinder->current;
			//1.1 ȸ�� ��ġ, ������ ����, ��å, �޴�����ȣ, �̸����ּҸ� �Է¹޴´�.
			fread(&index, sizeof(Long), 1, personalFile);
			flag = fread(&visitingCard.personal, sizeof(Personal), 1, personalFile);
		}
		fclose(companyFile);
		fclose(personalFile);
	}
	//2. ��뷮�� ����Ѵ�.
	return visitingCardBinder->length;
	//3. ������.
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

//FindByCompanyName
VisitingCard* FindByCompanyName(VisitingCardBinder* visitingCardBinder, char(*companyName))
{
	VisitingCard* it;
	VisitingCard* index = NULL;

	//1. ȸ���̸��� �Է¹޴´�.
	//2. ������ ���������� �׸��� ���� �̸��� ���� �������� �ݺ��Ѵ�.
	it = visitingCardBinder->first;
	while (it != NULL && strcmp(it->company.name, companyName) != 0)
	{
		it = it->next;
	}
	//3. ��ġ�� �����Ѵ�.
	if (it != NULL)
	{
		index = it;
	}
	//4. ��ġ�� ����Ѵ�.
	return index;
	//5. ������
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
		visitingCardBinder->current = index->next;
	}
	else
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

//Move
VisitingCard* Move(VisitingCardBinder* visitingCardBinder, VisitingCard* index)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. ���� ��ġ�� �Է¹��� ��ġ�� �����Ѵ�.
	visitingCardBinder->current = index;
	//3. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//4. ������.
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
	Boolean flag = _TRUE;

	//1. ����ö�� ���Ե��� ������ �������� �ڸ��������� �����Ѵ�.
	i = visitingCardBinder->length - 1;
	while (i >= 1 && flag == _TRUE)
	{
		previous = NULL;
		visitingCardBinder->current = visitingCardBinder->first;
		next = visitingCardBinder->current->next;
		flag = _FALSE;
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
				flag = _TRUE;
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

//Save
Long Save(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* it;
	Long index;
	Company company;
	int flag;
	FILE* personalFile;
	FILE* companyFile;

	companyFile = fopen("CompanyVisitingCard.dat", "wb+");
	personalFile = fopen("PersonalVisitingCard.dat", "wb");
	if (companyFile != NULL && personalFile != NULL)
	{
		//1. ����ö�� ���� �ƴѵ��� �ݺ��Ѵ�.
		it = visitingCardBinder->first;
		while (it != NULL)
		{
			//1.1.1 ��ũ���Ͽ��� ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� �д´�.
			fseek(companyFile, 0L, SEEK_SET);
			index = 1;
			flag = fread(&company, sizeof(Company), 1, companyFile);
			//1.1 ������ ���� �ƴѵ��� �׸��� ������ ��ȣ��� ����ö�� ��ȣ���� ���� ���� �������� �ݺ��Ѵ�.
			while (!feof(companyFile) && flag != 0 && strcmp(it->company.name, company.name) != 0)
			{
				//1.1.2 ȸ���� ��ġ�� ����.
				index++;
				//1.1.1 ��ũ���Ͽ��� ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� �д´�.
				flag = fread(&company, sizeof(Company), 1, companyFile);
			}
			//1.2 ������ ���̸�
			if (flag == 0)
			{
				//1.2.1 ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� ��ũ���Ͽ� ����Ѵ�.
				fwrite(&it->company, sizeof(Company), 1, companyFile);
			}
			//1.3 ȸ�� ��ġ, ������ ����, ��å, �޴�����ȣ, �̸����ּҸ� ��ũ���Ͽ� ����Ѵ�.
			fwrite(&index, sizeof(Long), 1, personalFile);
			fwrite(&it->personal, sizeof(Personal), 1, personalFile);
			it = it->next;
		}
		fclose(personalFile);
		fclose(companyFile);
	}
	//2. ������ ����Ѵ�.
	return visitingCardBinder->length;
	//3. ������.
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
