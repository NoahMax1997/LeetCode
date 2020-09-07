#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0,sum=0;
        vector<vector<int>> ret;
        vector<int> t_vec;
        stack<int> st;
        for(int i=0;i<candidates.size();i++){
            st.push(candidates[i]);    
        }
        while(!st.empty()){
            
        }
    }
};
int main()
{
    Solution a;
    vector<int> t={4,2,0,2,3,2,0};
    
    for(auto i:t){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}