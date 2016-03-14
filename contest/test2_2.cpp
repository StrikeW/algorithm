#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LL long long
#define ULL unsigned long long

LL get_SP(vector<int>& vec,int K){
    priority_queue<int,vector<int> > int_queue;

    for(int i=0;i<K;i++){
        int_queue.push(vec[i]);
    }
    LL SP=0;
    LL curr=1;
    for(int i=K;i<vec.size();i++){
        SP+=curr*int_queue.top();
        int_queue.pop();
        int_queue.push(vec[i]);
        curr++;
    }
    while(int_queue.size()>0){
        SP+=curr*int_queue.top();
        int_queue.pop();
        curr++;
    }
    return SP;
}

int main(){
    LL N,Q;
    cin>>N>>Q;
    vector<int> vec_p;
    vec_p.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&vec_p[i]);
    }
    int left=1;  // >Q
    int right=vec_p.size();  // <=Q
    //find x that f(x)<=q and f(x-1)>Q
    while(left<right){
        int mid=(left+right)/2;
        LL ret=get_SP(vec_p,mid);
        if(ret >Q){
            left=mid+1;
        } else {
            right=mid;
        }
    }
    cout<<left<<endl;
}
