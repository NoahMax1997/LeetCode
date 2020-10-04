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
    vector<int> ret;
    vector<int> inorderTraversalDFS(TreeNode* root){
        if(root!=NULL){
            inorderTraversalDFS(root->left);
            ret.push_back(root->val);
            inorderTraversalDFS(root->right);
        }
    }
    vector<int> inorderTraversalStack(TreeNode* root) {
        vector<int> ret;
        if(!root){
            return ret;
        }
        stack<TreeNode*> st;
        // st.push(root);
        while(root||!st.empty()){
            while (root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ret.push_back(root->val);
            st.push(root->right);
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
