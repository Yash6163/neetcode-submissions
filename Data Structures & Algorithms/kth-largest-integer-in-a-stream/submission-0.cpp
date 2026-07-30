class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k1, vector<int>& nums1) {
        k=k1;
        for(auto it: nums1)pq.push(it);
    }
    int add(int val) {
        pq.push(val);
        while(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};
