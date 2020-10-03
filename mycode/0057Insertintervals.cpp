#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
//the same as 56
class Solution {
public:
    struct Node
    {
        int left;
        int right;
    };
    static bool cmp(Node a,Node b){
        return a.left<b.left;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        vector<Node> t_intervals;
        for(int i=0;i<intervals.size();i++){
            Node a;
            a.left=intervals[i][0];
            a.right=intervals[i][1];
            t_intervals.push_back(a);
        }
        // cout<<t_intervals.size()<<endl;
        sort(t_intervals.begin(),t_intervals.end(),cmp);
        // cout<<t_intervals.size()<<endl;
        for(int i=0;i<t_intervals.size();i++){
            // cout<<t_intervals[i].left<<" "<<t_intervals[i].right<<endl;
            if(ret.size()==0){
                vector<int> t;
                t.push_back(t_intervals[i].left);
                t.push_back(t_intervals[i].right);
                ret.push_back(t);
            }else{
                vector<int> &t_vec=ret.back();
                //[1,4] [2,3]
                // if(t_intervals[i].left<=t_vec[1])
                if(t_intervals[i].left<=t_vec[1]&&t_vec[1]<=t_intervals[i].right){
                    t_vec[1]=t_intervals[i].right;
                }else if(t_intervals[i].left>t_vec[1]){
                    vector<int> t;
                    t.push_back(t_intervals[i].left);
                    t.push_back(t_intervals[i].right);
                    ret.push_back(t);
                }
            }
        }
        return ret;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(),intervals.end());//amazing i had never known this operator of sort vector
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals[i].size();j++){
                cout<<intervals[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<int> t;
        t.push_back(newInterval[0]);
        t.push_back(newInterval[1]);
        intervals.push_back(t);
        return merge(intervals);
    }
};
int main (){
	Solution a;
    vector<vector<int>> t={{1,3},{2,6},{8,10},{15,18},{4,6}};
    vector<int> p;
    a.insert(t,p);
    // a.merge(t);
    system("pause");
	return 0;
} 