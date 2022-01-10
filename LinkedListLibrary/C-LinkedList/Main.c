#include "LinkedList.h"
#include<stdlib.h>//free
#include<stdio.h>//printf
#pragma warning(disable:4996)

int Compare(void* one, void* other);
int main(int argc, char* argv[])
{
	LinkedList linkedList;
	Node* index;
	Node* previous = NULL;
	Node** (*indexes);
	Long count;
	Long object;
	Long key;
	Long i;
	Long value;

	//메인테스트 시나리오
	//1. 연결리스트를 만든다. (Create)
	Create(&linkedList);
	//2. 100을 연결리스트에서 마지막에 추가한다.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//3. 연결리스트에서 100을 지운다.(Delete)
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("지워졌습니다.\n");
	}
	//4. 100을 연결리스트에서 마지막에 추가한다.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//5. 50을 연결리스트에서 처음에 추가한다.(AppendFromHead)
	object = 50;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//6. 120을 연결리스트에서 마지막에 추가한다.(AppendFromTail)
	object = 120;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//7. 모두 지운다. (DelteAllItems)
	DeleteAllItems(&linkedList);
	if (linkedList.head == NULL)
	{
		printf("다 지워졌습니다.\n");
	}
	//8. 100을 연결리스트에서 처음에 추가한다.(AppendFromHead)
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//9. 50을 연결리스트에서 마지막에 추가한다.(AppendFromTail)
	object = 50;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//10. 120을 연결리스트에서 처음에 추가한다.(AppendFromHead)
	object = 120;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//11. 연결리스트에서 처음을 지운다.(DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//12. 연결리스트에서 마지막을 지운다. (DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//13. 연결리스트에서 처음을 지운다.(DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//14. 100을 연결리스트애서 마지막에 추가한다.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//15. 연결리스트에서 50을 처음보다 앞에 추가한다.(InsertBefore)
	object = 50;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//16.연결리스트에서 마지막으로 이동한다.(Last)
	index = Last(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//17. 연결리스트에서 마지막보다 뒤에 120을 추가한다.(InsertAfter)
	object = 120;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//18. 연결리스트에서 마지막을 지운다.(DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//19. 연결리스트에서 처음을 지운다. (DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//20. 연결리스트에서 마지막을 지운다. (DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//21. 100을 연결리스트의 처음에 추가한다.(AppendFromHead)
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//22. 연결리스트에서 50을 마지막뒤에 추가한다.(InsertAfter)
	object = 50;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//23. 연결리스트에서 처음으로 이동한다.(First)
	index = First(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//24. 연결리스트에서 처음보다 앞에 120을 추가한다.(InsertBefore)
	object = 120;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//25. 연결리스트에서 다음으로 이동한다.
	index = Next(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//26. 연결리스트에서 90을 두번째 뒤에 추가한다.(InsertAfter)
	object = 90;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//27. 연결리스트에서 200을 세번째 앞에 추가한다.(InsertBefore)
	object = 200;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//28. 연결리스트에서 90을 찾는다.(LinearSearchUnique)
	key = 90;
	index = LinearSearchUnique(&linkedList, &key, Compare);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//29. 연결리스트에서 90을 지운다.(Delete)
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//30. 연결리스트에서 처음에 50을 추가한다.(AppendFromHead)
	object = 50;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	index = First(&linkedList);
	previous = NULL;
	while (index != previous)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		previous = index;
		index = Next(&linkedList);
	}
	printf("\n");
	//31. 연결리스트에서 중복된 50을 찾는다.(LinearSearchDuplicate)
	key = 50;
	LinearSearchDuplicate(&linkedList, &key, &indexes, &count, Compare);
	i = 0;
	while (i < count)
	{
		GetAt(&linkedList, index, &value, sizeof(Long));
		printf("%d ", value);
		i++;
	}
	printf("\n");
	//32. 연결리스트에서 처음을 지운다.(Delete)
	i = 0;
	index = Delete(&linkedList, indexes[i]);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//33. 마지막으로 이동한다.(Move)
	i = 1;
	index = Move(&linkedList, indexes[i]);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	if (indexes != NULL)
	{
		free(indexes);
	}
	//34. 다음으로 이동한다.
	index = Next(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//35. 연결리스트에서 마지막을 지운다.
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("지워졌습니다.	");
		index = First(&linkedList);
		previous = NULL;
		while (index != previous)
		{
			GetAt(&linkedList, index, &value, sizeof(Long));
			printf("%d ", value);
			previous = index;
			index = Next(&linkedList);
		}
		printf("\n");
	}
	//36. 연결리스트에서 이전으로 이동한다.(Previous)
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//37. 연결리스트에서 처음으로 이동한다.(First)
	index = First(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//38. 연결리스트에서 이전으로 이동한다. (Previous)
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//39. 연결리스트를 없앤다. (Destroy)
	Destroy(&linkedList);
	return 0;
}

//함수포인터
int Compare(void* one, void* other)
{
	Long* one_ = (Long*)one;
	Long* other_ = (Long*)other;
	int ret;
	if (*one_ > * other_)
	{
		ret = 1;
	}
	else if (*one_ == *other_)
	{
		ret = 0;
	}
	else if (*one_ < *other_)
	{
		ret = -1;
	}
	return ret;
}