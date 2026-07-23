class DisjointSet{
    public:
    vector<int>rank;
    vector<int>parent;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(parent[node]==node){
            return node; 
        }
        return parent[node]=find_parent(parent[node]);
    }
    void union_by_rank(int u,int v){
        int ult_u=find_parent(u);
        int ult_v=find_parent(v);
        if(ult_u==ult_v)return ;
        if(rank[ult_u]<rank[ult_v])parent[ult_u]=parent[ult_v];
        else if(rank[ult_u]>rank[ult_v])parent[ult_v]=parent[ult_u];
        else {
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            if(ds.find_parent(u)==ds.find_parent(v)){
                return {u,v};
            }
            ds.union_by_rank(u,v);
        }
        return {};
    }
};
