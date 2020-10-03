#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositiveSelf(vector<int>& nums) {
        int ret=1;
        if(nums.size()==0) return 1;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
        }
        if(i<nums.size()&&nums[i]>1){
            return 1;
        }else if (i==nums.size())
        {
            return 1;
        }
        for(;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>1){
                break;
            }
        }
        ret=nums[i]+1;
        return ret;
    }
    int firstMissingPositiveSwap(vector<int>& nums) {
        for(int i= 0;i< nums.size();i++){
            while(nums[i]>0&&nums[i]<nums.size()&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                break;
            }
        }
        return i+1;
    }
    int firstMissingPositiveHash(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                nums[i]=nums.size()+1;
            }
            // cout<<nums[i]<<endl;
        }
        for(int i=0 ;i<nums.size();i++){
            int tmp = abs(nums[i]);
            if(tmp<=nums.size()&&tmp>0){
                nums[tmp-1]=-abs(nums[tmp-1]);
            }
        }
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
        }
        return i+1;
    }
    int firstMissingPositive(vector<int>& nums) {
        return firstMissingPositiveHash(nums);
    }
};
int main()
{
    Solution a;
    vector<int> t={3,4,-1,1};
    // for(auto t:a.combinationSum(t,7))
    // for(auto i:t){
    //     cout<<i<<endl;
    // }
    cout<<a.firstMissingPositive(t);
    system("pause");
    return 0;
}