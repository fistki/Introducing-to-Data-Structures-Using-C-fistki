#include <vector>
#include <cstdio>

template<typename Data>
class DequeImpl {
public:
	DequeImpl();
	~DequeImpl();
	bool empty() const;
	void push_back(const Data& data);
	void push_front(const Data& data);

	Data pop_back();
	Data pop_front();

	Data get_back();
	Data get_front();
private:
	struct Node
	{
		Data data;
		Node* next;
		Node* prev;
		Node() : next(nullptr), prev(nullptr) {}
		Node(const Data& _data, Node* _next = nullptr, Node* _prev = nullptr) : data(_data), next(_next), prev(_prev) {}
		~Node() {}
	};
	Node* front;
	Node* rear;
};
template<typename Data>
DequeImpl<Data>::DequeImpl() :front(nullptr), rear(nullptr) {}
template<typename Data>
DequeImpl<Data>::~DequeImpl()
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
bool DequeImpl<Data>::empty() const
{
	if (front == nullptr || rear == nullptr) return true;
	else return false;
}
template<typename Data>
void DequeImpl<Data>::push_back(const Data& data)
{
	Node* newNode = new Node(data,nullptr,rear);
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
void DequeImpl<Data>::push_front(const Data& data)
{
	Node* newNode = new Node(data,front,nullptr);
	if (empty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		front->prev = newNode;
		front = newNode;
	}
}
template<typename Data>
Data DequeImpl<Data>::pop_back()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	Node* delNode = rear;
	Data retData(rear->data);
	if (rear->prev != nullptr)
	{
		rear->prev->next = nullptr;
		rear = rear->prev;
	}
	else
	{
		rear = nullptr;
		front = nullptr;
	}
	delete delNode;
	return retData;
}
template<typename Data>
Data DequeImpl<Data>::pop_front()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	Node* delNode = front;
	Data retData(front->data);
	if (front->next != nullptr)
	{
		front->next->prev = nullptr;
		front = front->next;
	}
	else
	{
		rear = nullptr;
		front = nullptr;
	}
	delete delNode;
	return retData;
}
template<typename Data>
Data DequeImpl<Data>::get_back()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	return rear->data;
}
template<typename Data>
Data DequeImpl<Data>::get_front()
{
	if (empty())
	{
		printf("Queue Memory Error : Queue is Empty\n");
		exit(-1);
	}
	return front->data;
}