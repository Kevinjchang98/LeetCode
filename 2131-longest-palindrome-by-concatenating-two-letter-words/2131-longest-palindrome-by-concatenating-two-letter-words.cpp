class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> s;
        int ans = 0;
        
        for (auto w : words) {
            string comp = w;
            reverse(comp.begin(), comp.end());
            
            if (s[comp] > 0) {
                ans += 4;
                s[comp]--;
            } else
                s[w]++;
        }
        
        for (auto w : s)
            if (w.second > 0 && w.first[0] == w.first[1])
                return ans + 2;
        
        return ans;
    }
};