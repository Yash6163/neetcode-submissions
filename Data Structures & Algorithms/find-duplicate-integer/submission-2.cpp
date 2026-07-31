class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(auto it : nums)hash[it]++;
        for(int i=1;i<=n;i++){
            if(hash[i]>1)return i;
        }
        return 0;
    }
};
