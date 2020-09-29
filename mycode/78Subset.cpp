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
    void dfs(vector<vector<int>> &ret,vector<int>& nums,vector<int> &t_vec,int index){
        if(t_vec.size()<=nums.size()){
            ret.push_back(t_vec);
            for(int i=index;i<nums.size();i++)
            {
                t_vec.push_back(nums[i]);
                dfs(ret,nums,t_vec,i+1);
                t_vec.pop_back();
            }
        }else
        {
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        dfs(ret,nums,t_vec,0);
        return ret;
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}