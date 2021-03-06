#include <iostream>
#include <vector>
using namespace std;
//从后往前搜导致无法处理 多个*连续的情景
class Solution
{
public:
    bool isMatch(string s, string p,int s_size,int p_size){
        if(s_size==0&&p_size==0){
            return true;
        }else if(s_size!=0&&p_size==0){
            return false;
        }else if(s_size==0&&p_size>=2&&p[p_size-1]=='*'){
            return isMatch(s,p,s_size,p_size-2);
        }else if(s_size==0){
            return false;
        }
        if(s[s_size-1]==p[p_size-1]||p[p_size-1]=='.'){
            return isMatch(s,p,s_size-1,p_size-1);
        }else if(p[p_size-1]=='*'&&p[p_size-2]=='.'){
            return isMatch(s,p,s_size,p_size-2)||isMatch(s,p,s_size-1,p_size);
        }else if(p[p_size-1]=='*'&&s[s_size-1]==p[p_size-2]){
            return isMatch(s,p,s_size,p_size-2)||isMatch(s,p,s_size-1,p_size);
        }else if(p[p_size-1]=='*'&&s[s_size-1]!=p[p_size-2]){
            return isMatch(s,p,s_size,p_size-2);
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p)
    {
        return isMatch(s,p,s.size(),p.size());   
    }
};

int main()
{
    Solution a;
    cout<<a.isMatch("aa", "a")<<endl;
    cout<<a.isMatch("aa", "a*")<<endl;
    cout<<a.isMatch("ab", ".*")<<endl;
    cout<<a.isMatch("aab", "c*a*b")<<endl;
    cout<<a.isMatch("mississippi", "mis*is*p*.")<<endl;
    cout<<a.isMatch("mississippi", "mis*is*ip*.")<<endl;
    cout<<a.isMatch("a", ".*..a*")<<endl;
    system("pause");
    return 0;
}