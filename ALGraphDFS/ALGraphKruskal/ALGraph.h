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
	virtual void AddEdge(int fromV, int toV);
	virtual void RemoveEdge(int fromV, int toV);

	int GetVertexNum() const;
	int GetEdgeNum() const;

protected:
	std::list<int>::iterator GetVertexBegin(int visitV);
	std::list<int>::iterator GetVertexEnd(int visitV);
	std::list<int>* GetVertexList(int visitV);
	void RecoverEdge(int fromV, int toV);

private:
	void RemoveWayEdge(int fromV, int toV);

	int numOfVertex;
	int numOfEdge;
	std::vector<std::shared_ptr<std::list<int>>> adjList;
};