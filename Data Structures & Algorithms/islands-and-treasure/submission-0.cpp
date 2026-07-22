const int INF = 2147483647;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,INF));

        queue<pair<int,pair<int,int>>>q;
        //push all goals and unreachables
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==-1)vis[i][j]=-1;
                else if(grid[i][j]==0){
                    vis[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }

        //traverse from eavch goal to all the states

        vector<int>m_row={+1,-1,0,0};
        vector<int>m_col={0,0,+1,-1};
        while(!q.empty()){
            int dist=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            // traverse in all directions
            for(int i=0;i<4;i++){
                int n_row=row+m_row[i];
                int n_col=col+m_col[i];

                if(n_row>=0 && n_row<grid.size() && n_col>=0 && n_col<grid[0].size() && grid[n_row][n_col]==INF && vis[n_row][n_col]>dist+1){
                    vis[n_row][n_col]=dist+1;
                    q.push({dist+1,{n_row,n_col}});
                }
            }
        }
        grid=vis;
    }
};
