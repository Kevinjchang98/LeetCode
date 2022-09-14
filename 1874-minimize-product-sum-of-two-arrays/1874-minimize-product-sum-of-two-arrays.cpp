class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        
        priority_queue<int> n2;
        
        for (int i : nums2)
            n2.push(i);
        
        int ans = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            ans += nums1[i] * n2.top();
            n2.pop();
        }
        
        return ans;
    }
};