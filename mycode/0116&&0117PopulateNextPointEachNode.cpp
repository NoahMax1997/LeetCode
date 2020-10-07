#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node* next;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int,vector<Node*> > Map;
    void bfs(Node* root,int level){
        if(root==nullptr){
            return;
        }
        if(Map.find(level)==Map.end()){
            Map[level]=vector<Node*>();
        }
        Map[level].push_back(root);
        // Map[level].push_back(root->right);
        bfs(root->left,level+1);
        bfs(root->right,level+1);
    }
    void dfs_using_next(Node* root){
        if(root==nullptr){
            return;
        }
        if(root->left&&root->right){
            root->left->next=root->right;
            root->right->next=root->next==nullptr?nullptr:root->next->left;
        }
        dfs_using_next(root->left);
        dfs_using_next(root->right);
    }
    Node *connect(Node* root) {
        if(root==nullptr){
            return nullptr;
        }
        bfs(root,0);
        for(auto i:Map){
            for(int j=0;j<i.second.size()-1;j++){
                i.second[j]->next=i.second[j+1];
            }
        }
        return root;
    }
};
int main (){

    return 0;
}