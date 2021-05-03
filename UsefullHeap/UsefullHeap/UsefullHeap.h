#pragma once
#include <memory>
#include "UsefullHeapImpl.h"

class Heap {
public:
	Heap(PriorityComp _comp) : pimpl(new HeapImpl(_comp)) {}
	bool HIsEmpty() const { return pimpl->HIsEmpty(); }
	void HInsert(const HData& _data) { pimpl->HInsert(_data); }
	HData HDelete() { return pimpl->HDelete(); }

private:
	std::shared_ptr<HeapImpl> pimpl;
};
