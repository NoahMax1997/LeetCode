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
    vector<array<int,2>> ans;
    bool dfs(vector<vector<char>>& board,int i,int j){
        
        if (i >= board.size()||j >= board[0].size()||i<0||j<0)
        {
            return false;
        }

        if (board[i][j] == 'X')
        {
            return true;
        }
        array<int,2> tmp_array;
        tmp_array[0] = i,tmp_array[1] = j;
        board[i][j] = 'X';
        ans.push_back(tmp_array);
        return dfs(board,i+1,j)&&dfs(board,i,j+1)&&dfs(board,i-1,j)&&dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    continue;
                }

                if(!dfs(board,i,j)){
                    cout<<i<<" "<<j<<endl;
                    for (size_t k = 0; k < ans.size(); k++)
                    {
                        board[ans[k][0]][ans[k][1]] = 'O';
                    }
                    ans.clear();  
                }
            }
        }
        
    }
};
int main (){
		
	return 0;
}
