class Solution {
public:
    vector<vector<int>> dp;
    int d(int i, int canbuy, vector<int>& prices, int fee) {
        int n = prices.size();
        if(i >=n) return 0;
        if(dp[i][canbuy] != -1) return dp[i][canbuy];
        if(canbuy) { // 1 -> stay or buy
            dp[i][canbuy] = max(-prices[i]+d(i+1, 0, prices, fee), d(i+1, 1, prices, fee));
        }
        else{ //0 -> sell or stay
            dp[i][canbuy] = max(prices[i]-fee+d(i+1, 1, prices, fee), d(i+1, 0, prices, fee));
        }
        return dp[i][canbuy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        dp.assign(prices.size()+1, vector<int>(2, -1));    
    
        return d(0, 1, prices, fee);
    }
};