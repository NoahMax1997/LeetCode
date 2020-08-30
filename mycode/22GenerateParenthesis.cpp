#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string& s) {
        stack<char> t_stack;
        if(s=="") return true;
        else{
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    t_stack.push(s[i]);
                }else if(!t_stack.empty()&&s[i]==')'){
                    t_stack.pop();
                }else return false;
            }
        }
        if(t_stack.empty()){
            return true;
        }
        return false;
    }
    void generateTheString(vector<string>& ret,string str,const int& n,int num){
        if(n==num){
            // cout<<str<<endl;
            if(isValid(str)){
                // cout<<"right:"<<str<<endl;
                ret.push_back(str);
            }
            str.clear();
        }else{
            str.push_back('(');
            generateTheString(ret,str,n,num+1);
            str.pop_back();
            str.push_back(')');
            generateTheString(ret,str,n,num+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str;
        generateTheString(ret,str,n*2,0);
        return ret;
    }
};
int main (){
    Solution a;
    a.generateParenthesis(3);
    system("pause");
}