---
title: validTicTacToe
date: 2021-01-30 14:00:59
tags: 算法
---
# LeetCode 794 有效的井字游戏
## 题目描述
用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

游戏该板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：
* 玩家轮流将字符放入空位（" "）中。
* 第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
* “X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
* 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
* 当所有位置非空时，也算为游戏结束。
* 如果游戏结束，玩家不允许再放置字符。

```python
示例 1:
输入: board = ["O  ", "   ", "   "]
输出: false
解释: 第一个玩家总是放置“X”。

示例 2:
输入: board = ["XOX", " X ", "   "]
输出: false
解释: 玩家应该是轮流放置的。

示例 3:
输入: board = ["XXX", "   ", "OOO"]
输出: false

示例 4:
输入: board = ["XOX", "O O", "XOX"]
输出: true
```
说明:

* 游戏板 `board` 是长度为 3 的字符串数组，其中每个字符串 `board[i]` 的长度为 3。
* `board[i][j]` 是集合 `{" ", "X", "O"}` 中的一个字符。

## 解题思路
首先 由于放置`X`先于`O` 则`X`的数量大于等于`O`的数量，且之多比`O`多一个

如满足以上条件，分析可能的局面如下四种
* 游戏结束后没有赢家
* 执`X`者获胜 此时`X`数量比`O`多一个
* 执`X`者获胜 此时`X`数量与`O`相等
* 两个人都赢 此情况违背了规则

所以可使用一个函数判断属于哪种局面，并得到结果

## 代码
```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x=0,o=0;
        for(auto i:board){
            for(auto j:i){
                if(j=='X') x++;
                else if(j=='O') o++;       
            }
        }
        if(x-o>1||x-o<0) return false;
        int res=winer(board);
        switch (res)
        {
        case 0:
            return true;
        case 1:
            return (x-o)==1;
        case 2:
            return x==o;
        case 3:
            return false;
        }
        return false;
    }
    int winer(vector<string>& board){
        bool xW=false,oW=false;
        for(auto i : board){
            if(i=="XXX"||i=="OOO"){
                i[0]=='X'?xW=true:oW=true;
            }
        }
        for(int i=0;i<3;i++){
            if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=' ')
                board[0][i]=='X'?xW=true:oW=true;
        }
        if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' '){
            board[0][0]=='X'?xW=true:oW=true;
        }
        if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' '){
            board[1][1]=='X'?xW=true:oW=true;
        }
        if(oW&&xW) return 3;
        if(!(oW||xW)) return 0;
        return xW?1:2; 
    }
};
```
{% asset_link 794.有效的井字游戏.cpp 794.有效的井字游戏.cpp %}