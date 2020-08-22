#include <iostream>
#include <map>
#include<unordered_set>
using namespace std;
class Solution {
public:
	unordered_set<char> charSet;
    int lengthOfLongestSubstring(string s) {
    	int ret=0;
    	int longest=0;
        for(int i=0;i<s.length();i++){
        	int tempLength=0;
        	int j;
        	for(j=charSet.size()+i;j<s.length();j++){
        		if(charSet.find(s.at(j))==charSet.end()){
        			charSet.insert(s.at(j));
				}else{
					break;
				}
			}
			tempLength=j-i;
			if(longest<tempLength){
        		longest=tempLength;
			}
			charSet.erase(s.at(i));
		}
		return longest;
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
