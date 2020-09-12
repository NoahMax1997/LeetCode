#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int max_hight=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>max_hight){
                max_hight=height[i];
            }
        }
        for(int i=0;i<max_hight+1;i++){
            
        }
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}