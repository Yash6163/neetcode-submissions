class Solution {
public:
    int findMin(vector<int> &arr) {
        int l=0,r=arr.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            //agar mid bda h toh search in left
            if(arr[mid]>arr[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return arr[l];
    }
};
