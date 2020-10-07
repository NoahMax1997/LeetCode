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
    set<ListNode*> Set;
    ListNode *detectCycleSet(ListNode *head) {
        ListNode *tail=head;
        int i=0;
        while(tail){
            if(Set.find(tail)!=Set.end()){
                return tail;
            }
            Set.insert(tail);
            tail=tail->next;
        }
        return NULL;
    }
    ListNode *detectCycleTwoPoint(ListNode *head) {
        ListNode *pre=head,*fast=head,*slow=head;
        while(fast&&slow){
            if(slow==fast){
                break;
            }
            slow=slow->next;
            if(fast->next){
                fast=fast->next->next;
            }else
            {
                fast=fast->next;
            }
        }
        while(pre&&fast){
            if(pre==fast){
                return pre;
            }
            pre=pre->next;
            fast=fast->next;
        }
        return NULL;
    }
};
int main (){
		
	return 0;
}
