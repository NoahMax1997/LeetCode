#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution {
public:
    string ret="";
    string reverseWords(string s) {
        int i=0;
        if(s==""){
            return ret;
        }
        for(i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                break;
            }
        }
        if(i==-1){
            return "";
        }else{
            s=s.substr(0,i+1);
        }
        for(i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                break;
            }
        }
        if(ret!=""){
            ret+=" "+s.substr(i+1,s.size()-i-1);
        }else{
            ret=s.substr(i+1,s.size()-i-1);
        }
        if(i>=0){
            reverseWords(s.substr(0,i+1));
        }
    }
};
int main (){
		
	return 0;
}
