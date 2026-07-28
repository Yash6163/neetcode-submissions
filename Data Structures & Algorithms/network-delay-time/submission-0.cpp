class Solution {
public:
    vector<int> dijkstra(vector<vector<vector<int>>>& adjls, int source) {

        vector<int> dist(adjls.size(), INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {

            int val = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (val > dist[node]) continue;

            for (auto it : adjls[node]) {

                if (dist[it[0]] > val + it[1]) {
                    dist[it[0]] = val + it[1];
                    pq.push({dist[it[0]], it[0]});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<vector<int>>> adjls(n + 1);

        for (auto it : times) {
            adjls[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist = dijkstra(adjls, k);

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};