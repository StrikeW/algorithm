#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct edge{
	int dst;
};
struct vertex{
	int indegree;
	vector<edge>out_edges;
};
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

bool topology(vector<vertex>& graph){
	queue<int> sorted_queue;
	for(int i=0;i<graph.size();i++){
		if(graph[i].indegree==0){
			sorted_queue.push(i);
		}
	}
	int count=0;
	while(sorted_queue.size()>0){
		int id=sorted_queue.front();
		sorted_queue.pop();
		count++;
		for(int i=0;i<graph[id].out_edges.size();i++){
			int dst=graph[id].out_edges[i].dst;
			graph[dst].indegree--;
			if(graph[dst].indegree==0){
				sorted_queue.push(dst);
			}
		}
	}
	return count== graph.size();
}

int main(){
	int T;
	cin >>T;
	while(T>0){
		T--;
		int N,M;
		cin>>N>>M;
		vector<vertex> g;
		while(M>0){
			M--;
			int A,B;
			cin>>A>>B;
			add_edge(g,A,B);
		}
		if(!topology(g))
			cout<<"Wrong"<<endl;
		else
			cout<<"Correct"<<endl;
	}
}




