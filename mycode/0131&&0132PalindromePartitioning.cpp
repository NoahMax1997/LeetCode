#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isParlindrome(const string &str) const {
        int left=0,right=str.size()-1;
        while(left<=right){
            if(str[left]!=str[right]){
                break;
            }
            left++;
            right--;
        }
        return left>=right;
    }
    void dfs_0131(vector<vector<string>> &ret,vector<string> &ans,string str){
        if(isParlindrome(str)){
            ans.push_back(str);
            ret.push_back(ans);
            ans.pop_back();
        }
        for(int i=1;i<str.size();i++){
            string t_str=str.substr(0,i);
            if(isParlindrome(t_str)){
                ans.push_back(t_str);
                dfs_0131(ret,ans,str.substr(i,str.size()-t_str.size()));
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //131
        vector<vector<string>> ret;
        vector<string> ans;
        if(s.size()==0){
            ret.push_back(ans);
            return ret;
        }
        dfs_0131(ret,ans,s);
        return ret;
    }
    void dfs_0132(string str,int &sum,int &min_sum){
        //time over 25/29
        if(isParlindrome(str)){
            if(sum<min_sum){
                min_sum=sum;
            }
            return;
        }
        for(int i=1;i<str.size();i++){
            string t_str=str.substr(0,i);
            if(isParlindrome(t_str)){
                sum++;
                dfs_0132(str.substr(i,str.size()-t_str.size()),sum,min_sum);
                sum--;
            }
        }
    }
    int minCut(string s) {
        //132
        int min_sum=INT_MAX,sum=0;
        if(s.size()==0){
            return 0;
        }
        dfs_0132(s,sum,min_sum);
        return min_sum;
    }
};
int main (){
		
	return 0;
}
