#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int Set = 0;
    int max_length = 0;
    bool judgeStringInSet(const string &str){
        for (size_t i = 0; i < str.size(); i++)
        {
            /* code */
            if (Set&(1<<str[i]-'a'))
            {
                /* code */
                return false;
            }
            Set|=(1<<str[i]-'a');
        }
        return true;
    }
    void pushStringToSet(const string &str){
        for (size_t i = 0; i < str.size(); i++)
        {
            /* code */
            Set|=(1<<str[i]-'a');
        }
    }
    void eraseStringInSet(const string &str){
        for (size_t i = 0; i < str.size(); i++)
        {
            /* code */
            Set^=(1<<str[i]-'a');
        }
    }
    void dfs(vector<string>& arr,int index,int len){
        if (len>max_length)
        {
            /* code */
            max_length = len;
        }
        if(index >= arr.size()){
            return;
        }
        int tt = Set;
        if (!judgeStringInSet(arr[index]))
        {
            /* code */
            Set = tt;
            dfs(arr,index+1,len);
        }
        else{
            // pushStringToSet(arr[index]);
            // pushStringToSet(arr[index]);
            dfs(arr,index+1,len+arr[index].size());
            eraseStringInSet(arr[index]);
            dfs(arr,index+1,len);
        }
    }
    int maxLength(vector<string>& arr) {
        dfs(arr,0,0);
        return max_length;
    }
};
int main (){
	Solution s;
    system("pause");
	return 0;
}
