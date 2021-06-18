#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows,"");
        string ret = "";
        cout<<rows.size()<<endl;
        int index = 0,direct = 0,row = 0;
        if (numRows <= 1)
        {
            /* code */
            return s;
        }
        
        while (index < s.size())
        {
            /* code */
            if (direct == 0)
            {
                /* code */
                rows[row]+=s[index];
                row++;
                if (row == numRows)
                {
                    /* code */
                    direct = 1;
                    row-=2;
                }
                
            }
            else
            {
                rows[row]+=s[index];
                row--;
                if (row == -1)
                {
                    /* code */
                    direct = 0;
                    row+=2;
                }
            }
            index++;
        }
        
        for (size_t i = 0; i < numRows; i++)
        {
            /* code */
            cout<<rows[i]<<endl;
            ret+=rows[i];
        }
        
        return ret;
    }
};
int main (){
	Solution a;
	cout<<a.convert("PAYPALISHIRING",3);
    system("pause");
	return 0;
} 
