#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=0,h_size=haystack.size(),n_size=needle.size();
        if(n_size==0) return 0;
        if(h_size==0) return -1;
        while(index<=h_size-n_size){
            int t_index=0;
            while(index+t_index<h_size&&t_index<n_size&&haystack[index+t_index]==needle[t_index]){
                t_index++;
            }
            if(t_index==n_size){
                return index;
            }
            index++;
        }
        return -1;
    }
};
int main (){
    Solution a;
    
    system("pause");
    return 0;
}