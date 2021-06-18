#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[102][102] = {0};
        dp[0][0] = true;
        for (size_t i = 0; i < s1.size(); i++)
        {
            /* code */
            for (size_t j = 0; j < s2.size(); j++)
            {
                /* code */
                int index = i + j - 1;
                if (index < 0)
                {
                    /* code */
                    continue;
                }
                dp[i][j] = dp[]
            }
            
        }
        
    }
};
int main (){
		
	return 0;
}
