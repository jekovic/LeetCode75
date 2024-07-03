class StockSpanner {
public:
    //vector<int> res;
    vector<pair<int, int>> v;
    int idx = 0;

    StockSpanner() {
        //v.push_back({0, 0});
    }
    
    int next(int price) {
        int result = 0;
        v.push_back({++idx, price});
        for(int i = v.size()-1; i>=0; i--) {
            if(v[i].second > price) break;
            else result++;
        }
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */