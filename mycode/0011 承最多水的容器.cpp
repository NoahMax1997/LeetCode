#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
    	long ret=0;
        for(int i=1;i<height.size();i++){
        	for(int j=0;j<i;j++){
        		long tmp=(i-j)*min(height[i],height[j]);
        		ret=tmp>ret?tmp:ret;
			}	
		}
		return ret;
    }
};
int main (){
	Solution a;
	
	return 0;
} 
