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
	vector<vector<int>> threeSum(vector<int>& nums) {

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
