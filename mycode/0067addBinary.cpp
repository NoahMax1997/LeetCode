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
    string addBinary(string a, string b) {
        string ret = "";
        int index_a = a.size()-1, index_b = b.size()-1;
        char flag = '0';
        while (index_a >= 0 && index_b >= 0)
        {
            /* code */
            int count = a[index_a]-'0'+b[index_b]-'0'+flag-'0';
            if (count%2 == 0)
            {
                /* code */
                ret = '0' + ret;
                flag = '0';
            }
            else
            {
                ret = '1' + ret;
                flag = '1';
            }
            index_a--;
            index_b--;
        }
        while (index_a>=0)
        {
            /* code */
            ret = a[index_a] + ret;
            index_a--;
        }
        while (index_b>=0)
        {
            /* code */
            ret = b[index_b] + ret;
            index_b--;
        }
        return ret;
    }
};
int main (){
	Solution s;
    system("pause");
	return 0;
}
