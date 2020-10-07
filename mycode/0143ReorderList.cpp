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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    struct TwoNode
    {
        ListNode* pre;
        ListNode* now;
    };
    map<int,TwoNode*> Map;
    void reorderList(ListNode* head) {
        ListNode* tail=head,*pre=NULL;
        int sum=0,i=0;
        while(tail){
            Map[sum]->now=tail;
            Map[sum]->pre=pre;
            sum++;
            pre=tail;
            tail=tail->next;
        }
        tail=head;
        while(tail){
            if(Map.find(sum-i)!=Map.end()&&Map[sum-i]->now!=tail){
                Map[sum-i]->now->next=tail->next;
                tail->next=Map[sum-i]->now;
                Map[sum-i]->pre->next=NULL;
                i++;
                tail=tail->next->next;
            }else{
                break;
            }
        }
    }
};
int main (){
		
	return 0;
}
