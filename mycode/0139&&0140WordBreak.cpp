#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    set<int> Set;
    bool wordBreakDFS(string s, vector<string>& wordDict) {
        bool ret=false;
        if(s==""){
            return true;
        }
        int i=0;
        for(i=0;i<wordDict.size();i++){
            if(s.size()<wordDict[i].size()){
                continue;
            }else if(s.substr(0,wordDict[i].size())==wordDict[i]){
                int size=s.size()-wordDict[i].size();
                if(Set.find(size)!=Set.end()){
                    continue;
                }
                Set.insert(size);
                ret|= wordBreakDFS(s.substr(wordDict[i].size(),size),wordDict);
                if(ret==true){
                    break;
                }
            }else{
                continue;
            }
        }
        return ret;
    }
    bool is(vector<string>& wordDict,string str){
        if(str==""){
            return true;
        }
        for(int i=0;i<wordDict.size();i++){
            if(str==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    bool wordBreakDP(string s, vector<string>& wordDict) {
        bool *dp=new bool[s.size()+1];
        for(int i=0;i<s.size()+1;i++){
            dp[i]=false;
        }
        dp[0]=true;
        for(int i=1;i<s.size()+1;i++){
            for(int j=0;j<=i;j++){
                // cout<<i<<" "<<j<<" " <<s.substr(j,i-j)<<endl;
                dp[i]|=dp[j]&&is(wordDict,s.substr(j,i-j));
                // cout<<"dp[4]: "<<dp[8]<<endl;
            }
        }
        return dp[s.size()];
    }
    bool dfs_0140(string s, vector<string>& wordDict,vector<string> &ret,string str){
        bool t_ret=false;
        if(s==""){
            ret.push_back(str);
            return true;
        }
        for(int i=0;i<wordDict.size();i++){
            if(s.size()<wordDict[i].size()){
                continue;
            }else if(s.substr(0,wordDict[i].size())==wordDict[i]){
                int size=s.size()-wordDict[i].size();
                if(Set.find(size)!=Set.end()){
                    continue;
                }
                string t_str=str;
                if(t_str!=""){
                    t_str+=" ";
                }
                t_str+=wordDict[i];
                bool tt=dfs_0140(s.substr(wordDict[i].size(),size),wordDict,ret,t_str);
                t_ret|=tt;
                if(tt==false){
                    Set.insert(size);
                }
            }else{
                continue;
            }
        }
        return t_ret;
    }
    vector<string> wordBreak_0140(string s, vector<string>& wordDict) {
        vector<string> ret;
        dfs_0140(s,wordDict,ret,"");
        return ret;
    }
};
int main (){
    Solution s;
	vector<string> wordDict={"leet","code"};
    cout<<s.wordBreakDP("leetcode",wordDict);
    system("pause");
	return 0;
}
