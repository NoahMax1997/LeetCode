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
    void dfs(vector<vector<char>>& grid,int i,int j){
        if (grid.size()==0)
        {
            return;
        }
        
        int m = grid.size(),n = grid[0].size();

        if (i>=m||j>=n)
        {
            /* code */
            return;
        }
        
        if (grid[i][j] == '0')
        {
            return;
        }
        
        grid[i][j] = '0';
        if (j-1>=0)
        {
            /* code */
            dfs(grid,i,j-1);
        }
        if (i-1>=0)
        {
            dfs(grid,i-1,j);           
        }
        if (j+1<n)
        {
            dfs(grid,i,j+1);           
        }
        if (i+1<m)
        {
            dfs(grid,i+1,j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            /* code */
            for (size_t j = 0; i < grid[i].size(); i++)
            {
                /* code */
                if (grid[i][j]=='1')
                {
                    /* code */
                    ret++;
                    dfs(grid,i,j);
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
