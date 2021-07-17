#pragma once
#include <vector>
#include "ALGraph.h"
class ALGraphDFS : public ALGraph {
public:
	ALGraphDFS(int numV);
	virtual ~ALGraphDFS();

	void ShowGraphVertex(int startVertex);
	bool VisitVertex(int visitVertex);
private:
	std::vector<bool> visitInfo;
};