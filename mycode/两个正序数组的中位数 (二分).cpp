#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int flag=1,rmin1=INT_MAX,lmax1=INT_MIN,rmin2=INT_MAX,lmax2=INT_MIN;
    	int size1=nums1.size(),size2=nums2.size(),size=size1+size2;
    	int k;
    	if(nums1.size()>nums2.size()){
    		return	findMedianSortedArrays(nums2,nums1);
		}
    	if(size==1){
    		return (double)(nums1.size()==0)?nums2[0]:nums1[0];
		}
    	if(size%2==0){
    		k=size/2;
		}else{
			k=size/2+1;
		}
    	
    	int c1=0,c2=k-c1;
    	while(1){
    		lmax1=(c1==0)?INT_MIN:nums1[(c1-1)<nums1.size()?c1-1:nums1.size()-1];
    		rmin1=(c1>=size1)?INT_MAX:nums1[c1];
    		lmax2=(c2==0)?INT_MIN:nums2[(c2-1)<nums2.size()?c2-1:nums2.size()-1];
    		rmin2=(c2>=size2)?INT_MAX:nums2[c2];
    		if(lmax1<=rmin2&&lmax2<=rmin1){
    			 break;
			}else if(lmax1<rmin2&&lmax2>rmin1){
				c1++,c2--;
			}else if(lmax1>rmin2&&lmax2<rmin1){
				c1--,c2++;
			}
		}
		if(size%2==0){
    		return (max(lmax1,lmax2)+min(rmin1,rmin2))/2.0;
		}else{
			return max(lmax1,lmax2);
		}
		return 0;
    }
};
int main (){
		
	return 0;
}
