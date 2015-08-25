#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2,int start1,int start2,int k){
        int size1=nums1.size()-start1;
        int size2=nums2.size()-start2;
        if(size1==0)
            return nums2[start2+k];
        if(size2==0)
            return nums1[start1+k];
        if(k==0)
            return min(nums1[start1],nums2[start2]);
        int off=min(size1-1,size2-1);
        off=min(off,(k-1)/2);
        if(nums1[start1+off]<nums2[start2+off])
            return findKth(nums1,nums2,start1+off+1,start2,k-off-1);
        else
            return findKth(nums1,nums2,start1,start2+off+1,k-off-1);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        if(size1+size2 == 0)
            return 0;
        if((size1+size2) %2 ==1)
            return findKth(nums1,nums2,0,0,(size1+size2)/2);
        else 
            return (findKth(nums1,nums2,0,0,(size1+size2)/2)+findKth(nums1,nums2,0,0,(size1+size2)/2 -1))/2.0;
    }
};

int main(){
	int a1[] = {1,2};
	int a1_len=sizeof(a1)/sizeof(a1[0]);
    vector<int> v1(a1,a1+a1_len);
	int a2[] = {1,2};
	int a2_len=sizeof(a2)/sizeof(a2[0]);
    vector<int> v2(a2,a2+a2_len);
    Solution s;
    //cout<<s.findMedianSortedArrays(v1,v2)<<endl;
    cout<<s.findKth(v1,v2,0,0,2)<<endl;
}