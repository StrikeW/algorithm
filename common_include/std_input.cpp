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
http://blog.itpub.net/7379093/viewspace-838542/
*/

void ip_addr(){
/*
5
4.3.2.1/10
4.3.2.2/11
4.3.2.3
4.3.2.4/1
4.3.2.5/10
*/
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a[4];
		int mask=32;
		int r=scanf("%d.%d.%d.%d/%d",&a[0],&a[1],&a[2],&a[3],&mask);
		printf("%d\n",r);
		//printf("%d %d %d %d / %d\n",a[0],a[1],a[2],a[3],mask);
	}
	
}
int main(){
	ip_addr();
}


