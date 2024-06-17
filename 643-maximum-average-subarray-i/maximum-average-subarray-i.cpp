class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        double ret = 0.0;
        for(int i=0; i < k; i++) {
            sum += nums[i]; 
        }
        ret = sum;

        if( nums.size() > k) {
            for(int i = k; i < nums.size(); i++ ) {
                sum = sum - nums[i-k] + nums[i];
                if(ret < sum) ret = sum;
            }
        }

        return ret/k;
    }
};