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

struct item{
	int input;
	int output;
};
bool cmp(item a,item b){
    return a.output < b.output;
}

struct vertex{
	item data;
	vector<int> children;
};
void delete_val(vector<int>& vec,int val){
	for(vector<int>::iterator iter= vec.begin();iter!=vec.end(); ){
		if(*iter==val){
			iter=vec.erase(iter);
		} else {
			iter++;
		}
	}
}
void root_as(vector<vertex>& vec,int id,int pid){
	delete_val(vec[id].children,pid);
	for(int i=0;i<vec[id].children.size();i++){
		root_as(vec,vec[id].children[i],id);
	}
};

item merge(item old,item curr){
	item ret;
	ret.input=max(old.input+(curr.input-curr.output),curr.input);
	ret.output =ret.input - (old.input-old.output + curr.input-curr.output);
	return ret;
}
item get_best_order(vector<vertex>& vec,int root){
	vector<item> child_item;
	for(int i=0;i<vec[root].children.size();i++){
		child_item.push_back(get_best_order(vec,vec[root].children[i]));
	}
	sort(child_item.begin(),child_item.end(),cmp);
	item result;
	result.input=0;
	result.output=0;
	for(int i=0;i<child_item.size();i++){
		result=merge(result,child_item[i]);
	}
	result=merge(result,vec[root].data);
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<vertex> vec;
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin>>vec[i].data.input;
		cin>>vec[i].data.output;
	}
	for(int i=0;i<n-1;i++){
		int src;
		int dst;
		cin>>src>>dst;
		src--;
		dst--;
		vec[src].children.push_back(dst);
		vec[dst].children.push_back(src);
	}
	root_as(vec,0,-1);
	item result = get_best_order(vec,0);
	cout<<result.input<<endl;
}




