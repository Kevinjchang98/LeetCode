class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int d = nums[i];
            
            for (int j = i; j < nums.size(); j++) {
                d = __gcd(nums[j], d);
                if (d == k) ans++;
            }
        }
        
        return ans;
    }
};