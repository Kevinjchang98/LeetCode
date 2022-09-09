class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(),
            [](const vector<int> &a, const vector<int> &b) -> bool {
                return (a[0] == b[0] ? b[1] > a[1] : a[0] > b[0]);
            });
        
        int ans = 0;
        int maxD = 0;
        
        for (auto c : properties) {
            if (c[1] < maxD)
                ans++;
            
            maxD = max(maxD, c[1]);
        }
        
        return ans;
    }
};