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

	// ���� ���� �湮
	VisitVertex(visitV);
	// ���� ������ ������ push
	q.push(visitV);

	while (GetVertexList(visitV) != nullptr)
	{
		for (int nextV : *GetVertexList(visitV))
		{
			if (VisitVertex(nextV))	// �湮�� �������� ���
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
