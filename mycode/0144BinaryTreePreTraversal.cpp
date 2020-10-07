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
    void dfsPre(TreeNode* root){
        if(!root){
            return;
        }
        ret.push_back(root->val);
        dfsPre(root->left);
        dfsPre(root->right);
    }
    void dfsPost(TreeNode* root){
        if(!root){
            return;
        }
        dfsPost(root->left);
        dfsPost(root->right);
        ret.push_back(root->val);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfsPre(root);
        return ret;
    }
};
int main (){
		
	return 0;
}
