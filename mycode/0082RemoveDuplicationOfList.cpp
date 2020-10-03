#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode *tail=head,*pre=head;
        while(tail&&tail->next){
            // cout<<"tail:"<<tail->val<<endl;
            if(tail->val==tail->next->val){
                // cout<<"equal:"<<tail->val<<endl;
                int flag=tail->val;
                while(tail&&tail->val==flag){
                    if(head==tail){
                        head=tail->next;
                        delete tail;
                        tail=head;
                        pre=head;
                    }else{
                        pre->next=tail->next;
                        delete tail;
                        tail=pre->next;
                    }
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
