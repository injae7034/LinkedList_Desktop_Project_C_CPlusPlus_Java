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

	VisitingCard first = { {"정길동", "대리", "01024367967", "Jung@naver.com"}, {"삼성전자", "경기도 용인",
	"0313692447", "0312245674", "Samsung.com"}, NULL };
	VisitingCard second = { {"홍길동", "대리", "01036937428", "Hong@naver.com"}, {"신한은행", "서울 중구",
	"023798872", "023347713", "Shinhan.com"}, NULL };
	VisitingCard third = { {"차길동", "과장", "01036925571", "Cha@naver.com"}, {"엘지전자", "경기도 파주",
	"0312397871", "0313392468", "LG.com"}, NULL };
	VisitingCard fourth = { {"김길동", "부장", "01036901127", "Kim@naver.com"}, {"현대자동차", "울산 북구",
	"0524379702", "0524479981", "Hyundai.com"}, NULL };
	VisitingCard fifth = { {"나길동", "사원", "01036928827", "Na@naver.com"}, {"SK하이닉스", "경기도 이천",
	"0317789548", "0313692258", "SK.com"}, NULL };
	VisitingCard sixth = { {"장길동", "전무", "01044287990", "Jang@naver.com"}, {"노랑풍선", "서울 중구",
	"025578899", "029912970", "Yellow.com"}, NULL };
	VisitingCard visitingCard;

	//메인테스트 시나리오
	//1. 명함철을 만든다.
	Create(&visitingCardBinder);
	//2. 명함철에 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, first);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//3. 명함철에서 명함을 꺼낸다.
	visitingCard = TakeOut(&visitingCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", visitingCard.personal.name, visitingCard.personal.position,
		visitingCard.personal.cellularPhoneNumber, visitingCard.personal.emailAddress, visitingCard.company.name,
		visitingCard.company.address, visitingCard.company.telephoneNumber, visitingCard.company.faxNumber,
		visitingCard.company.url);
	printf("\n");
	//4. 명함철에 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, second);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//5. 명함철에 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, third);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//6. 명함철에 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, fourth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//7. 명함철에서 세 번째 명함을 꺼낸다.
	visitingCard = TakeOut(&visitingCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", visitingCard.personal.name, visitingCard.personal.position,
		visitingCard.personal.cellularPhoneNumber, visitingCard.personal.emailAddress, visitingCard.company.name,
		visitingCard.company.address, visitingCard.company.telephoneNumber, visitingCard.company.faxNumber,
		visitingCard.company.url);
	printf("\n");
	//8. 명함철에 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, fifth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//9. 명함철에서 차길동을 찾는다.
	Find(&visitingCardBinder, "차길동", &indexes, &count);
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
	//10. 차길동의 명함을 명함철에서 꺼낸다.
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
	//11. 명함철에서 명함을 끼운다.
	index = TakeIn(&visitingCardBinder, sixth);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//12. 명함철에서 명함을 끼운다.
	strcpy(visitingCard.personal.name, "홍길동");
	strcpy(visitingCard.personal.position, "이사");
	strcpy(visitingCard.personal.cellularPhoneNumber, "01098721234");
	strcpy(visitingCard.personal.emailAddress, "Hong@gmail.com");
	strcpy(visitingCard.company.name, "아시아나항공");
	strcpy(visitingCard.company.address, "서울 중구");
	strcpy(visitingCard.company.telephoneNumber, "028711297");
	strcpy(visitingCard.company.faxNumber, "023978819");
	strcpy(visitingCard.company.url, "Asiana.com");
	index = TakeIn(&visitingCardBinder, visitingCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("\n");
	//13. 명함철에서 홍길동을 찾는다.
	Find(&visitingCardBinder, "홍길동", &indexes, &count);
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
	//14. 명함철에서 처음으로 이동한다.
	index = First(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//15. 명함철에서 이전으로 이동한다.
	index = Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//16. 명함철에서 다음으로 이동한다.
	index = Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//17. 명함철에서 마지막으로 이동한다.
	index = Last(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//18. 명함철에서 다음으로 이동한다.
	index = Next(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	//19. 명함철에서 이전으로 이동한다.
	index = Previous(&visitingCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
		index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
	printf("정리하기전\n");
	//20. 개인의 성명을 기준으로 하여 자모음순으로 명함철을 정리한다.
	index = First(&visitingCardBinder);
	while (index != previous)
	{
		printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
			index->personal.cellularPhoneNumber, index->personal.emailAddress, index->company.name,
			index->company.address, index->company.telephoneNumber, index->company.faxNumber, index->company.url);
		previous = index;
		index = Next(&visitingCardBinder);
	}
	printf("정리한후\n");
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

	//21. 명함철을 없앤다.
	Destroy(&visitingCardBinder);

	return 0;
}

//Create
void Create(VisitingCardBinder* visitingCardBinder)
{
	//1. 명함을 만든다.
	visitingCardBinder->first = NULL;
	visitingCardBinder->length = 0;
	visitingCardBinder->current = NULL;
	//2. 끝내다.
}

//TakeIn
VisitingCard* TakeIn(VisitingCardBinder* visitingCardBinder, VisitingCard visitingCard)
{
	VisitingCard* previous = NULL;
	VisitingCard* it;

	//1. 명함을 입력받는다.
	//2. 명함을 놓을 위치를 찾는다.
	it = visitingCardBinder->first;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//3. 명함을 넣는다.
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
	//4. 명함철에서 개수를 늘린다.
	visitingCardBinder->length++;
	//5. 명함철의 현재 위치를 출력한다.
	return visitingCardBinder->current;
	//6. 끝내다.
}

//Find
void Find(VisitingCardBinder* visitingCardBinder, char(*name), VisitingCard** (*indexes), Long* count)
{
	VisitingCard* it;
	Long i = 0;

	*count = 0;
	//1. 성명을 입력받는다.
	//2. 위치들 배열을 만든다.
	*indexes = (VisitingCard * (*))calloc(visitingCardBinder->length, sizeof(VisitingCard*));
	//3. 명함의 마지막까지 반복한다.
	it = visitingCardBinder->first;
	while (it != NULL)
	{
		//3.1 명함의 성명과 입력받은 성명이 같으면
		if (strcmp(it->personal.name, name) == 0)
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
VisitingCard TakeOut(VisitingCardBinder* visitingCardBinder, VisitingCard* index)
{
	VisitingCard visitingCard;
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. 명함의 위치를 입력받는다.
	//2. 위치를 찾는다.
	it = visitingCardBinder->first;
	while (it != index)
	{
		previous = it;
		it = it->next;
	}
	//3. 명함을 꺼낸다.
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
	//4. 개수를 감소시킨다.
	visitingCardBinder->length--;
	//5. 명함을 출력한다.
	return visitingCard;
	//6. 끝내다.
}

//First
VisitingCard* First(VisitingCardBinder* visitingCardBinder)
{
	//1. 현재 위치를 처음으로 이동시킨다.
	visitingCardBinder->current = visitingCardBinder->first;
	//2. 현재위치를 출력한다.
	return visitingCardBinder->current;
	//3. 끝내다.
}

//Previous
VisitingCard* Previous(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. 현재 위치의 이전 위치를 찾는다.
	it = visitingCardBinder->first;
	while (it != visitingCardBinder->current)
	{
		previous = it;
		it = it->next;
	}
	//2. 현재 위치를 이전 위치로 이동시킨다.
	if (previous != NULL)
	{
		visitingCardBinder->current = previous;
	}
	//3. 현재 위치를 출력한다.
	return visitingCardBinder->current;
	//4. 끝내다.
}

//Next
VisitingCard* Next(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* previous;
	
	//1. 현재 위치를 다음 위치로 이동시킨다.
	previous = visitingCardBinder->current;
	visitingCardBinder->current = visitingCardBinder->current->next;
	if (visitingCardBinder->current == NULL)
	{
		visitingCardBinder->current = previous;
	}
	//2. 현재 위치를 출력한다.
	return visitingCardBinder->current;
	//3. 끝내다.
}

//Last
VisitingCard* Last(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* it;
	VisitingCard* previous = NULL;

	//1. 명함의 마지막 위치를 찾는다.
	it = visitingCardBinder->current;
	while (it != NULL)
	{
		previous = it;
		it = it->next;
	}
	//2. 현재 위치를 마지막으로 이동시킨다.
	visitingCardBinder->current = previous;
	//3. 현재 위치를 출력한다.
	return visitingCardBinder->current;
	//4. 끝내다.

}

//Arrange
void Arrange(VisitingCardBinder* visitingCardBinder)
{
	VisitingCard* previous;
	VisitingCard* next;
	Long i;
	Long j;
	Boolean flag = TRUE;

	//1. 명함철의 명함들을 성명을 기준으로 자모음순으로 정렬한다.
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
	//2. 끝내다.
}

//Destroy
void Destroy(VisitingCardBinder* visitingCardBinder)
{
	//1. 명함철에서 순서대로 명함을 지운다.
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
	//2. 끝내다.
}
