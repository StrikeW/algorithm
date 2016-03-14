#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int vec_max(vector<int>& v){
    int m=INT_MIN;
    for(int i=0;i<v.size();i++){
        m=max(m,v[i]);
    }
    return m;
}
int vec_sum(vector<int>& v){
    int s=0;
    for(int i=0;i<v.size();i++){
        s+=v[i];
    }
    return s;
}
int main(){
    int Q;
    cin>>Q;
    for(int q=0;q<Q;q++){
        int N,M,K,T;
        cin>>N>>M>>K>>T;
        vector<int> A;
        vector<int> B;
        A.resize(M);
        B.resize(M);
        for(int i=0;i<M;i++){
            cin>>A[i];
        }
        for(int i=0;i<M;i++){
            cin>>B[i];
        }
        int n=0;
        int total_cost=0;
        for(n=0;n<N;n++){
            int maxb=vec_max(B);
            if(maxb==0){
                break;
            }
            vector<int> F;
            F.resize(K+vec_max(B),INT_MAX);
            F[0]=0;
            for(int x=1;x<F.size();x++){
                for(int i=0;i<M;i++){
                    if(x>=B[i] && F[x-B[i]]!=INT_MAX ){
                        F[x]=min((F[x-B[i]]+A[i]),F[x]);
                    }
                }
            }
            int value=INT_MAX;
            for(int x=K;x<F.size();x++){
                value=min(value,F[x]);
            }
            total_cost+=value;
            for(int i=0;i<M;i++){
                B[i]=B[i]/T;
            }
        }
        if(n!=N){
            cout<<"No Answer"<<endl;
        } else {
            cout<<total_cost<<endl;
        }
    }
}
