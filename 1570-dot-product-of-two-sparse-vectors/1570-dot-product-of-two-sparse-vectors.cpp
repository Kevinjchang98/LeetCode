class SparseVector {
private:
    int size;
    unordered_map<int, int> data;
public:
    
    SparseVector(vector<int> &nums) {
        size = nums.size();
        
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                data.insert(make_pair(i, nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        
        for (auto e : data) {
            if (vec.data.find(e.first) != vec.data.end()) {
                ans += vec.data[e.first] * e.second;
            }
        }
        
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);