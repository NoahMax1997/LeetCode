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
    void print(ListNode *tt,int n){
        cout<<"print:"<<n<<endl;
        for(int i=0;i<n&&tt!=NULL;i++){
            printf("value=%d ",tt->val);
            tt=tt->next;
        }
        cout<<endl;
    }
    ListNode* mergeList(ListNode *head,const int &n){
        // print(head,n);
        if(n==0){
            return;
        }
        if(n==1){
            head->next=NULL;
            return head;
        }else{
            ListNode *ret=new ListNode(0,NULL);
            int mid=n/2;
            ListNode *tail=head,*index=head,*pre=ret;
            for(int i=0;i<mid;i++){
                tail=tail->next;
            }
            head=mergeList(head,mid);
            tail=mergeList(tail,n-mid);
            ListNode* tt;
            // if(n==2){
            //     cout<<"sf";
            // }
            while(head&&tail){
                if(head->val<tail->val){
                    ret->next=new ListNode(head->val,NULL);
                    head=head->next;
                }else{
                    ret->next=new ListNode(tail->val,NULL);
                    tail=tail->next;
                }
                ret=ret->next;
            }
            if(tail!=NULL){
                ret->next=tail;
            }else if(head!=NULL){
                ret->next=head;
            }
            return pre->next;
        }
    }
    ListNode* sortList(ListNode* head) {
        int n=0;
        ListNode *tt=head;
        while(tt){
            n++;
            tt=tt->next;
        }
        return mergeList(head,n);
    }
};

int main (){
    ListNode *head=new ListNode(4,new ListNode(2,new ListNode(1,new ListNode(3,NULL))));
    Solution s;
    s.sortList(head);
    system("pause");
	return 0;
}
