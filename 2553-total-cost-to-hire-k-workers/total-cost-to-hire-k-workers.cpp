class Solution {
public:
    long long result = 0;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        int q=0, w = costs.size()-1;
        while(q < candidates and q <= w) {
            pq.push({costs[q], q});
            q++;
        }
        while(w >= costs.size() - candidates and q <= w) {
            pq.push({costs[w], w});
            w--;
        }
        while(k--) {
            int cost = pq.top().first, idx = pq.top().second;
            pq.pop();
            result += cost;
            if(q<=w) {
                if(idx < q) {
                    pq.push({costs[q], q});
                    q++;
                }
                else{
                    pq.push({costs[w], w});
                    w--;
                }
            }
        }
        return result;
    }
};