#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(const int& target,const vector<int>& candidates,vector<vector<int>>& ret,vector<int>& t_vec,int &sum,int &index){
        if(sum==target){
            // for(auto i:t_vec){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            ret.push_back(t_vec);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(sum+candidates[i]>target){
                // break;//排好序
                continue;//未排序
            }else{
                sum+=candidates[i];
                t_vec.push_back(candidates[i]);
                dfs(target,candidates,ret,t_vec,sum,i);
                sum-=candidates[i];
                t_vec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        int sum=0;
        dfs(target,candidates,ret,t_vec,sum);
        return ret;
    }
};
int main()
{
    Solution a;
    vector<int> t={2,3,6,7};
    // for(auto t:a.combinationSum(t,7))
    // for(auto i:t){
    //     cout<<i<<endl;
    // }
    system("pause");
    return 0;
}