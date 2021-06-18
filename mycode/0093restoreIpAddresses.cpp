#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> ret;
    bool compareStr(const string &a,const string &b){
        if(a.size()>b.size()){
            return true;
        }else if (a.size()<b.size())
        {
            /* code */
            return false;
        }

        
        for (size_t i = 0; i < a.size(); i++)
        {
            /* code */
            if (a[i]>b[i])
            {
                /* code */
                return true;
            }else if (a[i]<b[i])
            {
                /* code */
                return false;
            }
            
        }
        return true;
    }
    bool judgeVaild(const string &str){
        if (str.size() == 0)
        {
            /* code */
            return false;
        }
        else if (str.size()>1)
        {
            if (str[0] == '0')
            {
                /* code */
                return false;
            }
            else
            {
                /* code */
                return compareStr(str,"0")&&!compareStr(str,"256");
            }
        }
        return true;
    }
    void dfs(string s,int index,string ans,int time){
        if (index >= s.size())
        {
            /* code */
            if (time == 4)
            {
                /* code */
                ret.push_back(ans);
            }
            return;
        }
        
        
        for (size_t i = 1; i <= 3&&i+index<=s.size(); i++)
        {
            /* code */
            string tmp_str = s.substr(index,i);
            if (!judgeVaild(tmp_str))
            {
                /* code */
                break;
            }

            if(time!=0){
                tmp_str = "."+tmp_str;
            }

            dfs(s,index+i,ans+tmp_str,time+1);
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size()<=12)
        {
            /* code */
            dfs(s,0,"",0);
        }
        
        return ret;
    }
};
int main (){
		
	return 0;
}
