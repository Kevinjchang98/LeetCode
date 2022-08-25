class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int l[26] = {};
        
        for (auto c : magazine) {
            l[c - 'a']++;
        }
        
        for (auto c : ransomNote) {
            if (--l[c - 'a'] == -1) 
                return false;
        }
        
        return true;
    }
};