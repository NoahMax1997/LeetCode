#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int q=0,size=nums.size();
        for(int i=0;i<size;i++){
            if (nums[i]!=val)
            {
                nums[q++]=nums[i];
            }
        }
        return q;
    }
};
int main (){
    Solution a;
    
    system("pause");
    return 0;
}