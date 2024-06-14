class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> answer(sz, 0);
        vector<int> pre(sz, 1), post(sz, 1);

        for(int i=1; i != sz; i++) {
            pre[i] = pre[i-1]*nums[i-1];
        }

        for(int i = sz-2; i>=0; i--) {
            post[i] = post[i+1]*nums[i+1];
        }

        for(int i=0; i<sz; i++) {
            answer[i] = pre[i]*post[i];
        }

        return answer;
    }
};