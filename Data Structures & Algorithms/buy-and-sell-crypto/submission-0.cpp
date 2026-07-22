class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bought = prices[0];
        int profit = 0;
        for(int i = 1;i<n;i++){
            if (prices[i]<=bought){
                bought = prices[i];
            }else{
                profit = max(prices[i]-bought,profit);
            }
        }
        return profit;
    }
};
