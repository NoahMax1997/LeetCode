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
    void dfs(vector<vector<int>>& triangle,int level,int index,int &min_sum,int t_sum){
        if(level==triangle.size()){
            // cout<<"t_sum:"<<t_sum<<endl;
            if(t_sum==3){

            }
            if(t_sum<min_sum){
                min_sum=t_sum;
                cout<<"t_sum:"<<t_sum<<endl;
            }
            return;
        }else{
            cout<<level<<" "<<index<<" "<<triangle[level][index]<<endl;
            dfs(triangle,level+1,index,min_sum,t_sum+triangle[level][index]);
            if(index+1<triangle[level].size()){
                t_sum+=triangle[level][index+1];
                dfs(triangle,level+1,index+1,min_sum,t_sum);
            }    
        }
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int min_sum=100000,t_sum=0;
        // dfs(triangle,0,0,min_sum,t_sum);
        if(triangle.size()==0){
            return 0;
        }
        int dp[201][201]={0};
        dp[0][0]=triangle[0][0];
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }else if(j==triangle[i].size()-1){
                    dp[i][j]=dp[i-1][triangle[i-1].size()-1]+triangle[i][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }
            }
        }
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            if(dp[triangle.size()-1][i]<min_sum){
                min_sum=dp[triangle.size()-1][i];
            }
        }
        return min_sum;
    }
};
int main (){
    vector<vector<int>> ii={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution s;
    cout<<s.minimumTotal(ii)<<endl;
    system("pause");
    return 0;
}