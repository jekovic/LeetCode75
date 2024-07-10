class Solution {
public:
    int find_max ( vector<int>& piles) {
        int ret = 0;
        for(int p : piles) {
            ret = max(p, ret);
        }
        return ret;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = find_max(piles);

        while(start < end){
            int mid = start + (end-start) / 2;
            int total = 0;
            for(int p : piles){
                total += ceil((double)p / mid);
            }
            if(total > h){
                start = mid + 1;
            }
            else end = mid;
        }

        return start;
    }
};