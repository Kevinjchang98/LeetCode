class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int ans = curr;
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > curr + num)
                curr = num;
            else
                curr = curr + num;
            
            if (curr > ans)
                ans = curr;
        }
        
        return ans;
    }
};