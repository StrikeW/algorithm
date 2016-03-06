#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//nth_element(v.begin(),v.begin()+middle,v.end());

void partial_sort(){
    int a[] = {1,18,3,2,5,16,7,4,9,19,14,11,6,13,12,15,8,17,10};
    int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v2(a,a+a_len);
    nth_element(v2.begin(),v2.begin()+v2.size()/2,v2.end());
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
    cout<<endl;
    //output
    //1 8 3 2 5 6 7 4 9 10 14 11 16 13 12 15 18 17 19
}

void internal_quick_sort(int* a,int start,int end){
    if(end-start<=1){
        return ;
    }
    nth_element(a+start,a+start+(end-start)/2,a+end);
    internal_quick_sort(a,start,start+(end-start)/2);
    internal_quick_sort(a,start+(end-start)/2+1,end);
}

void quick_sort(){
    int a[] = {1,18,3,2,5,16,7,4,9,19,14,11,6,13,12,15,8,17,10};
    int a_len=sizeof(a)/sizeof(a[0]);
    internal_quick_sort(a,0,a_len);
    for(int i=0;i<a_len;i++){
        cout<<a[i]<<endl;
    }
}
int main(){
    partial_sort();
    //quick_sort();
}
