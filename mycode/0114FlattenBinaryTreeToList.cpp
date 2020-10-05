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
    bool isLeft(TreeNode* root){
        return !root->left&&!root->right;
    }
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }else if(root->left==nullptr&&root->right==nullptr){

        }else if(root->left!=nullptr&&root->right==nullptr&&isLeft(root->left)){
            root->right=root->left;
            root->left=nullptr;
        }else if(root->left==nullptr&&root->right!=nullptr&&isLeft(root->right)){

        }else if(root->left!=nullptr&&root->right!=nullptr&&isLeft(root->left)&&isLeft(root->right)){
            root->left->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }else{
            flatten(root->left);
            flatten(root->right);
            TreeNode* tail=root->left;
            while(tail->right){
                tail=tail->right;
            }
            tail->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
    }
};
int main (){

    return 0;
}