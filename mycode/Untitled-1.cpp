#include <iostream>
#include <set>
using namespace std;
char a[100][100];
bool isOk(const int &n,int &i,int &j){
    bool ret=false;
    if(i==0&&j==0||i==n-1&&j==n-1||i==0&&j==n-1||i==n-1&&j==0){
        ret=true;
    }else{
        int left=j-1,right=j+1,up=i-1,down=i+1,sum=0;
        if(left>=0&& a[i][left]=='#'){
            sum++;
        }
        if(right<n&&a[i][right]=='#'){
            sum++;
        }
        if(up>=0&&a[up][j]=='#'){
            sum++;
        }
        if(down<n&&a[down][j]=='#'){
            sum++;
        }
        if(sum<2){
            ret=true;
        }
    }
    return ret;
}
void print(const int &n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
int main (){
    int n;
    cin>>n;
    set<int> t_set;
    while(n--){
        int t,sum=0,ii=0,jj=0,direction=0;
        cin>>t;
        sum=t*t;
        // for(int i=0;i<t;i++){
        //     for(int j=0;j<t;j++){
        //         a[i][j]='#';
        //     }
        // }
        for(int i=0;i<sum;i++){
            if(direction==0){
                //right
                while(jj>=0&&jj<t&&t_set.find(ii*t+jj)==t_set.end()){
                    if(isOk(t,ii,jj)){
                        a[ii][jj]='#';
                    }
                    t_set.insert(ii*t+jj);
                    jj++;
                }
                direction=1;
            }else if(direction==1){
                //down
                while(ii>=0&&ii<t&&t_set.find(ii*t+jj)==t_set.end()){
                    if(isOk(t,ii,jj)){
                        a[ii][jj]='#';
                    }
                    t_set.insert(ii*t+jj);
                    ii++;
                }
                direction=2;
            }
            else if(direction==2){
                //left
                while(jj>=0&&jj<t&&t_set.find(ii*t+jj)==t_set.end()){
                    if(isOk(t,ii,jj)){
                        a[ii][jj]='#';
                    }
                    t_set.insert(ii*t+jj);
                    jj--;
                }
                direction=3;
            }
            else if(ii>=0&&direction==3){
                //up
                while(t_set.find(ii*t+jj)==t_set.end()){
                    if(isOk(t,ii,jj)){
                        a[ii][jj]='#';
                    }
                    t_set.insert(ii*t+jj);
                    ii--;
                }
                direction=0;
            }
        }
        print(t);
    }
    system("pause");
    return 0;
}