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
	vector<vector<char> > data;
	vector<vector<bool> > need_clear;
	graph(int n,int m){
		N=n;
		M=m;
		data.resize(N);
		for(int i=0;i<N;i++){
			data[i].resize(M);
		}
		need_clear.resize(N);
		for(int i=0;i<N;i++){
			need_clear[i].resize(M);
		}
	}
	int count(){
		int c;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(data[i][j]!='.'){
					c++;
				}
			}
		}
		return c;
	}
	bool clear(){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				need_clear[i][j]=false;
			}
		}
		bool found=false;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(i>=2){
					if(data[i][j] == data[i-1][j] && data[i][j] == data[i-2][j]  && data[i][j]!='.' ){
						need_clear[i][j]=true;
						need_clear[i-1][j]=true;
						need_clear[i-2][j]=true;
						found=true;
					}
				}
				if(j>=2){
					if(data[i][j] == data[i][j-1] && data[i][j] == data[i][j-2] && data[i][j]!='.' ){
						need_clear[i][j]=true;
						need_clear[i][j-1]=true;
						need_clear[i][j-2]=true;
						found=true;
					}
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(need_clear[i][j]){
					data[i][j]='.';
				}
			}
		}
		return found;
	}
	void drop(){
		for(int j=0;j<M;j++){
			int last_empty=N-1;
			for(int i=N-1;i>=0;i--){
				if(data[i][j]!='.'){
					swap(data[i][j],data[last_empty][j]);
					last_empty--;
				}
			}	
		}
	}
};

int main(){
	int S;
	cin.sync_with_stdio(false);
	cin>>S;
	while(S>0){
		S--;
		int N,M;
		cin>>N>>M;
		graph* g1=new graph(N,M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>g1->data[i][j];
			}
		}
		int x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;
		int c1=g1->count();
		char c=g1->data[x0][y0];
		g1->data[x0][y0]=g1->data[x1][y1];
		g1->data[x1][y1]=c;
		while(g1->clear()){
			g1->drop();
		}
		int c2=g1->count();
		cout<<c1-c2<<endl;
	}
}




