class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        
        for(int i=1; i<=n; i++) {
            int num = i;
            int cnt = 0;
            while(num != 0) {
                cnt += num%2;
                num /=2;
            }    
            res[i] = cnt;
        }

        return res;
    }
};