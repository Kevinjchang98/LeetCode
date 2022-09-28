class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            
            if (m.find(c) != m.end()) {
                return {i, m[c]};
            } else {
                m.insert({nums[i], i});
            }
        }
        
        return {};
    }
};