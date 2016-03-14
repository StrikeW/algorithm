#include <iostream>
#include <vector>
using namespace std;

struct item{
	int a;
	int val;
	bool selected;
	item(int _a,int v){
		a=_a;
		val=v;
		selected=false;
	}
};
int main(){


	int Q;
	cin>>Q;
	for(int q=0;q<Q;q++){
		int N;
		cin>>N;
		vector<item> arr;
		for(int n=0;n<N;n++){
			double input;
			int val;
			cin>>input>>val;
			int a=(int)(input*2);
			arr.push_back(item(a,val));
		}
		int result=0;
		for(int i=0;i<arr.size();i++){
			if(arr[i].a%10==0 && arr[i].val>result){
				result=arr[i].val;
			}
		}
		for(int i=0;i<arr.size();i++){
			for(int j=i+1;j<arr.size();j++){
				int sum=arr[i].a+arr[j].a;
				int sum_val=arr[i].val+arr[j].val;
				if(sum%10==0 && sum_val>result){
					result=sum_val;
				}
			}
		}
		for(int i=0;i<arr.size();i++){
			for(int j=i+1;j<arr.size();j++){
				for(int k=j+1;k<arr.size();k++){
					int sum=arr[i].a+arr[j].a+arr[k].a;
					int sum_val=arr[i].val+arr[j].val+arr[k].val;
					if(sum%10==0 && sum_val>result){
						result=sum_val;
					}
				}
			}
		}
		cout<<result<<endl;
	}
}