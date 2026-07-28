void find(vector<vector<int>>&ans,vector<int>&nums,vector<int>&arr,int index,int n,int target){
    if(target<0)return ;
    if(index==n){
        if(target==0)ans.push_back(arr);
        return ;
    }
    //include state
    arr.push_back(nums[index]);
    find(ans,nums,arr,index,n,target-nums[index]);
    arr.pop_back();
    find(ans,nums,arr,index+1,n,target);
    return;
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        find(ans,nums,arr,0,nums.size(),target);
        return ans;
    }
};
