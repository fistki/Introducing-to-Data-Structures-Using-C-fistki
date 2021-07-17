#include "ALGraphBFS.h"
#include <queue>


ALGraphBFS::ALGraphBFS(int numV)
	: ALGraph(numV), visitInfo(numV, false)
{
}

ALGraphBFS::~ALGraphBFS()
{
}

void ALGraphBFS::ShowGraphVertex(int startVertex)
{
	std::queue<int> q;
	int visitV = startVertex;
	int nextV;

	// 시작 정점 방문
	VisitVertex(visitV);
	// 시작 정점의 정보를 push
	q.push(visitV);

	while (GetVertexList(visitV) != nullptr)
	{
		for (int nextV : *GetVertexList(visitV))
		{
			if (VisitVertex(nextV))	// 방문에 성공했을 경우
			{
				q.push(nextV);
			}
		}

		if (q.empty())	
			break;
		else
		{
			visitV = q.front();
			q.pop();
		}
	}

	visitInfo.clear();
	visitInfo.resize(GetVertexNum());
}

bool ALGraphBFS::VisitVertex(int visitVertex)
{
	if (visitInfo[visitVertex] == false)
	{
		visitInfo[visitVertex] = true;
		printf("%c ", visitVertex + 'A');
		return true;
	}
	return false;
}
