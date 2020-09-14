#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trapForce(vector<int>& height) {
        //time over
        int size=height.size(),sum=0;
        for(int i=1;i<size-1;i++){
            int left=i,right=i,left_max=0,right_max=0;
            while(left>=0){
                left_max=max(left_max,height[left]);
                left--;
            }
            while(right<size){
                right_max=max(right_max,height[right]);
                right++;
            }
            sum+=min(left_max,right_max)-height[i];
        }
        return sum;
    }
    int trapSaveMax(vector<int>& height) {
        //o(n)
        int ret=0,size=height.size();
        if(size<3){
            return 0;
        }
        vector<int> left_max(size),right_max(size);
        left_max[0]=height[0],right_max[size-1]=height[size-1];
        for(int i=1;i<size;i++){
            left_max[i]=max(left_max[i-1],height[i]);
        }
        for(int i=size-2;i>=0;i--){
            right_max[i]=max(right_max[i+1],height[i]);
        }
        for(int i=1;i<size-1;i++){
            ret+=min(left_max[i],right_max[i])-height[i];
        }
        return ret;
    }
    int trapByStack(vector<int>& height) {
        //o(n)
        stack<int> st;
        int cur=0,size=height.size(),ret=0;
        while(cur<size){
            while(!st.empty()&&height[cur]>height[st.top()]){
                int top=st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int dis=cur-st.top()-1;
                ret+=dis*(min(height[st.top()],height[cur])-height[top]);
            }
            st.push(cur);
            cur++;
        }
        return ret;
    }
    int trap(vector<int>& height) {
        return trapByStack(height);
        // return trapSaveMax(height);
    }
};
int main()
{
    Solution a;
    system("pause");
    return 0;
}