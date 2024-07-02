class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(int n : nums) {
        //     pq.push(n);
        // }

        // for(int i=0; i<k-1; k++){
        //     pq.pop();
        // }

        // return pq.top();
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};