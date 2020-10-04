#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleAreaQuicker(vector<int>& heights) {
        int ret=0;
        vector<int> left_vec(heights.size()),right_vec(heights.size(),heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            if(st.empty()||heights[i]>heights[st.top()]){
                st.push(i);
                left_vec[i]=i-1;
            }else{
                while(!st.empty()&&heights[i]<=heights[st.top()]){
                    right_vec[st.top()]=i;//every pop num's right limit is i
                    st.pop();
                }
                if(st.empty()){
                    left_vec[i]=-1;
                }else{
                    left_vec[i]=st.top();
                }
                st.push(i);
            }
        }
        // MyPrint(left_vec);
        // MyPrint(right_vec);
        for(int i=0;i<heights.size();i++){
            if(heights[i]*(right_vec[i]-left_vec[i]-1)>ret){
                ret=heights[i]*(right_vec[i]-left_vec[i]-1);
            }
        }
        return ret;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //stupid
        int ret=0;
        if(matrix.size()==0){
            return ret;
        }
        vector<int> t_vec(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    t_vec[j]++;
                }else{
                    t_vec[j]=0;
                }
            }
            ret=max(largestRectangleAreaQuicker(t_vec),ret);
        }
        return ret;
    }
};
int main (){
		
	return 0;
}
