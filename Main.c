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

	//�����׽�Ʈ �ó�����
	//1. ���Ḯ��Ʈ�� �����. (Create)
	Create(&linkedList);
	//2. 100�� ���Ḯ��Ʈ���� �������� �߰��Ѵ�.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//3. ���Ḯ��Ʈ���� 100�� �����.(Delete)
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("���������ϴ�.\n");
	}
	//4. 100�� ���Ḯ��Ʈ���� �������� �߰��Ѵ�.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//5. 50�� ���Ḯ��Ʈ���� ó���� �߰��Ѵ�.(AppendFromHead)
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
	//6. 120�� ���Ḯ��Ʈ���� �������� �߰��Ѵ�.(AppendFromTail)
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
	//7. ��� �����. (DelteAllItems)
	DeleteAllItems(&linkedList);
	if (linkedList.head == NULL)
	{
		printf("�� ���������ϴ�.\n");
	}
	//8. 100�� ���Ḯ��Ʈ���� ó���� �߰��Ѵ�.(AppendFromHead)
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//9. 50�� ���Ḯ��Ʈ���� �������� �߰��Ѵ�.(AppendFromTail)
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
	//10. 120�� ���Ḯ��Ʈ���� ó���� �߰��Ѵ�.(AppendFromHead)
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
	//11. ���Ḯ��Ʈ���� ó���� �����.(DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//12. ���Ḯ��Ʈ���� �������� �����. (DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//13. ���Ḯ��Ʈ���� ó���� �����.(DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//14. 100�� ���Ḯ��Ʈ�ּ� �������� �߰��Ѵ�.(AppendFromTail)
	object = 100;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//15. ���Ḯ��Ʈ���� 50�� ó������ �տ� �߰��Ѵ�.(InsertBefore)
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
	//16.���Ḯ��Ʈ���� ���������� �̵��Ѵ�.(Last)
	index = Last(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//17. ���Ḯ��Ʈ���� ���������� �ڿ� 120�� �߰��Ѵ�.(InsertAfter)
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
	//18. ���Ḯ��Ʈ���� �������� �����.(DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//19. ���Ḯ��Ʈ���� ó���� �����. (DeleteFromHead)
	index = DeleteFromHead(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//20. ���Ḯ��Ʈ���� �������� �����. (DeleteFromTail)
	index = DeleteFromTail(&linkedList);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//21. 100�� ���Ḯ��Ʈ�� ó���� �߰��Ѵ�.(AppendFromHead)
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
	//22. ���Ḯ��Ʈ���� 50�� �������ڿ� �߰��Ѵ�.(InsertAfter)
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
	//23. ���Ḯ��Ʈ���� ó������ �̵��Ѵ�.(First)
	index = First(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//24. ���Ḯ��Ʈ���� ó������ �տ� 120�� �߰��Ѵ�.(InsertBefore)
	object = 120;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//25. ���Ḯ��Ʈ���� �������� �̵��Ѵ�.
	index = Next(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//26. ���Ḯ��Ʈ���� 90�� �ι�° �ڿ� �߰��Ѵ�.(InsertAfter)
	object = 90;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//27. ���Ḯ��Ʈ���� 200�� ����° �տ� �߰��Ѵ�.(InsertBefore)
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
	//28. ���Ḯ��Ʈ���� 90�� ã�´�.(LinearSearchUnique)
	key = 90;
	index = LinearSearchUnique(&linkedList, &key, Compare);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//29. ���Ḯ��Ʈ���� 90�� �����.(Delete)
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//30. ���Ḯ��Ʈ���� ó���� 50�� �߰��Ѵ�.(AppendFromHead)
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
	//31. ���Ḯ��Ʈ���� �ߺ��� 50�� ã�´�.(LinearSearchDuplicate)
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
	//32. ���Ḯ��Ʈ���� ó���� �����.(Delete)
	i = 0;
	index = Delete(&linkedList, indexes[i]);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//33. ���������� �̵��Ѵ�.(Move)
	i = 1;
	index = Move(&linkedList, indexes[i]);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	if (indexes != NULL)
	{
		free(indexes);
	}
	//34. �������� �̵��Ѵ�.
	index = Next(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//35. ���Ḯ��Ʈ���� �������� �����.
	index = Delete(&linkedList, index);
	if (index == NULL)
	{
		printf("���������ϴ�.	");
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
	//36. ���Ḯ��Ʈ���� �������� �̵��Ѵ�.(Previous)
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//37. ���Ḯ��Ʈ���� ó������ �̵��Ѵ�.(First)
	index = First(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//38. ���Ḯ��Ʈ���� �������� �̵��Ѵ�. (Previous)
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &value, sizeof(Long));
	printf("%d\n", value);
	//39. ���Ḯ��Ʈ�� ���ش�. (Destroy)
	Destroy(&linkedList);
	return 0;
}

//�Լ�������
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