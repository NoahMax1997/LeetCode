#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int position=0,end=0;
        for(int i=0;i<nums.size();i++){
            if(i<=end&&i+nums[i]>end){
                end=i+nums[i];
            }
        }
        if(end>=nums.size()-1){
            return  true;
        }
        return false;
    }
};
int main (){
	Solution a;
    // a.myPow(2,10);
	return 0;
} 