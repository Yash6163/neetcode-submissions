void find(vector<vector<int>>&ans,vector<int>&nums,vector<int>&arr,int index,int n){
    if(index==n){
        ans.push_back(arr);
        return ;
    }
    //include state
    arr.push_back(nums[index]);
    find(ans,nums,arr,index+1,n);
    arr.pop_back();
    find(ans,nums,arr,index+1,n);
    return;
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        find(ans,nums,arr,0,nums.size());
        return ans;
    }
};
