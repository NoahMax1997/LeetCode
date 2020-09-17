#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isNum(char ch){
        if(ch>='0'&&ch<='9'){
            return true;
        }
        return false;
    }
    bool isNumber(string s) {
        int e_sum=0,_sum=0,__sum=0,plus_sum=0,sub_sum=0;
        bool ret=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='e'){
                e_sum++;
            }else if(s[i]=='.'){
                _sum++;
            }else if(s[i]=='/'){
                __sum++;
            }else if(s[i]=='-'){
                sub_sum++;
            }else if(s[i]=='+'){
                plus_sum++;
            }
            if(s[i]=='+'){
                if(i!=0&&s[i-1]!='e'){
                    ret=false;
                }
            }else if(s[i]=='-'){
                if(i!=0){
                    ret=false;
                }
            }else if(s[i]=='e'){
                int j;
                for(j=i+1;j<s.size();j++){
                    if(!isNum(s[i])){
                        break;
                    }
                }
                if(j!=s.size()){
                    ret=false;
                }
            }
            if(!isNum(s[i])&&s[i]!='e'&&s[i]!='-'&&s[i]!='+'&&s[i]!='/'&&s[i]!='.'){
                ret=false;
            }else if((s[i]=='e'||s[i]=='.'||s[i]=='/')&&(i==0||i==s.size()-1||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='/'||s[i-1]=='.'||
            s[i+1]=='/'||s[i+1]=='.')){
                ret=false;
            }else if((s[i]=='-'||s[i]=='+')&&i==s.size()-1){
                ret=false;
            }
            if(e_sum>1||_sum>1||__sum>1||sub_sum>1||plus_sum>1){
                ret=false;
            }
            if(ret==false){
                break;
            }
        }
        return ret;
    }
};
int main()
{
    Solution a;
    string str;
    while(1){
        getline(cin,str);
        cout<<a.isNumber(str)<<endl;
    }
    
    system("pause");
    return 0;
}