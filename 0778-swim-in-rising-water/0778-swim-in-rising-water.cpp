class Solution {
public:
    bool bfs(int mid, vector<vector<int>>& grid, int n) {
        if (grid[0][0] > mid || grid[n - 1][n - 1] > mid)
            return false;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto& inx = q.front();
            int i = inx.first;
            int j = inx.second;
            q.pop();
            if (i == n - 1 && j == n - 1)
                return true;
            int row[] = {-1, 1, 0, 0};
            int col[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; k++) {
                int nrow = i + row[k];
                int ncol = j + col[k];
                if (ncol < n && nrow < n && nrow >= 0 && ncol >= 0 &&
                    !vis[nrow][ncol] && grid[nrow][ncol] <= mid) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int high = grid[0][0];
        int low = grid[0][0];
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, grid[i][j]);
                low = min(low, grid[i][j]);
            }
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bfs(mid, grid, n)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};