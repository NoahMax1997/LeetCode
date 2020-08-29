#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isLeftParentheses(const char &ch){
        if(ch=='{'||ch=='('||ch=='['){
            return true;
        }
        return false;
    }
    bool isMatch(const char &ch1,const char &ch2){
        if(ch1=='('&&ch2==')'||ch1=='{'&&ch2=='}'||ch1=='['&&ch2==']') return true;
        return false; 
    }
    bool isValid(string s) {
        stack<char> t_stack;
        if(s=="") return true;
        else{
            for(int i=0;i<s.size();i++){
                if(isLeftParentheses(s[i])){
                    t_stack.push(s[i]);
                }else if(!t_stack.empty()&&isMatch(t_stack.top(),s[i])){
                    t_stack.pop();
                }else return false;
            }
        }
        if(t_stack.empty()){
            return true;
        }
        return false;
    }
};
int main (){
    
    return 0;
}