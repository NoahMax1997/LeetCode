#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num[3]={0};
        for(int i=0;i<nums.size();i++){
            num[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            while(num[i]--){
                nums[index++]=i;
            }
        }
        // return nums;
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}