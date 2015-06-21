#include <iostream>
#include <vector>
#include <math.h>
#include <climits> //INT_MAX
using namespace std;

struct edge{
	int dst;
	int distance;
};
struct vertex{
	int distance;
	int previous;
	bool visited;
	vector<edge>out_edges;
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

void dijkstra(vector<vertex>& graph, int source){
	for(int i=0;i<graph.size();i++){
		graph[i].distance=INT_MAX;
		graph[i].previous=-1;
		graph[i].visited=false;
	}
	graph[source].distance=0;

	int count=0;
	while(count<graph.size()){
		//get next min
		int min_value=INT_MAX;
		int min_index=-1;
		for(int i=0;i<graph.size();i++){
			if(!graph[i].visited && graph[i].distance<=min_value){
				min_value=graph[i].distance;
				min_index=i;
			}
		}
		graph[min_index].visited=true;
		count++;
		
		//iterate on all out-edges
		for(int i=0;i<graph[min_index].out_edges.size();i++){
			int dst=graph[min_index].out_edges[i].dst;
			int distance=graph[min_index].out_edges[i].distance;
			if(graph[dst].distance>graph[min_index].distance+distance){
				graph[dst].distance=graph[min_index].distance+distance;
				graph[dst].previous=min_index;
			}
		}
	}

}

int main(){
	int N,M,S,T;
	cin >>N>>M>>S>>T;

	vector<vertex> g;
	for(int i=0;i<M;i++){
		int x,y,d;
		cin>>x>>y>>d;
		add_edge(g,x,y,d);
		add_edge(g,y,x,d);
	}
	dijkstra(g,S);
	cout<<g[T].distance<<endl;

}