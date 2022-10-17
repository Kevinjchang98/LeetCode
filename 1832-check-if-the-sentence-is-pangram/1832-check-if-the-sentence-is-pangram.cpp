class Solution {
public:
    bool checkIfPangram(string sentence) {
        int l[26] = {};
        
        for (char c : sentence) {
            l[c - 'a']++;
        }
        
        for (int i : l) {
            if (i == 0) return false;
        }
        
        return true;
    }
};