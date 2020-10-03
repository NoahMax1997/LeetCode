#include <iostream>
#include <vector>
using namespace std;
//从后往前搜导致无法处理 多个*连续的情景
class Solution {
private:
    inline int isSpecial(char ch){
        if(ch=='*') return 1;
        else if(ch=='.') return 2;
        else return 0;
    }
public:
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
    bool isMatch(string s, string p) {
        int first_index=0,second_index=0;
        while(first_index<s.size()&&second_index<p.size()){
            char t_ch=p[second_index];
            if(isSpecial(t_ch)==0){
                if(s[first_index]==t_ch){
                    first_index++;
                    second_index++;
                }else{
                    if(second_index+1==p.size()||p[second_index+1]!='*'){
                        return false;
                    }else{
                        // first_index++;
                        second_index+=2;
                    }
                }
            }else if(isSpecial(t_ch)==1){
                if(p[second_index-1]==s[first_index]){
                    while(first_index<s.size()&&p[second_index-1]==s[first_index])
                        first_index++;
                    second_index++;
                    while(second_index<p.size()&&p[second_index-2]==p[second_index])
                        second_index++;
                }else{
                    // first_index++;
                    second_index++;
                }
            }else{
                if(second_index<p.size()&&p[second_index+1]=='*'){
                    while(second_index<p.size()&&isSpecial(p[second_index])!=0){
                        second_index++;
                    }
                    if(second_index>=p.size()){
                        return true;
                    }else{
                        int i;
                        for(i=s.size()-1;i>=0&&s[i]!=p[second_index];i--);
                        first_index= i>=0?i:0;
                    }
                }else{
                    p[second_index]=s[first_index];
                    second_index++;
                    first_index++;
                }
            }
        }
        if(first_index==s.size()&&second_index==p.size()){
            return true;
        }else{
            return false;
        }
    }
};
int main (){
    Solution a;
    
    cout<<a.isMatch("abaabaaaabbabbaaabaabababbaabaabbabaaaaabababbababaabbabaabbbbaabbbbbbbabaaabbaaaaabbaabbbaaaaabbbabb","ab*aaba**abbaaaa**b*b****aa***a*b**ba*a**ba*baaa*b*ab*");
    system("pause");
    return 0;
}