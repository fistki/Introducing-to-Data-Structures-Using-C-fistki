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
	// 인자로 전달된 두 정점이 연결되어 있다면 true, 그렇지 않다면 false를 반환
	bool IsConnVertex(int v1, int v2);

private:
	std::vector<bool> visitInfo;
};