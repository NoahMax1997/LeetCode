#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret=0,length=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                ret=length;
                if(ret>0){
                    break;
                }
                length=0;
            }else{
                length++;
            }
        }
        if(ret==0){
            ret=length;
        }
        return ret;
    }
};
int main (){
	Solution s;
    
    system("pause");
	return 0;
}
