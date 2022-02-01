#ifndef _LINKEDLIST_H
#define _LINKEDLSIT_H

typedef signed long int Long;
template <typename T>
class LinkedList
{
public:
	//Nested Class
	class Node
	{
		friend class LinkedList;//LinkedList���� Node�� private����� �����ϱ� ���� ��������.
	public:
		//�Ű����� 0�� ������
		Node()
		{
			this->previous = this;
			this->next = this;
		}
		//�Ű����� 1�� ������
		Node(T object)
		{
			this->previous = this;
			this->object = object;
			this->next = this;
		}
		//�Ű����� 2�� ������
		Node(Node* previous, T object)
		{
			this->previous = previous;
			this->object = object;
			this->next = this;
		}
		Node(T object, Node* next)
		{
			this->previous = this;
			this->object = object;
			this->next = next;
		}
		//�Ű����� 3�� ������
		Node(Node* previous, T object, Node* next)
		{
			this->previous = previous;
			this->object = object;
			this->next = next;
		}
		//���������
		Node(const Node& source)
		{
			this->previous = source.previous;
			this->object = source.object;
			this->next = source.next;
		}
		//ġȯ������
		Node& operator=(const Node& source)
		{
			this->previous = source.previous;
			this->object = source.object;
			this->next = source.next;

			return *this;
		}
		//GetAt
		T& GetObject() const
		{
			return const_cast<T&>(this->object);
		}
		//�Ҹ���
		~Node()
		{

		}
	private:
		Node* previous;
		T object;
		Node* next;
	};
public:
	//�⺻������
	LinkedList();
	//���������
	LinkedList(const LinkedList& source);
	//ġȯ������
	LinkedList<T>& operator=(const LinkedList& source);
	//÷�ڿ�����
	T& operator[](Long index);
	Node* InsertBefore(Node* index, T object);
	Node* InsertAfter(Node* index, T object);
	Node* AppendFromHead(T object);
	Node* AppendFromTail(T object);
	Node* Delete(Node* index);
	Node* DeleteFromHead();
	Node* DeleteFromTail();
	void DeleteAllItems();
	Node* LinearSearchUnique(void* key, int(*compare)(void*, void*));
	void LinearSearchDuplicate(void* key, Node** (*indexes), Long* count, int(*compare)(void*, void*));
	Node* First();
	Node* Previous();
	Node* Next();
	Node* Last();
	Node* Move(Node* index);
	//�Ҹ���
	~LinkedList();
	//�ζ����Լ�
	Long GetLength() const;
	Node* GetCurrent() const;

private:
	Node* head;
	Node* tail;
	Long length;
	Node* current;
};

//�ζ����Լ�
template <typename T>
inline Long LinkedList<T>::GetLength() const
{
	return this->length;
}

template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::GetCurrent() const
{
	return const_cast<Node*>(this->current);
}


//�⺻������
template <typename T>
LinkedList<T>::LinkedList()
{
	//1. ���Ḯ��Ʈ�� �����.
	this->head = 0;
	this->tail = 0;
	this->length = 0;
	this->current = 0;
	//2. ������.
}

//���������
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& source)
{
	//this->head, this->tail�� ������.
	Node* previous = 0;
	Node* it = source.head;
	while (it != previous)
	{
		if (previous != 0)
		{
			this->current = new Node(this->tail, it->object);
			this->tail->next = this->current;
			this->tail = this->current;
		}
		else //ó�� this�� Node�� �����ϴ� ���
		{
			this->current = new Node(it->object);
			this->head = this->current;
			this->tail = this->current;
		}
		previous = it;
		it = it->next;
	}
	//this->length����
	this->length = source.length;
	//this->currnet����
	this->current = this->head;
	it = source.head;
	while (it != source.current)
	{
		this->current = this->current->next;
		it = it->next;
	}
}

//ġȯ������
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& source)
{
	//ġȯ�ϱ� ����(�����ϱ� ����) this�� �ִ� ���� �����͸� ��� �Ҵ������Ѵ�.
	//DeleteAllItems�� logic�� ������. �ٸ� ���� class�� ������ ���곻���� ����� �� ���⶧����
	//DeleteAllItems�� ȣ������ �ʰ� �׳� ������.
	if (this->head != 0)
	{
		Node* previous = 0;
		this->current = this->head;
		while (this->current != previous)
		{
			previous = this->current;
			this->head = this->current->next;
			if (this->current != 0)
			{
				delete this->current;
			}
			this->length--;
			this->current = this->head;
		}
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}
	//this->head, this->tail�� ������.
	Node* previous = 0;
	Node* it = source.head;
	while (it != previous)
	{
		if (previous != 0)
		{
			this->current = new Node(this->tail, it->object);
			this->tail->next = this->current;
			this->tail = this->current;
		}
		else //ó�� this�� Node�� �����ϴ� ���
		{
			this->current = new Node(it->object);
			this->head = this->current;
			this->tail = this->current;
		}
		previous = it;
		it = it->next;
	}
	//this->length����
	this->length = source.length;
	//this->currnet����
	this->current = this->head;
	it = source.head;
	while (it != source.current)
	{
		this->current = this->current->next;
		it = it->next;
	}
	return *this;
}

//÷�ڿ�����
template <typename T>
T& LinkedList<T>::operator[](Long index)
{
	Node* it = this->head;
	Long i = 0;
	while (i < index)
	{
		it = it->next;
		i++;
	}

	return it->GetObject();
}

