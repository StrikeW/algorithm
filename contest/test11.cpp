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
struct score_pair{
	int S;
	int T;
	score_pair(int s,int t){
		S=s;
		T=t;
	}
};
vector<score_pair> get_possible_pair(int S,int T,int Ai){
	vector<score_pair> result;
	int s=0;
	while(true){
		if(s*S>=Ai){
			result.push_back(score_pair(s,0));
			break;
		}
		int t=(Ai-s*S)/T;
		if(t*T + s*S < Ai){
			t++;
		}
		result.push_back(score_pair(s,t));
		s++;
	}
	return result;
}
int Minimal;
int remove_tomany_t[1001][1001];
void dfs(int M,vector< vector<score_pair> > & matrix,vector<int> & A , int level , int curr_S, int curr_T ){
	if(level==A.size()){
		if(curr_S<Minimal){
			Minimal=curr_S;
		}
		return ;
	}
	if(remove_tomany_t[level][curr_S]<=curr_T){
		return ;
	} else {
		remove_tomany_t[level][curr_S]=curr_T;
	}
	int score= A[level];
	for(int i=matrix[score].size()-1;i>=0;i--){
		int next_S=curr_S+matrix[score][i].S;
		int next_T=curr_T+matrix[score][i].T;
		if(next_S + next_T >M){
			continue;
		}
		if(next_S >= Minimal){
			continue;
		}
		dfs(M,matrix,A,level+1,next_S,next_T);
	}
	return ;
}

int dp(int M,vector< vector<score_pair> > & matrix,vector<int> & A){
	int score_0=A[0];
	for(int i=0;i<matrix[score_0].size();i++){
		int s=matrix[score_0][i].S;
		int t=matrix[score_0][i].T;
		if(s+t<=M ){
			remove_tomany_t[0][s]=s+t;
		}
	}
	for(int i=1;i<A.size();i++){
		for(int j=0;j<=M;j++){
			if(remove_tomany_t[i-1][j]!=INF){
				int score= A[i];
				for(int x=0;x<matrix[score].size();x++){
					int s=matrix[score][x].S;
					int t=matrix[score][x].T;
					int new_val=remove_tomany_t[i-1][j]+s+t;
					if(new_val<=M && remove_tomany_t[i][j+s]>new_val){
						remove_tomany_t[i][j+s]=new_val;
					}
				}
			}
		}
	}
	int ret=INF;
	for(int j=0;j<=M;j++){
		if(remove_tomany_t[A.size()-1][j]!=INF){
			return j;
		}
	}
	return ret;
}
int main(){
	int Q;
	cin>>Q;
	while(Q>0){
		Minimal=INF;
		CLR(remove_tomany_t,INF);
		Q--;
		int N,M,S,T;
		cin>>N>>M>>S>>T;
		vector<int> A;
		for(int i=0;i<N;i++){
			int tmp;
			cin>>tmp;
			A.push_back(tmp);
		}
		vector< vector<score_pair> > matrix;
		matrix.resize(51);
		for(int i=1;i<=50;i++){
			matrix[i]=get_possible_pair(S,T,i);
		}
		// dfs(M,matrix,A,0,0,0);
		Minimal=dp(M,matrix,A);
		if(Minimal!=INF){
			cout<<Minimal<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
}

