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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix1=matrix;
        for(int i=0;i<matrix1.size();i++){
            for(int index=0;index<matrix1[i].size();index++){
                if(matrix1[i][index]==0){
                    for(int j=0;j<matrix[i].size();j++){
                        matrix[i][j]=0;
                    }
                    for(int j=0;j<matrix.size();j++){
                        matrix[j][index]=0;
                    }
                }
            }
        }
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}