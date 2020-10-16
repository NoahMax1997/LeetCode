#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
//排序然后确保每一层的枚举数字不同就行 
class Solution { 
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
		//有两个样例错误
		vector<vector<int> > ret;
		vector<int> t_vec;
		sort(nums.begin(),nums.end());
		if(nums.size()<3) return ret;
		for(vector<int>::iterator it=nums.begin();it<nums.end();){
			while(it!=nums.begin()&&it<nums.end()&&*(it-1)==*it){//先判定迭代器是否越界 再取值 
				it++;//这个东西在增加 注意不让他越界 
			}
			if(it==nums.end()) break;
			t_vec.push_back(*it);
			it++;
			for(vector<int>::iterator jt=it;jt<nums.end();){
				while(jt!=it&&jt<nums.end()&&*(jt-1)==*jt){
					jt++;
				}
				if(jt==nums.end()) break;
				t_vec.push_back(*jt);
				jt++;
				for(vector<int>::iterator kt=jt;kt<nums.end();){
					while(kt!=jt&&kt<nums.end()&&*(kt-1)==*kt){
						kt++;
					}
					if(kt==nums.end()) break;
					t_vec.push_back(*kt);
					kt++;
//					if(t_vec.size()==3){
//						printf("%d %d %d\n",t_vec[0],t_vec[1],t_vec[2]);
//					}
					if(t_vec[0]+t_vec[1]+t_vec[2]==0){
						ret.push_back(t_vec);
					}
					t_vec.pop_back();
				}
				t_vec.pop_back();
			}
			t_vec.pop_back();
		}
		return ret;
    }
	
	vector<vector<int>> threeSumTwoPoint(vector<int>& nums){
		vector<vector<int>> ret;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			if(nums[i]>0){
				break;
			}
			if(i>0&&nums[i]==nums[i-1]){
				continue;
			}
			int left=i+1,right=nums.size()-1;
			while(left<right){
				if(nums[i]+nums[left]+nums[right]==0){
					ret.push_back({nums[i],nums[left],nums[right]});
					left++;
					right--;
					while(left<right&&nums[left]==nums[left-1]){
						left++;
					}
					while(left<right&&nums[right]==nums[right+1]){
						right--;
					}
				}
				else if(nums[i]+nums[left]+nums[right]>0){
					right--;
				}else if(nums[i]+nums[left]+nums[right]<0){
					left++;
				}
			}
		}
	}
	set<int> Set;
	void dfs(vector<vector<int>> &ret,vector<int>& nums,vector<int>& t_vec,int index){
		if(index>3){
			return;
		}
		if(index==3){
			int sum=0;
			for(auto i:t_vec){
				sum+=i;
			}
			if(sum==0)
				ret.push_back(t_vec);
		}
		else{
			for(int i=index;i<nums.size();i++){
				// if(Set.find(nums[i])!=Set.end()){
				// 	continue;
				// }
				if(i==0||nums[i-1]!=nums[i]){
					t_vec.push_back(nums[i]);
					// Set.insert(nums[i]);
					dfs(ret,nums,t_vec,index+1);
					t_vec.pop_back();
					// Set.erase(nums[i]);
				}
			}
		}
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		for(auto i:nums){
			cout<<i<<" ";
		}
		cout<<endl;
		vector<vector<int>> ret;
		vector<int> t_vec;
		dfs(ret,nums,t_vec,0);
		return ret;
	}
};
	
int main (){
	Solution a;
	vector<int> t;
	t.push_back(0);
	t.push_back(0);
	t.push_back(0);
	t.push_back(0);
	a.threeSum(t);
	return 0;
} 
