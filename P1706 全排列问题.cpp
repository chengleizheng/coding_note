#include<iostream>
#include<algorithm>     //运用copy函数

using namespace std;

int n;
int used[15] = {0};       //used[i]用于标注编号为i的元素是否用过
int res[15] = {0};        //编号从1开始，表示已加入列中的元素

void dfs(int k){
    //此处k表示已经排好的层数，从1计
    if(k == n){
        for(int i=1;i<=n;i++){
            printf("%5d",res[i]);
        }
        cout<<endl;
        return;
    }
    else{
        for(int i = 1;i<=n;i++){
            if(used[i]==1){
                continue;
            }
            else{
                //进入else说明i还没有用过
                res[k+1] = i;
                used[i] = 1;
                dfs(k+1);
                used[i] = 0;      //回溯
            }
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}
