class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int s = grid.size();
        vector<int> r(s, 0), c(s, 0);
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                r[i] = max(r[i], grid[i][j]);
                c[j] = max(c[j], grid[i][j]);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                ans += min(r[i], c[j]) - grid[i][j];
            }
        }
        
        return ans;
    }
};