class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        
        while (j < nums.size()) {
            while (nums[i] == nums[j]) {
                j++;
                if (j == nums.size())
                    return i + 1;
            }
                
            nums[++i] = nums[j++];
        }
        
        return i + 1;
    }
};