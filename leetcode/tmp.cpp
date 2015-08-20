#include <vector>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head==NULL)
            return NULL;
        ListNode* iter=head->next;
        ListNode* prev=head;
        prev->next=NULL;
        while(true){
            if(iter==NULL){
                return prev;
            }
            ListNode* next=iter->next;  
            iter->next=prev;
            prev=iter;
            iter=next;
        }
    }
    bool isPalindrome(ListNode* head) {
        int size=0;
        ListNode* iter=head;
        while(iter!=NULL){
            iter=iter->next;
            size++;
        }
        if(size==0 || size==1)
            return true;
        ListNode* middle=head;
        int count=0;
        while(count<size/2){
            middle=middle->next;
            count++;
        }
        if(size%2==0){
        } else {
            middle=middle->next;
        }
        //reverse middle
        ListNode* rhead=reverseList(middle);
        //check
        bool allthesame=true;
        ListNode* iter1=head;
        ListNode* iter2=rhead;
        for(int i=0;i<size/2;i++){
            if(iter1->val !=iter2->val){
                allthesame=false;
                break;
            }
            iter1=iter1->next;
            iter2=iter2->next;
        }
        //reverse back
        reverseList(rhead);
        return allthesame;
    }
};

int main(){
    Solution s;
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    node1->next=node2;
    cout<<s.isPalindrome(node1)<<endl;
}
