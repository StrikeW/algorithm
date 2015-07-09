#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
	int dst;
};
struct vertex{
	int indegree;
	int count;
	vector<edge>out_edges;
};
void add_vertex(vector<vertex>& graph,int x){
	if(graph.size()<=x)
		graph.resize(x+1);
	graph[x].count++;
}
void add_edge(vector<vertex>& graph,int x,int y){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e;
	e.dst=y;
	graph[x].out_edges.push_back(e);
	graph[y].indegree++;
}

int topology(vector<vertex>& graph){
	queue<int> sorted_queue;
	for(int i=0;i<graph.size();i++){
		if(graph[i].indegree==0){
			sorted_queue.push(i);
		}
	}
	int sum=0;
	while(sorted_queue.size()>0){
		int id=sorted_queue.front();
		sorted_queue.pop();
		if(id>=100001){
			sum+=graph[id].count;
			sum%=142857;
		}
		//count++;
		for(int i=0;i<graph[id].out_edges.size();i++){
			int dst=graph[id].out_edges[i].dst;
			graph[dst].indegree--;
			graph[dst].count+=graph[id].count;
			graph[dst].count%=142857;
			if(graph[dst].indegree==0){
				sorted_queue.push(dst);
			}
		}
	}
	return sum;
}
int main(){
	int T;
	cin>>T;
	while(T>0){
		T--;
		int N,M;
		cin>>N>>M;
		vector<vertex> g;
		while(M>0){
			M--;
			int sig=0;
			scanf("%d",&sig);
			add_vertex(g,sig);
		}
		int vid=100001;
		while(N>0){
			N--;
			int sig=0;
			int K;
			scanf("%d %d",&sig,&K);
			add_edge(g,sig,vid);
			while(K>0){
				K--;
				int sig2;
				scanf("%d",&sig2);
				add_edge(g,vid,sig2);
			}
			vid++;
		}
		topology(g);
		for(int i=100001;i<g.size();i++){
			printf("%d ",g[i].count);
		}
		printf("\n");
	}

}




