#include <iostream>
#include <vector>
using namespace std;
//  0
//  1        2
//  3   4    5     6
//  7 8 9 10 11 12 13 14
class myheap{ // min_heap
    void shift_up(){
        //after insert a new element to the tail of data
        //we need to shift up
        int idx=data.size()-1;
        while(idx>0){
            int prev_idx=(idx-1)/2;
            if(data[prev_idx]> data[idx]){
                swap(data[idx],data[prev_idx]);
                idx=prev_idx;
            } else {
                break;
            }
        }
    }
    void shift_down(int idx){
        if(data.size()<=1){
            return ;
        }
        while(true){
            int left_idx=idx*2+1;
            int right_idx=idx*2+2;
            if(left_idx>=data.size()){
                break;
            }
            int smaller_idx=left_idx;
            if(right_idx<data.size() && data[left_idx]> data[right_idx]){
                smaller_idx=right_idx;
            }
            if(smaller_idx<data.size() && data[smaller_idx]< data[idx]){
                swap(data[idx],data[smaller_idx]);
                idx=smaller_idx;
                continue;
            }
            break;
        }
    }
public:
    vector<int> data;
    int size(){
        return data.size();
    }
    void push(int n){
        data.push_back(n);
        shift_up();
    }
    int pop(){
        int ret=data[0];
        data[0]=data[data.size()-1];
        data.pop_back();
        shift_down(0);
        return ret;
    }
    void make_heap(){
        for(int i=data.size()/2;i>=0;i--){
            shift_down(i);
        }
    }
};


int main(){
    int a[] = {1,18,3,2,5,16,7,4,9,19,14,11,6,13,12,15,8,17,10};
    int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v(a,a+a_len);
    myheap mheap;
    mheap.data=v;
    mheap.make_heap();
    // for(int i=0;i<v.size();i++){
    //     mheap.push(v[i]);
    // }
    while(mheap.size()>0){
        cout<<mheap.pop()<<" ";
    }
    cout<<endl;
}
