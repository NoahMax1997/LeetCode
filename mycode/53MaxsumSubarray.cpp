#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArrayWrong(vector<int>& nums) {
        //wrong 
        int left=0,right=nums.size()-1,sum=0;
        while(left<=right){
            if(nums[left]<=0){
                left++;
            }
            if(nums[right]<=0){
                right--;
            }if(nums[left]>0&&nums[right]>0){
                int t_sum=0;
                for(int i=left;i<=right;i++){
                    t_sum+=nums[i];
                }
                if(t_sum>sum){
                    sum=t_sum;
                }
                left++;
                right--;
            }
        }
        return sum;
    }
    int maxSubArrayDP(vector<int>& nums) {
        int *dp=new int[nums.size()+1],ret=INT_MIN;
        dp[0]=0;
        for(int i=1;i<nums.size()+1;i++){
            dp[i]=max(dp[i-1]+nums[i-1],nums[i-1]);
            if(dp[i]>ret){
                ret=dp[i];
            }
        }
        return ret;
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayDP(nums);
    }
};
int main (){
	Solution a;
    // a.myPow(2,10);
	return 0;
} 