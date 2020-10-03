#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //...................................
        int i=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};
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