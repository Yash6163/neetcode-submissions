class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int length=1,n=nums.size(),maxlen=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i])continue;
            if(nums[i-1]+1==nums[i])length++;
            else length=1;
            maxlen=max(maxlen,length);
        }
        return maxlen;
    }
};
