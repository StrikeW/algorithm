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

/*
int dfs(int i, int s, bool e) {
    if (i==-1) return s==target_s;
    if (!e && ~f[i][s]) return f[i][s];
    int res = 0;
    int u = e?num[i]:9;
    for (int d = first?1:0; d <= u; ++d)
        res += dfs(i-1, new_s(s, d), e&&d==u);
    return e?res:f[i][s]=res;
}
f为记忆化数组；

i为当前处理串的第i位（权重表示法，也即后面剩下i+1位待填数）；

s为之前数字的状态（如果要求后面的数满足什么状态，也可以再记一个目标状态t之类，for的时候枚举下t）；

e表示之前的数是否是上界的前缀（即后面的数能否任意填）。

for循环枚举数字时，要注意是否能枚举0，以及0对于状态的影响，有的题目前导0和中间的0是等价的，
但有的不是，对于后者可以在dfs时再加一个状态变量z，表示前面是否全部是前导0，
也可以看是否是首位，然后外面统计时候枚举一下位数。It depends.
*/

int f[20][10];
int num[20];
// 不要62和4
int dfs(int i, int s, bool e) {
    if (i==0) return s!=4;
    if (!e && f[i][s]!=0) return f[i][s];
    int res = 0;
    int u = e?num[i-1]:9;
    for (int d = 0; d <= u; ++d){
    	if(d==4 || (s==6 && d==2) ){
    		continue;
    	}
        res += dfs(i-1, d , e&&(d==u));
    }
    return e?res:f[i][s]=res;
}
int solve(int n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	int len=0;
	while(n>0){
		num[len]=n%10;
		n=n/10;
		len++;
	}
	return dfs(len,0,true);
}
int main(){
	CLR(f,0);
	CLR(num,0);
	while(true){
		int a,b;
		cin>>a>>b;
		if(a==0 && b==0){
			break;
		}
		cout<<solve(b) - solve(a-1)<<endl;
	}
}











