class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int result = -1;
    int one_cnt = 0;
    vector<pair<int, int>> two;

    bool find_one(vector<vector<int>>& grid) {
        bool flag = false;
        for(int i=0; i != grid.size(); i++) {
            for(int j=0; j != grid[i].size(); j++){
                if(grid[i][j] == 1){
                    flag = true;
                    one_cnt++;
                }
                else if(grid[i][j] == 2) {
                    two.push_back({i, j});
                }
            }
        }
        return flag;
    }

    void bfs(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        for(int i=0; i != two.size(); i++) {
            q.push({two[i].first, two[i].second});
            vis[two[i].first][two[i].second] = 1;
        }
        
        int ti = 0;
        while(1) {
            if(one_cnt <= 0) break;
            else if(q.empty() and one_cnt > 0){
                ti = -1; break;
            }
            ti++;
            int end = q.size();
            for(int a = 0; a != end; a++) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                    if(vis[nx][ny]) continue;
                    if(grid[nx][ny] == 0) continue;
                    if(grid[nx][ny] == 1){
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        one_cnt--;
                    }
                }
            }
        }
        result = ti;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        if(!find_one(grid)) return 0;
        
        bfs(grid);
        
        return result;
    }
};