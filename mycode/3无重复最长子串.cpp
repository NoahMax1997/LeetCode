#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;
unordered_set<char> charSet;
class Solution {
public:
    int lengthOfLongestSubstring(string s){
    	for(int i=0;i<s.length();i++){
    		charSet.insert(s[i]);
    		if(i>0&&charSet.find(s[i-1])!=charSet.end()){
    			charSet.erase(s[i-1]); 
			}
			int j=i+1;
			if(charSet.size()>0){
				j=i+charSet.size();
			}
			for(;j<s.length();j++){
				if(charSet.find(s[j])!=charSet.end()){
					break;
				}
				charSet.insert(s[j]);
			}	
		}
    }
};
int main (){
	Solution s;
	string str;
	while(cin>>str){
		cout<<s.lengthOfLongestSubstring(str)<<" "<<endl;
	}	
	return 0;
}
