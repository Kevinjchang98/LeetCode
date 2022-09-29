class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto comp = [x](int a, int b) {return abs(a - x) == abs(b - x) ? a > b : abs(a - x) > abs(b - x);};
        
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        vector<int> ans = {};
        
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};