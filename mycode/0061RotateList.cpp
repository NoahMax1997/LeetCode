#include <iostream>
#include <vector>
#include <set>
#include <map>
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
    ListNode* rotateRightForce(ListNode* head, int k) {
        ListNode *tail=head,*pre=head;
        if(head==NULL){
            return head;//don't forget anymore
        }
        while(k--){
            while(tail->next!=NULL){
                pre=tail;
                tail=tail->next;
            }
            if(tail==head){
                return head;
            }
            pre->next=NULL;
            tail->next=head;
            head=tail;
        }
        return head;
    }
    ListNode* rotateRightRound(ListNode* head, int k) {
        ListNode *tail=head,*pre=head;
        int size=0;
        if(head==NULL){
            return head;
        }
        while(tail->next!=NULL){
            size++;
            tail=tail->next;
        }
        tail->next=head;
        int t_head=0;
        while(k--){
            t_head--;
            if(t_head<0){
                t_head=size;
            }
        }
        tail=head;
        for(int i=0;i<size;i++){
            if(i==t_head){
                pre->next=NULL;
                head=tail;
            }
            pre=tail;
            tail=tail->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        return rotateRightRound(head,k);
    }
};
int main (){
	Solution a;
    // a.myPow(2,10);
    system("pause");
	return 0;
} 