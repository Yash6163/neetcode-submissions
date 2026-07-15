bool isvalid(int row,int col,vector<vector<char>>&board,char val){
    for(int i=0;i<board.size();i++){
        if(board[i][col]==val && i!=row)return false;
    }
    for(int i=0;i<board[0].size();i++){
        if(board[row][i]==val && i!=col)return false;
    }
    //getting the contributing matrix overall closest 
    int start_index=(row/3)*3;
    int start_col=(col/3)*3;
    for(int i=start_index;i<start_index+3;i++){
        for(int j=start_col;j<start_col+3;j++){
            if(board[i][j]==val && (i!=row || j!=col))return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.' && !isvalid(i,j,board,board[i][j]))return false;
            }
        }
        return true;
    }
};
