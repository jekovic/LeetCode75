class Solution {
public:
    vector<vector<int>> map;

    int uniquePaths(int m, int n) {
        map.assign(m, vector<int>(n, 0));
        map[0][0] = 0;
        if(m == 1 and n == 1) return 1;

        for(int i=1; i<m; i++) map[i][0] = 1;
        for(int i=1; i<n; i++) map[0][i] = 1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++){
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }

        return map[m-1][n-1];
    }
};