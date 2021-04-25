#include <memory>

template<typename Data>
class Queue {
public:
	virtual ~Queue() {}

	virtual bool empty() const = 0;
	virtual void enqueue(const Data& data) = 0;
	virtual Data dequeue() = 0;
	virtual Data peek() const = 0;

};


	