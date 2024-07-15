class Solution {
public:
    int dfs(vector<vector<int>> &graph, vector<int> &vis, int curr) {
        
        vis[curr] = 1; 
        int count = 0;
        for (auto &node: graph[curr]) {
            
            if (!vis[abs(node)]) {
                count += dfs(graph, vis, abs(node)) + (node > 0);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        int count = 0;
        vector<int> vis(n, 0);
        for (auto &con: connections) {
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(-con[0]);
        }
        
        return dfs(graph, vis, 0);
        
    }
};