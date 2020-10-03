#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int i=0,j=matrix[0].size()-1,row_size=matrix.size(),col_size=matrix[0].size();
        bool ret=false;
        while(i<row_size&&j>=0){
            if(matrix[i][j]==target){
                ret=true;
                break;
            }else if(matrix[i][j]<target){
                i++;
            }else if(matrix[i][j]>target){
                j--;
            }
        }
        return ret;
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}