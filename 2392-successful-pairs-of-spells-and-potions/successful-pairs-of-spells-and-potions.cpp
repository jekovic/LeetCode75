class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());

        for(int i=0; i != spells.size(); i++) {
            
            double temp = success/double(spells[i]);
            int left = 0, right = potions.size()-1;
            int idx = 0;
            while(left <= right) {
                int k = (left+right) / 2;
                if(potions[k]>=temp){
                    right = k - 1;
                }
                else{
                    left = k + 1;
                }
            }
            idx = potions.size() - left;
            res.push_back(idx);
        }

        return res;
    }
};