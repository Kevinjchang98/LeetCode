class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
            return s;
        else if (s.size() == 2 && s[0] == s[1])
            return s;
        
        string ans = "";
        
        auto find = [&s](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            
            return s.substr(++l, r - l);
        };
        
        for (int i = 0; i < s.size(); i++) {            
            vector<string> curr = {find(i, i), find(i, i+1), ans};
            
            ans = *max_element(curr.begin(), curr.end(),
                               [](string a, string b) {
                                  return a.size() < b.size();
                               });
        }
        
        return ans.size() == 0 ? s.substr(0, 1) : ans;
    }
};