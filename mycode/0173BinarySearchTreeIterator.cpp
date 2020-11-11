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

class BSTIteratorDFS{
public:
    vector<int> vec;
    int index;
    BSTIteratorDFS(TreeNode* root) {
        index=0;
        vec.clear();
        vector<int>().swap(vec);
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    /** @return the next smallest number */
    int next() {
        // cout<<vec[index]<<endl;
        return vec[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<vec.size();
    }
};
class BSTIteratorStack{
public:
    stack<TreeNode*> st;
    BSTIteratorStack(TreeNode* root) {
        lpush(root);
    }
    void lpush(TreeNode* root){
        if(root==NULL){
            return;
        }
        st.push(root);
        lpush(root->left);
    }
    /** @return the next smallest number */
    int next() {
        // cout<<vec[index]<<endl;
        TreeNode* t=st.top();
        st.pop();
        lpush(t->right);
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size();
    }
};
int main (){
		
	return 0;
}
