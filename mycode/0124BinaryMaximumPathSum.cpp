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
    int ret=0;
    int getGain(TreeNode* root){
        if(root==NULL){
            return 0;
        }else{
            int left=getGain(root->left);
            int right=getGain(root->right);
            ret=max(left+right+root->val,ret);
        }
    }
    int maxPathSum(TreeNode* root) {
        getGain(root);
        return ret;
    }
};
int main (){
    
    system("pause");
    return 0;
}