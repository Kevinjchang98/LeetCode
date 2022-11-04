class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> ans = {0, 0};
        
        for (int i = 0; i < s.size(); i++) {
            auto a = find(i, i, s);
            auto b = find(i, i + 1, s);
            
            if (a.second - a.first > b.second - b.first
               && a.second - a.first > ans.second - ans.first)
                ans = a;
            else if (b.second - b.first > ans.second - ans.first)
                ans = b;
        }
        
        return ans.second - ans.first == 0 
            ? s.substr(0, 1) 
            : s.substr(ans.first + 1, ans.second - ans.first - 1);
    }
    
    pair<int, int> find(int l, int r, const string& s) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return {l, r};
    }
};