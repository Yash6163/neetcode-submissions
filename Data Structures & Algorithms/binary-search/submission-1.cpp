class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left=0,right=arr.size()-1;
        while(left<=right){
            int mid=right+left/2;
            if(arr[mid]>target)right=mid-1;
            else if(arr[mid]<target)left=mid+1;
            else return mid;
        }
        return -1;
    }
};
