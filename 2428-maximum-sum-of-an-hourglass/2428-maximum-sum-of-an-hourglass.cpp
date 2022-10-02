class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        
        for (int i = 0; i <= grid.size() - 3; i++) {
            for (int j = 0; j <= grid[0].size() - 3; j++) {
                vector<vector<int>> newV = {{grid[i][j], grid[i][j + 1], grid[i][j + 2]},
                                            {grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2]},
                                            {grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]}};
                
                ans = max(ans, returnSum(newV));
                cout << ans << endl;
            }
        }
            
        return ans;
    }
    
    int returnSum(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < 3; i++) {
            ans += grid[0][i];
            ans += grid[2][i];
        }
        
        ans += grid[1][1];
        
        return ans;
    }
};