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

class BSTIterator {
public:
    vector<int> vec;
    int index=0;
    BSTIterator(TreeNode* root) {
        index=0;
        vec.clear();
        vec.swap(vector<int>());
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        BSTIterator(root->left);
        vec.push_back(root->val);
        BSTIterator(root->right);
    }
    /** @return the next smallest number */
    int next() {
        return vec[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index+1<vec.size();
    }
};
int main (){
		
	return 0;
}
