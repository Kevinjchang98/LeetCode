class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<char, int>> c;
        
        for (int i = 0; i < s.size(); i++) {
            c.push_back({s[i], indices[i]});
        }
        
        sort(c.begin(), c.end(),
             [](pair<char, int> a, pair<char, int> b) {
                 return a.second < b.second;
             });
        
        string ans;
        
        for (auto e : c) {
            ans += e.first;
        }
        
        return ans;
    }
};