void find(vector<vector<int>>&ans,vector<bool>&take,vector<int>&nums,vector<int>&arr,int n){
        if(arr.size()==n){
            ans.push_back(arr);
            return ;
        }
    for(int i=0;i<n;i++){
        if(take[i]==true)continue;
        else{
            //pick n non pick condition 
            arr.push_back(nums[i]);
            take[i]=true;
            find(ans,take,nums,arr,n);
            arr.pop_back();
            take[i]=false;
        }
    }
    return;
}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>take(nums.size(),0);
        vector<vector<int>>ans;
        vector<int>arr;
        find(ans,take,nums,arr,nums.size());
        return ans;
    }
};
