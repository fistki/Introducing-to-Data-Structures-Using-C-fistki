#pragma once
#include <list>
#include <vector>
#include <memory>

enum EVertex { A, B, C, D, E, F, G, H, I, J };

class ALGraph {
public:
	ALGraph(int numV);
	virtual ~ALGraph();

	static void ShowGraphEdgeInfo(const ALGraph& pg);
	void AddEdge(int fromV, int toV);

protected:
	std::list<int>::iterator GetVertexBegin(int visitV);
	std::list<int>::iterator GetVertexEnd(int visitV);
	std::list<int>* GetVertexList(int visitV);
	int GetVertexNum() const;

private:
	int numOfVertex;
	int numOfEdge;
	std::vector<std::shared_ptr<std::list<int>>> adjList;
};