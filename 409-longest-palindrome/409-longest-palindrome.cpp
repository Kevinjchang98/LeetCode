class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {};
        
        for (char c : s) {
            count[c]++;
        }
        
        int ans = 0;
        
        for (int e : count) {
            ans += (e / 2) * 2;
        }
        
        return ans + (ans < s.size() ? 1 : 0);
    }
};