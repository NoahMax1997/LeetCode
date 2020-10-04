#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numTreesDFS(int begin,int end){
        //time over
        int ret=0;
        if(begin>end){
            ret = 1;
        }
        for(int i=begin;i<=end;i++){
            ret += numTreesDFS(begin,i-1)*numTreesDFS(i+1,end);
        }
        return ret;
    }
    int numTreesDP(int n){
        int dp[20]={0};
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[n]+=dp[i-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        if(n==0){
            return 1;
        }
        else{
            // return numTreesDFS(1,n);
            return numTreesDP(n);
        }
    }
};
int main (){
		
	return 0;
}
