#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	long long long_numerator=numerator;
    	long long long_denominator=denominator;

    	if(long_numerator==0)
    		return "0";
    	string result="";
    	if( (long_numerator<0 && long_denominator>0) || (long_numerator>0 && long_denominator<0)){
    		result="-";
    	}
    	long_numerator=abs(long_numerator);
    	long_denominator=abs(long_denominator);
        long long before_dot=long_numerator/long_denominator;
        result=result+to_string(before_dot);
        if(long_numerator%long_denominator==0){
            return result;
        }
        result=result+".";

        // 1/30 as example
        unordered_map<long long,int> digit_to_position;
        vector<int> digit_vec;
        long_numerator=(long_numerator%long_denominator)*10;
        while(true){
            if(digit_to_position.find(long_numerator)==digit_to_position.end()){
            	digit_to_position[long_numerator]=digit_vec.size();
            	digit_vec.push_back(long_numerator/long_denominator);
            	long_numerator=(long_numerator%long_denominator)*10;
            	if(long_numerator==0){
            		for(int i=0;i<digit_vec.size();i++){
            			string last_digit="0";
            			last_digit[0]+=digit_vec[i];
            			result=result+last_digit;
            		}
            		break;
            	}
            } else {
            	int start=digit_to_position[long_numerator];
            	for(int i=0;i<start;i++){
            		string last_digit="0";
            		last_digit[0]+=digit_vec[i];
            		result=result+last_digit;
            	}
            	result=result+"(";
            	for(int i=start;i<digit_vec.size();i++){
            		string last_digit="0";
            		last_digit[0]+=digit_vec[i];
            		result=result+last_digit;
            	}
            	result=result+")";
            	break;
            }
        }
        return result;
    }
};

int main(){
	Solution s;
	cout<<s.fractionToDecimal(2,20)<<endl;
	cout<<s.fractionToDecimal(1,30)<<endl;
	cout<<s.fractionToDecimal(-1,-2147483648)<<endl;
	cout<<s.fractionToDecimal(-2147483648, 1)<<endl;

}