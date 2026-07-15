static bool cmp(vector<int>a,vector<int>b){
    if(a[0]==b[0])return a[1]<b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it : nums)mpp[it]++;
        vector<vector<int>>ans;
        for(auto it : mpp){
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>as;
        for(int i=0;i<k;i++){
            as.push_back(ans[i][1]);
        }
        return as;
    }
};
