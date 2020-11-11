#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int total=0,best=0,best1=0,best2=0,limit=-1;
    void dfs(vector<int>& prices,int index){
        //time over
        if(index<=limit){
            return;
        }
        for(int i=index+1;i<prices.size();i++){
            if(i<=limit){
                continue;
            }   
            if(total==0&&prices[i]-prices[index]>0){
                total++;
                limit=i;
                best1=prices[i]-prices[index];
                if(best1>best){
                    best=best1;
                }
                // cout<<"one:"<<index<<" "<<i<<" "<<best1<<endl;
                for(int i=0;i<prices.size();i++){
                    dfs(prices,i);
                }
                total--;
                limit=-1;
            }else if(total==1&&prices[i]-prices[index]>0){
                if(best1+prices[i]-prices[index]>best){
                    best=best1+prices[i]-prices[index];
                    // cout<<"two:"<<index<<" "<<i<<" "<<best<<endl;
                }
            }
        }
    }
    int maxProfit1(vector<int>& prices) {
        for(int i=0;i<prices.size();i++){
            dfs(prices,i);
        }
        return best;
    }
    int maxProfit(vector<int>& prices) {
        int maxProfit1[100005]={0},maxProfit2[100005]={0},size=prices.size();
        int min_price=prices[0],max_price=prices[size-1],max_pro1=0,max_pro2=0;
        for(int i=0;i<size;i++){
            if(min_price>prices[i]){
                min_price=prices[i];
            }
            else if(prices[i]-min_price>max_pro1){
                max_pro1=prices[i]-min_price;
            }
            maxProfit1[i]=max_pro1;
            if(max_price<prices[size-i-1]){
                max_price=prices[size-i-1];
            }else if(max_price-prices[size-i-1]>max_pro2){
                max_pro2=max_price-prices[size-i-1];
            }
            maxProfit2[size-i-1]=max_pro2;
        }
        int ret=0;
        for(int i=0;i<size;i++){
            ret=max(maxProfit2[i]+maxProfit1[i],ret);
        }
        return ret;
    }
};
int main (){

    return 0;
}