#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int left=0,right=height.size()-1;
    	long ret=0;
		while(left<=right){
			long t_area=(right-left)*(height[left]>height[right]?height[right]:height[left]);
			if(t_area>ret) ret=t_area;
			height[left]>=height[right]?right--:left++;
		} 
		return ret;
    }
};
int main (){
	Solution a;
	
	return 0;
} 
