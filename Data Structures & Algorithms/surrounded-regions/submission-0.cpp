void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board){
    vis[row][col]=1;
    vector<int> mrow={+1,-1,0,0};
    vector<int> mcol={0,0,+1,-1};
    //call dfs if adjacent one is inside & unvisited & is a 'O'
    for(int i=0;i<4;i++){
        int crow=row+mrow[i];
        int ccol=col+mcol[i];
        if(crow>=0 && crow<board.size() && ccol>=0 && ccol<board[0].size() && vis[crow][ccol]==0 && board[crow][ccol]=='O'){
            dfs(crow,ccol,vis,board);
        }
    }
}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        //call for the row boundaries
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && visited[0][j]==0){
                dfs(0,j,visited,board);
            }
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                dfs(n-1,j,visited,board);
            }
        }
        //call for the column boundaries
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, visited, board);
            }
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) {
                dfs(i, m - 1, visited, board);
            }
        }
        //now flip all unvisited 'O' to 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};