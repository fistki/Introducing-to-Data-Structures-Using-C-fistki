#include "namecard.h"
#include "arraylist.h"

int main(void)
{
	ArrayList<NameCard*> list;
	NameCard* _outpNameCard;

	//1. 총 3명의 전화번호 정보를, 리스트에 저장

	list.LInsert(makeNameCard("Mike", "01012345678"));
	list.LInsert(makeNameCard("John", "01022342679"));
	list.LInsert(makeNameCard("Ho", "01012345661"));


	//2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력
	
	if (list.LFirst(_outpNameCard))
	{
		if(_outpNameCard->getName() == "Ho")
			showCardInfo(*_outpNameCard);

		while(list.LNext(_outpNameCard))
			if (_outpNameCard->getName() == "Ho") {
				showCardInfo(*_outpNameCard);
				break;
			}
	}

	//3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 변경

	if (list.LFirst(_outpNameCard))
	{
		if (_outpNameCard->getName() == "Mike")
			_outpNameCard->changePhoneNum("01099998888");
		while (list.LNext(_outpNameCard))
		{
			if (_outpNameCard->getName() == "Mike")
				_outpNameCard->changePhoneNum("01099998888");
			break;
		}
	}


	//4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보 삭제

	if (list.LFirst(_outpNameCard))
	{
		if (_outpNameCard->getName() == "John") {
			delete list.LRemove();
		}
		while (list.LNext(_outpNameCard))
		{
			if (_outpNameCard->getName() == "John") {
				delete list.LRemove();
				break;
			}
		}
	}


	//5. 남아 있는 모든 사람의 전화번호를 출력

	if (list.LFirst(_outpNameCard))
	{
		showCardInfo(*_outpNameCard);
		while (list.LNext(_outpNameCard))
		{
			showCardInfo(*_outpNameCard);
		}
	}


	return 0;
}