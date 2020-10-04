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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root,long long lower,long long upper) {
        bool ret=true;
        if(root==NULL){
            
        }
        else if(lower>=root->val){
            ret=false;
        }else if(upper<=root->val){
            ret=false;
        }else{
            ret= isValidBST(root->left,lower,root->val)&&isValidBST(root->right,root->val,upper);
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
