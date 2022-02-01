#include "LinkedList.h"
#include<stddef.h>//size_t
#include<stdlib.h>//free, malloc, calloc
#include<memory.h>//memcpy
#pragma warning(disable:4996)


//Create
void Create(LinkedList* linkedList)
{
	//1. ���Ḯ��Ʈ�� �����.
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->length = 0;
	linkedList->current = NULL;
	//2. ������.
}

//InsertBefore
Node* InsertBefore(LinkedList* linkedList, Node* index, void* object, size_t size)
{
	//1. ��ġ�� �����͸� �Է¹޴´�.
	//2. ���ο� ��带 �����.
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->next = index;
	//3. ���� ���� ��带 ��ġ�� �ִ´�.
	if (linkedList->head != index)
	{
		linkedList->current->previous = index->previous;
		index->previous->next = linkedList->current;
	}
	else
	{
		linkedList->current->previous = linkedList->current;
		linkedList->head = linkedList->current;
	}
	index->previous = linkedList->current;
	linkedList->length++;
	//4. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//5. ������.
}

//InsertAfter
Node* InsertAfter(LinkedList* linkedList, Node* index, void* object, size_t size)
{
	//1. ��ġ�� �����͸� �Է¹޴´�.
	//2. ���ο� ��带 �����.
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->previous = index;
	//3. ���� ���� ��带 ��ġ�� �ִ´�.
	if (linkedList->tail != index)
	{
		linkedList->current->next = index->next;
		index->next->previous = linkedList->current;
	}
	else
	{
		linkedList->current->next = linkedList->current;
		linkedList->tail = linkedList->current;
	}
	index->next = linkedList->current;
	linkedList->length++;
	//4. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//5. ������.
}

//AppendFromHead
Node* AppendFromHead(LinkedList* linkedList, void* object, size_t size)
{
	//1. �����͸� �Է¹޴´�.
	//2. ���ο� ��带 �����.
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->previous = linkedList->current;
	//3. ���� ���� ��带 ó���� �д�.
	if (linkedList->head != NULL)
	{
		linkedList->current->next = linkedList->head;
		linkedList->head->previous = linkedList->current;
	}
	else
	{
		linkedList->current->next = linkedList->current;
		linkedList->tail = linkedList->current;
	}
	linkedList->head = linkedList->current;
	linkedList->length++;
	//4. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//5. ������.
}

//AppendFromTail
Node* AppendFromTail(LinkedList* linkedList, void* object, size_t size)
{
	//1. �����͸� �Է¹޴´�.
	//2. ���ο� ��带 �����.
	linkedList->current = (Node*)malloc(sizeof(Node) + size);
	memcpy(linkedList->current + 1, object, size);
	linkedList->current->next = linkedList->current;
	//3. ���� ���� ��带 �������� �д�.
	if (linkedList->head != NULL)
	{
		linkedList->current->previous = linkedList->tail;
		linkedList->tail->next = linkedList->current;
	}
	else
	{
		linkedList->current->previous = linkedList->current;
		linkedList->head = linkedList->current;
	}
	linkedList->tail = linkedList->current;
	linkedList->length++;
	//4. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//5. ������.
}

//Delete
Node* Delete(LinkedList* linkedList, Node *index)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. �Է¹��� ��ġ�� head�� tail�� ���� ������
	if (linkedList->head != index && linkedList->tail != index)
	{
		index->previous->next = index->next;
		index->next->previous = index->previous;
		linkedList->current = index->next;
	}
	//3. �Է¹��� ��ġ�� head�� ���� tail���� ���� ������
	else if (linkedList->head == index && linkedList->tail != index)
	{
		linkedList->head = index->next;
		index->next->previous = linkedList->head;
		linkedList->current = index->next;
	}
	//4. �Է¹��� ��ġ�� head�� �ٸ��� tail���� ������
	else if (linkedList->head != index && linkedList->tail == index)
	{
		linkedList->tail = index->previous;
		index->previous->next = linkedList->tail;
		linkedList->current = index->previous;
	}
	//5. �Է¹��� ��ġ�� head�� tail�� ���� ������
	else
	{
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	//6. index�� �����.
	if (index != NULL)
	{
		free(index);
		index = NULL;
	}
	linkedList->length--;
	//7. ��ġ�� ����Ѵ�.
	return index;
	//8. ������.
}

