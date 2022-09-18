class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr;
        int count = 0;
        
        for (int e : nums) {
            if (count == 0) {
                curr = e;
                count = 1;
            } else if (curr == e) {
                count++;
            } else {
                count--;
            }
        }
        
        return curr;
    }
};