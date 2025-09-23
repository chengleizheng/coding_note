#include<iostream>
#include<cstring>
using namespace std;

long long memo[21][21][21];
//用memo来记忆结果
bool computed[21][21][21];

long long w(long long a, long long b, long long c) {
    // 条件1：如果任一参数≤0，返回1
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    
    // 条件2：如果任一参数>20，转换为w(20,20,20)
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    
    // 检查是否已计算过
    if (computed[a][b][c]) {
        return memo[a][b][c];
    }
    
    // 标记为已计算
    computed[a][b][c] = true;
    
    // 条件3：a < b < c
    if (a < b && b < c) {
        memo[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    // 条件4：其他情况
    else {
        memo[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    
    return memo[a][b][c];
}

int main() {
    // 初始化记忆化数组
    memset(computed, false, sizeof(computed));
    
    long long a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        long long result = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, result);
    }
    
    return 0;
}
