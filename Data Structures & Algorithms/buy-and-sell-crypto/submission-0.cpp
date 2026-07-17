class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_price=INT_MAX,max_price=INT_MIN;
        for(int i=0;i<n;i++){
            min_price=min(min_price,prices[i]);
            max_price=max(max_price,abs(min_price-prices[i]));
        }
        return max_price;
    }
};
