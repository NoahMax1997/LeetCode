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
    void dfs(TreeNode* root,vector<vector<int>> &ret,int height,int flag){
        if(root==nullptr){
            return;
        }
        while(ret.size()<=height){
            // cout<<"d";
            ret.push_back(vector<int>());
        }
        // cout<<"d";
        if(flag==0){
            ret[height].push_back(root->val);
            flag=1;
        }else{
            ret[height].insert(ret[height].begin(),root->val);
        // cout<<"d";
            flag=0;
        } 
        dfs(root->left,ret,height+1,flag);
        // cout<<"d";
        dfs(root->right,ret,height+1,flag);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        int flag=0;
        dfs(root,ret,0,flag);
        return ret;
    }
};
int main (){
		
	return 0;
}
