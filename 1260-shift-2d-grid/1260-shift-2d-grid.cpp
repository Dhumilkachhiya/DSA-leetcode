class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for (int t = 0; t < k; t++) {
            int curr = grid[n - 1][m - 1];
            int next = grid[0][0];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    next = grid[i][j];
                    grid[i][j] = curr;
                    curr = next;
                }
            }
        }

        return grid;
    }
};