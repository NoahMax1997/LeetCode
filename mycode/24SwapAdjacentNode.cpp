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
    void SwapTwoNode(ListNode** pre,ListNode** left,ListNode** right){
        if(*pre==nullptr){
            (*left)->next=(*right)->next;
            (*right)->next=(*left);
        }else{
            (*left)->next=(*right)->next;
            (*right)->next=(*left);
            (*pre)->next=(*right);
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode **tail=&head,**pre=NULL;
        while(*tail!=NULL&&(*tail)->next!=NULL){
            SwapTwoNode(pre,tail,&((*tail)->next));
            pre=&(*tail)->next;
            tail=&(*tail)->next->next;
        }
        return head;
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
    system("pause");
    return 0;
}