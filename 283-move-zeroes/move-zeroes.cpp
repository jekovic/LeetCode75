class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ret;
        int cnt = 0;
        for(int i=0; i != nums.size(); i++) {
            if(nums[i] == 0){
                cnt++;
            }
            else{
                ret.push_back(nums[i]);
            }
        }

        for(int i=0; i<cnt; i++) {
            ret.push_back(0);
        }

        nums = ret;
    }
};