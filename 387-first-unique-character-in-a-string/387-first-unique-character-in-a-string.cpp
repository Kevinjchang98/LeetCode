class Solution {
public:
    int firstUniqChar(string s) {
        int letters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
        for (char c : s) {
            letters[c - 97]++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (letters[s[i] - 97] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};