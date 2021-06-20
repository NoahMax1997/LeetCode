#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ret;
        vector<array<int,105>> pre(nums.size()+1);
        fill(pre[0].begin(),pre[0].end(),0);
        pre[0][nums[0]] = 1;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            /* code */
            copy_n(pre[i].begin(),105,pre[i+1].begin());
            pre[i+1][nums[i+1]]++;
        }
        
        for (size_t i = 0; i < queries.size(); i++)
        {
            int min_num = INT_MAX,flag= 0,last = 0,left = queries[i][0],right = queries[i][1]-1;
            for (size_t j = 0; j <105; j++)
            {
                if (pre[left][j]==pre[right][j])
                {
                    continue;
                }
                
                if (last)
                {
                    min_num = min_num>j-last?j-last:min_num;
                }
                last = j;
            }
            
            if (min_num == INT_MAX)
            {
                ret.push_back(-1);
            }else{
                ret.push_back(min_num);
            }
            
        }
        return ret; 
    }
};
int main (){
	Solution s;
    system("pause");
	return 0;
}
