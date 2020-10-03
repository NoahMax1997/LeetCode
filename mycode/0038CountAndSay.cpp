#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string t_str="1",ret="";
        while (--n)
        {
            int i=0,sum=1;
            while(i<t_str.size()-1){
                if(t_str[i]!=t_str[i+1]){
                    ret.push_back('0'+sum);
                    ret.push_back(t_str[i]);
                    sum=0;
                }
                sum++;
                i++;
            }
            ret.push_back('0'+sum);
            ret.push_back(t_str[i]);
            t_str=ret;
            // cout<<t_str<<endl;
            ret.clear();
        }
        return t_str;
    }
};
int main()
{
    Solution a;
    vector<int> t={4,2,0,2,3,2,0};
    cout<<a.countAndSay(3)<<endl;
    // for(auto i:t){
    //     cout<<i<<endl;
    // }
    system("pause");
    return 0;
}