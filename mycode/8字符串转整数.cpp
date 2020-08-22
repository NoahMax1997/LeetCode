#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int is_num(char a){
		if(a>='0'&&a<='9') return 1;
		else if(a==' ') return -1;
		return 0;
	}
    int myAtoi(string str) {
        if(str.length()==0) return 0;
        int left=0,size=str.size(),right=size-1;
        while(left<size&&is_num(str[left])==-1){
        	left++;
		}
    	if(left>=size) return 0;
        char first_ch=str[left];
        if(first_ch!='-'&&first_ch!='+'&&is_num(first_ch)!=1){
        	return 0;
		}else if(first_ch=='+'||first_ch=='-'){
			left++;
		}
		if(left>=size) return 0;
		while(left<size&&str[left]=='0'){
			left++;
		}
		right=left;
		while(right<size&&is_num(str[right])==1){
			right++;
		}
//		right=right>=size?size-1:right;
		if(right-left==0) return 0;
        string new_str=str.substr(left,right-left);
        int new_size=new_str.size();
        if(new_size>10){
        	if(first_ch=='-'){
        		return INT_MIN;
			}
			return INT_MAX;
		}
        else if(new_size==10){
        	if(first_ch=='-'){
        		if(new_str=="2147483648"){
        			return INT_MIN;
				}
        		string tmp_str="2147483648";
        		int i;
        		for(i=0;i<new_size;i++){
        			if(new_str[i]>tmp_str[i]){
        				return INT_MIN;
					}else if(new_str[i]<tmp_str[i]){
						break;
					}
				}
			}else{
				string tmp_str="2147483647";
        		int i;
        		for(i=0;i<new_size;i++){
        			if(new_str[i]<tmp_str[i]){
        				break;
					}else if(new_str[i]>tmp_str[i]){
						return INT_MAX;
					}
				}
			}
		}
		int flag=1,ret=0;
		for(int i=new_size-1;i>=0;i--){
			ret+=(new_str[i]-'0')*flag;
			if(i!=0){
				flag*=10;//flag intÒç³ö 
			}
		}
		if(first_ch=='-'){
			ret=-ret;
		}
		return ret;
    }
};
int main (){
	Solution a;
	a.myAtoi("1095502006p8");
	return 0;
} 
