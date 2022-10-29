class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans = {};
        
        for (string qw : queries) {
            for (string dw : dictionary) {
                if (helper(qw, dw)) {
                    ans.push_back(qw);
                    break;
                }
            }
        }
        
        return ans;
    }
    
    bool helper(const string& a, const string& b) {
        int diff = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                if (++diff > 2)
                    return false;
        }
        
        return true;
    }
};