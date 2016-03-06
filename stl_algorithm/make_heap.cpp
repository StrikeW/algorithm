#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//cmp,default= less<int>(),
//if we want a min_heap, we can use greater<int>()
//make_heap(v.begin(),v.end(),cmp)
//push_heap(v.begin(),v.end(),cmp)
//pop_heap(v.begin(),v.end(),cmp)

void pop_one_by_one(){
    int a[] = {1,5,3,2};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v(a,a+a_len);
    make_heap(v.begin(),v.end());

    v.push_back(4);
    push_heap(v.begin(),v.end());

    while(v.size()>0){
        cout<<v.front()<<" ";
        pop_heap(v.begin(),v.end());
        v.pop_back();
    }
    cout<<endl;
}
void sort(){
    int a[] = {1,5,3,2,4};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v(a,a+a_len);
    make_heap(v.begin(),v.end());
    sort_heap(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    sort();
}
