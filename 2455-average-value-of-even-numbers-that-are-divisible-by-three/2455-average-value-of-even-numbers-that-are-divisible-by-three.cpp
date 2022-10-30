class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0;
        int sum = 0;
        
        for (int i : nums) {
            if (i % 3 == 0 && i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        
        return count > 0 ? sum / count : 0;
    }
};