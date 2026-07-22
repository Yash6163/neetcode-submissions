void dfs(vector<int>&vis,vector<vector<int>>&adjls,int node){
    vis[node]=1;
    for(auto it : adjls[node]){
        if(!vis[it])dfs(vis,adjls,it);
    }
}
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjls(n);
        for(auto it : edges){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        //traverse
        vector<int>vis(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(vis,adjls,i);
                components++;
            }
        }
        return components;
    }
};
