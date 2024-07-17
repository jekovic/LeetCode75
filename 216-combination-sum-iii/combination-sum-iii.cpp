class Solution {
public:
    vector<int> vis;
    vector<vector<int>> res;

    void dfs(int k, int cnt, int n, int sum) {
        if(cnt == k and n == sum){
            vector<int> temp;
            for(int i=1; i<=9; i++){
                if(vis[i]){
                    temp.push_back(i);
                }
            }
            if(find(res.begin(), res.end(), temp) == res.end()) res.push_back(temp);
            return;
        }
        for(int i=1; i<=9; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            dfs(k, cnt+1, n, sum+i);
            vis[i] = 0;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vis.assign(10, 0);

        dfs(k, 0, n, 0);

        return res;
    }
};