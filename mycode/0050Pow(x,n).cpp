#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    double myPowForce(double x, int n) {
        //time over
        int flag=1;
        if(n<0) flag=0;
        if(n==INT_MIN){
            for(int i=0;i<=INT_MAX;i++){
                x*=2;
            }
            x=1/x;
        }else{
           n=abs(n);
           for(int i=0;i<n;i++){
                   x*=x;
           }
           if(flag==0){
               x=1/x;
           }
        }
        return x;
    }
    double myPowQuickMul(double &x, int n) {
        if(n==0){
            return 1.0;
        }else{
            double y=myPowQuickMul(x,n/2);
            return n%2==0?y*y:y*y*x;
        }
    }
    double myPowBinary(double &x, int n){
        double contribution=x,ret=1;
        long long N=abs(n);
        if(n==0){
            return 1.0;
        }else{
            while(N){
                if(N%2==1){
                    ret*=contribution;
                }
                contribution*=contribution;
                N=N>>1;
            }
        }
        return n>0?ret:1.0/ret;
    }
    double myPow(double x, int n) {
        // return n>0?myPowQuickMul(x,n):1.0/myPowQuickMul(x,n);
        return myPowBinary(x,n);
    }
};
int main (){
	Solution a;
    a.myPow(2,10);
	return 0;
} 