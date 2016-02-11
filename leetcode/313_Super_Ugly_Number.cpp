#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
struct item{
	int val;
	int prime;
    int index;
	item(int v,int p,int i):val(v),prime(p),index(i){}
};
struct cmp{
	bool operator()(item a,item b){
		return a.val>b.val;
        //we like smaller first
	}
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> result;
        result.push_back(1);
        priority_queue<item,vector<item>,cmp > p_queue;
        for(int i=0;i<primes.size();i++){
            p_queue.push(item(primes[i],primes[i],0));
        }
        while(true){
            if(result.size()==n){
                return result.back();
            }
            item smallest_item=p_queue.top();
            p_queue.pop();
            if(smallest_item.val > result.back()){
                result.push_back(smallest_item.val);
                //cout<<result.back()<<endl;
            }
            int idx=smallest_item.index+1;
            p_queue.push(item(smallest_item.prime*result[idx],smallest_item.prime,idx));
        }
    }
};


int main(){
    Solution s;
    int a[] = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> primes(a,a+a_len);
    cout<<s.nthSuperUglyNumber(100000,primes)<<endl;
}
