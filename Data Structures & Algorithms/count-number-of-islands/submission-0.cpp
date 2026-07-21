void dfs(vector<vector<int>>&vis,vector<vector<char>>&grid,int row,int col){
    vis[row][col]=1;
    vector<int>m_row={+1,-1,0,0};
    vector<int>m_col={0,0,-1,+1};
    for(int i=0;i<4;i++){
        int n_row=row+m_row[i];
        int n_col=col+m_col[i];

        if(n_row>=0 && n_row<grid.size() && n_col>=0 && n_col<grid[0].size() && grid[n_row][n_col]=='1' && vis[n_row][n_col]==0){
            dfs(vis,grid,n_row,n_col);
        }
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    island++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return island;
    }
};
