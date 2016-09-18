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


int data[1005][1005];
int dp[1005][1005];
int main(){
	
	cin.sync_with_stdio(false);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>data[i][j];
			
		}
	}

	CLR(dp,INF);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int count=0;
			int tmp=data[i][j];
			if(tmp==0){
				dp[i][j]=10000000;
				continue;
			}
			while(tmp%2 == 0){
				tmp= tmp/2 ;
				count++;
			}
			if(i==0 & j==0){
				dp[i][j]=count;
			}
			else if(i==0 ){
				dp[i][j]=dp[i][j-1]+count;
			}
			else if(j==0 ){
				dp[i][j]=dp[i-1][j]+count;
			}
			else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+count;
			}
		}
	}
	int last=dp[N-1][N-1];
	CLR(dp,INF);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int count=0;
			int tmp=data[i][j];
			if(tmp==0){
				dp[i][j]=10000000;
				continue;
			}
			while(tmp%5 == 0){
				tmp= tmp/5 ;
				count++;
			}
			if(i==0 & j==0){
				dp[i][j]=count;
			}
			else if(i==0 ){
				dp[i][j]=dp[i][j-1]+count;
			}
			else if(j==0 ){
				dp[i][j]=dp[i-1][j]+count;
			}
			else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+count;
			}
		}
	}
	last=min(last,dp[N-1][N-1]);
	cout<<last<<endl;
}



