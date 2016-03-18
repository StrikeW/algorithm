#include <climits>  //INT_MAX  INT_MIN


#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))

void setmin(int &x, int y)
{
    x = min(x, y);
}

int dp[54][54][54][3][3][4];

void init(){
	int N=52;
	CLR(dp,INF);
	dp[1][0][0][0][0][3]=1;
	dp[0][1][0][1][0][3]=1;
	dp[0][0][1][2][0][3]=1;
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			for(int k = 0; k < N; k ++){
				for(int p = 0; p < 3; p ++){
					for(int q = 0; q < 3; q ++){
						for(int r = 1; r <=3 ; r ++){
							if(dp[i][j][k][p][q][r] != INF){
								for(int nxt=0;nxt<3;nxt++){
									int ii = i, jj = j, kk = k;
									if(nxt == 0) ii ++;
                                	if(nxt == 1) jj ++;
                                	if(nxt == 2) kk ++;
									//if put at the same level as last one
									//we need p+1 space, but we have only 0
									int require_space= max(p+1,nxt+1);
									int another_line=3;
									//dp[i][j][k][p][q][r]
									setmin(dp[ii][jj][kk][nxt][q][another_line],dp[i][j][k][p][q][r]+require_space+1);

									//if put at the different level as last one
									//we need max(q+1,nxt+1) space , and we already have r
									if(max(q+1,nxt+1)<=r){
										//we have enough space
										another_line=1; 
										setmin(dp[ii][jj][kk][nxt][p][another_line],dp[i][j][k][p][q][r]+1);
									} else {
										int more_space=max(q+1,nxt+1)-r;
										setmin(dp[ii][jj][kk][nxt][p][1+more_space],dp[i][j][k][p][q][r]+1+more_space);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



int main(){
	init();
	dp[0][0][0][0][0][1] = 0;
	int n, m, k, T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &n, &m, &k);
        int ans = INF;
        for(int i = 0; i < 3; i ++)
        {
            for(int j = 0; j < 3; j ++)
            {
                for(int s = 1; s <= 3; s ++)
                    ans = min(ans, dp[n][m][k][i][j][s]);
            }
        }
        printf("%d\n", ans);
    }
}




