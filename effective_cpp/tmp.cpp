#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_times[10];
        int guess_times[10];
        for(int i=0;i<10;i++){
            secret_times[i]=0;
            guess_times[i]=0;
        }
        int A=0;
        int B=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                A++;
            } else {
                secret_times[secret[i]-'0']++;
                secret_times[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cout<<secret_times[i]<<" "<<guess_times[i]<<endl;
        }
        for(int i=0;i<10;i++){
            B+=min(secret_times[i],guess_times[i]);
        }
        string str=to_string(A);
        str+="A";
        str+=to_string(B);
        str+="B";
        return str;
    }
};
int main(){
	Solution s;
	s.getHint("1807","7810");
}
