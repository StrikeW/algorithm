#include <iostream>
#include <vector>
using namespace std;

int* segTree;//[maxid*4+10];
int* data;//[maxid];
void build(int node,int begin,int end){
	if(begin==end){
		segTree[node]=data[begin];
		return ;
	}
	int middle=(begin+end)/2;
	build(node*2,begin,middle);
	build(node*2+1,middle+1,end);
	segTree[node]=min(segTree[node*2],segTree[node*2+1]);
}
int query(int node,int begin,int end,int left,int right){
	if(left==begin && right==end)
		return segTree[node];
	int middle=(begin+end)/2;
	if(right<=middle)
		return query(node*2,begin,middle,left,right);
	else if(left >middle)
		return query(node*2+1,middle+1,end,left,right);
	else {
		int l=query(node*2,begin,middle,left,middle);
		int r=query(node*2+1,middle+1,end,middle+1,right);
		return min(l,r);
	}
}
void update(int node,int begin,int end,int index,int val){
	if(begin==end){
		segTree[node]=val;
		return ;
	}
	int middle=(begin+end)/2;
	if(index<=middle)
		update(node*2,begin,middle,index,val);
	else
		update(node*2+1,middle+1,end,index,val);
	segTree[node]=min(segTree[node*2],segTree[node*2+1]);
}
int main(){
	int N;
	cin>>N;
	data=new int[N+1];
	segTree=new int[10*N+10];
	int index=0;
	while(N>0){
		N--;
		index++;
		scanf("%d",&data[index]);
		//cin>>data[index];
	}
	build(1,1,index);
	int M;
	cin>>M;
	while(M>0){
		M--;
		int type,A,B;
		scanf("%d %d %d",&type,&A,&B);
		//cin>>type>>A>>B;
		if(type==0){
			printf("%d\n", query(1,1,index,A,B));
			//cout<<query(1,1,index,A,B)<<endl;
		} else{
			update(1,1,index,A,B);
		}
	}

}








