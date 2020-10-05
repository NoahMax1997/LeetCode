#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
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
    TreeNode *pre=NULL,*x=nullptr,*y=nullptr;
    void dfs(TreeNode *root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        if(pre&&pre->val>root->val){
            x=root;
            if(y==nullptr){
                y=pre;
            }
        }
        pre=root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(x&&y){
            int t=x->val;
            x->val=y->val;
            y->val=t;
        }
    }
};
int main (){
		
	return 0;
}