//InsertBefore
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertBefore(Node* index, T object)
{
	if (this->head != index)
	{
		this->current = new Node(index->previous, object, index);
	}
	else
	{
		this->current = new Node(object, index);
	}
	if (this->head != index)
	{
		index->previous->next = this->current;
	}
	else
	{
		this->head = this->current;
	}
	index->previous = this->current;
	this->length++;

	return this->current;
}

//InsertAfter
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(Node* index, T object)
{
	if (this->tail != index)
	{
		this->current = new Node(index, object, index->next);
	}
	else
	{
		this->current = new Node(index, object);
	}
	if (this->tail != index)
	{
		index->next->previous = this->current;
	}
	else
	{
		this->tail = this->current;
	}
	index->next = this->current;
	this->length++;

	return this->current;
}

//AppendFromHead
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromHead(T object)
{
	if (this->head != 0)
	{
		this->current = new Node(object, this->head);
	}
	else
	{
		this->current = new Node(object);
	}
	if (this->head != 0)
	{
		this->head->previous = this->current;
	}
	else
	{
		this->tail = this->current;
	}
	this->head = this->current;
	this->length++;

	return this->current;
}

//AppendFromTail
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromTail(T object)
{
	if (this->head!= 0)
	{
		this->current = new Node(this->tail, object);
	}
	else
	{
		this->current = new Node(object);
	}
	if (this->head != 0)
	{
		this->tail->next = this->current;
	}
	else
	{
		this->head = this->current;
	}
	this->tail = this->current;
	this->length++;

	return this->current;
}

//Delete
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Delete(Node* index)
{
	if (this->head != index && this->tail != index)
	{
		index->previous->next = index->next;
		index->next->previous = index->previous;
		this->current = index->next;
	}
	else if (this->head == index && this->tail != index)
	{
		this->head = index->next;
		index->next->previous = this->head;
		this->current = index->next;
	}
	else if (this->head != index && this->tail == index)
	{
		this->tail = index->previous;
		index->previous->next = this->tail;
		this->current = index->previous;
	}
	else
	{
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0)
	{
		delete index;
		index = 0;//NULL�� �ʱ�ȭ ��۸� ������ ����.
	}
	this->length--;

	return index;
}

//DeleteFromHead
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromHead()
{
	Node* index = this->head;
	if (this->head != this->tail)
	{
		this->head = this->head->next;
		this->head->previous = this->head;
		this->current = this->head;
	}
	else
	{
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0)
	{
		delete index;
		index = 0;
	}
	this->length--;

	return index;
}

//DeleteFromTail
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromTail()
{
	Node* index = this->tail;
	if (this->head != this->tail)
	{
		this->tail = this->tail->previous;
		this->tail->next = this->tail;
		this->current = this->tail;
	}
	else
	{
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0)
	{
		delete index;
		index = 0;
	}
	this->length--;

	return index;
}

//DeleteAllItems
template <typename T>
void LinkedList<T>::DeleteAllItems()
{
	Node* previous = 0;
	this->current = this->head;
	while (this->current != previous)
	{
		previous = this->current;
		this->head = this->current->next;
		if (this->current != 0)
		{
			delete this->current;
		}
		this->length--;
		this->current = this->head;
	}
		this->head = 0;
		this->tail = 0;
		this->current = 0;
}

//LinearSearchUnique
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::LinearSearchUnique(void* key, int(*compare)(void*, void*))
{
	Node* index = 0;
	Node* it;
	Node* previous = 0;

	it = this->head;
	while (it != previous && compare(&it->object, key) != 0)
	{
		previous = it;
		it = it->next;
	}
	if (it != previous)
	{
		index = it;
	}

	return index;
}

//LinearSerchDuplicate
template <typename T>
void LinkedList<T>::LinearSearchDuplicate(void* key, Node** (*indexes), Long* count, int(*compare)(void*, void*))
{
	Node* it;
	Node* previous = 0;
	Long i = 0;
	//�ʱ�ȭ
	*indexes = 0;
	*count = 0;
	//�� �迭��Ұ� Node*�� ������ �迭�� ���� �Ҵ���. 
	*indexes = new Node * [this->length];

	it = this->head;
	while (it != previous)
	{
		if (compare(&it->object, key) == 0)
		{
			(*indexes)[i] = it;
			i++;
			(*count)++;
		}
		previous = it;
		it = it->next;
	}
}

//First
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::First()
{
	this->current = this->head;

	return this->current;
}

//Previous
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Previous()
{
	this->current = this->current->previous;

	return this->current;
}

//Next
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Next()
{
	this->current = this->current->next;

	return this->current;
}

//Last
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Last()
{
	this->current = this->tail;

	return this->current;
}

//Move
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Move(Node* index)
{
	this->current = index;

	return this->current;
}


//�Ҹ���
template <typename T>
LinkedList<T>::~LinkedList()
{
	//1. ���Ḯ��Ʈ�� ���ش�.
	Node* previous = 0;
	this->current = this->head;
	while (this->current != previous)
	{
		previous = this->current;
		this->head = this->current->next;
		if (this->current != 0)
		{
			delete this->current;
		}
		this->current = this->head;
	}
}


#endif // !_LINKEDLIST_H