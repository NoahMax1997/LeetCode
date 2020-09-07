#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //可以分治为找后面位数的字典序，找不到位数递增
        //very slow and use much memory
        if(nums.size()<=1) return;
        int begin=nums.size()-2,end=nums.size()-1;
        while(begin>=0){
            end=nums.size()-1;
            while(end>=begin){
                for(int i=end-1;i>=begin;i--){
                    if(nums[end]>nums[i]){
                        int t=nums[end];
                        nums[end]=nums[i];
                        nums[i]=t;
                        sort(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
                end--;
            }
            begin--;
        }
        if(begin==-1){
            sort(nums.begin(),nums.end());
        }
    }
};
int main()
{
    Solution a;
    vector<int> t={4,2,0,2,3,2,0};
    a.nextPermutation(t);
    for(auto i:t){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}