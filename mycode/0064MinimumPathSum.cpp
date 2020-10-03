#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int **dp=new int*[grid.size()+1];
        for(int i=0;i<grid.size()+1;i++){
            dp[i]=new int [grid[0].size()+1];
        }
        memset(dp,sizeof(dp),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[0][0];
                }else if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    Solution a;
    
    system("pause");
    return 0;
}