#include <memory>
#include "dequeimpl.h"
template<typename Data>
class Deque {
public:
	Deque(): pImpl(new DequeImpl<Data>) {}
	~Deque() {}

	bool empty() const { return pImpl->empty(); }
	void push_back(const Data& data) { pImpl->push_back(data); }
	void push_front(const Data& data) { pImpl->push_front(data); }

	Data pop_back() { return pImpl->pop_back(); }
	Data pop_front() { return pImpl->pop_front(); }

	Data get_back() { return pImpl->get_back(); }
	Data get_front() { return pImpl->get_front(); }

private:
	Deque(const Deque& rhs);				// 복사 금지
	Deque& operator=(const Deque& rhs);	// 복사 금지
	std::shared_ptr<DequeImpl<Data>> pImpl;
};

