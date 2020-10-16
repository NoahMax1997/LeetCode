#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
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
    int  treeHeight(TreeNode* root){
        int left=1,right=1;
        if(!root->left){
            left=1;
        }else{
            left+=treeHeight(root->left);
        }
        if(!root->right){
            right=1;
        }else{
            right+=treeHeight(root->right);
        }
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ret=abs(treeHeight(root->left)-treeHeight(root->right))<=1;
        ret=ret&&isBalanced(root->left)&&isBalanced(root->right);
        return ret;
    }
};
int main (){
		
	return 0;
}
