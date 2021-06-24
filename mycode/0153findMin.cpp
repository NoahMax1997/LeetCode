#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1,mid = (left+right)/2;
        while (left<right)
        {
            if (nums[right]>nums[mid])
            {
                right = mid;
            }else
            {
                left = mid;
            }
            
            
            mid = (left + right)/2;
            
        }
        return nums[mid];
    }
};
int main (){
		
	return 0;
}
