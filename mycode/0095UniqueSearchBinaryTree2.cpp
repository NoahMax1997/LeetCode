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
    vector<TreeNode*> generateTrees(int begin,int end){
        if(begin>end){
            return {nullptr};
        }
        vector<TreeNode*> ret;
        for(int i=begin;i<=end;i++){
            vector<TreeNode*> left_tree= generateTrees(begin,i-1);
            vector<TreeNode*> right_tree=generateTrees(i+1,end);
            for(auto left:left_tree){
                for(auto right:right_tree){
                    TreeNode *T=new TreeNode(i);
                    T->left=left;
                    T->right=right;
                    ret.push_back(T);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};
int main (){
		
	return 0;
}
