#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1==NULL&&l2==NULL) return NULL;
        ListNode *ret=new ListNode(),*l1_nonius=l1,*l2_nonius=l2,*tail=ret;
        while(l1_nonius!=NULL&&l2_nonius!=NULL){
            // cout<<l1_nonius->val<<" "<<l2_nonius->val<<endl;
            if(l1_nonius->val > l2_nonius->val){
                *tail=*l2_nonius;
                // tail->val=l2_nonius->val;
                l2_nonius=l2_nonius->next;
            }else{
                *tail=*l1_nonius;
                // tail->val=l1_nonius->val;
                l1_nonius=l1_nonius->next;
            }
            tail->next=new ListNode();
            tail=tail->next;
        }
        while(l1_nonius!=NULL){
            *tail=*l1_nonius;
            // tail->val=l1_nonius->val;
            l1_nonius=l1_nonius->next;
            if(l1_nonius!=NULL){
                tail->next=new ListNode();
            }
            tail=tail->next;
        }
        while(l2_nonius!=NULL){
            *tail=*l2_nonius;
            // tail->val=l2_nonius->val;
            l2_nonius=l2_nonius->next;
            if(l2_nonius!=NULL){
                tail->next=new ListNode();
            }
            tail=tail->next;
        }
        return ret;
    }
};
int main()
{
    Solution a;
    ListNode *l1,*l2;
    l1=new ListNode(1,new ListNode(2,new ListNode(4,nullptr)));
    l2=new ListNode(1,new ListNode(3,new ListNode(4,nullptr)));
    ListNode *h1=l1,*h2=l2;
    // l1->val=1;
    // l1=l1->next;//l1只是获取了上一个节点的next的值；l1和上个节点的next是两个变量；给l1 new出新空间不会让上个节点的next也有那个空间
    // l1=new ListNode();
    // l1->val=2;
    // l1=l1->next;
    // l1=new ListNode();
    // l1->val=4;
    // l1=l1->next;
    // l1=NULL;
    
    // l2=new ListNode());
    // ListNode* h2=l2;


    ListNode *t;
    t= a.mergeTwoLists(h1,h2);
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }
    system("pause");
    return 0;
}