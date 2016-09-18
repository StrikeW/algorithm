#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
struct edge{
	int src;
	int dst;
	int distance;
};
bool cmp(edge a,edge b){
    return a.distance < b.distance;
}
struct vertex{
	int parent;
};
int find_root(vector<vertex>& vec,int i){
	int child=i;
	int root=child;
	while(true){
		if(vec[child].parent==child){
			root=child;
			break;
		}
		child=vec[child].parent;
	}
	child=i;
	while(true){
		int next=vec[child].parent;
		if(vec[child].parent!=root){
			vec[child].parent=root;
			child=next;
		} else {
			break;
		}
	}
	return root;
}

//void insert(vector<vertex>& vec,int i,int j){
//	int r1=find_root(vec,i);
//	int r2=find_root(vec,i);
//}

int main(){
	cin.sync_with_stdio(false);
	while(true){
		int N;
		cin>>N;
		if(N==0){
			break;
		}
		vector<edge> edge_vec;
		for(int i=0;i<(N*(N-1)/2);i++){
			int src;
			int dst;
			int distance;
			cin>>src>>dst>>distance;
			edge e;
			e.src=src-1;
			e.dst=dst-1;
			e.distance=distance;
			edge_vec.push_back(e);
		}
		sort(edge_vec.begin(),edge_vec.end(),cmp);
		vector<vertex> vertex_vec;
		vertex_vec.resize(N);
		for(int i=0;i<N;i++){
			vertex_vec[i].parent=i;
		}
		int add_count=0;
		int add_sum=0;
		int curr=0;
		while(add_count<N-1){
			int r1=find_root(vertex_vec,edge_vec[curr].src);
			int r2=find_root(vertex_vec,edge_vec[curr].dst);
			if(r1!=r2){
				add_count++;
				add_sum+=edge_vec[curr].distance;
				vertex_vec[r1].parent=r2;
			}
			curr++;
		}
		cout<<add_sum<<endl;
	}
}



