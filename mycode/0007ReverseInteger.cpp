#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int reverse(int x) {
    	long ret=0;
    	vector<int> vec;
    	if(x==0||x==INT_MIN) return 0;
    	bool flag=false; 
    	if(x<0){
    		flag=true;
			x=-x;
		} 
  		while(x>0){
  			vec.push_back(x%10);
  			x/=10;
		}	
		while(vec.size()){
			ret+=vec[0]*pow(10,(vec.size()-1));
			vec.erase(vec.begin());
			if(ret>INT_MAX&&flag==false){
				ret=0;
				break;
			}else if(ret>0x80000000&&flag==true){
				ret=0;
				break;
			}
		}
		if(flag){
			ret=-ret;
		}
		return ret;
    }
};
int main (){
	
	return 0;
}
