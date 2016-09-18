#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    long T;
    cin>>T;
    long t=0;
    while(t<T){
        t++;
        cout<<"Case #"<<t<<":"<<endl;
        long N,M;
        cin>>N>>M;
        vector< double> vec;
/*
        vec.push_back(1);
        while(N>0){
            double tmp;
            cin>>tmp;
            vec.push_back(tmp);
            N--;
        }
        for(int i=1;i<vec.size();i++){
            vec[i]=vec[i]*vec[i-1];
        }
*/
        while(N>0){
            double tmp;
            cin>>tmp;
            vec.push_back(tmp);
            N--;
        }
        while(M>0){
            M--;
            double L;
            double R;
            cin>>L>>R;
            double  val=1;
            for(int i=L;i<=R;i++){
                //val*=vec[i];
                val*=pow (vec[i], (( double) 1.0)/(R-L+1));
            }
            //double  val=vec[R+1]/vec[L];
            printf("%.12f\n",val);
        }

    }
}
