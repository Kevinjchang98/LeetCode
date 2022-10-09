class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());

        ans[0] = pref[0];
        int currPI = ans[0];
        string currP;
        
        for (int i = 1; i < pref.size(); i++) {
            currP = bitset<32>(currPI).to_string();
            string currAns = "00000000000000000000000000000000";
            string target = bitset<32>(pref[i]).to_string();
            
            for (int i = 0; i < currAns.size(); i++) {
                if (target[i] == '0') {
                    currAns[i] = currP[i];
                } else if (target[i] == '1') {
                    currAns[i] = currP[i] == '1' ? '0' : '1';
                }
            }
            
            ans[i] = stoi(currAns, 0, 2);
            currPI = currPI ^ ans[i];
        }
        
        return ans;
    }
};