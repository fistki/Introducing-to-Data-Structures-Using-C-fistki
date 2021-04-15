#include "arraylist.h"
#include "point.h"
#include <cstdio>
int main(void)
{
	ArrayList<Point> list;
	Point compPos;
	Point _outPos;
	// 4���� �����͸� list�� �����ϱ�

	list.LInsert(Point(2, 1));	
	list.LInsert(Point(2, 2));
	list.LInsert(Point(3, 1));
	list.LInsert(Point(3, 2));


	// ����� ������ ���
	if (list.LFirst(_outPos)){
		ShowPointPos(_outPos);

		while (list.LNext(_outPos))
			ShowPointPos(_outPos);
	}
	printf("\n");
	
	// xpos�� 2�� ��� ������ ����
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

	// ���� �� ���� ������ ���
	printf("���� ���� ������ �� : %d\n", list.LCount());
	if (list.LFirst(_outPos)) {
		ShowPointPos(_outPos);

		while (list.LNext(_outPos))
			ShowPointPos(_outPos);
	}
	printf("\n");


	return 0;
}