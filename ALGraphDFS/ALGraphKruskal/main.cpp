#include "ALGraphKruskal.h"

void testKruskal();

int main(void)
{
	printf("/////TEST Kruskal Algorithm//////\n\n");
	testKruskal();
	printf("\n\n");

	return 0;
}

void testKruskal(void)
{
	ALGraphK graph(6);

	graph.AddEdge(A, B, 9);
	graph.AddEdge(B, C, 2);
	graph.AddEdge(A, C, 12);
	graph.AddEdge(A, D, 8);
	graph.AddEdge(D, C, 6);
	graph.AddEdge(A, F, 11);
	graph.AddEdge(F, D, 4);
	graph.AddEdge(D, E, 3);
	graph.AddEdge(E, C, 7);
	graph.AddEdge(F, E, 13);

	graph.ConKruskalMST();
	ALGraphK::ShowGraphEdgeInfo(graph);
	printf("\n");
	graph.ShowGraphEdgeWeighInfo();
}