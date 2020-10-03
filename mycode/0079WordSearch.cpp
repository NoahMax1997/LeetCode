#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int flag=0;
    void dfs(vector<vector<char>>& board, string &word,int index,string &t_str,int i,int j)
    {
        if(flag==1){
            return;
        }
        if(i>=board.size()||j>=board[0].size()||i<0||j<0){
            return;
        }
        if(board[i][j]==word[index]){
            cout<<t_str<<endl;
            t_str.push_back(board[i][j]);
            string tt_str=t_str;
            char tmp=board[i][j];
            board[i][j]='.';
            index++;
            if(index==word.size()){
                flag=1;
            }
            dfs(board, word,index,t_str,i+1,j);//every direction may success 
            if(t_str==word){
                flag=1;
                return;
            }else{
                t_str=tt_str;
            }
            dfs(board, word,index,t_str,i,j+1);
            if(t_str==word){
                flag=1;
                return;
            }else{
                t_str=tt_str;
            }
            dfs(board, word,index,t_str,i-1,j);
            if(t_str==word){
                flag=1;
                return;
            }else{
                t_str=tt_str;
            }
            dfs(board, word,index,t_str,i,j-1);
            if(t_str==word){
                flag=1;
                return;
            }else{
                t_str=tt_str;
            }
            board[i][j]=tmp;
            // t_str.pop_back();
        }
        else if(t_str.size()>0){
            return;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0){
            return false;
        }
        if(word.size()==0){
            return true;
        }
        string t_str="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                t_str="";
                if(word[0]==board[i][j]){
                    cout<<i<<" "<<j<<endl;
                    dfs(board, word,0,t_str,i,j);
                    if(t_str==word){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}