#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<string>> ans_map;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            ans_map[tmp].push_back(strs[i]);
        }
        for(auto it:ans_map){
            ret.push_back(it.second);
        }
        return ret;
    }
};
int main (){
	Solution a;
	return 0;
} 
