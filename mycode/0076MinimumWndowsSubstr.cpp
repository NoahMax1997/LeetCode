#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool all_in(string sub_str,const string &t) const{
        // cout<<sub_str<<" "<<t<<endl;
        int i=0;
        for(i=0;i<t.size();i++){
            // cout<<"ttt:"<<t[i]<<endl;
            if(sub_str.find(t[i],0)==string::npos||sub_str.empty()){
                return false;
            }else if(sub_str.find(t[i],0)!=string::npos){
                sub_str.erase(sub_str.find(t[i],0),1);
            }
        }
        return true;
    }
    string minWindowForce(string s, string t) {
        string min_str="";
        int left=0,right=0;
        while(right<s.size()&&left<=right&&){
            right++;
            if(all_in(s.substr(left,right-left),t)){
                
            }
            while(left<=right&&all_in(s.substr(left,right-left),t)){
                if(right-left<min_str.size()||min_str==""){
                    min_str=s.substr(left,right-left);
                    // cout<<min_str<<endl;
                }
                left++;
            }
        }
        return min_str;
    }
    string minWindow(string s, string t) {
        return minWindowForce(s,t);
    }
};
int main (){
	Solution s;
    s.minWindow("aa","aa");
    cout<<"sdf"<<endl;
    system("pause");
	return 0;
}
