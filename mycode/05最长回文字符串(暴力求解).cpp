#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    	string ret="";
    	if(s.length()<=1) return s; 
        for(int i=0;i<s.length();i++){
        	for(int j=s.length()-1;j>=i;j--){
        		if((j-i+1)<ret.size()) continue;
        		int left=i,right=j; 
        		while(left<=right){
        			if(s[left]!=s[right]){
        				break;
					}
					left++;
					right--;
				}
				if(left>right){
					string temp=s.substr(i,j-i+1);
					if(temp.size()>ret.size()){
						ret=temp;
					}
				}
			}
		}
		return ret;
    }
};
int main (){
	
	return 0;
} 
