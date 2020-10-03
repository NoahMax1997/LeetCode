#include <iostream>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists,int begin,int end) {
        if(begin>=end){
            return lists[begin];
        }
        int mid=(end+begin)/2;
        return mergeTwoLists(mergeKLists(lists,begin,mid),mergeKLists(lists,mid+1,end));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret=NULL;
        if(lists.size()==0) return NULL;
        return mergeKLists(lists,0,lists.size()-1);
    }
};
int main (){
    Solution a;
    
    system("pause");
}