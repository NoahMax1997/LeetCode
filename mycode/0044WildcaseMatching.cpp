#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isMatchReverse(string& s,string &p,int s_index,int p_index){
        //time over
        bool ret=false;
        if(s_index==-1&&p_index==-1||(s_index<0&&p_index==0&&p[p_index]=='*')){
            ret = true;
        }else if(s_index<0||p_index<0){
            ret = false;
        }else if(p_index==0&&p[p_index]=='*'){
            ret = true;
        }
        else{
            if(s[s_index]==p[p_index]){
                ret = isMatchReverse(s,p,s_index-1,p_index-1);
            }else if(p[p_index]=='*'){
                // cout<<s_index<<" "<<p_index<<"|"<<endl;
                bool tmp=isMatchReverse(s,p,s_index,p_index-1)||(isMatchReverse(s,p,s_index-1,p_index));
                // cout<<tmp<<endl;
                ret = tmp;
            }else if(p[p_index]=='?'){
                // ret = isMatch(s,p,s_index-1,p_index-1)||(isMatch(s,p,s_index-1,p_index));
                ret = isMatchReverse(s,p,s_index-1,p_index-1);
            }else if(s[s_index]!=p[p_index]){
                ret = false;
            }
        }
        return ret;
    }
    bool isMatchNormal(string& s,string &p,int s_index,int p_index){
        if(p_index==p.size()){
            return s_index==s.size();
        }else if(s_index==s.size()){
            return p_index==p.size()||p_index==p.size()-1&&p[p_index]=='*';
        }
        else if(s[s_index]==p[p_index]||p[p_index]=='?'){
            return isMatchNormal(s,p,s_index+1,p_index+1);
        }else if(p[p_index]=='*'){
            return isMatchNormal(s,p,s_index+1,p_index)||isMatchNormal(s,p,s_index,p_index+1);
        }
        return false;
    }
    bool DPMatch(string &s, string &p){
        bool dp[200][200];
        // memset(dp,sizeof(dp),false);
        for(int i=1;i<=p.size();i++){
            if(p[i-1]=='*'){
                dp[0][i]=true;
            }else{
                break;
            }
        }
        dp[0][0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j]|dp[i][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    bool isMatch(string s, string p) {
        if(p.size()>0){
            for(int i=0;i<p.size()-1;i++){
                if(p[i]=='*'&&p[i+1]==p[i]){
                    p.erase(p.begin()+i+1);
                    i--;
                }
            }
        }
        // return isMatchReverse(s,p,s.size()-1,p.size()-1);
        // return isMatchNormal(s,p,0,0);
        return DPMatch(s,p);
        // return 1;
    }
};
int main (){
    Solution a;
//  "abaabaaaabbabbaaabaabababbaabaabbabaaaaabababbababaabbabaabbbbaabbbbbbbabaaabbaaaaabbaabbbaaaaabbbabb"
//  "ab*aaba**abbaaaa**b*b****aa***a*b**ba*a**ba*baaa*b*ab*"
    // cout<<a.isMatch("abaabaaaabbabbaaabaabababbaabaabbabaaaaabababbababaabbabaabbbbaabbbbbbbabaaabbaaaaabbaabbbaaaaabbbabb","ab*aaba**abbaaaa**b*b****aa***a*b**ba*a**ba*baaa*b*ab*");
    cout<<a.isMatch("aab","c*a*b*");
    system("pause");
    return 0;
}