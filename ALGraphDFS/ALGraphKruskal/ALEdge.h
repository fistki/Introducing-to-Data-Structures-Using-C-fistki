#pragma once

struct Edge {
	Edge() : v1(0), v2(0), weight(0) {}
	Edge(int _v1, int _v2, int _weight) : v1(_v1), v2(_v2), weight(_weight) {}
	int v1;
	int v2;
	int weight;
};
