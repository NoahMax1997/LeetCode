#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//∏¥‘”∂»∫‹∏ﬂ 
    string longestCommonPrefix(vector<string>& strs) {
        int left=0;
        if(strs.size()==0) return "";
        else if(strs.size()==1) return strs[0];
        string t_str=strs[0];
		while(1){
			int i;
			for(i=1;i<strs.size();i++){
				if(left>=t_str.length()||left>=strs[i].length()||strs[i][left]!=t_str[left]){
					break;
				}
			}
			if(i!=strs.size()){
				return t_str.substr(0,left);
			}else{
				left++;
			}
		} 
//		return str;
    }
};
int main (){
	Solution a;
	
	return 0;
} 
