class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        s.push({0, temperatures[0]}); // idx, value
        temperatures[0] = 0;

        for(int i=1; i!= temperatures.size(); i++) {
            while(!s.empty() and s.top().second < temperatures[i]) {
                temperatures[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push({i, temperatures[i]});
            temperatures[i] = 0;
        }

        return temperatures;
    }
};