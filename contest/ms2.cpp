#include <climits>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
using namespace std;
int dp[101][101][2];
int main(){
	int N,M;
	cin>>N>>M;
	vector<string> maze;
	maze.resize(N);
	for(int i=0;i<N;i++){
		cin>>maze[i];
	}
	CLR(dp,INF);
	dp[0][0][0]=0; // right
	dp[0][0][1]=1; // down
	if(M==1 || maze[0][1]=='b'){
		dp[0][0][1]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i==0 && j==0){
				continue;
			}
			int need_clear=((maze[i][j]=='b')?1:0);
			// from up to down
			if(i!=0){
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+need_clear);
				int turn_down;
				if(j==M-1 || (maze[i-1][j+1]=='b')){
					turn_down=0;
				} else {
					turn_down=1;
				}
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+turn_down+need_clear);
			}
			// from left to right
			if(j!=0){
				dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][0]+need_clear);
				int turn_right;
				if(i==N-1 || (maze[i+1][j-1]=='b')){
					turn_right=0;
				} else {
					turn_right=1;
				}
				dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][1]+turn_right+need_clear);
			}
			// change direction
			int turn_down;
			if(j==M-1 || (maze[i][j+1]=='b')){
				turn_down=0;
			} else {
				turn_down=1;
			}
			int turn_right;
			if(i==N-1 || (maze[i+1][j]=='b')){
				turn_right=0;
			} else {
				turn_right=1;
			}
			dp[i][j][1]=min(dp[i][j][1],dp[i][j][0]+turn_right);
			dp[i][j][0]=min(dp[i][j][0],dp[i][j][1]+turn_down);

		}
	}
	cout<<min(dp[N-1][M-1][0],dp[N-1][M-1][1])<<endl;
}




