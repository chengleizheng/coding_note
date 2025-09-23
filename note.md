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
# memset 函数详细用法指南

## 基本介绍

`memset` 是 C/C++ 中一个非常实用的内存操作函数，用于将一段内存设置为指定的值。

## 基本语法

```cpp
#include <cstring>  // 必须包含这个头文件

memset(ptr, value, size);
```

**参数说明：**
- `ptr`：指向要设置的内存块的指针
- `value`：要设置的值（0-255）
- `size`：要设置的字节数

## 核心特性

### 重要特性
- **按字节设置**：memset 是按字节操作的，这很重要！
- **只能安全地设置 0 和 -1**：对于 int、long 等多字节类型
- **可以设置任意值**：对于 char、bool 等单字节类型

### 为什么只能用 0 和 -1？

以 int 类型为例（4字节）：

| 操作 | 每个字节的值 | 二进制表示 | 最终结果 |
|------|-------------|------------|----------|
| `memset(arr, 0, sizeof(arr))` | 0 | `00000000 00000000 00000000 00000000` | 0 |
| `memset(arr, -1, sizeof(arr))` | 255 | `11111111 11111111 11111111 11111111` | -1 |
| `memset(arr, 1, sizeof(arr))` | 1 | `00000001 00000001 00000001 00000001` | 16843009 |

## 常用示例

### 1. 数组初始化为0

```cpp
int arr[10];
memset(arr, 0, sizeof(arr));
// 结果: 0 0 0 0 0 0 0 0 0 0
```

### 2. 数组初始化为-1（常用于初始化为无效值）

```cpp
int arr[5];
memset(arr, -1, sizeof(arr));
// 结果: -1 -1 -1 -1 -1
```

### 3. 二维数组初始化

```cpp
int matrix[3][4];
memset(matrix, 0, sizeof(matrix));
// 整个矩阵都被初始化为0
```

### 4. bool数组初始化

```cpp
bool visited[8];
memset(visited, false, sizeof(visited));  // 初始化为false
// 结果: false false false false false false false false

memset(visited, true, sizeof(visited));   // 初始化为true
// 结果: true true true true true true true true
```

### 5. 字符数组初始化

```cpp
char str[20];
memset(str, 'A', sizeof(str) - 1);  // 填充为'A'，保留最后一个位置
str[19] = '\0';  // 手动添加字符串结束符
// 结果: "AAAAAAAAAAAAAAAAAAA"
```

## 正确用法 vs 错误用法

### ✅ 正确用法

```cpp
// 初始化为0
int arr[100];
memset(arr, 0, sizeof(arr));

// 初始化为-1
memset(arr, -1, sizeof(arr));

// bool数组
bool visited[100];
memset(visited, false, sizeof(visited));

// 字符数组
char str[100];
memset(str, 'A', sizeof(str));
```

### ❌ 错误用法

```cpp
// 想初始化int数组为1，但实际结果是16843009
int dp[100];
memset(dp, 1, sizeof(dp));  // 错误！
```

**错误原因：** memset按字节设置，`1` 被设置到每个字节上，对于4字节的int，结果是 `00000001 00000001 00000001 00000001`，转换为十进制就是16843009。

## 替代方案

当需要初始化为0或-1以外的值时：

### 方法1：使用循环
```cpp
int arr[100];
for (int i = 0; i < 100; i++) {
    arr[i] = 1;
}
```

### 方法2：使用fill函数（C++）
```cpp
int arr[100];
fill(arr, arr + 100, 1);
```

### 方法3：初始化时直接赋值
```cpp
int arr[100] = {1};  // 只有arr[0]=1，其余为0
int arr[100] = {};   // 全部初始化为0
```

## 算法竞赛中的常用模式

```cpp
// 1. 初始化visited数组
bool vis[1005];
memset(vis, false, sizeof(vis));

// 2. 初始化距离数组为无穷大（用-1表示）
int dist[1005];
memset(dist, -1, sizeof(dist));

// 3. 初始化dp数组
int dp[105][105];
memset(dp, 0, sizeof(dp));

// 4. 初始化邻接矩阵
int graph[505][505];
memset(graph, 0, sizeof(graph));
```

## 注意事项

1. **必须包含头文件**：`#include <cstring>`
2. **只对0和-1安全**：对于多字节数据类型
3. **按字节操作**：理解这一点很重要
4. **sizeof的使用**：确保使用正确的大小
5. **字符串处理**：记得手动添加'\0'结束符

## 总结

`memset` 是一个强大的内存初始化工具，在算法竞赛和日常编程中都非常实用。记住它的核心特性：按字节设置，只对0和-1完全安全，就能避免大部分使用错误。对于其他值的初始化，建议使用循环或其他专门的函数。
