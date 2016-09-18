#include <iostream>
using namespace std;

long get_pow_of_2(long k){
    long v=1;
    while(v<k){
        v*=2;
    }
    return v;
}
long f(long k){
    if(k==1){
        return 0;
    }
    long powof2=get_pow_of_2(k);
    if(k==powof2){
        return 0;
    }
    return 1-f(powof2-k);
}
int main(){
    long T;
    cin>>T;
    long t=0;
    while(t<T){
        t++;
        long K;
        cin>>K;
        cout<<"Case #"<<t<<": "<<f(K)<<endl;
    }
}
