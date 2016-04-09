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

#define MOD	1000000007
bool check(int a,int b,int m){
	if(a>=0 && b>=0 && (m-a-b)>=0)
		return true;
	return false;
}
LL dp[101][101][101];
LL ans[101][101];
// dp[i][a][b], a = number of col 1, b = number of col 2 , m-a-b = number of 0
int main(){
	for(LL m=1;m<=100;m++){
		CLR(dp,0);
		dp[0][0][0]=1;  // virtual row 0
		int n=100;
		for(LL i=0;i<n;i++){
			for(LL a=0;a<=m;a++){
				for(LL b=0;b<=m;b++){
					if(!check(a,b,m)){
						continue;
					}
					if(dp[i][a][b] == 0 ){
						continue;
					} else {
						//cout<<"("<<i<<","<<a<<","<<b<<")"<< dp[i][a][b]<<endl;
					}
					// dp[i][a][b];
					// 不放
					dp[i+1][a][b]+=dp[i][a][b];
					dp[i+1][a][b]%=MOD;
					// 放1个到0
					if(check(a+1,b,m) && (m-a-b>0)){
						dp[i+1][a+1][b]+= (m-a-b) * dp[i][a][b];
						dp[i+1][a+1][b]%= MOD;
					}
					// 放1个到1
					if(check(a-1,b+1,m) && (a>0)){
						dp[i+1][a-1][b+1]+= a * dp[i][a][b];
						dp[i+1][a-1][b+1]%= MOD;
					}
					// 放2个到0
					if(check(a+2,b,m) && (m-a-b>1)){
						dp[i+1][a+2][b]+= ((m-a-b) * (m-a-b-1) /2)* dp[i][a][b];
						dp[i+1][a+2][b]%= MOD;
					}
					// 放2个到1
					if(check(a-2,b+2,m) && (a>1)){
						dp[i+1][a-2][b+2]+= a *(a-1) /2 * dp[i][a][b];
						dp[i+1][a-2][b+2]%= MOD;
					}
					// 放1个到0 放1个到1
					if(check(a,b+1,m) && (a>0) && (m-a-b>0) ){
						dp[i+1][a][b+1]+= a *(m-a-b) * dp[i][a][b];
						dp[i+1][a][b+1]%= MOD;
					}
					// 放了1个2到0
					if(check(a,b+1,m) &&  (m-a-b>0) ){
						dp[i+1][a][b+1]+= (m-a-b) * dp[i][a][b];
						dp[i+1][a][b+1]%= MOD;
					}
				}
			}
			LL sum=0;
			for(LL a=0;a<=m;a++){
				for(LL b=0;b<=m;b++){
					sum+=dp[i+1][a][b];
					sum%=MOD;
				}
			}
			ans[i+1][m]=sum;
		}
	}
	int T;
	cin>>T;
	while(T>0){
		T--;
		LL n,m;
		cin>>n>>m;
		cout<<ans[n][m]<<endl;
	}
}
// int main(){
// 	int T;
// 	cin>>T;
// 	while(T>0){
// 		T--;
// 		LL n,m;
// 		cin>>n>>m;
// 		CLR(dp,0);
// 		dp[0][0][0]=1;  // virtual row 0
// 		for(LL i=0;i<n;i++){
// 			for(LL a=0;a<=m;a++){
// 				for(LL b=0;b<=m;b++){
// 					if(!check(a,b,m)){
// 						continue;
// 					}
// 					if(dp[i][a][b] == 0 ){
// 						continue;
// 					} else {
// 						//cout<<"("<<i<<","<<a<<","<<b<<")"<< dp[i][a][b]<<endl;
// 					}
// 					// dp[i][a][b];
// 					// 不放
// 					dp[i+1][a][b]+=dp[i][a][b];
// 					dp[i+1][a][b]%=MOD;
// 					// 放1个到0
// 					if(check(a+1,b,m) && (m-a-b>0)){
// 						dp[i+1][a+1][b]+= (m-a-b) * dp[i][a][b];
// 						dp[i+1][a+1][b]%= MOD;
// 					}
// 					// 放1个到1
// 					if(check(a-1,b+1,m) && (a>0)){
// 						dp[i+1][a-1][b+1]+= a * dp[i][a][b];
// 						dp[i+1][a-1][b+1]%= MOD;
// 					}
// 					// 放2个到0
// 					if(check(a+2,b,m) && (m-a-b>1)){
// 						dp[i+1][a+2][b]+= ((m-a-b) * (m-a-b-1) /2)* dp[i][a][b];
// 						dp[i+1][a+2][b]%= MOD;
// 					}
// 					// 放2个到1
// 					if(check(a-2,b+2,m) && (a>1)){
// 						dp[i+1][a-2][b+2]+= a *(a-1) /2 * dp[i][a][b];
// 						dp[i+1][a-2][b+2]%= MOD;
// 					}
// 					// 放1个到0 放1个到1
// 					if(check(a,b+1,m) && (a>0) && (m-a-b>0) ){
// 						dp[i+1][a][b+1]+= a *(m-a-b) * dp[i][a][b];
// 						dp[i+1][a][b+1]%= MOD;
// 					}
// 					// 放了1个2到0
// 					if(check(a,b+1,m) &&  (m-a-b>0) ){
// 						dp[i+1][a][b+1]+= (m-a-b) * dp[i][a][b];
// 						dp[i+1][a][b+1]%= MOD;
// 					}
// 				}
// 			}
// 		}
// 		LL sum=0;
// 		for(LL a=0;a<=m;a++){
// 			for(LL b=0;b<=m;b++){
// 				if(dp[n][a][b] != 0 ){
// 					//cout<<"("<<n<<","<<a<<","<<b<<")"<< dp[n][a][b]<<endl;
// 				}
// 				sum+=dp[n][a][b];
// 				sum%=MOD;
// 			}
// 		}
// 		cout<<sum<<endl;
// 	}
// }









