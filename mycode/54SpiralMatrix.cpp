#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //wrong
        bool Map[100][100];
        memset(Map,sizeof(Map),false);
        vector<int> ret;
        int i=0,j=0,size_i=matrix.size(),size_j=matrix[0].size(),N=size_i*size_j;
        while(N){
            if((i==0||Map[i-1][j])&&(j==0||Map[i][j-1])){
                while(j<size_j&&Map[i][j]==false){
                    Map[i][j]=true;
                    ret.push_back(matrix[i][j]);
                    j++;
                    N--;
                }
                i++;
                j--;
            }else if((i==0||Map[i-1][j])&&(j==size_j-1||Map[i][j+1])){
                while(i<size_i&&Map[i][j]==false){
                    Map[i][j]=true;
                    ret.push_back(matrix[i][j]);
                    i++;
                    N--;
                }
                j--;
                i--;
            }else if((i==size_i-1||Map[i+1][j])&&(j==size_j-1||Map[i][j+1])){
                while(j>=0&&Map[i][j]==false){
                    Map[i][j]=true;
                    ret.push_back(matrix[i][j]);
                    j--;
                    N--;
                }
                i--;
                j++;
            }else if((i==size_i-1||Map[i+1][j])&&(j==0||Map[i][j+1])){
                while(i>=0&&Map[i][j]==false){
                    Map[i][j]=true;
                    ret.push_back(matrix[i][j]);
                    i--;
                    N--;
                }
                j++;
                i++;
            }
            for(int t=0;t<ret.size();t++){
                cout<<ret[t]<<" ";
            } 
            cout<<endl;
        }
        return ret;
    }
};
int main (){
	Solution a;
    vector<vector<int>> m={{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    // a.myPow(2,10);
    a.spiralOrder(m);
    system("pause");
	return 0;
} 