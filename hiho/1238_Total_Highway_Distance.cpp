#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <climits> //INT_MAX
using namespace std;
struct edge{
	int dst;
	int distance;
	int count;
};
struct vertex{
	int distance;
	bool visited;
	vector<edge>out_edges;
};
void add_edge(vector<vertex>& graph,int x,int y,int distance){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e1;
	e1.dst=y;
	e1.distance=distance;
	graph[x].out_edges.push_back(e1);

	edge e2;
	e2.dst=x;
	e2.distance=distance;
	graph[y].out_edges.push_back(e2);
}
int calculate_count(map<pair<int,int>, edge> &query_map,vector<vertex>& graph,int parent,int child){
	int result=0;
	for(int i=0;i<graph[child].out_edges.size();i++){
		int next_level=graph[child].out_edges[i].dst;
		if(next_level==parent)
			continue;
		int c=calculate_count(query_map,graph,child,next_level);
		graph[child].out_edges[i].count=c;
		pair<int,int> p=pair<int,int>(min(child,next_level),max(child,next_level));
		query_map[p]=graph[child].out_edges[i];
		result+=c;
	}
	result+=1;
	return result;
}
int main(){
	int N,M;
	cin>>N>>M;
	vector<vertex> graph;
	map<pair<int,int>, edge> query_map;
	for(int i=0;i<N-1;i++){
		int u,v,k;
		cin>>u>>v>>k;
		add_edge(graph,u-1,v-1,k); 
	}
	calculate_count(query_map,graph,-1,0);
	long long total=0;
	map<pair<int,int>, edge>::iterator iter;
	for(iter=query_map.begin();iter!=query_map.end();iter++){
		long long c=(iter->second).count;
		c*=(N-c);
		total+=c*(iter->second).distance ;
	}	
	for(int i=0;i<M;i++){
		string str;
		cin>>str;
		if(str=="QUERY"){
			cout<<total<<endl;
		} else {
			int u,v,k;
			cin>>u>>v>>k;
			u--;
			v--;
			pair<int,int> p=pair<int,int>(min(u,v),max(u,v));
			long long c=query_map[p].count;
			c*=(N-c);
			total+=c*(k-query_map[p].distance);
			query_map[p].distance=k;
			//cout<<total<<endl;
		}
	}
}





