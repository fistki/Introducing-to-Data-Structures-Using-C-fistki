#pragma once
#include <vector>
#include <memory>

#include <memory>
#include "SimpleHeapImpl.h"

class Heap {
public:
	Heap() : pimpl(new HeapImpl) {}
	bool HIsEmpty() const { return pimpl->HIsEmpty(); }
	void HInsert(Priority _pr, const HData& _data) { pimpl->HInsert(_pr, _data); }
	void HInsert(const HData& _data, Priority _pr) { pimpl->HInsert(_pr, _data); }
	HData HDelete() { return pimpl->HDelete(); }

private:
	std::shared_ptr<HeapImpl> pimpl;
	
};