# 题目
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
```
输入: 123
输出: 321
```
示例 2:
```
输入: -123
输出: -321
```
示例 3:
```
输入: 120
输出: 21
```
注意:
```
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0
```
# 解答

```
class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        if(x<0)
        {
            x*=-1;
            flag=true;
        }
        long r=0;
        while(x)
        {
            r=r*10+(x%10);
            x=x/10;
            if(r>INT_MAX||r<INT_MIN)
            {
                r=0;
                break;
            }
        }
        if(flag)
        {
            r*=-1;   
        }
        return r;
    }
};
```
