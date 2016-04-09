#include <climits>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    bool exist;
    bool allow;
    int priority;
    TrieNode* next[2];
    TrieNode() {
        for(int i=0;i<2;i++){
            next[i]=NULL;
        }
        exist=false;
    }
};

int get_bit(unsigned int ip, int n){
	return (ip>>(32-n)) & 1;
}
class Trie {
public:
	TrieNode* root;
    Trie() {
        root = new TrieNode();
        root->exist=false;
    }
    void insert(unsigned int ip, int nmask,bool allow,int priority) {
        if(nmask==0){
        	bool found=root->exist;
        	if(root->exist== false){
        		root->exist=true;
        		root->allow=allow;
        		root->priority=priority;
        	}
        	return ;
        }
        TrieNode* iter=root;
        int curr=1;
        while(curr<=nmask){
        	if(iter->exist==true){
        		return ;
        	}
        	if(iter->next[get_bit(ip,curr)]==NULL){
                iter->next[get_bit(ip,curr)]=new TrieNode();
            }
            iter=iter->next[get_bit(ip,curr)];
            curr++;
        }
        if(iter->exist==false){
        	iter->exist=true;
        	iter->allow=allow;
        	iter->priority=priority;
        }
        return ;
    }

    int search(unsigned int ip) {
        TrieNode* iter=root;
        int max_priority=-1;
        int max_allow=1;
        int curr=1;
        while(curr<=32){
        	if(iter->exist==true && iter->priority > max_priority){
        		max_priority=iter->priority;
        		if(iter->allow){
	    			max_allow=1;
	    		} else {
	    			max_allow=-1;
	    		}
        	}
        	if(iter->next[get_bit(ip,curr)]==NULL){
                return max_allow;
            }
            iter=iter->next[get_bit(ip,curr)];
            curr++;
        }
        if(iter->exist==false){
        	return 0;
        }
        if(iter->allow){
			return 1;
		} else {
			return -1;
		}
    }
};

struct ipinfo{
	bool allow;
	int nmask;
	int data[4];
	unsigned int binary_ip;
};
unsigned int str_to_binary(string& ip){
	int data[4];
	int last_pos=0;
	for(int i=0;i<4;i++){
		int val=0;
		while(last_pos<ip.size()){
			if(ip[last_pos]=='.' || ip[last_pos]=='/' ){
				last_pos++;
				break;
			}
			val*=10;
			val+=ip[last_pos]-'0';
			last_pos++;
		}
		data[i]=val;
	}
	unsigned int v=0;
	for(int i=0;i<4;i++){
		v= v<<8;
		v= v| data[i];
	}
	return v;
}

bool check(ipinfo& info,unsigned int ip2){
	if(info.nmask==0){
		return true;
	}
	if(info.nmask==32){
		return info.binary_ip == ip2;
	}
	
	return (info.binary_ip>>(32-info.nmask)) == 	(ip2>>(32-info.nmask));
}
int main(){
	cout.sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	vector<ipinfo> info_vec;
	info_vec.reserve(N);
	Trie ipTrie;
	while(N>0){
		N--;
		string str,ip;
		cin>>str>>ip;
		ipinfo info;
		if(str[0]=='a'){
			info.allow=true;
		} else {
			info.allow=false;
		}
		int last_pos=0;
		for(int i=0;i<=4;i++){
			int val=0;
			if(i==4 && last_pos>=ip.size()){
				info.nmask=32;
				break;
			}
			while(last_pos<ip.size()){
				if(ip[last_pos]=='.' || ip[last_pos]=='/' ){
					last_pos++;
					break;
				}
				val*=10;
				val+=ip[last_pos]-'0';
				last_pos++;
			}
			if(i!=4){
				info.data[i]=val;
			} else {
				info.nmask=val;
			}
		}
		unsigned int v=0;
		for(int i=0;i<4;i++){
			v= v<<8;
			v= v| info.data[i];
		}
		info.binary_ip=v;
		
		ipTrie.insert(info.binary_ip, info.nmask,info.allow,N);
		//if(ipTrie.insert(info.binary_ip, info.nmask,info.allow)){
		//	info_vec.push_back(info);
		//}

		// bool new_ip=true;
		// for(int j=0;j<info_vec.size();j++){
		// 	if(check(info_vec[j] , info.binary_ip) && info.nmask >= info_vec[j].nmask){
		// 		new_ip=false;
		// 		break;
		// 	}
		// }
		// if(new_ip){
		// 	info_vec.push_back(info);
		// }
	}

	for(int i=0;i<M;i++){
		string ip;
		cin>>ip;
		unsigned int binary_ip=str_to_binary(ip);
		bool found=false;
		int r=ipTrie.search(binary_ip);
		if(r==0 || r==1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		// for(int j=0;j<info_vec.size();j++){
		// 	if(check(info_vec[j] , binary_ip)){
		// 		if(info_vec[j].allow){
		// 			cout<<"YES"<<endl;
		// 		} else {
		// 			cout<<"NO"<<endl;
		// 		}
		// 		found=true;
		// 		break;
		// 	}
		// }
		if(!found){
			//cout<<"YES"<<endl;
		}
	}
}

/*
2 1
allow 1.2.3.4/30
deny 1.1.1.1
1.1.1.1
*/


