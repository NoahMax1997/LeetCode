#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int i=0,j=0;
    	int sum=nums1.size()+nums2.size();
    	if(nums1.size()==0){
    		if(sum%2==0){
    			return (double)(nums2[sum/2]+nums2[sum/2-1])/2;
			}else{
				return (double)(nums2[sum/2]);
			}
    	}
    	if(nums2.size()==0){
    		if(sum%2==0){
    			return (double)(nums1[sum/2]+nums1[sum/2-1])/2;
			}else{
				return (double)(nums1[sum/2]);
			}
    	}
        while(i<nums1.size()||j<nums2.size()){
        	if(i+j+1==sum/2){
        		if(sum%2==0){
        			//找出nums[i] nums[j]  nums[i+1] nums[j+1] 顺便确保不数组越界 
        			if(i+1==nums1.size()&&j+1==nums2.size()){
        				return (double)(nums2[j]+nums1[i])/2;
					}
        			else if(i+1==nums1.size()){
        				if(nums1[i]<nums2[j+1]){
        					return (double)(nums2[j]+nums1[i])/2;
						}else{
							return (double)(nums2[j]+nums2[j+1])/2;
						}
					}else if(j+1==nums2.size()){
						if(nums2[j]<nums1[i+1]){
        					return (double)(nums2[j]+nums1[i])/2;
						}else{
							return (double)(nums1[i]+nums1[i+1])/2;
						}
					}else{
						if(nums1[i+1]<nums2[j]){
							return (double)(nums1[i+1]+nums1[i])/2;
						}else if(nums1[i]>nums2[j+1]){
							return (double)(nums2[j+1]+nums2[j])/2;
						}else{
							return (double)(nums2[j]+nums1[i])/2;
						}
					}
				}else{
					if(i+1==nums1.size()&&j+1==nums2.size()){
        				return (double)(nums2[j]+nums1[i])/2;
        				if(nums1[i]<nums2[j]){
	        				return (double)(nums2[j]);
						}else{
							return (double)(nums1[i]);
						}	
					}else if(i+1==nums1.size()){
						if(nums1[i]<nums2[j]){
							return (double)nums2[j];
						}else{
							return min(nums1[i],nums2[j+1]);
						}
					}else if(j+1==nums2.size()){
						if(nums2[j]<nums1[i]){
							return (double)nums1[i];
						}else{
							return min(nums2[j],nums1[i+1]);
						}
					}else{
						
					}
		
				}
			}
        	if(nums1[i]>nums2[j]){
        		j++;
			}else{
				i++;
			}
		}
		return 0;
    }
};
int main (){
		
	return 0;
}
