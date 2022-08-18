class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        
        int temp = i-1;
        
        if (temp >= 0) {
            i = nums.size() - 1;

            while (i > temp && nums[i] <= nums[temp]) {
                i--;
            }

            swap(nums[temp++], nums[i]);

            int j = nums.size() - 1;
            while (temp < j) {
                swap(nums[temp++], nums[j--]);
            }
        } else {
            int j = nums.size() - 1;
            temp = 0;
            while (temp < j) {
                swap(nums[temp++], nums[j--]);
            }
        }
    }
};