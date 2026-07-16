class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int lmax=INT_MIN,rmax=INT_MIN,ans=INT_MIN;
        while(l<r){
            lmax=max(lmax,heights[l]);
            rmax=max(rmax,heights[r]);
            ans=max(ans,min(lmax,rmax)*(r-l));
            if(lmax>rmax)r--;
            else l++;
        }
        return ans;
    }
};
