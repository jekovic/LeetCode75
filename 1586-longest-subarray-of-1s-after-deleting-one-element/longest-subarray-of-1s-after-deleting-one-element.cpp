class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int left = 0, right = 0, z = -1;
        int n = nums.size();
        while(right<n)
        {
            if(nums[right] == 0 and z == -1){
                z = right;
                //right++;
            }
            else if(nums[right] == 0 and z != -1){
                left = ++z;
                z = right;
            }

            if(right == n and z == -1){
                result = max(result, right - left);
                break;
            }
            
            result = max(result, right - left);
            right++;
        }

        return result;
    }
};