#include<iostream>
#include<algorithm>     //运用copy函数

using namespace std;

long long ans[25][25][25];
bool is_count[25][25][25]={0};

long long w(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        return w(20,20,20);
    }
    else if(a<b&&b<c){
        //w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)
        if(!is_count[a][b][c-1]){
            ans[a][b][c-1] = w(a,b,c-1);
            is_count[a][b][c-1] = true;
        }
        if(!is_count[a][b-1][c-1]){
            ans[a][b-1][c-1] = w(a,b-1,c-1);
            is_count[a][b-1][c-1] = true;
        }
        if(!is_count[a][b-1][c]){
            ans[a][b-1][c] = w(a,b-1,c);
            is_count[a][b-1][c] = true;
        }
        ans[a][b][c] = ans[a][b][c-1] + ans[a][b-1][c-1] - ans[a][b-1][c];
        is_count[a][b][c] = true;
        return ans[a][b][c];
    }
    else{
        //w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
        if(!is_count[a-1][b][c]){
            ans[a-1][b][c] = w(a-1,b,c);
            is_count[a-1][b][c] = true;
        }
        if(!is_count[a-1][b][c-1]){
            ans[a-1][b][c-1] = w(a-1,b,c-1);
            is_count[a-1][b][c-1] = true;
        }
        if(!is_count[a-1][b-1][c-1]){
            ans[a-1][b-1][c-1] = w(a-1,b-1,c-1);
            is_count[a-1][b-1][c-1] = true;
        }
        ans[a][b][c] = ans[a-1][b][c] + ans[a-1][b-1][c] + ans[a-1][b][c-1] - ans[a-1][b-1][c-1];
        is_count[a][b][c] = true;
        return ans[a][b][c];
    }
}


int main(){
    while (1)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        long long res = w(a,b,c);
        printf("w(%lld,%lld,%lld)=%lld\n",a,b,c,res);
        
    }
    
}
