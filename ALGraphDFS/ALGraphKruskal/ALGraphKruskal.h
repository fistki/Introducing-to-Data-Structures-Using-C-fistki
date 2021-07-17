#pragma once
#include "ALGraphDFS.h"
#include <queue>

template<typename Data> class PriorityQueue;

class ALGraphK : public ALGraphDFS {
public:
	ALGraphK(int numV);
	virtual ~ALGraphK();

	// 크루스칼 알고리즘을 기반으로 MST를 구성합니다.
	void ConKruskalMST();
	void ShowGraphEdgeWeighInfo();
	void AddEdge(int fromV, int toV, int weight);

private:
	PriorityQueue<class Edge>* weightInfo;
};
