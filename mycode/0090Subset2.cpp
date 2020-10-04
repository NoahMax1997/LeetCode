#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfsSlow(vector<vector<int>> &ret,vector<int> &t_vec,set<int> &i_set,vector<int>& nums){
        vector<int> tt_vec=t_vec;
        sort(tt_vec.begin(),tt_vec.end());
        if(find(ret.begin(),ret.end(),tt_vec)==ret.end()){
            ret.push_back(tt_vec);
        }else{
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i_set.find(i)==i_set.end()){
                t_vec.push_back(nums[i]);
                i_set.insert(i);
                dfsSlow(ret,t_vec,i_set,nums);
                i_set.erase(i);
                t_vec.pop_back();
            }
        }
    }
    void dfsQuick(vector<vector<int>> &ret,vector<int> &t_vec,set<int> &i_set,vector<int>& nums){
        vector<int> tt_vec=t_vec;
        sort(tt_vec.begin(),tt_vec.end());
        if(find(ret.begin(),ret.end(),tt_vec)==ret.end()){
            ret.push_back(tt_vec);
        }else{
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i_set.find(i)==i_set.end()){
                t_vec.push_back(nums[i]);
                i_set.insert(i);
                dfsSlow(ret,t_vec,i_set,nums);
                i_set.erase(i);
                t_vec.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        set<int> i_set;
        // dfsSlow(ret,t_vec,i_set,nums);
        sort(nums.begin(),nums.end());
        
        return ret;
    }
};
int main (){
		
	return 0;
}
