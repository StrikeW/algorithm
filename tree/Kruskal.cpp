#include <iostream>
#include <vector>
#include <climits> //INT_MAX
using namespace std;
/*
	O(n^2)
	每次加入一个新的顶点
*/
struct edge{
	int src;
	int dst;
	int distance;
};
struct vertex{
	bool visited;
	int parent;
};

void add_edge(vector<vertex>& graph,int x,int y,int distance){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e;
	e.dst=y;
	e.distance=distance;
	graph[x].out_edges.push_back(e);
}