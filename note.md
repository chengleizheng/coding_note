+ 数据的种类记得辨别，有小数点记得用double

+ 判断质数的函数：

	```cpp
	bool is_prime(int n){
	  //判断是否是质数的函数
	  if(n<=1||(n%2==0&&n!=2)){
	      return false;
	  }
	  else if(n==2){
	      return true;
	  }
	  for(int i=3;i<=sqrt(n);i+=2){
	      if(n%i==0){
	          return false;
	      }
	  }
	  return true;
	}
	```

+ 运用memset来初始化各类数组 

	**1.基本语法**

	```cpp
	memset(指针, 值, 字节数)
	```

	**2.重要特性**

	**只能**安全地设置 0 和 -1：对于 int、long 等多字节类型
	可以设置任意值：对于 char、bool 等单字节类型

	**3.常见使用场景**

	 ```cpp
	// ✅ 正确用法
	int arr[100];
	memset(arr, 0, sizeof(arr));        // 初始化为0
	memset(arr, -1, sizeof(arr));       // 初始化为-1
	bool visited[100];
	memset(visited, false, sizeof(visited));  // false = 0
	memset(visited, true, sizeof(visited));   // true ≠ 0，但通常工作正常char str[100];
	memset(str, 'A', sizeof(str));      // 可以设置任意字符
	// ❌ 错误用法  
	int dp[100];
	memset(dp, 1, sizeof(dp));          // 想设置为1，实际设置为16843009替代方案
	当需要初始化为0或-1以外的值时：
	// 方法1：使用循环
	for (int i = 0; i < n; i++) {
	 arr[i] = 1;
	}
	// 方法2：使用fill函数（C++）
	fill(arr, arr + n, 1);
	// 方法3：初始化时直接赋值
	int arr[100] = {1}; 
	// 只有arr[0]=1，其余为0：
	//其他例子：三维数组
	bool computed[21][21][21];
	memset(computed, false, sizeof(computed));  // 全部设为false
	 ```

+ 回溯法

	**算法模版**

	```c
	void backtrack(参数) {
	    if (终止条件) {
	        收集结果;
	        return;
	    }
	    
	    for (所有选择) {
	        if (剪枝条件) continue;
	        做选择;
	        backtrack(新状态);
	        撤销选择;  // 关键
	    }
	}
	```

+ 递归和递推

	**以斐波那契数列求解对比**

	```c
	// 记忆化递归（递归+缓存）
	int memo[100];
	bool computed[100] = {false};
	int fibonacci_memo(int n) {
	    cout << "计算 F(" << n << ")";
	    if (computed[n]) {
	        cout << " (已缓存)" << endl;
	        return memo[n];
	    }
	    cout << endl;
	    
	    if (n <= 1) {
	        memo[n] = n;
	        computed[n] = true;
	        return n;
	    }
	    
	    memo[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2);
	    computed[n] = true;
	    return memo[n];
	}
	
	// 递推方法（动态规划）
	int fibonacci_iterative(int n) {
	    if (n <= 1) return n;
	    
	    vector<int> dp(n+1);
	    dp[0] = 0;
	    dp[1] = 1;
	    
	    cout << "递推过程：" << endl;
	    cout << "F(0) = " << dp[0] << endl;
	    cout << "F(1) = " << dp[1] << endl;
	    
	    for (int i = 2; i <= n; i++) {
	        dp[i] = dp[i-1] + dp[i-2];
	        cout << "F(" << i << ") = F(" << (i-1) << ") + F(" << (i-2) << ") = " << dp[i] << endl;
	    }
	    
	    return dp[n];
	}
	```
 + **vscode异常**
	Exception has occurred. **Arithmetic exception**-算数异常，通常是分母为零
 + fib数列记忆优化
   ```c
	long long ans[30000010];
   long long fib(long long n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    else{
        ans[n] = fib(n-1)+fib(n-2);
        return ans[n];
    }
	}
	```
	
