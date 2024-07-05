class Solution {
public:    
    vector<int> dp;

    void dy_pro(vector<int>& n){
        dp.assign(n.size(), 0);
        dp[0] = n[0];
        dp[1] = max(n[1], n[0]);
        for(int i=2; i<n.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2]+ n[i]);
        }
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        dy_pro(nums);

        return dp[nums.size()-1];        
    }
};