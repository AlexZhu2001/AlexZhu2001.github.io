/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
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
// @lc code=end

