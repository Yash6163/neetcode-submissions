class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //kahn algo here
        vector<vector<int>>adjls(n);
        vector<int>ans;
        vector<int>indegree(n,0);
        //prepare adjls and indegree
        for(auto it : pre){
            int source=it[1];
            int dest=it[0];
            adjls[source].push_back(dest);
            indegree[dest]++;

        }
        queue<int>q;
        //push all 0 indegree in the queue
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        //traverse the queue
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it : adjls[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
                
            }
        }
        if(ans.size()==n)return true;
        return false;
    }
};
