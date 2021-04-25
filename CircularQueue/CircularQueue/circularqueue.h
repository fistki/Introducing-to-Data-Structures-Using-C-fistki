#include "queue.h"
#include "circularqueueimpl.h"
#include <memory>

template<typename Data>
class CQueue : public Queue<Data> {
public:
	CQueue(): pImpl(new CQueueImpl<Data>) { }
	~CQueue(){ }

	bool empty() const { return pImpl->empty(); }
	void enqueue(const Data& data) { pImpl->enqueue(data); }
	Data dequeue() { return pImpl->dequeue(); }
	Data peek() const { return pImpl->peek(); }
private:
	CQueue(const CQueue& rhs);				// 복사 금지
	CQueue& operator=(const CQueue& rhs);	// 복사 금지
	std::shared_ptr<CQueueImpl<Data>> pImpl;
};
