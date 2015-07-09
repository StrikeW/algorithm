#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits> //INT_MAX
#include <queue>
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

	edge e2;
	e2.dst=x;
	e2.distance=distance;
	graph[y].out_edges.push_back(e2);
}

struct point{
	int id;
	int x;
	int y;
};
bool cmp_x(point a,point b){ 
		return a.x<b.x;  
};
bool cmp_y(point a,point b){ 
		return a.y<b.y;  
};

struct cmp_vertex{
	int id;
	int distance;
	cmp_vertex(int _id,int _distance){
		id=_id;
		distance=_distance;
	}
};
struct cmp_func{  
	bool operator()(cmp_vertex a,cmp_vertex b){  
		return a.distance > b.distance;
	}  
};
void dijkstra(vector<vertex>& graph, int source){
	for(int i=0;i<graph.size();i++){
		graph[i].distance=INT_MAX;
		graph[i].previous=-1;
		graph[i].visited=false;
	}
	graph[source].distance=0;
	priority_queue<cmp_vertex,vector<cmp_vertex>,cmp_func> cmp_queue;
	cmp_queue.push(cmp_vertex(source,graph[source].distance));
	int count=0;
	while(count<graph.size()){
		//get next min
		int min_value=INT_MAX;
		int min_index=-1;
		while(graph[cmp_queue.top().id].visited){
			cmp_queue.pop();
		}
		min_index=cmp_queue.top().id;
		cmp_queue.pop();
		graph[min_index].visited=true;
		count++;
		
		//iterate on all out-edges
		for(int i=0;i<graph[min_index].out_edges.size();i++){
			int dst=graph[min_index].out_edges[i].dst;
			int distance=graph[min_index].out_edges[i].distance;
			if(graph[dst].distance>graph[min_index].distance+distance){
				graph[dst].distance=graph[min_index].distance+distance;
				cmp_queue.push(cmp_vertex(dst,graph[dst].distance));
				graph[dst].previous=min_index;
			}
		}
	}

}
int main(){
	int N;
	cin>>N;
	vector<point> vec;
	vec.reserve(N);
	while(N>0){
		N--;
		point p;
		p.id=vec.size();
		scanf("%d %d",&(p.x),&(p.y));
		vec.push_back(p);
	}
	vector<vertex> graph;
	sort(vec.begin(),vec.end(),cmp_x);
	for(int i=0;i<vec.size()-1;i++){
		int distance=vec[i+1].x-vec[i].x;
		if(distance<0)
			distance=0-distance;
		add_edge(graph,vec[i].id,vec[i+1].id,distance);
	}
	sort(vec.begin(),vec.end(),cmp_y);
	for(int i=0;i<vec.size()-1;i++){
		int distance=vec[i+1].y-vec[i].y;
		if(distance<0)
			distance=0-distance;
		add_edge(graph,vec[i].id,vec[i+1].id,distance);
	}
	dijkstra(graph,0);
	cout<<graph[graph.size()-1].distance<<endl;
}

