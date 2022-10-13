class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,i=0;
        for(int j=1; j<prices.size(); j++){
            if(prices[i]>prices[j])
                i=j;
            if(prices[j]-prices[i]>profit)
                profit=prices[j]-prices[i];
        }
        return profit;
    }
};