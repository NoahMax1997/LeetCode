#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                int t=matrix[j][i];
                matrix[j][i]=matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i]=t;
            }
        }
    }
};
int main (){
	Solution a;
    // a.myPow(2,10);
	return 0;
} 