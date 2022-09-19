class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0, f = 0;

        while (f < nums.size()) {
            if (nums[f] != val) {
                nums[s++] = nums[f];
            }
            f++;
        }
        
        return s;
    }
};