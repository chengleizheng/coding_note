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
