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

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))

vector<int> B;
vector<int> A;
vector<vector<int> > citymap;
void query(int x,int y,int p,int q){
	//clear
	for(int i=0;i<citymap.size();i++){
		for(int j=0;j<citymap[i].size();j++){
			if(citymap[i][j]!=-1){
				citymap[i][j]=INT_MAX;
			}
		}
	}

	citymap[x][y]=0;
	queue<pair<int,int> > v_queue;
	v_queue.push(pair<int,int>(x,y));
	while(v_queue.size()>0){
		pair<int,int> point=v_queue.front();
		v_queue.pop();
		// up down left right
		int new_x[]={point.first-1,point.first+1,point.first,point.first};
		int new_y[]={point.second,point.second,point.second-1,point.second+1};
		int new_dis[]={B[point.first-1],B[point.first],A[point.second-1],A[point.second]};
		for(int i=0;i<4;i++){
			if(citymap[new_x[i]][new_y[i]] == -1){
				continue;
			}
			if(citymap[new_x[i]][new_y[i]] > citymap[point.first][point.second] + new_dis[i] ){	
				citymap[new_x[i]][new_y[i]]	=citymap[point.first][point.second] + new_dis[i];	
				v_queue.push(pair<int,int>(new_x[i],new_y[i]));
			}
		}
	}


	// for(int i=0;i<citymap.size();i++){
	// 	for(int j=0;j<citymap[i].size();j++){
	// 		cout<<citymap[i][j]<<"\t";
			
	// 	}
	// 	cout<<endl;
	// }

	if(citymap[p][q]==INT_MAX){
		cout<<-1<<endl;
	} else {
		cout<<citymap[p][q]<<endl;
	}
}
int main(){
	int N,M;
	cin>>N>>M;
	B.push_back(0);
	for(int i=0;i<N-1;i++){
		int tmp;
		cin>>tmp;
		B.push_back(tmp);
	}
	B.push_back(0);
	A.push_back(0);
	for(int i=0;i<M-1;i++){
		int tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
	A.push_back(0);
	citymap.resize(N+2);
	for(int i=0;i<N+2;i++){
		citymap[i].resize(M+2);
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int x,y;
		cin>>x>>y;
		citymap[x][y]=-1;
	}
	for(int i=0;i<citymap.size();i++){
		citymap[i][0]=-1;
		citymap[i][M+1]=-1;
	}
	for(int i=0;i<citymap[0].size();i++){
		citymap[0][i]=-1;
		citymap[N+1][i]=-1;
	}
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++){
		int x,y,p,q;
		cin>>x>>y>>p>>q;
		query(x,y,p,q);
	}
}






