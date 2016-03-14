#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int attractive;
	int parent;
	vector<int> child;
	bool must;
	node(){
		attractive=0;
		must=false;
	}
};

struct edge{
	int src;
	int dst;
};


vector<node> nodes;
vector<edge> edges;
vector<int> recommend;


void root_as(vector<edge>& edge_list,vector<node>& node_list,int root){
	for(int i=0;i<edge_list.size();i++){
		edge e=edge_list[i];
		node_list[e.src].child.push_back(e.dst);
	}
	node_list[root].parent=-1;
	node_list[root].must=true;
	queue<int> node_queue;
	node_queue.push(root);
	while(node_queue.size()>0){
		int r=node_queue.front();
		node_queue.pop();
		vector<int> new_child;
		for(int i=0;i<node_list[r].child.size();i++){
			int c=node_list[r].child[i];
			if(c!=node_list[r].parent){
				node_queue.push(c);
				node_list[c].parent=r;
				new_child.push_back(c);
			}
		}
		node_list[r].child.swap(new_child);
	}
}
void must_visit(){
	for(int i=1;i<nodes.size();i++){
		if(nodes[i].must){
			int parent=nodes[i].parent;
			while(parent!=-1){
				nodes[parent].must=true;
				parent=nodes[parent].parent;
			}
		}
	}
	for(int i=1;i<nodes.size();i++){
		if(!nodes[i].must && nodes[nodes[i].parent].must){
			nodes[i].parent=1;
		}
	}
}

// f[i][j]表示 以节点i为root，共j个节点时的值
int f[101][101];

void dp(int root){
	if(nodes[root].child.size()==0){
		f[root][0]=0;
		f[root][1]=nodes[root].attractive;
		return ;
	}
	for()
}
int main(){
	int N,K,M;
	cin>>N>>K>>M;
	nodes.resize(N+1);
	for(int i=1;i<=N;i++){
		cin>>nodes[i].attractive;
	}	
	recommend.resize(K);
	for(int i=1;i<=K;i++){
		cin>>recommend[i];
	}	

	for(int i=0;i<N-1;i++){
		edge e;
		cin>>e.src>>e.dst;
		edges.push_back(e);
	}

	root_as(edges,nodes,1);


}
