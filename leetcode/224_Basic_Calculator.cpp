#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int i=0;
        return cal(s,i);
    }
    int cal(string& s,int& i){
    	int result=0;
    	bool add=true;
    	while(true){
    		if(i>=s.size()||s[i]==')'){
    			i++;
    			return result;
    		}
    		if(s[i]==' '){
    			i++;
    			continue;
    		}
    		if(s[i]=='+'){
    			i++;
    			add=true;
    			continue;
    		}
    		if(s[i]=='-'){
    			i++;
    			add=false;
    			continue;
    		}
    		int num=0;
    		if(s[i]=='('){
    			i++;
    			num=cal(s,i);
    		} else {
    			while(i<s.size()&& '0'<=s[i] && s[i]<='9'){
    				num=num*10;
    				num+=s[i]-'0';
    				i++;
    			}
    		}
    		if(add){
    			result+=num;
    		} else {
    			result-=num;
    		}
    	}
    }
};
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
int main(){
	Solution s;
	cout<<s.calculate("1 + 1");
	cout<<s.calculate(" 2-1 + 2 ");
	cout<<s.calculate(" (1+(4+5+2)-3)+(6+8) ");
}


