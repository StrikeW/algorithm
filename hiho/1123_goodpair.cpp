#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;
struct item{
	int val;
	int num;
	item(int v,int n){
		val=v;
		num=n;
	}
};
struct cmp{  
	bool operator()(item a,item b){  
		return a.val<b.val;
	}  
};

int main(){
	int T;
	cin>>T;
	while(T>0){
		T--;
		int n,m;
		cin>>n>>m;
		vector<item> seq_a;
		vector<item> seq_b;
		while(n>0){
			n--;
			int x,y;
			scanf("%d %d",&x,&y);
			seq_a.push_back(item(x,y));
		}
		while(m>0){
			m--;
			int x,y;
			scanf("%d %d",&x,&y);
			seq_b.push_back(item(x,y));
		}
		sort(seq_a.begin(),seq_a.end(),cmp());
		sort(seq_b.begin(),seq_b.end(),cmp());
		int a=0;
		int b=0;
		// if use int ... it will be WA
		unsigned long long sum_b=0;
		unsigned long long final_result = 0;
		while(a<seq_a.size() && seq_b[b].val>=seq_a[a].val){
			a++;
		}
		while(a<seq_a.size()){
			while(b<seq_b.size() && seq_b[b].val<seq_a[a].val){
				sum_b+=seq_b[b].num;
				b++;
			}
			final_result+=sum_b*seq_a[a].num;
			a++;
		}
		cout<<final_result<<endl;
	}
}