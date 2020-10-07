#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    map<Node*,Node*> Map;
    Node* copyRandomList(Node* head) {
        Node *tail=head,*ret=NULL,*t_tmp,*tt_tail;
        int i=0;
        while(tail){
            if(tail==head){
                ret=new Node(tail->val);
                tt_tail=ret; 
            }else{
                tt_tail->next=new Node(tail->val);
                tt_tail=tail->next;
            }
            tt_tail->random=tail->random;
            Map[tail]=tt_tail;
            tail=tail->next;
            // tt_tail=tt_tail->next;
        }
        tt_tail=ret;
        while(tt_tail){
            
            tt_tail->random=Map[tt_tail->random];
            tt_tail=tt_tail->next;
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
