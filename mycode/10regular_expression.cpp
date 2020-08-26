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
        }else if(s_size==0&&p_size!=0||s_size!=0&&p_size==0){
            return false;
        }
        if(s[s_size-1]==p[p_size-1]||p[p_size-1]=='.'){
            return isMatch(s,p,s_size-1,p_size-1);
        }else if(p[p_size-1]=='*'&&p[p_size-2]=='.'){
            bool ret=false;
            // s_size--;
            while(s_size>=0){
                p_size-=2;
                if(isMatch(s,p,s_size,p_size)){
                    ret=true;
                }
                p_size+=2;
                s_size--;
            }
            return ret;
        }else if(p[p_size-1]=='*'&&s[s_size-1]==p[p_size-2]){
            bool ret=false;
            // s_size--;
            while(s_size>=0&&s[s_size-1]==p[p_size-2]){
                p_size-=2;
                if(isMatch(s,p,s_size,p_size)){
                    ret=true;
                }
                p_size+=2;
                s_size--;
            }
            return ret;
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
    // cout<<a.isMatch("aa", "a")<<endl;
    // system("pause");
    cout<<a.isMatch("aa", "a*")<<endl;
    // system("pause");
    cout<<a.isMatch("ab", ".*")<<endl;
    cout<<a.isMatch("aab", "c*a*b")<<endl;
    cout<<a.isMatch("mississippi", "mis*is*p*.")<<endl;
    system("pause");
    return 0;
}