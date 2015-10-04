#include <iostream>
#include <vector>
#include <climits> //INT_MAX
#include <set>
using namespace std;
/*
	O(n^2)
*/
struct edge{
	int dst;
};
struct vertex{
	int distance;
	bool visited;
	vector<edge>out_edges;
	vertex(){
		visited=false;
		distance=0;
	}
};
void add_edge(vector<vertex>& graph,int x,int y){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e;
	e.dst=y;
	graph[x].out_edges.push_back(e);
}
int dfs(vector<vertex>& graph,int v){
	if(graph[v].visited){
		return graph[v].distance;
	}
	if(graph[v].out_edges.size()==0){
		return 0;
	}
	int m=0;
	for(int i=0;i<graph[v].out_edges.size();i++){
		m=max(m,dfs(graph,graph[v].out_edges[i].dst));
	}
	graph[v].visited=true;
	graph[v].distance=m+1;
	return graph[v].distance;
}
int main(){
	vector<vertex> graph;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x;
		int y;
		cin>>x>>y;
		add_edge(graph,x,y);
	}
	dfs(graph,1);
	set<int> s;
	int iter=1;
	while(true){
		s.insert(iter);
		if(graph[iter].out_edges.size()==0)
			break;
		for(int i=0;i<graph[iter].out_edges.size();i++){
			int child=graph[iter].out_edges[i].dst;
			if(graph[iter].distance==graph[child].distance+1){
				iter=child;
				break;
			}
		}
	}
	int m=0;
	for(int i=1;i<graph.size();i++){
		if(s.find(i)!=s.end())
			continue;
		if(graph[i].distance>m){
			m=graph[i].distance;
		}
	}
	cout<< m+graph[1].distance+1<<endl;
	return 0;
}


