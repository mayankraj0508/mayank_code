class Solution {
public:
    bool dfs(vector<vector<bool>>& visited, int row, int col, vector<vector<char>>& grid,
             char& val, int acrow, int accol, int depth, int prevrow, int precol) {
        
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return false;
        }

        if (grid[row][col] != val) {
            return false;
        }
          if (visited[row][col]) {
            
            return depth >= 4;
        }

        if (visited[row][col]) {
            if (row == acrow && col == accol && depth >= 4) {
                return true;
            }
            return false;
        }

        visited[row][col] = true;
        depth++;

        // Move Down
        if (!(row + 1 == prevrow && col == precol)) {
            if (dfs(visited, row + 1, col, grid, val, acrow, accol, depth, row, col)) return true;
        }
        // Move Up
        if (!(row - 1 == prevrow && col == precol)) {
            if (dfs(visited, row - 1, col, grid, val, acrow, accol, depth, row, col)) return true;
        }
        // Move Right
        if (!(row == prevrow && col + 1 == precol)) {
            if (dfs(visited, row, col + 1, grid, val, acrow, accol, depth, row, col)) return true;
        }
        // Move Left
        if (!(row == prevrow && col - 1 == precol)) {
            if (dfs(visited, row, col - 1, grid, val, acrow, accol, depth, row, col)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j]) {
                    int depth = 1; // Starting point counts as 1
                    if (dfs(visited, i, j, grid, grid[i][j], i, j, depth, -1, -1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
