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
	
	// 시작 정점 방문
	VisitVertex(visitV);
	// 시작 정점의 정보를 push
	s.push(visitV);
	
	bool visitFlag = false;

	while (GetVertexList(visitV) != nullptr)
	{
		visitFlag = false;

		for (int nextV : *GetVertexList(visitV))
		{
			if (VisitVertex(nextV))	// 방문에 성공했을 경우
			{
				s.push(visitV);	// 떠나는 정점을 스택에 push
				visitV = nextV;
				visitFlag = true;
				break;
			}
		}

		if (!visitFlag)
		{
			if (s.empty())	// 스택이 비었을 경우, 처음으로 되돌아온것이다.
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
		//printf("%c ", visitVertex + 'A');
		return true;
	}
	return false;
}

bool ALGraphDFS::IsConnVertex(int v1, int v2)
{
	std::stack<int> s;
	int visitV = v1;

	VisitVertex(visitV);
	s.push(visitV);
	while (GetVertexList(visitV) != nullptr)
	{
		int visitFlag = false;

		for (int nextV : *GetVertexList(visitV))
		{	
			// 정점을 돌아다니는 도중에 목표를 찾는다면 true를 반환
			if (nextV == v2)
			{
				// 함수가 반환하기 전 초기화 진행
				visitInfo.clear();
				visitInfo.resize(GetVertexNum());
				return true;
			}
			if (VisitVertex(nextV))
			{
				s.push(visitV);
				visitV = nextV;
				visitFlag = true;
			}
		}
		if (!visitFlag)
		{
			if (s.empty())	// 스택이 비었을 경우, 처음으로 되돌아온것이다.
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
	return false;
}
