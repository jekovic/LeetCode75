class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;

        while(left < right) {
            int min_h = min(height[left], height[right]);
            result = max(result, min_h * (right-left));
            if(height[left] > height[right]) right--;
            else left++;
        }  
        return result;
    }
};