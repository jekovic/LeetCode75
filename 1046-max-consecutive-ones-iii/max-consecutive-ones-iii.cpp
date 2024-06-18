class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int left = 0, right = 0, flips = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                flips++;
            }

            if(flips > k){
                if(nums[left] == 0){
                    flips--;
                }
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        

        return result;   
    }
};