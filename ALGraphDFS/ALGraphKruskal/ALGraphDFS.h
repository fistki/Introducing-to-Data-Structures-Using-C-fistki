#pragma once
#include <vector>
#include "ALGraph.h"
class ALGraphDFS : public ALGraph {
public:
	ALGraphDFS(int numV);
	virtual ~ALGraphDFS();

	void ShowGraphVertex(int startVertex);
	bool VisitVertex(int visitVertex);
	
protected:
	// ���ڷ� ���޵� �� ������ ����Ǿ� �ִٸ� true, �׷��� �ʴٸ� false�� ��ȯ
	bool IsConnVertex(int v1, int v2);

private:
	std::vector<bool> visitInfo;
};