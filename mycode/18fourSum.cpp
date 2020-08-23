#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//复杂度极高
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        if(nums.size() < 4) return ret;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() ; i++)
        {
            /* code */
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            t_vec.push_back(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j-1]==nums[j]){
                    continue;
                }
                t_vec.push_back(nums[j]);
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    if(nums[i]+nums[j]+nums[left]+nums[right]==target){
                        t_vec.push_back(nums[left]);
                        t_vec.push_back(nums[right]);
                        ret.push_back(t_vec);
                        t_vec.pop_back();
                        t_vec.pop_back();
                        left++;
                        while(left<right&&nums[left-1]==nums[left]){
                            left++;
                        }
                    }else if(nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }else{
                        left++;
                    }
                }
                t_vec.pop_back();
            }
            t_vec.pop_back();
        }
        return ret;
    }
};
int main (){
    
    system("pause");
    return 0;
}