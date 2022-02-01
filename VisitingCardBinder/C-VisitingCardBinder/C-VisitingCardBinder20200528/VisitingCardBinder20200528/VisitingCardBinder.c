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
	Long count;
	Long i;
	VisitingCard visitingCard;
	VisitingCard first = { {"���浿", "�븮", "01024367967", "Jung@naver.com"}, {"�Ｚ����", "��⵵ ����",
	"0313692447", "0312245674", "Samsung.com"}};

	VisitingCard second = { {"ȫ�浿", "�븮", "01036937428", "Hong@naver.com"}, {"��������", "���� �߱�",
	"023798872", "023347713", "Shinhan.com"}};
	VisitingCard third = { {"���浿", "����", "01036925571", "Cha@naver.com"}, {"��������", "��⵵ ����",
	"0312397871", "0313392468", "LG.com"}};
	VisitingCard fourth = { {"��浿", "����", "01036901127", "Kim@naver.com"}, {"�����ڵ���", "��� �ϱ�",
	"0524379702", "0524479981", "Hyundai.com"}};
	VisitingCard fifth = { {"���浿", "���", "01036928827", "Na@naver.com"}, {"SK���̴н�", "��⵵ ��õ",
	"0317789548", "0313692258", "SK.com"}};
	VisitingCard sixth = { {"��浿", "����", "01044287990", "Jang@naver.com"}, {"���ǳ��", "���� �߱�",
	"025578899", "029912970", "Yellow.com"}};

	//�����׽�Ʈ �ó�����
	//1. ����ö�� �����.
	VisitingCardBinder_Create(&visitingCardBinder);
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
	printf("\n");
	// ���� ������ ��ġ�� �ٲ۴�.
	index = VisitingCardBinder_Move(&visitingCardBinder, indexes[0]);
	printf("%s %s %s %s %s %s %s %s %s\n", indexes[0]->personal.name, indexes[0]->personal.position,
		indexes[0]->personal.cellularPhoneNumber, indexes[0]->personal.emailAddress,
		indexes[0]->company.name, indexes[0]->company.address, indexes[0]->company.telephoneNumber,
		indexes[0]->company.faxNumber, indexes[0]->company.url);
	printf("\n");
	if (indexes != NULL)
	{
		free(indexes);
	}
	//���ǳ���� ã�´�.
	index = FindByCompanyName(&visitingCardBinder, "���ǳ��");
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//14. ����ö���� ó������ �̵��Ѵ�.
	index = VisitingCardBinder_First(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//15. ����ö���� �������� �̵��Ѵ�.
	index = VisitingCardBinder_Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//16. ����ö���� �������� �̵��Ѵ�.
	index = VisitingCardBinder_Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//17. ����ö���� ���������� �̵��Ѵ�.
	index = VisitingCardBinder_Last(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//18. ����ö���� �������� �̵��Ѵ�.
	index = VisitingCardBinder_Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//19. ����ö���� �������� �̵��Ѵ�.
	index = VisitingCardBinder_Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
#if 0
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
#endif
	//Save
	Save(&visitingCardBinder);
	//20. ����ö�� ���ش�.
	VisitingCardBinder_Destroy(&visitingCardBinder);

	return 0;
}

//Create
void VisitingCardBinder_Create(VisitingCardBinder* visitingCardBinder)
{
	//1. ������ �����.
	Create(&visitingCardBinder->visitingCards);
	visitingCardBinder->length = 0;
	visitingCardBinder->current = NULL;
	//2. ������.
}

//Load
Long Load(VisitingCardBinder* visitingCardBinder)
{
	Node* node;
	VisitingCard visitingCard;
	Long i;
	Long index;//ȸ����ġ
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
			node = AppendFromTail(&visitingCardBinder->visitingCards, &visitingCard, sizeof(VisitingCard));
			visitingCardBinder->length++;
			visitingCardBinder->current = (VisitingCard*)(node + 1);
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
	Node* node;

	//1. ������ �Է¹޴´�.
	//2. ������ ���� ��ġ�� ã�´�.
	//3. ������ �ִ´�.
	node = AppendFromTail(&visitingCardBinder->visitingCards, &visitingCard, sizeof(VisitingCard));
	//4. ����ö���� ������ �ø���.
	visitingCardBinder->length++;
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//5. ����ö�� ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//6. ������.
}

//Find
void Find(VisitingCardBinder* visitingCardBinder, char(*name), VisitingCard** (*indexes), Long* count)
{
	Node* (*nodes);
	Long i = 0;

	*count = 0;
	*indexes = NULL;
	//1. ������ �Է¹޴´�.
	LinearSearchDuplicate(&visitingCardBinder->visitingCards, name, &nodes, count, ComparePersoanlNames);
	//2. ������ 0���� ũ��
	if (*count > 0)
	{
		//2.1 ��ġ�� �迭�� �����.
		*indexes = (VisitingCard * (*))calloc(*count, sizeof(VisitingCard*));
	}
	//3. ã�� ������ŭ �ݺ��Ѵ�.
	while (i < *count)
	{
		//3.1 ��ġ�� �����Ѵ�.
		(*indexes)[i] = (VisitingCard*)(nodes[i] + 1);
		i++;
	}
	//4. �Ҵ������Ѵ�.
	if (nodes != NULL)
	{
		free(nodes);
	}
	//5. ��ġ��� ������ ����Ѵ�.
	//6. ������.
}

//FindByCompanyName
VisitingCard* FindByCompanyName(VisitingCardBinder* visitingCardBinder, char(*companyName))
{
	Node* node;
	VisitingCard* index = NULL;

	//1. ȸ���̸��� �Է¹޴´�.
	//2. ����ö�� �Է¹��� ȸ�簡 �ִ��� ã�´�.
	node = LinearSearchUnique(&visitingCardBinder->visitingCards, companyName, CompareCompanyNames);
	//3. �Է¹��� ȸ�簡 ����ö�� ������
	if (node != NULL)
	{
		//3.1 ��ġ�� �����Ѵ�.
		index = (VisitingCard*)(node + 1);
	}
	//4. ��ġ�� ����Ѵ�.
	return index;
	//5. ������
}

//TakeOut
VisitingCard TakeOut(VisitingCardBinder* visitingCardBinder, VisitingCard* index)
{
	VisitingCard visitingCard;
	Node* node;

	//1. ������ ��ġ�� �Է¹޴´�.
	//2. ��ġ�� ã�´�.
	node = LinearSearchUnique(&visitingCardBinder->visitingCards, index, CompareVisitingCards);
	//3. ������ ������.
	GetAt(&visitingCardBinder->visitingCards, node, &visitingCard, sizeof(VisitingCard));
	//4. ������ ���ش�.
	Delete(&visitingCardBinder->visitingCards, node);
	//5. ����ö�� ������ �����ִ� ��쿡
	if (visitingCardBinder->visitingCards.current != NULL)
	{
		//5.1 ������ġ�� �����Ѵ�.
		visitingCardBinder->current = (VisitingCard*)(visitingCardBinder->visitingCards.current + 1);
	}
	//6. ����ö�� ������ ���� ��쿡
	else
	{
		visitingCardBinder->current = NULL;
	}
	//7. ����ö�� ���԰����� ���ҽ�Ų��.
	visitingCardBinder->length--;
	//8. ������ ����Ѵ�.
	return visitingCard;
	//9. ������.
}

//Move
VisitingCard* VisitingCardBinder_Move(VisitingCardBinder* visitingCardBinder, VisitingCard* index)
{
	Node* node;
	//1. ��ġ�� �Է¹޴´�.
	node = LinearSearchUnique(&visitingCardBinder->visitingCards, index, CompareVisitingCards);
	//2. ���� ��ġ�� �Է¹��� ��ġ�� �����Ѵ�.
	node = Move(&visitingCardBinder->visitingCards, node);
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//3. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//4. ������.
}


//First
VisitingCard* VisitingCardBinder_First(VisitingCardBinder* visitingCardBinder)
{
	Node* node;
	//1. ���� ��ġ�� ó������ �̵���Ų��.
	node = First(&visitingCardBinder->visitingCards);
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//2. ������ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.
}

//Previous
VisitingCard* VisitingCardBinder_Previous(VisitingCardBinder* visitingCardBinder)
{
	Node* node;

	//1. ���� ��ġ�� �������� �̵���Ų��.
	node = Previous(&visitingCardBinder->visitingCards);
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.
}

//Next
VisitingCard* VisitingCardBinder_Next(VisitingCardBinder* visitingCardBinder)
{
	Node* node;
	
	//1. ���� ��ġ�� �������� �̵���Ų��.
	node = Next(&visitingCardBinder->visitingCards);
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.
}

//Last
VisitingCard* VisitingCardBinder_Last(VisitingCardBinder* visitingCardBinder)
{
	Node* node;

	//1. ���� ��ġ�� ���������� �̵���Ų��.
	node = Last(&visitingCardBinder->visitingCards);
	visitingCardBinder->current = (VisitingCard*)(node + 1);
	//2. ���� ��ġ�� ����Ѵ�.
	return visitingCardBinder->current;
	//3. ������.

}
#if 0
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
#endif

//Save
Long Save(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard visitingCard;
	Long index;
	Company company;
	Node* it;
	Node* previous = NULL;
	int flag;
	FILE* personalFile;
	FILE* companyFile;

	companyFile = fopen("CompanyVisitingCard.dat", "wb+");
	personalFile = fopen("PersonalVisitingCard.dat", "wb");
	if (companyFile != NULL && personalFile != NULL)
	{
		//1. ����ö�� ���� �ƴѵ��� �ݺ��Ѵ�.
		it = First(&visitingCardBinder->visitingCards);
		while (it != previous)
		{
			GetAt(&visitingCardBinder->visitingCards, it, &visitingCard, sizeof(VisitingCard));
			//1.1.1 ��ũ���Ͽ��� ȸ���� ��ȣ��, �ּ�, ��ȭ��ȣ, �ѽ���ȣ, url�� �д´�.
			fseek(companyFile, 0L, SEEK_SET);
			index = 1;
			flag = fread(&company, sizeof(Company), 1, companyFile);
			//1.1 ������ ���� �ƴѵ��� �׸��� ������ ��ȣ��� ����ö�� ��ȣ���� ���� ���� �������� �ݺ��Ѵ�.
			while (!feof(companyFile) && flag != 0 && strcmp(visitingCard.company.name, company.name) != 0)
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
				fwrite(&visitingCard.company, sizeof(Company), 1, companyFile);
			}
			//1.3 ȸ�� ��ġ, ������ ����, ��å, �޴�����ȣ, �̸����ּҸ� ��ũ���Ͽ� ����Ѵ�.
			fwrite(&index, sizeof(Long), 1, personalFile);
			fwrite(&visitingCard.personal, sizeof(Personal), 1, personalFile);
			previous = it;
			it = Next(&visitingCardBinder->visitingCards);
		}
		fclose(personalFile);
		fclose(companyFile);
	}
	//2. ������ ����Ѵ�.
	return visitingCardBinder->length;
	//3. ������.
}

//Destroy
void VisitingCardBinder_Destroy(VisitingCardBinder* visitingCardBinder)
{
	//1. ����ö���� ������� ������ �����.
	Destroy(&visitingCardBinder->visitingCards);
	//2. ������.
}

int ComparePersoanlNames(void* one, void* other)
{
	VisitingCard* one_ = (VisitingCard*)one;
	char(*other_) = (char(*))other;

	return strcmp(one_->personal.name, other_);
}

int CompareCompanyNames(void* one, void* other)
{
	VisitingCard* one_ = (VisitingCard*)one;
	char(*other_) = (char(*))other;

	return strcmp(one_->company.name, other_);
}

int CompareVisitingCards(void* one, void* other)
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
