#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string str="";
        if(x<0) return false;
		while(x){
			str+=x%10+'0';
			x/=10;
		}
		int left=0,right=str.length()-1;
		while(left<=right){
			if(str[left]!=str[right]){
				return false;
			}
			left++;
			right--;
		}
		return true;
    }
};
int main (){
	Solution a;
	a.isPalindrome(121);
	return 0;
} 
