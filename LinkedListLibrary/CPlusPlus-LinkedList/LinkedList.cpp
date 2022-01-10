#include "LinkedList.h"
#include<iostream>
using namespace std;

//�Լ������� ����
int compare(void* one, void* other);

//�����׽�Ʈ �ó�����
int main(int argc, char* argv[])
{
	//1. ���Ḯ��Ʈ ������
	LinkedList<int> linkedList;
	LinkedList<int>::Node* index;
	//2. ���Ḯ��Ʈ���� 100�� �������� �߰��Ѵ�.
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//3. 100�� �����.
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//4. ���Ḯ��Ʈ���� 100�� �������� �߰��Ѵ�.
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//5. ���Ḯ��Ʈ���� 50�� ó���� �߰��Ѵ�.
	index = linkedList.AppendFromHead(50);
	cout << index->GetObject() << endl;
	//6. ���Ḯ��Ʈ���� 120�� �������� �߰��Ѵ�.
	index = linkedList.AppendFromTail(120);
	cout << index->GetObject() << endl;
	//7. ���Ḯ��Ʈ���� ��� �����.
	linkedList.DeleteAllItems();
	cout << linkedList.GetLength() << endl;
	if (linkedList.GetLength() == 0)
	{
		cout << "�� ���������ϴ�." << endl;
	}
	//8. ���Ḯ��Ʈ���� 100�� ó���� �߰��Ѵ�.
	index = linkedList.AppendFromHead(100);
	cout << index->GetObject() << endl;
	//9. ���Ḯ��Ʈ���� 50�� �������� �߰��Ѵ�.
	index = linkedList.AppendFromTail(50);
	cout << index->GetObject() << endl;
	//10. ���Ḯ��Ʈ���� 120�� ó���� �߰��Ѵ�.
	index = linkedList.AppendFromHead(120);
	cout << index->GetObject() << endl;
	//11. ���Ḯ��Ʈ���� ó���� �����.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//12. ���Ḯ��Ʈ���� �������� �����.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//13. ���Ḯ��Ʈ���� ó���� �����.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//14. ���Ḯ��Ʈ���� 100�� �������� �߰��Ѵ�.(1��)
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//15. ���Ḯ��Ʈ���� 50�� ó������ �տ� �߰��Ѵ�.(2��)
	index = linkedList.InsertBefore(index, 50);
	//16. ���Ḯ��Ʈ���� ���������� �̵��Ѵ�.
	index = linkedList.Last();
	cout << index->GetObject() << endl;
	//17. ���Ḯ��Ʈ���� ���������� �ڿ� 120�� �߰��Ѵ�.
	index = linkedList.InsertAfter(index, 120);
	cout << index->GetObject() << endl;
	//18. ���Ḯ��Ʈ���� �������� �����.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//19. ���Ḯ��Ʈ���� ó���� �����.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//20. ���Ḯ��Ʈ���� �������� �����.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//21. ���Ḯ��Ʈ���� ó���� 100�� �߰��Ѵ�.(1��) 100
	index = linkedList.AppendFromHead(100);
	cout << index->GetObject() << endl;
	//22. ���Ḯ��Ʈ���� 50�� ó���� �ڿ� �߰��Ѵ�.(2��) 100 50
	index = linkedList.InsertAfter(index, 50);
	cout << index->GetObject() << endl;
	//23. ���Ḯ��Ʈ���� ó������ �̵��Ѵ�.
	index = linkedList.First();
	cout << index->GetObject() << endl;
	//24. ���Ḯ��Ʈ���� ó������ �տ� 120�� �߰��Ѵ�. 120 100 50
	index = linkedList.InsertBefore(index, 120);
	cout << index->GetObject() << endl;
	//25. ���Ḯ��Ʈ���� �������� �̵��Ѵ�.
	index = linkedList.Next();
	cout << index->GetObject() << endl;
	//26. ���Ḯ��Ʈ���� 90�� �ι�° �ڿ� �߰��Ѵ�. 120 100 90 50
	index = linkedList.InsertAfter(index, 90);
	cout << index->GetObject() << endl;
	//27. ���Ḯ��Ʈ���� 200�� ������ �տ� �߰��Ѵ�. 120 100 200 90 50
	index = linkedList.InsertBefore(index, 200);
	cout << index->GetObject() << endl;
	//28. ���Ḯ��Ʈ���� 90�� ã�´�.
	Long key = 90;
	index = linkedList.LinearSearchUnique(&key, compare);
	cout << index->GetObject() << endl;
	//29. ���Ḯ��Ʈ���� 90�� �����. 120 100 200 50
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//30. ���Ḯ��Ʈ���� ó���� 50�� �߰��Ѵ�. 50 120 100 200 50
	index = linkedList.AppendFromHead(50);
	cout << index->GetObject() << endl;
	cout << "" << endl;
	//31. ���Ḯ��Ʈ���� �ߺ��� 50�� ã�´�.
	key = 50;
	LinkedList<int>::Node* (*indexes);
	Long count;
	linkedList.LinearSearchDuplicate(&key, &indexes, &count, compare);
	Long i = 0;
	while (i < count)
	{
		cout << indexes[i]->GetObject() << endl;
		i++;
	}
	//32. ���Ḯ��Ʈ���� ó�� 50�� �����.  120 100 200 50
	index = linkedList.Delete(indexes[0]);
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//33. ���Ḯ��Ʈ���� �ι�° 50���� �̵��Ѵ�. 50
	index = linkedList.Move(indexes[1]);
	cout << index->GetObject() << endl;
	//34. ���Ḯ��Ʈ���� �������� �̵��Ѵ�. 50
	index = linkedList.Next();
	cout << index->GetObject() << endl;
	//35. ���Ḯ��Ʈ���� ������ �����. 120 100 200
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "���������ϴ�." << endl;
	}
	//36. ���Ḯ��Ʈ���� �������� �̵��Ѵ�. 100
	index = linkedList.Previous();
	cout << index->GetObject() << endl;
	//37. ���Ḯ��Ʈ���� ó������ �̵��Ѵ�. 120
	index = linkedList.First();
	cout << index->GetObject() << endl;
	//38. ���Ḯ��Ʈ���� �������� �̵��Ѵ�. 120
	index = linkedList.Previous();
	cout << index->GetObject() << endl;
	cout << "������ other" << endl;
	//39. ġȯ������
	LinkedList<int> other;
	other = linkedList;
	LinkedList<int>::Node* previous = 0;
	LinkedList<int>::Node* it = other.First();
	while (it != previous)
	{
		cout << it->GetObject() << endl;
		previous = it;
		it = other.Next();
	}
	cout << "�������� linkedList" << endl;
	previous = 0;
	it = linkedList.First();
	while (it != previous)
	{
		cout << it->GetObject() << endl;
		previous = it;
		it = linkedList.Next();
	}
	cout << "��������� theOther" << endl;
	//40. ���������
	LinkedList<int> theOther(linkedList);
	previous = 0;
	it = theOther.First();
	while (it != previous)
	{
		cout << it->GetObject() << endl;
		previous = it;
		it = theOther.Next();
	}
	cout << "÷�ڿ����� ȣ��" << endl;
	//41. ÷�ڿ�����
	cout << linkedList[2] << endl;
	//42. ���Ḯ��Ʈ �Ҹ���
	return 0;
}

//�Լ�������
int compare(void* one, void* other)
{
	int* one_ = (int*)one;
	int* other_ = (int*)other;
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