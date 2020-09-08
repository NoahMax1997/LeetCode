#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    void dfsSelf(vector<int>& candidates, int target,vector<int> &t_vec,vector<vector<int>> &ret,int &sum,int &index,string &str,set<string> &str_s){
        //very slow and memory large
        if(sum==target){
            if(str_s.find(str)==str_s.end()){
                ret.push_back(t_vec);
                str_s.insert(str);
            }
        }else{
            for(int i=index;i<candidates.size();i++){
                if(sum+candidates[i]>target){
                    continue;
                }
                t_vec.push_back(candidates[i]);
                sum+=candidates[i];
                str.push_back('0'+candidates[i]);
                i++;
                dfsSelf(candidates,target,t_vec,ret,sum,i,str,str_s);
                i--;
                t_vec.pop_back();
                str.pop_back();
                sum-=candidates[i];
            }
        }
    }
    void dfsCutRepeatedSelf(vector<int>& candidates, int target,vector<int> &t_vec,vector<vector<int>> &ret,int &sum,int &index){
        // slow and memory large
        if(sum==target){
            ret.push_back(t_vec);
        }else{
            set<int> s;
            for(int i=index;i<candidates.size();i++){
                if(s.find(candidates[i])!=s.end()||sum+candidates[i]>target){
                    continue;
                }
                t_vec.push_back(candidates[i]);
                sum+=candidates[i];
                s.insert(candidates[i]);
                i++;
                dfsCutRepeatedSelf(candidates,target,t_vec,ret,sum,i);
                i--;
                t_vec.pop_back();
                sum-=candidates[i];
            }
        }
    }
    void dfsCutRepeated(vector<int>& candidates, int target,vector<int> &t_vec,vector<vector<int>> &ret,int &sum,int &index){
        // no set
        if(sum==target){
            ret.push_back(t_vec);
        }else{
            for(int i=index;i<candidates.size();i++){
                if(sum+candidates[i]>target){
                    continue;
                }
                if(i-1>=index&&candidates[i]==candidates[i-1]){
                    continue;
                }
                t_vec.push_back(candidates[i]);
                sum+=candidates[i];
                i++;
                dfsCutRepeated(candidates,target,t_vec,ret,sum,i);
                i--;
                t_vec.pop_back();
                sum-=candidates[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> t_vec;
        int sum=0,index=0;
        set<int> s;
        set<string> str_s;
        string str="";
        // dfsSelf(candidates,target,t_vec,ret,sum,index,str,str_s);
        // dfsCutRepeatedSelf(candidates,target,t_vec,ret,sum,index);
        dfsCutRepeated(candidates,target,t_vec,ret,sum,index);
        return ret;
    }
};
int main()
{
    Solution a;
    vector<int> t={2,3,6,7};
    // for(auto t:a.combinationSum(t,7))
    // for(auto i:t){
    //     cout<<i<<endl;
    // }
    system("pause");
    return 0;
}