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
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* tail=head->next,*pre=head,*t_tail=head,*t_pre=NULL;
        while(tail){
            t_tail=head;
            while(t_tail->next!=tail&&t_tail->val<tail->val){
                t_pre=t_tail;
                t_tail=t_tail->next;
            }
            pre->next=tail->next;
            tail->next=t_tail;
            if(head==t_tail){
                head=tail;
            }
            if(t_pre){
                t_pre->next=tail;
            }
            pre=tail;
            tail=pre->next;
        }
    }
};
int main (){
		
	return 0;
}
