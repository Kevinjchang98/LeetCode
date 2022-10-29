class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> c;
        
        for (int n : nums)
            c[n % space]++;
        
        auto comp = [&](int a, int b) {
            int ca = c[a % space], cb = c[b % space];
            return ca == cb ? a > b : ca < cb;
        };
        
        return *max_element(begin(nums), end(nums), comp);
    }
};