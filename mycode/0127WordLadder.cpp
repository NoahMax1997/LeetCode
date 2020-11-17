#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;
class Solution {
public:
    // set<string> Set;
    stack<string> st;
    map<string,set<string> > Map;//the times change to this  string 
    void init(vector<string>& wordList){
        for(auto i:)
    }
    bool isOnlyOne(const string &str1,const string &str2){
        int sum=0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                sum++;
                if(sum==2)
                    break;
            }
        }
        if(sum==1){
            return true;
        }
        return false;
    }
    void dfsRecursion(vector<string>& wordList,string beginWord, string endWord,set<string> &Set,int num,int &min_num){
        
    }
    void dfsNoRecursion(const vector<string>& wordList,const string &endWord){

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set<string> Set;
        // // int num;
        // int min_num=INT_MAX;
        // dfsRecursion(wordList,beginWord,endWord,Set,1,min_num);
        // if( min_num==INT_MAX){
        //     min_num=0;
        // }
        // return min_num;
        st.push(beginWord);

    }
};
int main (){
	
	return 0;
}
