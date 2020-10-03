#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
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
};
int main (){
		
	return 0;
}
