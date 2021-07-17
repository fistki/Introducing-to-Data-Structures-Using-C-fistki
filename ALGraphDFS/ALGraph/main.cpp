#include "ALGraphDFS.h"
#include "ALGraphBFS.h"

void testDFS(void);
void testBFS(void);

int main(void)
{
	printf("/////TEST DFS Search//////\n\n");
	testDFS();
	printf("\n\n");
	
	printf("/////TEST BFS Search//////\n\n");
	testBFS();
	return 0;
}

void testDFS(void)
{
	ALGraphDFS graph(7);

	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	ALGraphDFS::ShowGraphEdgeInfo(graph);

	graph.ShowGraphVertex(A); printf("\n");
	graph.ShowGraphVertex(C); printf("\n");
	graph.ShowGraphVertex(E); printf("\n");
	graph.ShowGraphVertex(G); printf("\n");
}

void testBFS(void)
{
	ALGraphBFS graph(7);

	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	ALGraphBFS::ShowGraphEdgeInfo(graph);

	graph.ShowGraphVertex(A); printf("\n");
	graph.ShowGraphVertex(C); printf("\n");
	graph.ShowGraphVertex(E); printf("\n");
	graph.ShowGraphVertex(G); printf("\n");
}