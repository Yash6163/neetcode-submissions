class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        vector<int>req;
        //store the required value in the reqv array nd the vlaue aval
        //at the mpp (map)
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
            req.push_back(target-nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mpp.find(req[i])!=mpp.end()&& mpp[req[i]] != i){
                ans.push_back(i);ans.push_back(mpp[req[i]]);
                break;
            }
        }
        return ans;
    }
};
