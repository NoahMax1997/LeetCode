#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    template<typename T>
    void MyPrint(T &t){
        cout<<"Myprint:"<<endl;
        for(auto i : t){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int largestRectangleAreaForce(vector<int>& heights) {
        //time over
        vector<int> t_height=heights;
        sort(t_height.begin(),t_height.end(),greater<int>());
        set<int> Set;
        for(auto i:t_height){
            Set.insert(i);
        }
        int ret=0;
        for(auto i=Set.begin();i!=Set.end();i++){
            int sum=0,tmp=*i;
            for(int j=0;j<heights.size();j++){
                if(tmp<=heights[j]){
                    sum++;
                }else{
                    if(sum*tmp>ret){
                        ret=sum*tmp;
                    }
                    sum=0;
                }
            }
            if(sum*tmp>ret){
                ret=sum*tmp;
            }
        }
        return ret;
    }
    int largestRectangleAreaQuick(vector<int>& heights) {
        int ret=0;
        vector<int> left_vec(heights.size()),right_vec(heights.size(),heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            if(st.empty()||heights[i]>heights[st.top()]){
                st.push(i);
                left_vec[i]=i-1;
            }else{
                while(!st.empty()&&heights[i]<=heights[st.top()]){
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
        stack<int>().swap(st);
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty()||heights[i]>heights[st.top()]){
                st.push(i);
                right_vec[i]=i+1;
            }else{
                while(!st.empty()&&heights[i]<=heights[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    right_vec[i]=heights.size();
                }else{
                    right_vec[i]=st.top();
                }
                st.push(i);
            }
        }
        MyPrint(left_vec);
        MyPrint(right_vec);
        for(int i=0;i<heights.size();i++){
            if(heights[i]*(right_vec[i]-left_vec[i]-1)>ret){
                ret=heights[i]*(right_vec[i]-left_vec[i]-1);
            }
        }
        return ret;
    }
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
        MyPrint(left_vec);
        MyPrint(right_vec);
        for(int i=0;i<heights.size();i++){
            if(heights[i]*(right_vec[i]-left_vec[i]-1)>ret){
                ret=heights[i]*(right_vec[i]-left_vec[i]-1);
            }
        }
        return ret;
    }
};
int main (){
	Solution s;
    vector<int> num={2,1,5,6,2,3};
    cout<<s.largestRectangleAreaQuicker(num);

    system("pause");
	return 0;
}
