#include <vector>
#include <cstdio>
template<typename Data>
class CQueueImpl {
public:
	enum { QUE_LEN = 100 };
	CQueueImpl();
	~CQueueImpl();
	bool empty() const;
	void enqueue(const Data& data);
	Data dequeue();
	Data peek();
private:
	int NextPosIdx(int pos);
	int front;
	int rear;
	std::vector<Data> queArr;
};
template<typename Data>
int CQueueImpl<Data>::NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1) return 0;
	else return pos + 1;
}

template<typename Data>
CQueueImpl<Data>::CQueueImpl() :front(0), rear(0), queArr(QUE_LEN) {}

template<typename Data>
CQueueImpl<Data>::~CQueueImpl() { }

template<typename Data>
bool CQueueImpl<Data>::empty() const
{
	if (front == rear) return true;
	else return false;
}
template<typename Data>
void CQueueImpl<Data>::enqueue(const Data& data)
{
	if (NextPosIdx(rear) == front)
	{
		printf("Queue Memory Error : Queue is full\n");
		exit(-1);
	}
	rear = NextPosIdx(rear);
	queArr[rear] = data;
}
template<typename Data>
Data CQueueImpl<Data>::dequeue()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	front = NextPosIdx(front);
	return queArr[front];
}
template<typename Data>
Data CQueueImpl<Data>::peek()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	return queArr[front];
}