//DeleteFromHead
Node* DeleteFromHead(LinkedList* linkedList)
{
	Node* index;
	//1. ��尳���� 1���� �ƴϸ�
	index = linkedList->head;
	if (linkedList->head != linkedList->tail)
	{
		linkedList->head = linkedList->head->next;
		linkedList->head->previous = linkedList->head;
		linkedList->current = linkedList->head;
	}
	//2. ��尳���� 1���̸�
	else
	{
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	//3.  index�� ���ش�.
	if (index != NULL)
	{
		free(index);
		index = NULL;
	}
	linkedList->length--;
	//4. index�� ����Ѵ�.
	return index;
	//5. ������.
}

//DeleteFromTail
Node* DeleteFromTail(LinkedList* linkedList)
{
	Node* index;
	//1. ��尳���� 1���� �ƴϸ�
	index = linkedList->tail;
	if (linkedList->head != linkedList->tail)
	{
		linkedList->tail = linkedList->tail->previous;
		linkedList->tail->next = linkedList->tail;
		linkedList->current = linkedList->tail;
	}
	//2. ��尳���� 1���̸�
	else
	{
		linkedList->head = NULL;
		linkedList->tail = NULL;
		linkedList->current = NULL;
	}
	//3.  index�� ���ش�.
	if (index != NULL)
	{
		free(index);
		index = NULL;
	}
	linkedList->length--;
	//4. index�� ����Ѵ�.
	return index;
	//5. ������.
}

//DeleteAllItems
void DeleteAllItems(LinkedList* linkedList)
{
	Node* previous = NULL;
	//1. ���Ḯ��Ʈ���� ������� �����.
	linkedList->current = linkedList->head;
	while (linkedList->current != previous)
	{
		previous = linkedList->current;
		linkedList->head = linkedList->current->next;
		if (linkedList->current != NULL)
		{
			free(linkedList->current);
		}
		linkedList->length--;
		linkedList->current = linkedList->head;
	}
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->current = NULL;
	//2. ������.
}

//GetAt
void GetAt(LinkedList* linkedList, Node* index, void* object, size_t size)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. object�� �����͸� �����Ѵ�.
	memcpy(object, index + 1, size);
	//3. object�� ����Ѵ�.
	//4. ������.
}

//First
Node* First(LinkedList* linkedList)
{
	//1. �������� ó������ �̵���Ų��.
	linkedList->current = linkedList->head;
	//2. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//3. ������.
}

//Previous
Node* Previous(LinkedList* linkedList)
{
	//1. ������ġ�� �������� �̵���Ų��.
	linkedList->current = linkedList->current->previous;
	//2. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//3. ������.
}

//Next
Node* Next(LinkedList* linkedList)
{
	//1. ������ġ�� �������� �̵���Ų��.
	linkedList->current = linkedList->current->next;
	//2. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//3. ������.
}

//Last
Node* Last(LinkedList* linkedList)
{
	//1. ������ġ�� ���������� �̵���Ų��.
	linkedList->current = linkedList->tail;
	//2. ���� ��ġ�� ����Ѵ�.
	return linkedList->current;
	//3. ������.
}

//Move
Node* Move(LinkedList* linkedList, Node* index)
{
	//1. ��ġ�� �Է¹޴´�.
	//2. ���� ��ġ�� �Է¹��� ��ġ�� �̵���Ų��.
	linkedList->current = index;
	//3. ������ġ�� ����Ѵ�.
	return linkedList->current;
	//4. ������.
}

//LinearSearchUnique
Node* LinearSearchUnique(LinkedList* linkedList, void* key, int(*compare)(void*, void*))
{
	Node* index = NULL;
	Node* it;
	Node* previous = NULL;

	//1. �����͸� �Է¹޴´�.
	//2. ������������ �׸��� ã�����ϴ� �����Ϳ� ���� ���� ���� �ݺ��Ѵ�.
	it = linkedList->head;
	while (it != previous && compare(it + 1, key) != 0)
	{
		previous = it;
		it = it->next;
	}
	//3. ��������尡 �ƴϸ�
	if (it != previous)
	{
		//3.1 ��ġ�� �����Ѵ�.
		index = it;
	}
	//4. ��ġ�� ����Ѵ�.
	return index;
	//5. ������.
}

//LinearSearchDuplicate
void LinearSearchDuplicate(LinkedList* linkedList, void* key, Node** (*indexes), Long* count,
	int(*compare)(void*, void*))
{
	Node* it;
	Node* previous = NULL;
	Long i = 0;

	*count = 0;
	//1. �����͸� �Է¹޴´�.
	//2. ��ġ�� �迭�� �����.
	*indexes = (Node * (*))calloc(linkedList->length, sizeof(Node*));
	//3. ����� ���������� �ݺ��Ѵ�.
	it = linkedList->head;
	while (it != previous)
	{
		//3.1 ã�� ���� ��嵥���� ���� ������
		if (compare(it + 1, key) == 0)
		{
			//3.1.1 ��ġ�� �����Ѵ�.
			(*indexes)[i] = it;
			i++;
			//3.1.2 ������ ����.
			(*count)++;
		}
		previous = it;
		it = it->next;
	}
	//4. ��ġ�� �迭�� ������ ����Ѵ�.
	//5. ������.
}

//Destory
void Destroy(LinkedList* linkedList)
{
	Node* previous = NULL;

	//1. ���Ḯ��Ʈ�� ������� �����.
	linkedList->current = linkedList->head;
	while (linkedList->current != previous)
	{
		previous = linkedList->current;
		linkedList->head = linkedList->current->next;
		if (linkedList->current != NULL)
		{
			free(linkedList->current);
		}
		linkedList->current = linkedList->head;
	}
	//2. ������.
}