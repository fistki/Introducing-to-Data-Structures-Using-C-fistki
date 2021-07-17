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
	std::vector<Edge> recvEdge(20);	// ������ ������ ���� ����
	Edge edge;
	int eidx = 0;

	while (GetEdgeNum() + 1 > GetVertexNum())	// MST ������ �� + 1 == ������ ���� �ɶ����� �ݺ�
	{
		// �켱 ���� ť���� ����ġ�� ���� ���� ������ ������ ������.
		edge = weightInfo->dequeue();

		// ���� ������ �׷������� �����Ѵ�.
		RemoveEdge(edge.v1, edge.v2);

		// ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�. 
		if (!IsConnVertex(edge.v1, edge.v2))
		{
			// ��ΰ� ���ٸ� ������ ������ �����Ѵ�.
			RecoverEdge(edge.v1, edge.v2);

			// ������ ������ ������ ������ �����Ѵ�.
			recvEdge[eidx++] = edge;

			// �̶� ������ ������ ������ �ٽ� �켱���� ť�� ���� �ʴ´�.
			// �켱���� ť�� �ٽ� ������ dequeue() ȣ�� �� �ٽ� ������ �����̴�.
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��
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
