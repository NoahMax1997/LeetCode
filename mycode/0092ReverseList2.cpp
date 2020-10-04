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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *n_tail=head,*m_tail=head,*m_pre=NULL;
        if(head==NULL){
            return head;
        }
        while(--n){
            n_tail=n_tail->next;
        }
        while (--m)
        {
            m_pre=m_tail;
            m_tail=m_tail->next;
        }
        
        while(m_tail!=n_tail){
            if(m_pre==NULL){
                head=m_tail->next;
                m_tail->next = n_tail->next;
                n_tail->next=m_tail;
                m_tail=head;
            }else{
                m_pre->next=m_tail->next;
                m_tail->next = n_tail->next;
                n_tail->next=m_tail;
                m_tail=m_pre->next;
            }
        }
        return head;
    }
};
int main (){
		
	return 0;
}
