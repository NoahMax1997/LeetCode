#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string add(string num1, string num2){
        int size1=num1.size(),size2=num2.size();
        if(size1<size2){
            swap(num1,num2);
        }
        string ret="";
        int index1=num1.size()-1,index2=num2.size()-1,flag=0,temp=0;
        while(index1>=0&&index2>=0){
            temp=num1[index1]-'0'+num2[index2]-'0'+flag;
            flag=temp/10;
            temp%=10;
            ret.push_back('0'+temp);
            index1--;
            index2--;
        }
        while(index1>=0){
            temp=num1[index1]-'0'+flag;
            flag=temp/10;
            temp%=10;
            ret.push_back('0'+temp);
            index1--;
        }
        while(index2>=0){
            temp=num2[index2]-'0'+flag;
            flag=temp/10;
            temp%=10;
            ret.push_back('0'+temp);
            index2--;
        }
        if(flag>0){
            ret.push_back('0'+flag);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string multiply(string num1, int num2) {
        int temp=0,flag=0;
        string ret="";
        for(int i=num1.size()-1;i>=0;i--){
            temp=(num1[i]-'0')*num2+flag;
            flag=temp/10;
            temp%=10;
            ret.push_back('0'+temp);
        }
        if(flag>0){
            ret.push_back('0'+flag);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if(num2=="0"||num1=="0") return "0";
        if(num1.size()<num2.size()){
            swap(num1,num2);
        }
        int size1=num1.size(),size2=num2.size();
        string ret="";
        // reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num2.size();i++)
        {   
            ret=add(ret,multiply(num1,num2[i]-'0'));
            num1.push_back('0');
        }
        return ret;
    }
};
int main()
{
    Solution a;
    vector<int> t={3,4,-1,1};
    // for(auto t:a.combinationSum(t,7))
    // for(auto i:t){
    //     cout<<i<<endl;
    // }
    cout<<a.add("1234","543999");
    system("pause");
    return 0;
}