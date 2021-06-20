#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <limits>
// #include <math>
using namespace std;
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid2.size()==0||grid1.size()==0)
        {
            /* code */
            return 0;
        }
        
        int grid2_dp[502][502] = {0};
        for (size_t i = 0; i < grid2.size(); i++)
        {
            for (size_t j = 0; j < grid2[0].size(); j++)
            {
                if (grid2[i][j] == 0)
                {
                    continue;
                }
                else
                {
                    
                }
                
            }
            
        }
        
    }
};
int main (){
	Solution s;
    
    system("pause");
	return 0;
}
