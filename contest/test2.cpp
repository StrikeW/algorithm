#include <iostream>
#include <vector>
#include <queue>
using namespace std;

size_t get_SP(vector<int>& vec,int K,size_t min_sp){
    size_t expected_sp=0;
    for(int i=vec.size();i>K;i--){
        expected_sp+=(i-K)*vec[i];
        if(expected_sp>min_sp){
            return min_sp+1;
        }
    }
    priority_queue<int,vector<int> > int_queue;
    for(int i=0;i<K;i++){
        int_queue.push(vec[i]);
    }
    size_t SP=0;
    size_t curr=1;
    for(int i=K;i<vec.size();i++){
        SP+=curr*int_queue.top();
        int_queue.pop();
        int_queue.push(vec[i]);
        curr++;
        if(SP>min_sp){
            return SP;
        }
    }
    while(int_queue.size()>0){
        SP+=curr*int_queue.top();
        int_queue.pop();
        curr++;
        if(SP>min_sp){
            return SP;
        }
    }
    return SP;
}
int main(){
    size_t N,Q;
    cin>>N>>Q;
    vector<int> vec_p;
    vec_p.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&vec_p[i]);
    }

    if(get_SP(vec_p,vec_p.size(),Q)>Q ){
        cout<<-1<<endl;
        return 0;
    }
    if(get_SP(vec_p,1,Q)<=Q ){
        cout<<1<<endl;
        return 0;
    }
    int left=1;  // >Q
    int right=vec_p.size();  // <=Q
    while(true){
        if(left+2<right){
            for(int k=left+1;k<=right;k++){
                if(get_SP(vec_p,k,Q)<=Q){
                    cout<<k<<endl;
                    return 0;
                }
            }
        }
        int middle= (left+right)/2;
        size_t sp_mid=get_SP(vec_p,middle,Q);
        if(sp_mid>Q){
            left=middle;
        } else {
            right=middle;
        }
    }
}
