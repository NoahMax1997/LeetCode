#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int ret=INT_MAX;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			int left=i+1,right=nums.size()-1;
//			if(left>=nums.size()||right<0) break;
			while(left<right){
				int t_abs=abs(target-nums[i]-nums[left]-nums[right]);
				if(t_abs<abs(ret-target)){
					ret=nums[i]+nums[left]+nums[right];
//					printf("%d %d %d\n",nums[i],nums[left],nums[right]);
				}
				if(right-1<=left||left+1>=right){
					break;
				}else{
					int t_abs1=abs(target-nums[i]-nums[left+1]-nums[right]);
					int t_abs2=abs(target-nums[i]-nums[left]-nums[right-1]);
					if(t_abs1<t_abs2){
						left++;
					}else{
						right--;
					}
				}
			}
		}
		return ret;
    }
};
int main (){
	vector<int> t;
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	t.push_back(1);
	Solution s;
	cout<<s.threeSumClosest(t,-100);
	return 0;
}
