#include <iostream>
#include <vector>
#include <climits> //INT_MAX
using namespace std;
/*
	O(n^2)
	每次加入一个新的顶点
*/
struct edge{
	int dst;
	int distance;
};
struct vertex{
	int distance;
	int road_distance;
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
int prim(vector<vertex>& graph){
	vector<int> min_distance;
	for(int i=0;i<graph.size();i++){
		graph[i].distance=INT_MAX;
		graph[i].visited=false;
	}
	graph[0].distance=0;
	int n=graph.size();
	int sum=0;
	while(n>0){
		n--;
		// find vertex with min distance
		int min_index=-1;
		int min_distance=INT_MAX;
		for(int i=0;i<graph.size();i++){
			if(graph[i].distance<min_distance && !graph[i].visited){
				min_index = i;
				min_distance=graph[i].distance;
			}
		}
		graph[min_index].visited=true;
		sum+=min_distance;
		// update 
		for(int i=0;i<graph[min_index].out_edges.size();i++){
			int dst=graph[min_index].out_edges[i].dst;
			int distance=graph[min_index].out_edges[i].distance;
			if(distance < graph[dst].distance && !graph[dst].visited){
				graph[dst].distance=distance;
			}
		}
	}
	return sum;
}
#include <queue>
struct node{
	int dis;
	int vid;
};
struct cmp{
	bool operator()(node a,node b){  
		return a.dis > b.dis;
	}  
};
int prim_heap(vector<vertex>& graph){
	vector<int> min_distance;
	for(int i=0;i<graph.size();i++){
		graph[i].distance=INT_MAX;
		graph[i].visited=false;
	}
	graph[0].distance=0;
	int n=graph.size();
	int sum=0;
	priority_queue<node,vector<node>,cmp> node_queue;
	node start;
	start.dis=0;
	start.vid=0;
	node_queue.push(start);
	while(n>0){
		n--;
		// find vertex with min distance
		node new_node;
		while(node_queue.size()>0){
			new_node=node_queue.top();
			node_queue.pop();
			if(!graph[new_node.vid].visited){
				break;
			}
		}

		int min_index=new_node.vid;
		int min_distance=new_node.dis;
		graph[min_index].visited=true;
		sum+=min_distance;
		// update 
		for(int i=0;i<graph[min_index].out_edges.size();i++){
			int dst=graph[min_index].out_edges[i].dst;
			int distance=graph[min_index].out_edges[i].distance;
			if(distance < graph[dst].distance && !graph[dst].visited){
				graph[dst].distance=distance;
				new_node.dis=distance;
				new_node.vid=dst;
				node_queue.push(new_node);
			}
		}
	}
	return sum;
}
void matrix_main(){
	int N;
	cin >> N;
	vector<vertex> graph;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int value;
			cin>>value;
			add_edge(graph,i,j,value);
		}
	}
	cout<<prim(graph)<<endl;
}
void adj_main(){
	int N,M;
	cin >> N >> M;
	vector<vertex> graph;
	for(int i=0;i<M;i++){
		int A,B;
		int value;
		cin>>A>>B>>value;
		add_edge(graph,A-1,B-1,value);
		add_edge(graph,B-1,A-1,value);
	}
	cout<<prim_heap(graph)<<endl;
}

int main(){
	adj_main();
}

