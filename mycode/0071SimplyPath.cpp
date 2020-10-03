#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        vector<string> vec;
        string ret="/";
        for(i=0;i<path.size()-1;){
            if(path[i]=='/'&&path[i+1]=='/'){
                path.erase(i,1);
            }else{
                i++;
            }
            // cout<<"11"<<endl;
        }
        cout<<path<<endl;
        i=0;
        while(i<path.size()){
            if(path[i]=='/'){
                if(i==path.size()-1){
                    break;
                }
                int index=path.find_first_of('/',i+1);
                string str=path.substr(i+1,index-i-1);
                if(str==".."){
                    if(!vec.empty()){
                        vec.pop_back();
                    }
                }else if(str=="."){
                    
                }else{
                    vec.push_back(str);
                }
            }
            i++;
            // cout<<"22"<<endl;
        }
        for(int i=0;vec.size()>i;i++){
            // cout<<"33"<<endl;    
            ret+=vec[i];
            if(i!=vec.size()-1){
                ret+="/";
            }
        }
        return ret;
    }
};
int main()
{
    Solution a;
    string str;
    // while(1){
    //     getline(cin,str);
    //     cout<<a.simplifyPath(str)<<endl;
    // }
    cout<<a.simplifyPath("/a//b////c/d//././/..")<<endl;
    system("pause");
    return 0;
}