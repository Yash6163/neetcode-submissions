vector<int>next_smaller(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans;
    ans.push_back(n);
    st.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())ans.push_back(n);
        else ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int>prev_smaller(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans;
    ans.push_back(-1);
    st.push(0);

    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        vector<int>left=prev_smaller(arr);
        vector<int>right=next_smaller(arr);
        int n=arr.size();

        int max_area=INT_MIN;
        for(int i=0;i<n;i++){
            max_area=max(max_area,(right[i]-left[i]-1)*arr[i]);
        }
        return max_area;
    }
};
