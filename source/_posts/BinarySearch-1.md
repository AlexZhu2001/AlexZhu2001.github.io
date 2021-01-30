---
title: BinarySearch_1
date: 2021-01-24 16:49:35
tags: 
    - 算法
    - BinarySearch
---
# 二分查找-1
## 思路 1：在循环体中查找元素

#### 代码模板
```cpp
int bs(vector<T> &vec,T target){
    int l=0,r=vec.size()-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(vec[mid]==target)
            return mid;
        else if(vec[mid]<target)
            l=mid+1;
        else 
            r=mid-1;
    }
    return -1;
}
```
#### 复杂度分析：
* 时间复杂度 二分查找的时间复杂度是 O(log⁡N) 这里N是输入数组的长度
* 空间复杂度 由于二分查找算法在执行的过程中只使用到常数个临时变量 因此空间复杂度是 O(1)

#### 细节
1. 循环可以继续的条件 `left<=right` 表明区间仅剩一个元素时仍需继续查找 
2. 取中间值 `(l+r)/2`可能导致`l+r`发生溢出 所以使用`l+(r-l)/2`来防止溢出
3. 取中间值也可以向上取整

## 练习
{% asset_link 374.猜数字大小.cpp 374.猜数字大小.cpp %}

{% asset_link 704.二分查找.cpp 704.二分查找.cpp %}
