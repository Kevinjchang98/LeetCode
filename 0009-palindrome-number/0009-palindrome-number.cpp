class Solution {
public:
    bool isPalindrome(int x) {
        string xS = to_string(x);
        
        int i = 0, j = xS.size() - 1;
        
        while (j > i) {
            if (xS[j--] != xS[i++])
                return false;
        }
        
        return true;
    }
};