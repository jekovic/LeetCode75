class Solution {
public:
    vector<vector<int>> map;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int result = 1e9;
    void check_entracne(vector<int>& entrance) {

    }
    void bfs(vector<vector<char>>& maze, vector<int>& entrance) {
        map.assign(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        map[entrance[0]][entrance[1]] = 1;
        q.push({entrance[0], entrance[1]});

        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < 0 || ny < 0  || nx >= m || ny >= n){
                    if(cx == entrance[0] and cy == entrance[1]) continue;
                    result = min(result, map[cx][cy]);
                    continue;
                }
                if(maze[nx][ny] == '+') continue;
                if(map[nx][ny] > 0) continue; 
                else if(maze[nx][ny] == '.'){
                    map[nx][ny] = map[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        
        bfs(maze, entrance);
        if(result == 1 || result == 1e9){
            return -1;
        }
        return --result;
    }
};