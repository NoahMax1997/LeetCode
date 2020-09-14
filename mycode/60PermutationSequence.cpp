#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfsPermutate(int n,int &k,set<int> &t_set,string &ans,string &ret,int index){
        if(index==n){
            if(k==n){
                ret=ans;
            }else{
                k++;
            }  
        }else{
            for(int i=1;i<n+1;i++){
                if(t_set.find(i)!=t_set.end()){
                    continue;
                }
                t_set.insert(i);
                ans.push_back(i);
                dfsPermutate(n,k,t_set,ans,index+1);
                t_set.erase(i);
                ans.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        int N=1;
        set<int> t_set;
        string vec,ret;
        for(int i=2;i<n-1;i++){
            N*=i;
        }
        int start=k/N+1,t=-1;
        dfsPermutate(k%N,t,t_set,vec,ret,0);
    }
};
int main (){
	Solution a;
    // a.myPow(2,10);
	return 0;
} 