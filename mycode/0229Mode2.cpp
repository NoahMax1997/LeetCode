#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        if(nums.size()==0){
            return ret;
        }
        int m=nums[0],n=nums[0],cm=0,cn=0;
        for(auto num:nums){
            if(cm==0){
                m=num;
            }else if(cn==0&&num!=m){
                n=num;
            }
            if(m==num){
                cm++;
            }else if(n==num){
                cn++;
            }else{
                cn--;
                cm--;
            }
        }
        cm=0,cn=0;
        for(auto num:nums){
            if(num==m){
                cm++;
            }
            else if(num==n){
                cn++;
            }
        }
        if(cm>nums.size()/3){
            ret.push_back(m);
        }
        if(cn>nums.size()/3){
            ret.push_back(n);
        }
        return ret;
    }
};
int main (){
	Solution s;
    
    system("pause");
	return 0;
}
