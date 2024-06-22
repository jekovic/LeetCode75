class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        int N = grid.size();
        vector<vector<int>> temp(N, vector<int>(N, 0));

        for(int i=0; i< N; i++){
            for(int j=0; j<N; j++){
                temp[i][j] = grid[j][i];
            }
        }

        for(int i=0; i < N; i++){
            for(int j=0; j<N; j++){
                if(grid[i] == temp[j])
                    res++;
            }
        }

        return res;
    }
};