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
    int sum(int n){
        int ret=0;
        while(n){
            n/=10;
            ret++;
        }
        return ret;
    }
    bool cmp(int a,int b){
        cout<<a<<" "<<b<<endl;
        bool ret=false;
        int a_sum=sum(a),b_sum=sum(b);
        if(a/pow(10,a_sum)!=b/pow(10,b_sum)){
            ret = a/pow(10,a_sum)>b/pow(10,b_sum);
        }
        else if(a_sum==b_sum){
            ret=a>b;
        }
        else{
            ret|=cmp(a%(int)pow(10,a_sum),b%(int)pow(10,b_sum));
        }
        return ret;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ret="";
        for(auto i:nums){
            char ch[100];
            sprintf(ch,"%d",i);
            ret+=ch;
        }
        return ret;
    }
};
int main (){
	Solution s;
    vector<int> vec={3,30,34,5,9};
    s.largestNumber(vec);
    system("pause");
	return 0;
}
