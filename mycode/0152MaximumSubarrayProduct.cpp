#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProductTimeOver(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int ret=INT_MIN,base=1;
        for(int i=0;i<nums.size();i++){
            base=nums[i];
            int t_min=ret,t_base=base;
            for(int j=1;j+i<nums.size();j++){
                t_base*=nums[i+j];
                if(t_base>t_min){
                    t_min=t_base;
                }
            }
            if(t_min>ret){
                ret=t_min;
            }
        }
        return ret;
    }
    int maxProductDP(vector<int>& nums) {
        int i_min=INT_MAX,i_max=INT_MIN,ret=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                i_min=min(i_min*nums[i],nums[i]);
                i_max=max(i_max*nums[i],nums[i]);   
            }else{
                i_min=min(i_max*nums[i],nums[i]);
                i_max=max(i_min*nums[i],nums[i]);  
            }
        }
        return max(ret,i_max);
    }
};
int main (){
		
	return 0;
}
