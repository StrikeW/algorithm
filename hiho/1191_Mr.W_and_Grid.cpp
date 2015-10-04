#include <iostream>
#include <vector>
using namespace std;

	
int	Solution(int n,int m,int i,int j){
	vector<vector<int> >dp;
	dp.resize(n);
	for(int i=0;i<dp.size();i++)
		dp[i].resize(m);
	dp[i-1][j-1]=1;
	int direct_i[4]={1,1,-1,-1};
	int direct_j[4]={1,-1,1,-1};
	for(int d=0;d<4;d++){
		for(int x=i-1;x>=0&&x<n;x+=direct_i[d]){
			for(int y=j-1;y>=0&&y<m;y+=direct_j[d]){
				if(x==i-1 || y==j-1){
					dp[x][y]=1;
				} else {
					dp[x][y]=dp[x-direct_i[d]][y]+dp[x][y-direct_j[d]];
					dp[x][y]=dp[x][y]%1000000007;
				}
			}
		}
	}
	int sum=0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(x==0||y==0||x==n-1 || y==m-1){
				sum+=dp[x][y];
				sum=sum%1000000007;
			}
		}
	}
	return sum;
}
int main(){
	int n,m,i,j;
	while(cin>>n>>m>>i>>j){
		cout<<Solution(n,m,i,j)<<endl;
	}
}