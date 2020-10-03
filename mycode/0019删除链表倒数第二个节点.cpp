#include <iostream>
using namespace std;
class Solution {
public:
	ListNode* next_n(ListNode* point,int n){
		while(n--){
			point=point->next;
		}
		return point;
	}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode *nonius=head,*pre=NULL;
        while(next_n(nonius,n)!=NULL){
        	pre=nonius;
        	nonius=nonius->next;
		}
		if(pre==NULL){
			head=head->next;
			delete nonius;
		}else{
			pre->next=nonius->next;
			delete nonius;
		}
		return head;
    }
};
int main (){
	
	return 0;
}
