#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void findAchar(string& ret,int num,int index)
public:
    vector<string> letterCombinations(string digits)
    {
        string Map[10] = {"", "", "abc", "bef", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        vector<int> nonius_vec;
        int sum = 1, size = digits.size(),min_size=INT_MAX;
        for (int i = 0; i < size; i++)
        {
            int t_size = Map[digits[i] - '0'].size();
            sum *= t_size;
            if (t_size < min_size)
                min_size = t_size;
            nonius_vec.push_back(0);
        }
        while (sum--)
        {
            int nonius = 0;
            string s_str="";
            while (nonius < size)
            {
                string t_str=Map[digits[nonius] - '0'];
                for (int i = nonius_vec[nonius]; i < t_str.size(); i++)
                {
                    t_str.push_back(t_str[i]);
                     
                }
                nonius++;
                for(int i=nonius;i<size;i++){
                    nonius_vec[i]=0;
                }
            }
        }
    }
};
int main()
{
    Solution a;

    return 0;
}
