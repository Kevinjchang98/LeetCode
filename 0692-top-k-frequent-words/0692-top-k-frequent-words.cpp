class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        
        for (auto w : words) {
            m[w]++;
        }
        
        auto comp = [&](pair<string, int> a, pair<string, int> b) {
            if (a.second != b.second)
                return a.second < b.second; 
            else
                return a.first < b.first;
        };
        
        vector<pair<int, string>> q;
        
        for (auto p : m) {
            q.push_back({-p.second, p.first});
        }
        
        make_heap(q.begin(), q.end(), greater<pair<int, string>>());
        
        vector<string> ans(k);
        
        for (int i = 0; i < k; i++) {
            pop_heap(q.begin(), q.end(), greater<pair<int, string>>());
            ans[i] = q.back().second;
            q.pop_back();
        }
        
        return ans;
    }
};