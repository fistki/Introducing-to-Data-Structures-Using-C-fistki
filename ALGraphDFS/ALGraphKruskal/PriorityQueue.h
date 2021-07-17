#pragma once

#include "UsefullHeap.h"

template<typename PData>
class PriorityQueue : public Heap<PData> {
public:
	PriorityQueue(typename Heap<PData>::PriorityComp pc);

	void enqueue(const PData& data);
	PData dequeue();
	bool empty() const;
};

template<typename PData>
PriorityQueue<PData>::PriorityQueue(typename Heap<PData>::PriorityComp pc)
	: Heap<PData>(pc)
{
	
}

template<typename PData>
inline void PriorityQueue<PData>::enqueue(const PData& data)
{
	Heap<PData>::insert(data);
}

template<typename PData>
inline PData PriorityQueue<PData>::dequeue()
{
	return Heap<PData>::erase();
}

template<typename PData>
inline bool PriorityQueue<PData>::empty() const
{
	return Heap<PData>::empty();
}
