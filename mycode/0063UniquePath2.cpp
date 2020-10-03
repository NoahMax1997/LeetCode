#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0||obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1){
            return 0;
        }
        int dp[101][101];
        memset(dp,sizeof(dp),0);
        int flag=0;
        for(int i=0;i<obstacleGrid.size();i++){
            if(flag==0&&obstacleGrid[i][0]==0){
                dp[i][0]=1;
            }else{
                flag=1;
                dp[i][0]=0;
            }
        }
        flag=0;
        for(int i=0;i<obstacleGrid[0].size();i++){
            if(flag==0&&obstacleGrid[0][i]==0){
                dp[0][i]=1;
            }else{
                flag=1;
                dp[0][i]=0;
            }
        }
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[i].size();j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
int main (){
    Solution a;
    // cout<<a.uniquePaths(10,10);
    system("pause");
    return 0;
}