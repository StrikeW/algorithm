#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
/*
	http://www.cppblog.com/ZAKIR/archive/2010/08/30/124869.html?opt=admin
	
*/
struct edge{
	int dst;
	bool cut_edge;
};
struct vertex{
	int depth;
	int low;
	bool cut_point;
	vector<edge>out_edges;
};
void add_edge(vector<vertex>& graph,int x,int y){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e;
	e.dst=y;
	e.cut_edge=false;
	graph[x].out_edges.push_back(e);
}

void DFS(vector<vertex>& graph,int curr,int parent,int depth){
	graph[curr].depth=depth;
	graph[curr].low=depth;
	int branch=0;
	for(int i=0;i<graph[curr].out_edges.size();i++){
		int child=graph[curr].out_edges[i].dst;
		if(graph[child].depth==0){
			branch++;
			DFS(graph,child,curr,depth+1);
			// after this , the graph[child].low is the final value
			if(graph[curr].low > graph[child].low){
				graph[curr].low = graph[child].low;
			}
			if((curr==1 && branch>1) || (curr!=1 && graph[child].low>=graph[curr].depth)){
				graph[curr].cut_point=true;
			}
			if(graph[child].low>graph[curr].depth){
         		graph[curr].out_edges[i].cut_edge=true;
			}
		} else {
			if(graph[curr].low > graph[child].depth && child!=parent){
				graph[curr].low = graph[child].depth;
			}
		}
	}
}

struct sort_edge{
	sort_edge(int s,int t){
		src=s;
		dst=t;
	}
	int src;
	int dst;
};
bool mysort(sort_edge A,sort_edge B){
	if(A.src != B.src)
		return A.src < B.src;
	else
		return A.dst < B.dst; 
}

int main(){
	int N,M;
	cin>>N>>M;

	vector<vertex> graph;
	while(M>0){
		M--;
		int A,B;
		cin>>A>>B;
		add_edge(graph,A,B);
		add_edge(graph,B,A);
	}
	DFS(graph,1,0,1);
	int count=0;
	for(int i=1;i<graph.size();i++){
		if(graph[i].cut_point){
			if(count!=0)
				cout<<" ";
			cout<<i;
			count++;
		}
	}
	if(count==0){
		cout<<"Null";
	}
	cout<<endl;

	vector<sort_edge> vec;
	for(int i=1;i<graph.size();i++){
		for(int j=0;j<graph[i].out_edges.size();j++){
			if(graph[i].out_edges[j].cut_edge){
				int dst=graph[i].out_edges[j].dst;
				if(i<dst)
					vec.push_back(sort_edge(i,dst));
				else
					vec.push_back(sort_edge(dst,i));
			}
		}
	}
	sort(vec.begin(),vec.end(),mysort);
	for(int i=0;i<vec.size();i++){
		if(i>0 && (vec[i].src == vec[i-1].src) && (vec[i].dst == vec[i-1].dst))
			continue;
		cout<<vec[i].src<<" "<<vec[i].dst<<endl;
	}
}











