class Solution {
public:
    const int mod_ = 1e9 + 7;
    vector<long long> d;

    void dp(int n) {
        d.assign(n+1, 0);
        d[0] = 1;
        d[1] = 1;
        d[2] = 2;
        for(int i=3; i<=n; i++){
            d[i] = (d[i-1] * 2 + d[i-3])%mod_;
        }
    }
    
    int numTilings(int n) {
        if(n==1) return 1%mod_;
        else if (n == 2) return 2%mod_;

        dp(n);

        return d[n];
    }
};