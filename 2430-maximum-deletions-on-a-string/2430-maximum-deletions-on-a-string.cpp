class Solution {
public:
    int dp[4000] = {};

    int helper(int i, const string& s) {
        if (dp[i] == 0) {
            dp[i] = 1;
            
            for (int j = 1; i + 2 * j <= s.size(); j++) {
                // if j letters from index i of s == j letters from idx i + j of s
                if (s.compare(i, j, s, i + j, j) == 0)
                    dp[i] = max(dp[i], 1 + helper(i + j, s));
            }
        }
        
        return dp[i];
    }
    
    int deleteString(string s) {
        return helper(0, s);
    }
};