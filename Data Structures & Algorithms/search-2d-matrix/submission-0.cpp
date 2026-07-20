class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {

        int n = arr.size();
        int m = arr[0].size();

        int l = 0, r = n - 1;
        while (l <= r) {

            int mid = (l + r) / 2;
            if (target < arr[mid][0])
                r = mid - 1;
            else if (target > arr[mid][m - 1])
                l = mid + 1;
            else {
               return binary_search(arr[mid].begin(), arr[mid].end(), target);
            }
        }

        return false;
    }
};