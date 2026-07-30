class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        for(int i=0;i<points.size();i++){
            double dist=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({dist,i});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            int val=pq.top().second;
            ans.push_back(points[val]);
            pq.pop();
        }
        return ans;
    }
};
