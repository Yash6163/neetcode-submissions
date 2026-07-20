int find_time(vector<int>&arr,int t){
    int total_time=0;
    for(auto it : arr){
        total_time+=((it+t-1)/t);
    }
    return total_time;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int min_time=INT_MAX;
        while(l<=r){
            int mid=(r+l)/2;
            int time=find_time(piles,mid);
            if(time>h)l=mid+1;
            else if (time<=h){
                min_time=mid;
                r=mid-1;
            }
        }
        return min_time;
    }
};
