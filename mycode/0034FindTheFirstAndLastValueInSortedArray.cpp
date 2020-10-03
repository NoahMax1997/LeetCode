#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid=(right+left)/2;
        vector<int> ret={-1,-1};
        while(left<=right){
            mid=(right+left)/2;
            // while(mid>=left&&nums[mid]==target){
            //     mid--;
            // }
            if(target==nums[mid]){
                ret.clear();
                int index=mid-1,t_min_index=INT_MAX,t_max_index=INT_MIN;
                while(index>=0&&nums[index]==target){
                    if(index<t_min_index) t_min_index=index;
                    index--;
                }
                // ret.push_back(mid);
                index=mid+1;
                while(index<=nums.size()-1&&nums[index]==target){
                    if(index>t_max_index) t_max_index=index;
                    index++;
                }
                if(t_min_index==INT_MAX){
                    ret.push_back(mid);
                }else{
                   ret.push_back(t_min_index); 
                }
                if(t_max_index==INT_MIN){
                    ret.push_back(mid);
                }else{
                    ret.push_back(t_max_index);
                }
                break;
            }
            else if(target<nums[mid]){
                right=mid-1;
            }else if(target>nums[mid]){
                left=mid+1;
            }
        }
        return ret;
    }
};
int main()
{
    Solution a;
    //5,7,7,8,8,10
    vector<int> t={2,2};
    t=a.searchRange(t,2);
    for(auto i:t){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}