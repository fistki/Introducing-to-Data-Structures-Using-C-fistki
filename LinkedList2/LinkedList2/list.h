template<typename LData>
class List {
public:
	enum { LIST_LEN = 100 };
	List() {}
	virtual ~List() {}
	virtual bool LInsert(const LData& data) = 0;	// ����Ʈ�� �����͸� ����

	virtual bool LFirst(LData& pdata) = 0;	// ù��° �����͸� pdata�� ����Ű�� �޸𸮿� ����
											// ������ ������ ���� �ʱ�ȭ ����,
											// ������ true, ���н� false ��ȯ

	virtual bool LNext(LData& pdata) = 0; 	// ������ �������� ���� �����͸� pdata�� ����Ű�� �޸𸮿� ����
											// �������� ������ ���� �ݺ�ȣ�� ����
											// ������ ���� �����ҷ��� ���� LFirst()�� ȣ���ؾ� �Ѵ�.
											// ������ true, ���н� false ��ȯ

	virtual LData LRemove(void) = 0;		// LFisrt() �Ǵ� LNext() �� ������ ��ȯ �����͸� �����Ѵ�.
											// ������ �����͸� ��ȯ�Ѵ�.
											// ������ ��ȯ �����ʹ� �����ϹǷ� �ݺ�ȣ�� �Ұ���

	virtual int LCount(void) = 0;			// ��Ʈ�� ����Ǿ��ִ� �������� ���� ��ȯ
};


