class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> c_candies = candies;
        sort(c_candies.begin(), c_candies.end());
        int big = c_candies[c_candies.size()-1];
        
        vector<bool> ret;

        for(const auto& c : candies) {
            if( c + extraCandies >= big){
                ret.push_back(true);
            }
            else{
                ret.push_back(false);
            }
        }
        return ret;
    }
};