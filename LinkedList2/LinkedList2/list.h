template<typename LData>
class List {
public:
	enum { LIST_LEN = 100 };
	List() {}
	virtual ~List() {}
	virtual bool LInsert(const LData& data) = 0;	// 리스트에 데이터를 저장

	virtual bool LFirst(LData& pdata) = 0;	// 첫번째 데이터를 pdata를 가르키는 메모리에 저장
											// 데이터 참조를 위한 초기화 진행,
											// 성공시 true, 실패시 false 반환

	virtual bool LNext(LData& pdata) = 0; 	// 참조된 데이터의 다음 데이터를 pdata가 가르키는 메모리에 저장
											// 순차적인 참조를 위해 반복호출 가능
											// 참조를 새로 시작할려면 먼저 LFirst()를 호출해야 한다.
											// 성공시 true, 실패시 false 반환

	virtual LData LRemove(void) = 0;		// LFisrt() 또는 LNext() 의 마지막 반환 데이터를 삭제한다.
											// 삭제된 데이터를 반환한다.
											// 마지막 반환 데이터는 삭제하므로 반복호출 불가능

	virtual int LCount(void) = 0;			// 라스트에 저장되어있는 데이터의 수를 반환
};


