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
    vector<vector<int>> generateMatrix(int n) {
        int ii=0,jj=0,N=n*n,index=1,LEFT=0,RIGHT=1,UP=2,DOWN=3,direction=RIGHT;
        vector<vector<int>> ret;
        for(int i=0;i<n;i++){
            vector<int> t_vec;
            for(int j=0;j<n;j++){
                t_vec.push_back(0);
            }
            ret.push_back(t_vec);
        }
        set<int> t_set;
        while(index<N+1){
            if(direction==LEFT){
                for(;jj>=0&&t_set.find(ii*n+jj)==t_set.end();jj--){
                    ret[ii][jj]=index++;
                    t_set.insert(ii*n+jj);
                }
                ii--;
                jj++;
                direction=UP;
            }else if(direction==RIGHT){
                for(;jj<n&&t_set.find(ii*n+jj)==t_set.end();jj++){
                    ret[ii][jj]=index++;
                    t_set.insert(ii*n+jj);
                }
                ii++;
                jj--;
                direction=DOWN;
            }else if(direction==UP){
                for(;ii>=0&&t_set.find(ii*n+jj)==t_set.end();ii--){
                    ret[ii][jj]=index++;
                    t_set.insert(ii*n+jj);
                }
                ii++;
                jj++;
                direction=RIGHT;
            }else if(direction==DOWN){
                for(;ii<n&&t_set.find(ii*n+jj)==t_set.end();ii++){
                    ret[ii][jj]=index++;
                    t_set.insert(ii*n+jj);
                }
                ii--;
                jj--;
                direction=LEFT;
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
