---
title: AHP
date: 2021-03-30 21:52:34
tags: Math
mathjax: true
---
# 层次分析法 AHP

## 针对问题类型
适用于解决评价类问题
可以使用打分法解决评价类问题
{% asset_img pic1.png 打分表 %}

## 如何解决评价类问题
明确三个问题
1. 我们评价的目标
2. 为了达到这个目标有几种方案
3. 评价的准则、指标
---
## 搜索文献地址
[知网](https://www.cnki.net/)
[Google学术](https://scholar.google.com/ )
[百度学术](https://xueshu.baidu.com/)

## 如何确定指标权重及各项的分数
分而治之:
一次性考虑这五个指标之间的关系,往往考虑不周
解决方法:
两个两个指标进行比较,最终根据两两比较的结果来推算出权重。
{% asset_img pic2.png 层次分析法重要性表格 %}

## 如何处理填写的数据
表可以转化成一个5x5的方阵 记该方阵为A 对应元素为$a_{ij}$
1. $$ a_{ij}表示的意义是,与指标j相比,i的重要程度 $$
2. $$ 当i=j时,两个指标相同,因此同等重要记为1,这就解释了主对角线元素为1 $$
3. $$ a_{ij}>0且满足a_{ij} \times a_{ji}=1 (我们称满足这一条件的矩阵为正互反矩阵) $$
该矩阵就是层次分析法的判断矩阵

## 一致矩阵
** 判断矩阵可能存在Bug **
{% asset_img pic4.png 判断矩阵不一致的情况 %}
----
若正互反矩阵满足
$$a_{ij} \times a{jk} = a_{ik}$$
则该矩阵为一致矩阵
<font color="#ff0000">注意:在使用判断矩阵求权重之前,必须对其进行一致性检验</font>
----
$$
\begin{bmatrix}
a_{11} &a_{12} &\cdots &a_{1n} \\
a_{21} &a_{22} &\cdots &a_{2n} \\
\vdots &\vdots &\ddots &\vdots \\
a_{n1} &a_{n2} &\cdots &a_{nn} \\
\end{bmatrix}
$$
为一致矩阵的充要条件是
$$
\left\{
    \begin{array}
        \leftline 
        a_{ij} > 0\\
        a_{11}=a_{22}=\cdots=a_{nn}\\ 
        \begin{bmatrix}
            a_{i1},&a_{i2},&\cdots,&a_{in}
        \end{bmatrix}=k
        \begin{bmatrix}
            a_{11},&a_{12},&\cdots,&a_{1n}
        \end{bmatrix}
    \end{array}
\right .
$$
----
引理:A为n阶方阵,且r(A)=1,则A有一个特征值为tr(A),其余特征值均为0
因为一致矩阵的各行成比例,所以一致矩阵的秩一定为1
由引理可知:一致矩阵有一个特征值为m,其余特征值均为0
容易得到,特征值为n时,对应的特征向量刚好为
$$
k
\begin{bmatrix}
    \cfrac{1}{a_{11}},&\cfrac{1}{a_{12}},&\cdots,&\cfrac{1}{a_{1n}}
\end{bmatrix}
$$
----
引理:m阶正互反矩阵A为一致矩阵时当且仅当最大特征值入m=n
且当正互反矩阵A非一致时,一定满足入m>n

## 一致性检验
1. 计算一致性指标CI
$$
CI=\cfrac{\lambda_{max}-n}{n-1}
$$
2. 查找对应的平均一致性指标RI
{% asset_img pic5.png 平均一致性指标 %}
3. 计算一致性比例CR
$$
CR=\frac{CI}{CR}
$$

** 如果CR<0.1,则可认为判断矩阵的一致性可以接受;否则需要对判断矩阵进行修正 **

## 计算权重
### 一致矩阵
取出其中一列数据计算即可,则每一位的权重
$$
w_i=\frac{a_{i1}}{\sum\limits_{j=1}^na_{j1}}
$$

<h1>未完待续 37:53</h1>