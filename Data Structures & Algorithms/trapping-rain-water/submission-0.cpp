class Solution {
public:
    int trap(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,heights[l]);
            rmax=max(rmax,heights[r]);
            if(lmax>rmax){
                ans+=(rmax-heights[r]);
                r--;
            }
            else {
                ans+=(lmax-heights[l]);
                l++;
            }
        }
        return ans;
    }
};
