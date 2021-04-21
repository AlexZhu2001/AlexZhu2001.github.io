---
title: LeetCode-91.解码方法
date: 2021-04-21 13:19:49
tags:
    - 算法
    - 字符串
    - 动态规划
mathjax: true
---
# LeetCode-91.解码方法

## 问题描述
{% asset_img question.png question %}

## 思路及解决方法
动态规划 
设 $f_i$ 是 $s[1:i]$ 对应字符串对应的解码方法次数(下标从1开始)
对于 $f_i$
1. 只使用了一个字符 `s[i]` 解码 若$s[i] \neq 0$ 则$s[i]$一定与A~I中一个对应
    状态转移方程为:
    $$
    f_i = f_{i-1} \quad s[i] \neq 0
    $$
2. 使用了两个字符 `s[i]` 和 `s[i-1]` 此时$s[i-1] \neq 0$ 且s[i]和s[i-1]组成的整数必须小于26
    状态转移方程为:
    $$
    f_i = f_{i-2} \quad s[i-1] \neq 0 并且 10 \cdot s[i-1]+s[i] \leq 26
    $$
    需要$i>1$才能转移 

边界条件 $f_0=1$
**空字符串可以有 1 种解码方法 解码出一个空字符串**

注意到 $f_i$ 只与 $f_{i-1}$ 和 $f_{i-2}$ 有关 我们只用三个变量即可

注意:**C++下标从零开始 注意减去一**


```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int prev1=1,prev2=0,now=0; 
        /*
            prev1 -> f[i-1]
            prev2 -> f[i-2]
            now -> f[i]
        */
        for(int i=1;i<=n;i++){
            now=0;
            if(s[i-1]!='0'){
                now+=prev1;
            }
            if(i>1&&s[i-2]!='0'&&((s[i-2]-'0')*10+s[i-1]-'0')<=26){
                now+=prev2;
            }
            prev2=prev1;
            prev1=now;
        }
        return now;
    }
    
};
```
{% asset_img 1.png AC %}