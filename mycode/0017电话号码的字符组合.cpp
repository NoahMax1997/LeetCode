#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void findAChar(string* Map,string &digits,int index1,int index2,string &str_ret,vector<string> &ret){
		if(index1==digits.size()){
			ret.push_back(str_ret);
			return;
		}else{
			string &t_str=Map[digits[index1]-'0'];
			for(int i=0;i<t_str.size();i++){
				str_ret.push_back(t_str[i]);
				findAChar(Map,digits,index1+1,index2,str_ret,ret);
				str_ret.pop_back();
			}
		}
	}
    vector<string> letterCombinations(string digits) {
		string Map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
		string str_ret="";
		vector<string> ret;
		if(digits=="") return ret;
		findAChar(Map,digits,0,0,str_ret,ret);
		return ret;
    }
};
int main (){
	Solution a;
	a.letterCombinations("23");
	system("pause");
	return 0;
} 
