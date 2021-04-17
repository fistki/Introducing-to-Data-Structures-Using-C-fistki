#include "linkedlist.h"						// ArrayListbyFistki에서 이거랑	
#include "point.h"
#include <cstdio>
int main(void)
{
	typedef LinkedList<Point> PList;		// 이거만 바뀜
	PList list;
	Point compPos;
	Point _outPos;
	// 4개의 데이터를 list에 저장하기

	list.LInsert(Point(2, 1));
	list.LInsert(Point(2, 2));
	list.LInsert(Point(3, 1));
	list.LInsert(Point(3, 2));


	// 저장된 데이터 출력
	if (list.LFirst(_outPos)) {
		ShowPointPos(_outPos);

		while (list.LNext(_outPos))
			ShowPointPos(_outPos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제
	compPos.SetPointPos(2, 2);

	if (list.LFirst(_outPos))
	{
		if (compPos == _outPos)
			list.LRemove();

		while (list.LNext(_outPos))
		{
			if (compPos == _outPos)
				list.LRemove();
		}

	}

	// 삭제 후 남은 데이터 출력
	printf("현재 남은 데이터 수 : %d\n", list.LCount());
	if (list.LFirst(_outPos)) {
		ShowPointPos(_outPos);

		while (list.LNext(_outPos))
			ShowPointPos(_outPos);
	}
	printf("\n");


	return 0;
}