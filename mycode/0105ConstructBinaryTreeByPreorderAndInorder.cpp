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
template<typename T>
void MyPrint(T &t){
    cout<<"Myprint:"<<endl;
    for(auto i : t){
        cout<<i<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=nullptr;
        if(preorder.size()==0){
            return root;
        }else if(preorder.size()>=1){
            root=new TreeNode(preorder[0]);
            int left_size=0;
            for(int i=0;i<inorder.size();i++){
                if(root->val==inorder[i]){
                    left_size=i;
                    break;
                }
            }
            vector<int> in_left_vec;
            vector<int> in_right_vec;
            vector<int> pre_left_vec;
            vector<int> pre_right_vec;
            MyPrint(preorder);
            MyPrint(inorder);
            for(int i=0;i<left_size;i++){
                in_left_vec.push_back(inorder[i]);
                pre_left_vec.push_back(preorder[i+1]);
            }
            for(int i=left_size+1;i<inorder.size();i++){
                in_right_vec.push_back(inorder[i]);
                pre_right_vec.push_back(preorder[i]);
            }
            MyPrint(in_left_vec);
            MyPrint(pre_left_vec);
            MyPrint(in_right_vec);
            MyPrint(pre_right_vec);
            root->left=buildTree(pre_left_vec,in_left_vec);
            root->right=buildTree(pre_right_vec,in_right_vec);
        }
        return root;
    }
};
int main (){
	Solution s;
    vector<int> prev={3,9,20,15,7};
    vector<int> in={9,3,15,20,7};
    s.buildTree(prev,in);
	return 0;
}
