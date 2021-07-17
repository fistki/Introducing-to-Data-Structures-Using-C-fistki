#pragma once
#include "ALGraph.h"
#include <vector>

class ALGraphBFS : public ALGraph {
public:
	ALGraphBFS(int numV);
	~ALGraphBFS();

	void ShowGraphVertex(int startVertex);
	bool VisitVertex(int visitVertex);

private:
	std::vector<bool> visitInfo;

};
