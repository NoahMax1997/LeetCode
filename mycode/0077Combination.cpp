#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &ret,vector<int> &t_vec,int n,int k,int index,int num)
    {
        if(index==k){
            ret.push_back(t_vec);
        }else{
            for(int i=num+1;i<=n;i++){
                t_vec.push_back(i);
                dfs(ret,t_vec,n,k,index+1,i);
                t_vec.pop_back();
            }
        }
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        dfs(ret,t_vec,n,k,0,0);
        return ret;
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}