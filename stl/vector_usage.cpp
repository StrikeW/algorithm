#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void init(){
	//{-1,-1,-1}
	vector<int> v1(3,-1); 
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<endl;

	//{3,2,5,4,1}
	int a[] = {3,2,5,4,1};
    vector<int> v2(a,a+5);
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<endl;
}


bool cmp(int a,int b){
    return a*a < b*b;
}
void sort(){
	int a[] = {3,-2,5,-4,1};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v2(a,a+a_len);
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<endl;

	//sort based on square value;
	sort(v2.begin(),v2.end(),cmp);
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<endl;
}

void delete_val(vector<int>& vec,int val){
	for(vector<int>::iterator iter= vec.begin();iter!=vec.end(); ){
		if(*iter==val){
			iter=vec.erase(iter);
		} else {
			iter++;
		}
	}
}
void delete_elelemt(){
	int a[] = {1,2,3,3,3,4,5,6,7};
	int a_len=sizeof(a)/sizeof(a[0]);
	vector<int> vec(a,a+a_len);
	for(vector<int>::iterator iter= vec.begin();iter!=vec.end(); ){
		if(*iter==3){
			iter=vec.erase(iter);
		} else {
			iter++;
		}
	}
	for(vector<int>::iterator iter= vec.begin();iter!=vec.end(); iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int main(){
	//init();
	//sort();
	delete_elelemt();
}