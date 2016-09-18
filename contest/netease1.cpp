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

struct graph{
	int N;
	int M;
	vector<vector<int> > data;
	graph(int n,int m){
		N=n;
		M=m;
		data.resize(max(n,m));
		for(int i=0;i<max(n,m);i++){
			data[i].resize(max(n,m));
		}
	}
};
void op1(graph* g1,graph *g2){
	g2->N=g1->M;
	g2->M=g1->N;
	for(int i=0;i<g1->N;i++){
		for(int j=0;j<g1->M;j++){
			g2->data[j][g1->N-i-1]=g1->data[i][j];
		}
	}
}
void op2(graph* g1,graph *g2){
	g2->N=g1->M;
	g2->M=g1->N;
	for(int i=0;i<g1->N;i++){
		for(int j=0;j<g1->M;j++){
			g2->data[g1->M-1-j][i]=g1->data[i][j];
		}
	}
}
void op3(graph* g1){
	for(int i=0;i<(g1->N)/2 ;i++){
		for(int j=0;j<g1->M ;j++){
			swap(g1->data[i][j],g1->data[g1->N-1-i][j]);
		}
	}
}
void op4(graph* g1){
	for(int i=0;i<g1->N ;i++){
		for(int j=0;j<(g1->M)/2 ;j++){
			swap(g1->data[i][j],g1->data[i][g1->M-1-j]);
		}
	}
}
void op5(graph* g1,int x0,int y0,int x1,int y1,int val){
	for(int i=x0;i<=x1 ;i++){
		for(int j=y0;j<=y1 ;j++){
			g1->data[i][j]+=val;
			if(g1->data[i][j]>=255){
				g1->data[i][j]=255;
			}
		}
	}
}
void op6(graph* g1,int x0,int y0,int x1,int y1,int val){
	for(int i=x0;i<=x1 ;i++){
		for(int j=y0;j<=y1 ;j++){
			g1->data[i][j]-=val;
			if(g1->data[i][j]<=0){
				g1->data[i][j]=0;
			}
		}
	}
}
void op7(graph* g1,graph* g2,int x0,int y0,int x1,int y1){
	for(int i=x0;i<=x1 ;i++){
		for(int j=y0;j<=y1 ;j++){
			g2->data[i-x0][j-y0]=g1->data[i][j];
		}
	}
	g2->N=x1-x0+1;
	g2->M=y1-y0+1;
}	

int main(){
	cin.sync_with_stdio(false);
	int S;
	cin>>S;
	while(S>0){
		S--;
		int N,M;
		cin>>N>>M;
		graph* g1=new graph(N,M);
		graph* g2=new graph(N,M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>g1->data[i][j];
			}
		}
		int T;
		cin>>T;
		while(T>0){
			T--;
			int op;
			int x0,x1,y0,y1,val;
			cin>>op;
			switch (op){
				case 1:
					op1(g1,g2);
					swap(g1,g2);
					break;
				case 2:
					op2(g1,g2);
					swap(g1,g2);
					break;
				case 3:
					op3(g1);
					break;
				case 4:
					op4(g1);
					break;
				case 5:
					cin>>x0>>y0>>x1>>y1>>val;
					op5(g1,x0,y0,x1,y1,val);
					break;
				case 6:
					cin>>x0>>y0>>x1>>y1>>val;
					op6(g1,x0,y0,x1,y1,val);
					break;
				case 7:
					cin>>x0>>y0>>x1>>y1;
					op7(g1,g2,x0,y0,x1,y1);
					swap(g1,g2);
					break;
			}
		}
		int val=0;
		for(int i=0;i<g1->N;i++){
			for(int j=0;j<g1->M;j++){
				val+=g1->data[i][j];
			}	
		}
		cout<<g1->N<<" "<<g1->M<<" "<<g1->data[0][0]<<" "<<val<<endl;
	}
}