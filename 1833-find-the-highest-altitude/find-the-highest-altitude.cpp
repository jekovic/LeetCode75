class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> res;
        res.push_back(0);

        for(int h : gain) {
            int temp = res.back() + h;
            res.push_back(temp);
        }

        sort(res.rbegin(), res.rend());

        return res[0];
    }
};