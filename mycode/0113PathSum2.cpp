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
    void dfs(TreeNode* root,int &sum,vector<vector<int>> &ret,vector<int> ans,int ans_sum){
        if(!root){
            return;
        }
        // if(root->val+ans_sum>sum){
        //     return;
        // }else{
        ans.push_back(root->val);
        ans_sum+=root->val;
        if(!root->right&&!root->left&&ans_sum==sum){
            ret.push_back(ans);
            return;
        }
        if(root->left){
            dfs(root->left,sum,ret,ans,ans_sum);
        }
        if(root->right){
            dfs(root->right,sum,ret,ans,ans_sum);
        }
        // }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> ans;
        dfs(root,sum,ret,ans,0);
        return ret;
    }
};
int main (){

    return 0;
}