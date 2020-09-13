#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    void jump(vector<int>& nums,int index,int &sum,int &ret) {
        int tmp=nums[index]>nums.size()-index-1?nums.size()-index-1:nums[index];
        if(sum>ret){
            return;
        }
        if(index==nums.size()-1){
            if(sum<ret){
                ret=sum;
            }
        }
        for(int i=1;i<=tmp;i++){
            if(index+i>=nums.size()-1){
                sum+=1;
                if(sum<ret){
                    ret=sum;
                }
                break;
            }else if(index+i+nums[index+i]>=nums.size()-1){
                sum+=2;
                if(sum<ret){
                    ret=sum;
                }
            }
            else{
                sum++;
                jump(nums,index+i,sum,ret);
                sum--;
            }
        }
    }
    int jumpGreedy(vector<int> &nums){
        int end=0,position=0,ret=0;
        for(int i=0;i<nums.size()-1;i++){
            if(position>=i){
                position=position>i+nums[i]?position:i+nums[i];
                if(end==i){
                    end=position;
                    ret++;
                }
            }
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        int sum=0,ret=INT_MAX;
        jump(nums,0,sum,ret);
        return ret;
    }

};	
int main (){
	Solution a;
	return 0;
} 
