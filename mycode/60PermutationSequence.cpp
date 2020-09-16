#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(int n,int &k,string &ret,string &vec,set<int> &t_set,int index,int &sta){
        if(index==n){
            sta++;
            if(sta==k){
                ret=vec;
            }
        }else{
            for(int i=0;i<n;i++){
                if(t_set.find(i)==t_set.end()){
                    t_set.insert(i);
                    vec.push_back(i+1+'0');
                    dfs(n,k,ret,vec,t_set,index+1,sta);
                    t_set.erase(i);
                    vec.pop_back();
                }
            }
        }
    }
    int getMul(int n){
        int ret=1;
        for(int i=2;i<=n;i++){
            ret*=i;
        }
        return ret;
    }
    string getPermutationDfs(int n, int k) {
        int sta=0;
        set<int> t_set;
        string vec,ret;
        // cout<<ret<<endl;
        if(n==1) return "1";
        int N=getMul(n-1),start=0;
        if(k>N){
            start=k/N;
            k=k%N;
            if(k==0){
                k=N;
                start--;
            }
        }
        t_set.insert(start);
        vec.push_back(start+1+'0');
        dfs(n,k,ret,vec,t_set,1,sta);
        return ret;
    }
    string getPermutation(int n, int k){
        vector<int> t_vec;
        string ret;
        for(int i=0;i<n;i++){
            t_vec.push_back(i+1);
        }
        while(ret.size()<n){
            int N=getMul(t_vec.size()-1),start=0;
            if(t_vec.size()==1){
                ret.push_back(t_vec[0]+'0');
                t_vec.clear();
                continue;
            }
            if(k>N){
                start=k/N;
                k=k%N;
                if(k==0){
                    k=N;
                    start--;
                }
            }
            ret.push_back(t_vec[start]+'0');
            t_vec.erase(start+t_vec.begin());
        }
        return ret;
    } 
};
int main (){
	Solution a;
    // a.myPow(2,10);
    cout<<a.getPermutation(3,3);
    system("pause");
	return 0;
} 