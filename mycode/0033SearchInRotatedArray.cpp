#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int searchForce(vector<int>& nums, int target) {
        //...................................
        int i=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
    int searchBinary(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int left=0,right=nums.size()-1,ret=-1;
        while(left<nums.size()&&right>=0&&left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                ret= mid;
                break;
            }
            if(nums[mid]>=nums[left]){
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
               if(target>nums[mid]&&target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                } 
            }
        }
        return ret;
    }
}
int main()
{
    Solution a;
    vector<int> t={4,2,0,2,3,2,0};
    
    for(auto i:t){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}