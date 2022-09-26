class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int ans = curr;
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            curr = max(num, curr + num);
            ans = max(ans, curr);
        }
        
        return ans;
    }
};