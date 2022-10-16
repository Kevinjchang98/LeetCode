class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int maxi = INT_MIN;
        
        for (int i : nums) {
            if (s.find(-i) == s.end()) {
                s.insert(i);
            } else {
                maxi = max(maxi, abs(i));
            }
        }
        
        return maxi == INT_MIN ? -1 : maxi;
    }
};