class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;

        int curbuy, curnot, aheadbuy, aheadnot;
        aheadbuy = 0;
        aheadnot = 0;

        for(int i=prices.size()-1; i>=0; i--) {
            curbuy = max(-prices[i] + aheadnot, 0 + aheadbuy);
            curnot = max(prices[i] - fee + aheadbuy, 0 + aheadnot);
            aheadbuy = curbuy;
            aheadnot = curnot;
        }

        return aheadbuy;
    }
};