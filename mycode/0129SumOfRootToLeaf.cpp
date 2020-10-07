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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root,vector<string> &vec,string &ans){
        if(root){
            vec.push_back(ans);
            return;
        }
        ans.push_back(root->val+'0');
        if(root->left){
            dfs(root->left,vec,ans);
        }
        if(root->right){
            dfs(root->right,vec,ans);
        }
        ans.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<string> vec;
        string ans="";
        dfs(root,vec,ans);
        int ret=0;
        for(int i=0;i<vec.size();i++){
            ret+=atoi(vec[i].c_str());
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
