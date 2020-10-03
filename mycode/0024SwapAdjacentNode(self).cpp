#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairsDFS(ListNode* head) {
        //recursion solusion
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode *next=head->next;
        head->next=swapPairsDFS(next->next);
        next->next=head;
        return next;
    }
    ListNode* swapPairsNoCur(ListNode* head) {
        //recursion solusion fastest
        ListNode *pre=nullptr,*tail=head;
        while(tail!=nullptr&&tail->next!=nullptr){
            if(pre==nullptr){
                head=head->next;
            }
            ListNode *next=tail->next;//remember the tail->next address
            tail->next=tail->next->next;
            next->next=tail;
            if(pre!=nullptr){
                pre->next=next;
            }
            pre=tail;
            tail=tail->next;
        }  
        return head; 
    }
    void swapTwoNode(ListNode* pre,ListNode* left,ListNode* right){
        if(pre==nullptr){
            left->next=right->next;
            right->next=left;
        }else{
            left->next=right->next;
            right->next=left;
            pre->next=right;
        }
    }
    ListNode* swapPairs(ListNode** head1) {
        ListNode *head =*head1,*tail=head,*pre=NULL;
        while(tail!=NULL&&tail->next!=NULL){
            if(pre==NULL){
                *head1=head->next;
            }
            swapTwoNode(pre,tail,tail->next);
            pre=tail;
            tail=tail->next;
        }
        return *head1;
    }
    ListNode* swapPairs(ListNode* head) {
        // return swapPairsDFS(head);
        // return swapPairs(&head);
        return swapPairsNoCur(head);
    }
};
int main (){
    Solution a;
    ListNode *head=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,NULL)))),*tmp=head;
    ListNode *t=head->next->next,*tail=head;
    t=NULL;
    while(tail!=NULL){
        cout<<tail->val<<endl;
        tail=tail->next;
    }
    // cout<<head<<endl;
    // cout<<head<<endl;
    tail = a.swapPairs(head);
    while(tail!=NULL){
        cout<<tail->val<<endl;
        tail=tail->next;
    }
    system("pause");
    return 0;
}