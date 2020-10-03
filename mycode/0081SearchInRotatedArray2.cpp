#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return false;
        }
        int left=0,right=nums.size()-1;
        bool ret=false;
        while(left<nums.size()&&right>=0&&left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                ret= true;
                break;
            }
            if(nums[mid]>nums[left]){
                if(target>=nums[left]&&target<nums[mid]){
                    while(mid>=1&&nums[mid-1]==nums[mid]){
                        mid--;
                    }
                    right=mid-1;
                }else{
                    while(mid<nums.size()-1&&nums[mid+1]==nums[mid]){
                        mid++;
                    }
                    left=mid+1;
                }
            }else if(nums[mid]==nums[left])
            {
                left++;
            }
            else{
               if(target>nums[mid]&&target<=nums[right]){
                   while(mid<nums.size()-1&&nums[mid+1]==nums[mid]){
                        mid++;
                    }
                    left=mid+1;
                }else{
                    while(mid>=1&&nums[mid-1]==nums[mid]){
                        mid--;
                    }
                    right=mid-1;
                } 
            }
        }
        return ret;
    }
};
int main (){
	Solution s;
    vector<int> vec={1,3,1,1,1};
    s.search(vec,3);
	return 0;
}
