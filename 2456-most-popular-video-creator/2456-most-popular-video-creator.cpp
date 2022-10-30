class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> vm;
        unordered_map<string, long long> ivm;
        unordered_map<string, string> idm;
        
        for (int i = 0; i < creators.size(); i++) {
            vm[creators[i]] += views[i];
            if (ivm[creators[i]] < views[i] 
                || (ivm[creators[i]] == views[i] 
                    && idm[creators[i]] > ids[i]) 
                || ivm[creators[i]] == 0) {
                ivm[creators[i]] = views[i];
                idm[creators[i]] = ids[i];
            }
        }
        
        auto compCreator = [&](pair<string, long long> pa, pair<string, long long> pb) {
            if (pa.second == pb.second)
                return pa.first > pb.first;
            else 
                return pa.second < pb.second;
        };
        
        
        auto maxCreator = *max_element(vm.begin(), vm.end(), compCreator);
        
        vector<string> maxCreators;
        
        for (const auto& c : vm) {
            if (c.second == maxCreator.second)
                maxCreators.push_back(c.first);
        }
        
        sort(maxCreators.begin(), maxCreators.end());
        
        vector<vector<string>> ans;
        
        for (string c : maxCreators)
            ans.push_back({c, idm[c]});

        return ans;
    }
};