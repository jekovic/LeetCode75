class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int ,int>> v;
        
        for(int i=0; i<n; i++) {
            v.push_back({nums2[i], i});
        }
        
        sort(v.rbegin(), v.rend());
        
        long long sum = 0;
        long long res = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<v.size(); i++) {
            auto temp = v[i];
            sum += nums1[temp.second];
            pq.push(nums1[temp.second]);

            if(pq.size() == k) res = max(res, sum*temp.first);

            if(pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }


        return res;
    }
};