#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* t1=l1;
    	ListNode* t2=l2;
    	ListNode* ret=new ListNode(0);
    	ListNode* t3=ret;
    	int flag=0;
        while(t1!=NULL&&t2!=NULL){
        	ListNode* node=new ListNode(0);
        	node->val=(t1->val+t2->val+flag)%10;
        	flag=(t1->val+t2->val+flag)/10;
        	t3->next=node;
        	t3=t3->next;
        	t1=t1->next;
        	t2=t2->next;
		}
		if(t1==NULL&&t2==NULL&&flag!=0){
			ListNode* node=new ListNode(0);
			node->val=flag;
			t3->next=node;
        	t3=t3->next;
        	flag=0;
		}
		while(t1!=NULL){
			ListNode* node=new ListNode(0);
			node->val=(t1->val+flag)%10;
			flag=(t1->val+flag)/10;
			t1=t1->next;
			t3->next=node;
        	t3=t3->next;
		}while(t2!=NULL){
			ListNode* node=new ListNode(0);
			node->val=(t2->val+flag)%10;
			flag=(t2->val+flag)/10;
			t2=t2->next;
			t3->next=node;
        	t3=t3->next;
		}
		if(flag!=0){
			ListNode* node=new ListNode(0);
			node->val=flag;
			t3->next=node;
        	t3=t3->next;
        	flag=0;
		}
		return ret->next;
    }
};
int main (){
	ListNode* a=new ListNode(0);
//	ListNode* b=new ListNode(0);
	initListWrong(a,3);
//	initListRight(b,3);
	coutList(a);
//	coutList(b->next);
//	Solution s;
//	coutList(s.addTwoNumbers(a,b));
	return 0;
} 
