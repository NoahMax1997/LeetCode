#include <iostream>
#include <map>
#include <set>
using namespace std;
set<string> strSet;
class Solution {
public:
	set<char> charSet;
    int lengthOfLongestSubstring(string s) {
    	int ret=0;
    	int longest=0;
        for(int i=0;i<s.length();i++){
        	int tempLength=0,start=i+charSet.size();
        	string subStr="";
        	for(int j=1;j<=s.length()-start;j++){
        		if(charSet.find(s.at(start+j-1))==charSet.end()){
        			charSet.insert(s.at(start+j-1));
				}else{
					break;
				}
        		subStr=s.substr(start,j);
        		if(subStr.length()<=longest) continue;
				if(tempLength<subStr.length()){
        			tempLength=subStr.length();
				}
			}
			if(longest<tempLength){
        		longest=tempLength;
			}
			charSet.erase(s.at(start));
//			for(set<char>::iterator it=charSet.begin();it!=charSet.end();it++){
//				cout<<*it<<" ";
//			}
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
