#include <vector>
#include <cstdio>

template<typename Data>
class LQueueImpl {
public:
	LQueueImpl();
	~LQueueImpl();
	bool empty() const;
	void enqueue(const Data& data);
	Data dequeue();
	Data peek();
private:
	struct Node
	{
		Data data;
		Node* next;
		Node() : next(nullptr) {}
		Node(const Data& _data, Node* _next = nullptr) : data(_data), next(_next) {}
		~Node() {}
	};
	Node* front;
	Node* rear;
};
template<typename Data>
LQueueImpl<Data>::LQueueImpl() :front(nullptr), rear(nullptr) {}
template<typename Data>
LQueueImpl<Data>::~LQueueImpl() 
{
	if (!empty())
	{
		Node* delcur = front;
		Node* delnext = front;
		while (delcur != nullptr)
		{
			delnext = delcur->next;
			delete delcur;
			delcur = delnext;
		}
	}
}
template<typename Data>
bool LQueueImpl<Data>::empty() const
{
	if (front == nullptr) return true;
	else return false;
}
template<typename Data>
void LQueueImpl<Data>::enqueue(const Data& data)
{
	Node* newNode = new Node(data);
	if (empty()) 
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}
template<typename Data>
Data LQueueImpl<Data>::dequeue()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	Node* delNode = front;
	Data retData(front->data);
	front = front->next;
	delete delNode;
	return retData;
}
template<typename Data>
Data LQueueImpl<Data>::peek()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	return front->data;
}