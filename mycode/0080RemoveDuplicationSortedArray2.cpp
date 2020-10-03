#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicatesSlow(vector<int>& nums) {
        map<int,int> Map;
        for(auto i:nums){
            Map[i]=0;
        }
        for(int i=0;i<nums.size();){
            if(Map[nums[i]]==2)
            {
                nums.erase(nums.begin()+i);
            }else
            {
                Map[nums[i]]++;
                i++;
            }
        }
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        if(nums.size()<3){
            return nums.size();
        }
        for(int i=1;i<nums.size();){
            if(nums[i]==nums[i-1]){
                count++;
            }else{
                count=1;
            }
            if(count==3){
                count--;
                nums.erase(nums.begin()+i);
            }else{
                i++;
            }
        }
        return nums.size();
    }
};
int main (){
		
	return 0;
}
