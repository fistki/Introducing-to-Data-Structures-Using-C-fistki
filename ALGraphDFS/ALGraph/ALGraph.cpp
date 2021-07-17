#include "ALGraph.h"

ALGraph::ALGraph(int numV)
	: numOfVertex(numV), numOfEdge(0), adjList()
{
	for(int i=0; i<numV; ++i)
		adjList.push_back(std::make_shared<std::list<int>>());
}

ALGraph::~ALGraph()
{
}

void ALGraph::ShowGraphEdgeInfo(const ALGraph& pg)
{
	for (int i=0; i<pg.numOfVertex; ++i)
	{
		printf("%c와 연결된 정점: ", i + 65);
	
		for (auto v : *(pg.adjList[i]))
		{
			printf("%c ", v + 65);
		}
		printf("\n");
	}
}

void ALGraph::AddEdge(int fromV, int toV)
{
	adjList[fromV]->push_back(toV);
	adjList[toV]->push_back(fromV);
	numOfEdge++;
}

std::list<int>::iterator ALGraph::GetVertexBegin(int visitV)
{
	return adjList[visitV]->begin();
}

std::list<int>::iterator ALGraph::GetVertexEnd(int visitV)
{
	return adjList[visitV]->end();
}

std::list<int>* ALGraph::GetVertexList(int visitV)
{
	return adjList[visitV].get();
}

int ALGraph::GetVertexNum() const
{
	return numOfVertex;
}
