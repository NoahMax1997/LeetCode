#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    // set<string> Set;
    map<string,int> Map;
    bool isOnlyOne(string str1,string str2){
        int sum=0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                sum++;
            }
        }
        if(sum==1){
            return true;
        }
        return false;
    }
    void dfs(vector<string>& wordList,string beginWord, string endWord,set<string> &Set,int num,int &min_num){
        if(beginWord==endWord){
            if(num<min_num){
                min_num=num;
            }
        }else{
            if(num>=min_num){
                return;
            }
            for(int i=0;i<wordList.size();i++){
                if(isOnlyOne(wordList[i],beginWord)&&Set.find(wordList[i])==Set.end()){
                    if(Map.find(wordList[i])!=Map.end()&&Map[wordList[i]]>num){
                        Map[wordList[i]]=num;
                        Set.insert(wordList[i]);
                        dfs(wordList,wordList[i],endWord,Set,num+1,min_num);
                        Set.erase(wordList[i]);
                    }
                    
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> Set;
        // int num;
        int min_num=INT_MAX;
        dfs(wordList,beginWord,endWord,Set,1,min_num);
        if( min_num==INT_MAX){
            min_num=0;
        }
        return min_num;
    }
};
int main (){
		
	return 0;
}
