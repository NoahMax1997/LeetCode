#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string Map[10]={"","","abc","bef","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
		for(int i=0;i<digits.size();i++){
			string t_str=Map[digits[i]-'0'];
			
		}
    }
};
int main (){
	Solution a;
	
	return 0;
} 
