#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
	{
		int ret=0;
		for(int i=0;i<32;i++){
			int t_num=0;
			for(auto j:nums){
				t_num+=(j>>i)&1;
			}
			ret|=(t_num%3)<<i;
		}
		return ret;
    }
};
int main (){
	
	return 0;
} 
