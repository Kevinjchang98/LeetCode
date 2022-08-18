class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (int i : arr) {
            auto item = m.find(i);
            m.insert({i, item != m.end() ? item->second++ : 1});
        }
        
        priority_queue<pair<int, int>> q;
        
        for (auto e : m) {
            q.push({e.second, e.first});    
        }
        
        int size = 0;
        int num = 0;
        
        while (size < arr.size() / 2) {
            size += q.top().first;
            q.pop();
            num++;
        }
        
        return num;
    }
};