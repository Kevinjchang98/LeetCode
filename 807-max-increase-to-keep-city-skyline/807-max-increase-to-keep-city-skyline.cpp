class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int temp = grid[i][j];
                grid[i][j] = -1;
                int colMax = grid[i][j];
                
                for (int k = 0; k < grid[i].size(); k++) {
                    if (k != i)
                        colMax = max(colMax, grid[k][j]);
                }
                
                int rowMax = *max_element(begin(grid[i]), end(grid[i]));
                
                grid[i][j] = temp;
                ans += min(colMax, rowMax) - temp < 0 ? 0 : min(colMax, rowMax) - temp;
            }
        }
        
        return ans;
    }
};