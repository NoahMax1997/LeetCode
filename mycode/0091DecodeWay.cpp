#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    set<string> str_set;
    void init(){
        for(int i=1;i<=26;i++){
            str_set.insert(to_string(i));
        }
    }
    void numDecodings1(string s,int &ret){
        //time over
        // cout<<"s:"<<s<<endl;
        if(str_set.find(s)!=str_set.end()){
            ret++;
        }
        if(s.size()>1&&str_set.find(s.substr(0,1))!=str_set.end()){
            numDecodings1(s.substr(1,s.size()-1),ret);
        }
        if(s.size()>2&&str_set.find(s.substr(0,2))!=str_set.end()){
            numDecodings1(s.substr(2,s.size()-2),ret);
        }
        
    }
    int numDecodingsDFS(string s) {
        int ret=0;
        if(s==""){
            return ret;
        }
        init();
        numDecodings1(s,ret);
        return ret;
    }
    int numDecodings(string s) {
        int ret=0;
        if(s==""){
            return ret;
        }
        init();
        int dp[101]={0};
        dp[0]=1;
        if(str_set.find(s.substr(0,1))!=str_set.end()){
            dp[1]=1;
        }
        for(int i=2;i<=s.size();i++){
            int add_num=0;
            if(str_set.find(s.substr(i-2,2))!=str_set.end()){
                add_num+= dp[i-2];
            }
            if(str_set.find(s.substr(i-1,1))!=str_set.end()){
                add_num+=dp[i-1];
            }
            dp[i]=add_num;
        }
        ret=dp[s.size()];
        return ret;
    }
};
int main (){
    Solution s;
    cout<<s.numDecodings("111111111111111");
    system("pause");
	return 0;
}
