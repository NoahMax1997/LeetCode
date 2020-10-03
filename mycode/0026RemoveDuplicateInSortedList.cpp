#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=0,q=1;
        int size=nums.size();
        if(size==0||size==1){
            return size;
        }
        
        for(q=1;q<size;q++){
            if(nums[q]!=nums[q-1]){
                nums[++p]=nums[q];
            }
        }
        return p+1;
    }
};
int main (){
    Solution a;
    
    system("pause");
    return 0;
}