bool compare(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
class Solution {
public:
    

    int findPeakElement(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i=0; i != nums.size(); i++){
            v.push_back({i, nums[i]});
        }
        sort(v.begin(), v.end(), compare);

        return v.back().first;
    }
};