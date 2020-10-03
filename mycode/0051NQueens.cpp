#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<string>> &ret,vector<string> &ans,set<int> &t_set0,set<int> &t_set1,set<int> &t_set2,int n,int index){
        if(index==n){
            ret.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(t_set0.find(i)!=t_set0.end()||t_set1.find(index+i)!=t_set1.end()||t_set2.find(index-i)!=t_set2.end()){
                continue;
            }
            ans[index][i]='Q';
            t_set1.insert(index+i);
            t_set2.insert(index-i);
            t_set0.insert(i);
            dfs(ret,ans,t_set0,t_set1,t_set2,n,index+1);
            ans[index][i]='.';
            t_set0.erase(i);
            t_set1.erase(index+i);
            t_set2.erase(index-i);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> ans;
        set<int> t_set0,t_set1,t_set2;//分别存竖冲突,左上冲突,右下冲突
        for(int i=0;i<n;i++){
            string t_s;
            for(int j=0;j<n;j++){
                t_s.push_back('.');
            }
            ans.push_back(t_s);
        }
        dfs(ret,ans,t_set0,t_set1,t_set2,n,0);
        return ret;
    }
};
int main (){
	Solution a;
	return 0;
} 