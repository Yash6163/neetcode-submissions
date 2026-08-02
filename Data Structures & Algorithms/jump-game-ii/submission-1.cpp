class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;
        int jumps=0,currend=0,farthest=0;
        for(int i=0;i<n;i++){
            farthest=max(farthest,nums[i]+i);
            if(i==currend){
                jumps++;
                currend=farthest;
                if(currend>=n-1)break;
            }
        }
        return jumps;
    }
};
