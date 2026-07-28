void find(vector<vector<int>>&ans,vector<int>&nums,vector<int>&arr,int index,int n,int target){
    if(target<0)return ;
    if(index==n){
        if(target==0)ans.push_back(arr);
        return ;
    }
    //include state
    arr.push_back(nums[index]);
    find(ans,nums,arr,index+1,n,target-nums[index]);
    arr.pop_back();
    while(index<=n-2 && nums[index]==nums[index+1]){
        index++;
    }
    find(ans,nums,arr,index+1,n,target);
    return;
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>arr;
        find(ans,nums,arr,0,nums.size(),target);
        return ans;
    }
};
