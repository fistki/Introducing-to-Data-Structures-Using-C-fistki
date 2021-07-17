#include "ALGraphKruskal.h"
#include "ALEdge.h"
#include "PriorityQueue.h"
#include <vector>
int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

ALGraphK::ALGraphK(int numV)
	: ALGraphDFS(numV), weightInfo(new PriorityQueue<Edge>(PQWeightComp))
{
}

ALGraphK::~ALGraphK()
{
	delete weightInfo;
}

void ALGraphK::ConKruskalMST()
{
	std::vector<Edge> recvEdge(20);	// 복원할 간선의 정보 저장
	Edge edge;
	int eidx = 0;

	while (GetEdgeNum() + 1 > GetVertexNum())	// MST 간선의 수 + 1 == 정점의 수가 될때까지 반복
	{
		// 우선 순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다.
		edge = weightInfo->dequeue();

		// 꺼낸 간선을 그래프에서 삭제한다.
		RemoveEdge(edge.v1, edge.v2);

		// 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다. 
		if (!IsConnVertex(edge.v1, edge.v2))
		{
			// 경로가 없다면 삭제한 간선을 복원한다.
			RecoverEdge(edge.v1, edge.v2);

			// 복원한 간선의 정보를 별도로 저장한다.
			recvEdge[eidx++] = edge;

			// 이때 복원한 간선의 정보를 다시 우선순위 큐에 넣지 않는다.
			// 우선순위 큐에 다시 넣으면 dequeue() 호출 시 다시 꺼내기 때문이다.
		}
	}

	// 우선순위 큐에서 삭제된 간선의 정보를 회복
	for (int i = 0; i < eidx; ++i)
	{
		weightInfo->enqueue(recvEdge[i]);
	}
}

void ALGraphK::ShowGraphEdgeWeighInfo()
{
	PriorityQueue<Edge> copyPQ(*weightInfo);
	Edge edge;

	while (!copyPQ.empty())
	{
		edge = copyPQ.dequeue();
		printf("(%c-%c), w:%d\n", edge.v1 + 'A', edge.v2 + 'A', edge.weight); 
	}
}

void ALGraphK::AddEdge(int fromV, int toV, int weight)
{
	ALGraph::AddEdge(fromV, toV);
	Edge edge(fromV, toV, weight);
	weightInfo->enqueue(edge);
}
