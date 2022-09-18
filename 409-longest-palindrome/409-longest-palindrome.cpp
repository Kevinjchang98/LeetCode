class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {};
        
        for (char c : s) {
            count[c]++;
        }
        
        int ans = 0;
        bool hasSingle = false;
        
        for (int e : count) {
            if (!hasSingle && e % 2 != 0 )
                hasSingle = true;
            ans += (e / 2) * 2;
        }
        
        return ans + (hasSingle ? 1 : 0);
    }
};