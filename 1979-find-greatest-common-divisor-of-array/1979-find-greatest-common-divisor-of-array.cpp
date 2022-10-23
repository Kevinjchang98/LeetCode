class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minN = nums[0], maxN = minN;
        
        for (int i = 0; i < nums.size(); i++) {
            minN = min(minN, nums[i]);
            maxN = max(maxN, nums[i]);
        }
        
        return __gcd(minN, maxN);
    }
};