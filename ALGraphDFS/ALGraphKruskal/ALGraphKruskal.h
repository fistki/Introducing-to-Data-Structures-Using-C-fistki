#pragma once
#include "ALGraphDFS.h"
#include <queue>

template<typename Data> class PriorityQueue;

class ALGraphK : public ALGraphDFS {
public:
	ALGraphK(int numV);
	virtual ~ALGraphK();

	// ũ�罺Į �˰����� ������� MST�� �����մϴ�.
	void ConKruskalMST();
	void ShowGraphEdgeWeighInfo();
	void AddEdge(int fromV, int toV, int weight);

private:
	PriorityQueue<class Edge>* weightInfo;
};
