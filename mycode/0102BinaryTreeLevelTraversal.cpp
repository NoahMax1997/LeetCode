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
    void dfs(TreeNode* root,vector<vector<int>> &ret,int height){
        if(root==nullptr){
            return;
        }
        if(ret.size()<=height){
            // cout<<"d";
            ret.push_back(vector<int>());
        }
        // cout<<"d";
        ret[height].push_back(root->val);
        dfs(root->left,ret,height+1);
        // cout<<"d";
        dfs(root->right,ret,height+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        dfs(root,ret,0);
        return ret;
    }
};
int main (){
		
	return 0;
}
