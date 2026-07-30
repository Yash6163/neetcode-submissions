class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones)pq.push(it);

        //now remove the 2's until the element left is 1
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            //now add back
            if(first!=second){
                pq.push(abs(first-second));
            }
            else{
                pq.push(0);
            }
        }
        return pq.top();
    }
};
