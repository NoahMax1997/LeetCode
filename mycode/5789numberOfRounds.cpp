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
    bool compareString(string a,string b){
        if (a.size()!= b.size())
        {
            /* code */
            return false;
        }
        
        for (size_t i = 0; i < a.size(); i++)
        {
            /* code */
        }
        return false;
    }
    bool compareTime(string startTime, string finishTime){
        string startTime_hh = startTime.substr(0,2),startTime_mm = startTime.substr(3,2),finishTime_hh = finishTime.substr(0,2),finishTime_mm = finishTime.substr(3,2);
        if (startTime_hh == finishTime_hh)
        {

        }
        
    }
    int numberOfRounds(string startTime, string finishTime) {

    }
};
int main (){
	Solution s;
    system("pause");
	return 0;
}
