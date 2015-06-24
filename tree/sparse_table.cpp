#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct sparse_table{
	//F[i][j] == min(F[0][i],...,F[0][i+2^j-1])
	vector<vector<int> > F;
	int level;
	sparse_table(int n){
		level=20;
		F.resize(n);
		for(int i=0;i<n;i++){
			F[i].resize(level+1);
		}
	}
	void add(int i,int x){
		F[i][0]=x;
	}
	void init(){
		for(int j=1;j<=level;j++){
			//length= 1<<j;
			for(int i=0;i<F.size();i++){
				if(i+(1<<j)-1 < F.size() ){
					F[i][j]=min(F[i][j-1],F[i+(1<<(j-1))][j-1]);
				} else{
					break;
				}
			}
		}
	}
	int query(int start,int end){
		int k=0;
		int n=2;
		while(n<end-start+1){
			k+=1;
			n*=2;
		}
		return min(F[start][k],F[end-(1<<k)+1][k]); 
	}
};


int main(){
	int N;
	cin>>N;
	sparse_table table(N+1);
	int count=0;
	while(N>0){
		N--;
		count++;
		int weight;
//		cin>>weight;
		scanf("%d",&weight); 
		table.add(count,weight);
	}
	table.init();
	int Q;
	cin>>Q;

	while(Q>0){
		Q--;
		int start;
		int end;
		scanf("%d %d",&start,&end); 
		printf("%d\n", table.query(start,end));
//		cin>>start>>end;
//		cout<<table.query(start,end)<<endl;
	}
}






