#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
http://blog.csdn.net/sunmenggmail/article/details/8030128
	对于欧拉图，从一个节点出发，随便往下走（走过之后需要标记一下，下次就不要来了），
	必然也在这个节点终止（因为除了起始节点，其他节点的度数都是偶数，只要能进去就能出来）。
	这样就构成了一个圈，但因为是随便走的，所以可能会有些边还没走过就回来了。
	我们就从终止节点逆着往前查找，直到找到第一个分叉路口，
	然后从这个节点出发继续上面的步骤，肯定也是可以找到一条回到这个点的路径的，
	这时我们把两个圈连在一起。当你把所有的圈都找出来后，整个欧拉回路的寻找就完成了。
*/
struct edge{
	int dst;
	bool visited;
};
void add_edge(vector<vector<edge> >& graph,int x,int y){
	if(graph.size()<=x)
		graph.resize(x+1);
	if(graph.size()<=y)
		graph.resize(y+1);
	edge e;
	e.dst=y;
	graph[x].push_back(e);
}
static void euler(vector<vector<edge> >& graph,int x,vector<int>& output) {
	int i;
	for (i = graph[x].size() - 1; i >= 0; --i) {
		if (!graph[x][i].visited) {
			graph[x][i].visited = true;
			euler(graph,graph[x][i].dst,output);
		}
	}
	output.push_back(x);
}

int main(){
	vector<vector<edge> > g;
	add_edge(g,1,2);
	add_edge(g,2,1);
	add_edge(g,1,4);
	add_edge(g,4,1);
	add_edge(g,2,3);
	add_edge(g,3,2);
	add_edge(g,3,4);
	add_edge(g,4,3);
	add_edge(g,2,4);
	add_edge(g,4,2);
	vector<int> output;
	euler(g,1,output);
	reverse(output.begin(),output.end());
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
}