#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestValidParenthesesSelf(string s) {
        stack<char> st;
        int sum=0,t_sum=0,tt_sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'&&st.size()!=0){
                t_sum+=2;
                st.pop();
            } 
            else if(s[i]==')'&&st.size()==0){
                sum=sum<t_sum?t_sum:sum;
                t_sum=0;
                // cout<<"dsfsd"<<endl;
                // cout<<s[i]<<" "<<st.size()<<endl;
            }
            // cout<<"size:"<<st.size()<<" i:"<<i<<" "<<sum<<endl;
        }
        return sum<t_sum?t_sum:sum;
    }
    int longestValidParenthesesDP(string s) {
        int* dp=new int[s.size()](),ret=0;
        for(int i=1;i<s.size();i++){
            // cout<<dp[i]<<endl;
            if(s[i]==')'&&s[i-1]=='('){
                dp[i]=(i-2>=0?dp[i-2]:0)+2;
            }else if(s[i]==')'&&s[i-1]==')'){
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                }
            }
            // cout<<dp[i]<<endl;
            if(ret<dp[i]){
                ret=dp[i];
            }
        }
        return ret;
    }
    int longestValidParentheses(string s) {
        // return longestValidParenthesesDP(s);
        return longestValidParenthesesSelf(s);
    }
};
int main()
{
    Solution a;
    //"()(()"   "(()" ")()())"
    string s="())()())";
    cout<<a.longestValidParentheses(s)<<endl;
    system("pause");
    return 0;
}