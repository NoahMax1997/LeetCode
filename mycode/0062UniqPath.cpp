#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    long long getMuti(long long n){
        long long ret=1;
        for(long long i=1;i<=n;i++){
            ret*=i;
        }
        return ret;
    }
    int uniquePathsMath(int m, int n) {
        //over flow
        if(m==0||n==0) return 0;
        long long N=m+n-2,t_m=m-1,t_n=n-1;
        long long t_nn=1;
        for(long long i=0;i<t_m;i++){
            t_nn*=(N-i);
        }
        return t_nn/getMuti(t_m);
    }
    int uniquePathsDP(int m, int n) {
        int dp[101][101];
        memset(dp,sizeof(dp),0);
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        return uniquePathsDP(m,n);
    }
};
int main (){
    Solution a;
    cout<<a.uniquePaths(10,10);
    system("pause");
    return 0;
}