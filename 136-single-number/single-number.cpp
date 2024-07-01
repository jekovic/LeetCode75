class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> m;
        unordered_map<int, int> um;
        for(int n:nums) {
            if(n >= 0)
                m[n]++;
            else {
                int idx= abs(n);
                um[idx]++;
            }
        }
        for(int i=0; i != m.size(); i++) {
            if(m[i] == 1){
                result = i;
            }
        }
        for(int i=0; i != um.size(); i++) {
            if(um[i] == 1){
                result = i*(-1);
            }
        }
        return result;
    }
};