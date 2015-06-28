#include <iostream>
#include <vector>
using namespace std;

struct seg{
	int num;
	int sum;
};
seg* segTree;
bool* range_set;
int* data;

void build(int node,int begin,int end){
	if(begin==end){
		segTree[node].sum=data[begin];
		segTree[node].num=1;
		return ;
	}
	int middle=(begin+end)/2;
	build(node*2,begin,middle);
	build(node*2+1,middle+1,end);
	segTree[node].num=segTree[node*2].num+segTree[node*2+1].num;
	segTree[node].sum=segTree[node*2].sum+segTree[node*2+1].sum;
}

int range_query(int node,int begin,int end,int left,int right){
	if(left==begin && right==end)
		return segTree[node].sum;
	if(range_set[node]){
		return segTree[node].sum/segTree[node].num * (right-left+1)  ;
	}
	int middle=(begin+end)/2;
	if(right<=middle)
		return range_query(node*2,begin,middle,left,right);
	else if(left >middle)
		return range_query(node*2+1,middle+1,end,left,right);
	else {
		int l=range_query(node*2,begin,middle,left,middle);
		int r=range_query(node*2+1,middle+1,end,middle+1,right);
		return l+r;
	}
}
void range_update(int node,int begin,int end,int left,int right,int val){
	if(begin==end){
		range_set[node]=true;
		segTree[node].sum=val;
		return ;
	}
	if(begin==left && end==right){
		segTree[node].sum=val * segTree[node].num;
		range_set[node]=true;
		return ;
	}
	if(range_set[node]){
		range_set[node]=false;
		range_set[node*2]=true;
		range_set[node*2+1]=true;
		segTree[node*2].sum=segTree[node].sum / segTree[node].num * segTree[node*2].num;
		segTree[node*2+1].sum=segTree[node].sum / segTree[node].num * segTree[node*2+1].num;	
	}
	int middle=(begin+end)/2;
	if(right<=middle){
		range_update(node*2,begin,middle,left,right,val);
	}
	else if(left >middle){
		range_update(node*2+1,middle+1,end,left,right,val);
	}
	else {
		range_update(node*2,begin,middle,left,middle,val);
		range_update(node*2+1,middle+1,end,middle+1,right,val);
	}
	segTree[node].sum=segTree[node*2].sum+segTree[node*2+1].sum;
}



int main(){
	int N;
	cin>>N;
	data=new int[N+1];
	segTree=new seg[10*N+10];
	range_set=new bool[10*N+10];
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
		int val;
		scanf("%d %d %d",&type,&A,&B);
		if(type==1)
			scanf("%d",&val);
		//cin>>type>>A>>B;
		if(type==0){
			printf("%d\n", range_query(1,1,index,A,B));
			//cout<<query(1,1,index,A,B)<<endl;
		} else{
			range_update(1,1,index,A,B,val);
		}
	}
}



