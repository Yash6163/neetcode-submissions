class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> vis(r, vector<int>(c, 0));

        //mark all the rotten ones
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==0){
                    vis[i][j]=1;
                }
            }
        }

        //now traverse bfs wise
        vector<int>m_row={+1,-1,0,0};
        vector<int>m_col={0,0,-1,+1};
        int min_time=0;
        while(!q.empty()){
            int time=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            min_time=max(min_time,time);

            for(int i=0;i<4;i++){

                int n_row = row + m_row[i];
                int n_col = col + m_col[i];

                if(n_row>=0 && n_row<grid.size() && n_col>=0 && n_col<grid[0].size() && grid[n_row][n_col]==1 ){
                    vis[n_row][n_col]=time+1;
                    q.push({time+1,{n_row,n_col}});
                    grid[n_row][n_col]=2;
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return min_time;
    }
};
