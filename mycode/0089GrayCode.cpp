#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> t_vec,ret;
        queue<int> que;
        // if(n==0) return ret;
        set<int> Set;
        que.push(0);
        ret.push_back(0);
        Set.insert(0);
        while(que.size()>0){
            t_vec.clear();
            int t_n=que.front(),tt_n=n,ttt_n=t_n,sum=0;
            que.pop();
            // cout<<t_n<<endl;
            for(int i=0;i<n;i++){
                t_vec.push_back(ttt_n%2);
                ttt_n=ttt_n>>1;
            }
            for(int i=0;i<t_vec.size();i++){
                if(sum==1){
                    break;
                }
                cout<<"t_n:"<<t_n<<" i:"<<t_vec[i]<<endl;
                if(t_vec[i]==0){
                    int tmp=pow(2,i)+t_n;
                    if(Set.find(tmp)==Set.end()){
                        sum++;
                        que.push(tmp);
                        ret.push_back(tmp);
                        Set.insert(tmp);
                    }
                }else{
                    int tmp=t_n-pow(2,i);
                    if(Set.find(tmp)==Set.end()){
                        que.push(tmp);
                        ret.push_back(tmp);
                        Set.insert(tmp);
                        sum++;
                    }
                }
            }
        }
        return ret;
    }
};
int main (){
	Solution s;
    s.grayCode(2);
    system("pause");
	return 0;
}
