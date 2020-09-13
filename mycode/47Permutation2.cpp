#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void permuteUnique(vector<int>& nums,vector<vector<int>> &ret,vector<int> &t_vec,set<int> &t_set,int index){
        //very slow
        if(index==nums.size()){
            ret.push_back(t_vec);
        }else{
            set<int> tmp_set;
            for(int i=0;i<nums.size();i++){
                if(tmp_set.find(nums[i])!=tmp_set.end()){
                    continue;
                }
                if(t_set.find(i)==t_set.end()){
                    t_vec.push_back(nums[i]);
                    t_set.insert(i);
                    permuteUnique(nums,ret,t_vec,t_set,index+1);
                    t_vec.pop_back();
                    t_set.erase(i);
                }
                tmp_set.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> t_vec;
        set<int> t_set;
        permuteUnique(nums,ret,t_vec,t_set,0);
        return ret;
    }
};
	
int main (){
	Solution a;
	vector<int> t={1,1,2};
    a.permuteUnique(t);
	return 0;
} 
