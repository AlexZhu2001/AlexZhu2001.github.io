---
title: BinarySearch-2
date: 2021-01-30 14:37:46
tags: 算法
---
# 二分查找-2
## 思路二 在循环体中排除

#### 代码模板
```cpp
int bs(vector<T> nums,T target){
    int l=0,r=nums.size()-1,mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(nums[mid]<target)
            l=mid+1;
        else r=mid;
    }
    return l;
}
```

## 细节分析
* 循环退出条件`l<r`
* 边界写法 
    * `r = mid` 和 `l = mid + 1` 和 `int mid = l + (r - l) / 2;` 一定是配对出现的；
    * `r = mid - 1` 和 `l = mid` 和 `int mid = l + (r - l + 1) / 2;` 一定是配对出现的。

## 适用范围
这种二分查找的思路，对于查找边界问题，会使得思考的过程变得简单。

## 练习

1. ### 搜索插入位置
[题目描述](https://leetcode-cn.com/problems/search-insert-position/description/)
#### 解题思路
首先 题目未说明数组是否为空 先判断是否为空
如果最后一个元素小于目标值 则应返回最后一个元素的下标加一 也即数组长度
其他情况可利用如上方法二分查找即可
#### 代码
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};
```
{% asset_link 35.搜索插入位置.cpp 35.搜索插入位置 %}
-------
2. 