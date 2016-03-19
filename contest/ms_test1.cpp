#include <climits>  //INT_MAX  INT_MIN
#include <cstring>

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

using namespace std;

int get_gcd(int a,int b){
	if(a<b){
		swap(a,b);
	}
	if(a%b==0){
		return b;
	}
	return get_gcd(a-b,b);
}
int gcd[101][101];
int dp[101][101][51];
int cal(int i,int n,int m){
	if(dp[i][n][m]!=-1){
		return dp[i][n][m];
	}
	if(n==0){
		if(m==1){
			dp[i][n][m]=1;
		} else {
			dp[i][n][m]=0;
		}
		return dp[i][n][m];	
	} else if(n<=i){
		dp[i][n][m]=0;
		return dp[i][n][m];	
	}
	dp[i][n][m]=0;
	for(int first=i+1;first<=n;first++){
		//first
		//n-first
		// m/gcd(m,n-first)
		dp[i][n][m]+=cal(first,n-first , m/gcd[m][first]);
	}
	dp[i][n][m]%= 1000000007;
	return dp[i][n][m];
}

//1 6 2
    // 2	4	1 
	// 3	3	2 0
int main(){
	int N,M;
	cin>>N>>M;
	CLR(dp, -1);
	for(int i=1;i<101;i++){
		for(int j=1;j<101;j++){
			gcd[i][j]=get_gcd(i,j);
		}
	}
	cout<<cal(0,N,M)<<endl;
	//dp[0][N][M];
	//first number should larger than 0;
	

}





