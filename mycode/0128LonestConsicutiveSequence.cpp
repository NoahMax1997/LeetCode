#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int longestConsecutiveForce(vector<int>& nums) {
        int ret=0;
        unordered_set<int> un_set;
        for(int i=0;i<nums.size();i++){
            un_set.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int tt=nums[i];
            while(un_set.find(tt+1)!=un_set.end()){
                tt++;
            }
            ret=max(tt-nums[i]+1,ret);
        }
        return ret;
    }
};
int main (){

    return 0;
}