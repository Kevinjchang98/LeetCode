class Solution {
public:
    int maxLength(vector<string>& arr) {
        return getMax(arr, 0, "");
    }
    
    int getMax(vector<string> arr, int pos, string res) { 
        unordered_set<char> resSet(res.begin(), res.end());
        if (res.size() != resSet.size()) {
            return 0;
        }
        
        int maxL = res.size();
        for (int i = pos; i < arr.size(); i++) {
            maxL = max(maxL, getMax(arr, i + 1, res + arr[i]));
        }
        
        return maxL;
    }    
};