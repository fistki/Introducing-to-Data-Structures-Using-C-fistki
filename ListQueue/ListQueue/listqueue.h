#include "queue.h"
#include "listqueueimpl.h"
#include <memory>

template<typename Data>
class LQueue : public Queue<Data> {
public:
	LQueue() : pImpl(new LQueueImpl<Data>) { }
	~LQueue() { }

	bool empty() const { return pImpl->empty(); }
	void enqueue(const Data& data) { pImpl->enqueue(data); }
	Data dequeue() { return pImpl->dequeue(); }
	Data peek() const { return pImpl->peek(); }
private:
	LQueue(const LQueue& rhs);				// ���� ����
	LQueue& operator=(const LQueue& rhs);	// ���� ����
	std::shared_ptr<LQueueImpl<Data>> pImpl;
};
