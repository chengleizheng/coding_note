/*
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    bool is_done[11001][11001] = {false};
    int memo[11001][11001] = {0};
    //用memo记录最终的地毯编号
    int n;
    cin>>n;
    for(int t = 1;t<=n;t++){
        int a,b,g,k;
        cin>>a>>b>>g>>k;
        for(int i = a;i<=a+g;i++){
            for(int j = b;j<=b+k;j++){
                if(is_done[i][j] == true){
                    //若已经被覆盖
                    memo[i][j] = t;
                }else{
                    //若还未被覆盖
                    is_done[i][j] = true;
                    memo[i][j] = t;
                }

            }
        }
    }
    int x,y;
    cin>>x>>y;
    if(is_done[x][y]){
        cout<<memo[x][y]<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}
    */
//以上是喜提MLE的错误解法

#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 10010;
int a[MAXN],b[MAXN],g[MAXN],k[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    int x,y;
    cin>>x>>y;
    int res = -1;
    //在没有覆盖的情况下结果为-1
    for(int i=1;i<=n;i++){
        if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]){
            res = i;
        }
    }
    cout<<res<<endl;
    
    return 0;

}
