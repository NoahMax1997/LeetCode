#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;
        }
        ListNode* position_node=head,*tail=head,*pre=NULL,*t_pre=NULL;
        while(position_node&&position_node->val<x){
            pre=position_node;
            t_pre=position_node;
            position_node=position_node->next;
        }
        tail=position_node;
        while(tail)
        {
            ListNode *t_tail=tail;
            if(tail->val<x){
                // cout<<tail->val<<endl;
                pre->next=tail->next;
                // tail=head;
                // while(tail->val<t_tail->val){
                //     t_pre=tail;
                //     tail=tail->next;
                // }
                tail=pre->next;
                if(t_pre==NULL){
                    cout<<"dsf"<<endl;
                    t_tail->next=head;
                    head=t_tail;
                    t_pre=head;//每次插入都在第一个大于x的东西左边相邻处
                }else{
                    t_tail->next=t_pre->next;
                    t_pre->next=t_tail;
                    t_pre=t_tail;
                }
            }else{
                pre=tail;
                tail=tail->next;
            } 
        }
        return head;
    }
};
int main (){
	
	return 0;
}
