class Solution {
public:
    vector<int> d;
    
    void dp(vector<int>& cost) {
        d[0] = cost[0];
        d[1] = cost[1];
        if(cost.size() == 2){
            d[2] = min(d[1], d[0]);
        }
        else{
            for(int i=2; i != cost.size(); i++){
                d[i] = min(d[i-2] + cost[i], d[i-1]+cost[i]);
            }
            d[cost.size()] = min(d[cost.size()-1], d[cost.size()-2]);
        }
    }

    int minCostClimbingStairs(vector<int>& cost) {
        d.assign(cost.size()+1, 0);
        dp(cost);
        return d[cost.size()];
    }
};