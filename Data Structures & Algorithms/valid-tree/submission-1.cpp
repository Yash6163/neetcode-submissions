bool dfs(vector<int>&vis,vector<vector<int>>&adjls,int node,int parent){

    vis[node]=1;
    for(auto it : adjls[node]){
        if(!vis[it]){
            if(!dfs(vis,adjls,it,node)){
                return false;
            }
        }
        else if (it!=parent){
            return false; //cycle hai hence not a valid tree
        }
    }
    return true; //no cycle
}
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<vector<int>>adjls(n);
        vector<int>vis(n,0);
        //make adjacency
        for(auto it : edges){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        //from adjacency traversal starts
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(vis,adjls,i,-1))return false;
            }
        }
        return true;
    }
};
