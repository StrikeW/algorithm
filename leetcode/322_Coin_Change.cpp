#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0){
            return -1;
        }
        if(amount==0){
            return 0;
        }

        vector<int> dp;
        int size=1;
        for(int i=0;i<coins.size();i++){
            size=max(size,coins[i]);
        }
        size+=2;
        dp.resize(size,-1);
        for(int i=1;i<=amount;i++){
            dp[i%size]=-1;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]<0){
                    continue;
                }
                if(i-coins[j]==0){
                    dp[i%size]=1;
                    break;
                }
                if(dp[(i-coins[j]) %size] == -1){
                    continue;
                }
                int possible_coin=dp[(i-coins[j]) %size]+1;
                if(dp[i%size]==-1 || dp[i%size] > possible_coin){
                    dp[i%size]= possible_coin;
                }
            }
        }
        return dp[(amount)%size];
    }
};

int main(){
    Solution s;
    vector<int> coins;
    // coins.push_back(1);
    // coins.push_back(2);
    // coins.push_back(5);
    // cout<<s.coinChange(coins,11)<<endl;

    coins.push_back(2);
    cout<<s.coinChange(coins,3)<<endl;

}
