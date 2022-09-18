class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int k = (nums1.size() + nums2.size() - 1) / 2;
        int l = 0, r = min(k, (int)nums1.size());
        
        while (r > l) {
            int m1 = ((r - l) / 2) + l;
            int m2 = k - m1;
            
            if (nums1[m1] < nums2[m2])
                l = m1 + 1;
            else
                r = m1;
        }
        
        int a = max(l > 0 ? nums1[l - 1] : INT_MIN, k - l >= 0 ? nums2[k - l] : INT_MAX);

        if ((nums1.size() + nums2.size()) % 2 != 0) {
            return a;
        } else {
            int b = min(l < nums1.size() ? nums1[l] : INT_MAX, k - l + 1 < nums2.size() ? nums2[k - l + 1] : INT_MAX);
            return (a + b) / 2.0;
        }
    }
};