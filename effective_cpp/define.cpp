#include <iostream>

using namespace std;

#define something(A, B)  ((A)+(B))

int main(){
    int a,b;
    a=3,b=4;
    cout << something(a=3,b=4)<<endl;
}
