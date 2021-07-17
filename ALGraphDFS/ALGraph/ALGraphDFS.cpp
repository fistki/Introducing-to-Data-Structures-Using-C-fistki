#include "ALGraphDFS.h"
#include <stack>
#include <memory>

ALGraphDFS::ALGraphDFS(int numV)
	: ALGraph(numV), visitInfo(numV, false)
{
}

ALGraphDFS::~ALGraphDFS()
{
}

void ALGraphDFS::ShowGraphVertex(int startVertex)
{
	std::stack<int> s;
	int visitV = startVertex;
	
	// ���� ���� �湮
	VisitVertex(visitV);
	// ���� ������ ������ push
	s.push(visitV);
	
	bool visitFlag = false;

	while (GetVertexList(visitV) != nullptr)
	{
		visitFlag = false;

		for (int nextV : *GetVertexList(visitV))
		{
			if (VisitVertex(nextV))	// �湮�� �������� ���
			{
				s.push(visitV);	// ������ ������ ���ÿ� push
				visitV = nextV;
				visitFlag = true;
				break;
			}
		}

		if (!visitFlag)
		{
			if (s.empty())	// ������ ����� ���, ó������ �ǵ��ƿ°��̴�.
				break;
			else
			{
				visitV = s.top();
				s.pop();
			}
		}
	}

	visitInfo.clear();
	visitInfo.resize(GetVertexNum());
}

bool ALGraphDFS::VisitVertex(int visitVertex)
{
	if (visitInfo[visitVertex] == false)
	{
		visitInfo[visitVertex] = true;
		printf("%c ", visitVertex + 'A');
		return true;
	}
	return false;
}