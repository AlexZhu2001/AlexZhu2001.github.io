---
title: LeetCode.栈的最小值
date: 2021-04-15 13:48:14
tags: 
    - 算法 
    - 栈
---
# 栈的最小值
## 题目描述
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

## 实例

```c
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```
## 解题方法
维护两个栈 一个存放数据 一个存放当前最小值

## 代码
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> min;
    vector<int> vec;
    MinStack() {

    }

    void push(int x) {
        vec.push_back(x);
        if(min.size()==0) min.push_back(x);
        else {
            int l=min.at(min.size()-1);
            min.push_back(l>x?x:l);
        }
    }

    void pop() {
        vec.pop_back();
        min.pop_back();
    }

    int top() {
        int x=vec.at(vec.size()-1);
        return x;
    }

    int getMin() {
        return *(min.end()-1);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
