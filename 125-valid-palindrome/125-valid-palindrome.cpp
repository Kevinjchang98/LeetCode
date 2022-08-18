class Solution {
public:
    bool isPalindrome(string s) {
        string onlyChar = "";
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                onlyChar += tolower(c);
            }
        }
        
        for (int i = 0; i < onlyChar.size() / 2; i++) {
            if (onlyChar[i] != onlyChar[onlyChar.size() - 1 - i])
                return false;
        }
        
        return true;
    }
};