#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
class Solution {
public:
    int ret = 0;
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if (grid2.size()==0)
        {
            return;
        }
        
        int m = grid2.size(),n = grid2[0].size();

        if (i>=m||j>=n)
        {
            /* code */
            return;
        }
        if(grid1[i][j] == '0'){
            return;
        }
        if (grid2[i][j] == '0')
        {
            ret++;
            return;
        }
        
        grid2[i][j] = '0';
        int flag = 0;
        if (j-1>=0)
        {
            /* code */
            dfs(grid1,grid2,i,j-1);
            flag++;
        }
        if (i-1>=0)
        {
            dfs(grid1,grid2,i-1,j);
            flag++;
        }
        if (j+1<n)
        {
            dfs(grid1,grid2,i,j+1);
            flag++;
        }
        if (i+1<m)
        {
            dfs(grid1,grid2,i+1,j);
            flag++;
        }
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        for (size_t i = 0; i < grid2.size(); i++)
        {
            /* code */
            for (size_t j = 0; i < grid2[i].size(); i++)
            {
                /* code */
                if (grid2[i][j]=='1')
                {
                    /* code */
                    dfs(grid1,grid2,i,j);
                }
                
            }
            
        }
        return ret;
    }
};
int main (){
	Solution s;
    system("pause");
	return 0;
}
