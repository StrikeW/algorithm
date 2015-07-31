#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.size()==0)
            return 0;
        if(height.size()==1)
            return height[0];
        vector<int> h_stack;
        vector<int> i_stack;
        int max=0;
        for(int i=0;i<height.size()+1;i++){
        	int current_height;
        	if(i<height.size())
        		current_height=height[i];
        	else
        		current_height=0;
        	if(h_stack.size()==0 || current_height>h_stack.back()){
        		h_stack.push_back(current_height);
        		i_stack.push_back(i);
        	} else if(current_height==h_stack.back()){
        		continue;
        	} else {
        		int last_i=i;
        		while(h_stack.size()>0 && current_height<=h_stack.back()){
        			int area=(i - i_stack.back())* h_stack.back();
        			if(area>max)
        				max=area;
        			last_i=i_stack.back();
        			h_stack.pop_back();	 
        			i_stack.pop_back();	 
        		}
        		h_stack.push_back(current_height);
        		i_stack.push_back(last_i);
        	}
        }
        return max;
    }
};
int main(){
	Solution s;
	//int a[] = {2,1,5,6,2,3};
    //int a[] = {1,1,1,1,1,1};
    //vector<int> v(a,a+6);

    int a[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> v(a,a+20);
    cout<<s.largestRectangleArea(v)<<endl;

}