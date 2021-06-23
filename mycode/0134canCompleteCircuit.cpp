#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = -1;
        int dp[105]={0};
        for (size_t i = 0; i < gas.size(); i++)
        {
            dp[i] = gas[i] - cost[i]; 
        }
        for (size_t i = 0; i < gas.size(); i++)
        {
            int index = i,count = 0,sum = dp[index];
            while (count < gas.size()&&sum>=0)
            {
                
                index++;
                count++;
                if (index == gas.size())
                {
                    index = 0;
                }
            }
            
            if (count == gas.size())
            {
                return i;
            }
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
