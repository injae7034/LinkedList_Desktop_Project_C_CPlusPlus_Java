#include "LinkedList.h"
#include<iostream>
using namespace std;

//함수포인터 선언
int compare(void* one, void* other);

//메인테스트 시나리오
int main(int argc, char* argv[])
{
	//1. 연결리스트 생성자
	LinkedList<int> linkedList;
	LinkedList<int>::Node* index;
	//2. 연결리스트에서 100을 마지막에 추가한다.
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//3. 100을 지운다.
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//4. 연결리스트에서 100을 마지막에 추가한다.
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//5. 연결리스트에서 50을 처음에 추가한다.
	index = linkedList.AppendFromHead(50);
	cout << index->GetObject() << endl;
	//6. 연결리스트에서 120을 마지막에 추가한다.
	index = linkedList.AppendFromTail(120);
	cout << index->GetObject() << endl;
	//7. 연결리스트에서 모두 지운다.
	linkedList.DeleteAllItems();
	cout << linkedList.GetLength() << endl;
	if (linkedList.GetLength() == 0)
	{
		cout << "다 지워졌습니다." << endl;
	}
	//8. 연결리스트에서 100을 처음에 추가한다.
	index = linkedList.AppendFromHead(100);
	cout << index->GetObject() << endl;
	//9. 연결리스트에서 50을 마지막에 추가한다.
	index = linkedList.AppendFromTail(50);
	cout << index->GetObject() << endl;
	//10. 연결리스트에서 120을 처음에 추가한다.
	index = linkedList.AppendFromHead(120);
	cout << index->GetObject() << endl;
	//11. 연결리스트에서 처음을 지운다.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//12. 연결리스트에서 마지막을 지운다.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//13. 연결리스트에서 처음을 지운다.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//14. 연결리스트에서 100을 마지막에 추가한다.(1개)
	index = linkedList.AppendFromTail(100);
	cout << index->GetObject() << endl;
	//15. 연결리스트에서 50을 처음보다 앞에 추가한다.(2개)
	index = linkedList.InsertBefore(index, 50);
	//16. 연결리스트에서 마지막으로 이동한다.
	index = linkedList.Last();
	cout << index->GetObject() << endl;
	//17. 연결리스트에서 마지막보다 뒤에 120을 추가한다.
	index = linkedList.InsertAfter(index, 120);
	cout << index->GetObject() << endl;
	//18. 연결리스트에서 마지막을 지운다.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//19. 연결리스트에서 처음을 지운다.
	index = linkedList.DeleteFromHead();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//20. 연결리스트에서 마지막을 지운다.
	index = linkedList.DeleteFromTail();
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//21. 연결리스트에서 처음에 100을 추가한다.(1개) 100
	index = linkedList.AppendFromHead(100);
	cout << index->GetObject() << endl;
	//22. 연결리스트에서 50을 처음의 뒤에 추가한다.(2개) 100 50
	index = linkedList.InsertAfter(index, 50);
	cout << index->GetObject() << endl;
	//23. 연결리스트에서 처음으로 이동한다.
	index = linkedList.First();
	cout << index->GetObject() << endl;
	//24. 연결리스트에서 처음보다 앞에 120을 추가한다. 120 100 50
	index = linkedList.InsertBefore(index, 120);
	cout << index->GetObject() << endl;
	//25. 연결리스트에서 다음으로 이동한다.
	index = linkedList.Next();
	cout << index->GetObject() << endl;
	//26. 연결리스트에서 90을 두번째 뒤에 추가한다. 120 100 90 50
	index = linkedList.InsertAfter(index, 90);
	cout << index->GetObject() << endl;
	//27. 연결리스트에서 200을 세번재 앞에 추가한다. 120 100 200 90 50
	index = linkedList.InsertBefore(index, 200);
	cout << index->GetObject() << endl;
	//28. 연결리스트에서 90을 찾는다.
	Long key = 90;
	index = linkedList.LinearSearchUnique(&key, compare);
	cout << index->GetObject() << endl;
	//29. 연결리스트에서 90을 지운다. 120 100 200 50
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//30. 연결리스트에서 처음에 50을 추가한다. 50 120 100 200 50
	index = linkedList.AppendFromHead(50);
	cout << index->GetObject() << endl;
	cout << "" << endl;
	//31. 연결리스트에서 중복된 50을 찾는다.
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
	//32. 연결리스트에서 처음 50을 지운다.  120 100 200 50
	index = linkedList.Delete(indexes[0]);
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//33. 연결리스트에서 두번째 50으로 이동한다. 50
	index = linkedList.Move(indexes[1]);
	cout << index->GetObject() << endl;
	//34. 연결리스트에서 다음으로 이동한다. 50
	index = linkedList.Next();
	cout << index->GetObject() << endl;
	//35. 연결리스트에서 다음을 지운다. 120 100 200
	index = linkedList.Delete(index);
	if (index == 0)
	{
		cout << "지워졌습니다." << endl;
	}
	//36. 연결리스트에서 이전으로 이동한다. 100
	index = linkedList.Previous();
	cout << index->GetObject() << endl;
	//37. 연결리스트에서 처음으로 이동한다. 120
	index = linkedList.First();
	cout << index->GetObject() << endl;
	//38. 연결리스트에서 이전으로 이동한다. 120
	index = linkedList.Previous();
	cout << index->GetObject() << endl;
	cout << "대입한 other" << endl;
	//39. 치환연산자
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
	cout << "대입해준 linkedList" << endl;
	previous = 0;
	it = linkedList.First();
	while (it != previous)
	{
		cout << it->GetObject() << endl;
		previous = it;
		it = linkedList.Next();
	}
	cout << "복사생성한 theOther" << endl;
	//40. 복사생성자
	LinkedList<int> theOther(linkedList);
	previous = 0;
	it = theOther.First();
	while (it != previous)
	{
		cout << it->GetObject() << endl;
		previous = it;
		it = theOther.Next();
	}
	cout << "첨자연산자 호출" << endl;
	//41. 첨자연산자
	cout << linkedList[2] << endl;
	//42. 연결리스트 소멸자
	return 0;
}

//함수포인터
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