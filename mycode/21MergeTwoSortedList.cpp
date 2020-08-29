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
        ListNode *ret=NULL,*l1_nonius=l1,*l2_nonius=l2,*tail=ret;
        while(l1_nonius!=NULL&&l2_nonius!=NULL){
            cout<<l1_nonius->val<<" "<<l2_nonius->val<<endl;
            if(l1_nonius->val > l2_nonius->val){
                tail=new ListNode(l2_nonius->val,NULL);
                tail=tail->next;
                l2_nonius=l2_nonius->next;
            }else{
                tail=new ListNode(l1_nonius->val,NULL);
                tail=tail->next;
                l1_nonius=l1_nonius->next;
            }
        }
        while(l1_nonius!=NULL){
            tail=new ListNode(l1_nonius->val,NULL);
            tail=tail->next;
            l1_nonius=l1_nonius->next;
        }
        while(l2_nonius!=NULL){
            tail=new ListNode(l2_nonius->val,NULL);
            tail=tail->next;
            l2_nonius=l2_nonius->next;
        }
        return ret;
    }
};
int main()
{
    Solution a;
    ListNode *l1,*l2;
    l1=new ListNode(1,NULL);
    ListNode* h1=l1;
    l1=l1->next;
    l1=new ListNode(2,NULL);
    l1=l1->next;
    l1=new ListNode(4,NULL);
    l1=l1->next;
    l2=new ListNode(1,NULL);
    ListNode* h2=l2;
    l2=l2->next;
    l2=new ListNode(3,NULL);
    l2=l2->next;
    l2=new ListNode(4,NULL);
    l2=l2->next;
    // ListNode *t= a.mergeTwoLists(h1,h2);
    ListNode *t= h1;
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }
    t= h2;
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }
    system("pause");
    return 0;
}