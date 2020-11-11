#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    ListNode *getMid(ListNode *left,ListNode *right){
        ListNode *fast=left,*slow=left;
        while(fast!=right&&fast->next!=right){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        return slow;
    }
    TreeNode* buildBinaryTree(ListNode *left,ListNode *right){
        TreeNode *tt
        if(left==right){
            tt=new TreeNode(left->val,NULL,NULL);
        }else{
            ListNode *mid=getMid(left,right);

            tt=new TreeNode(mid->val,NULL,NULL);
            tt->left=buildBinaryTree(left,mid);
            tt->right=buildBinaryTree(mid->next,right);
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // ListNode* tail=head;
        // while(tail->next!=NULL){
        //     tail=tail->next;
        // }
        return buildBinaryTree(head,NULL);
    }
};
int main (){

    return 0;
}