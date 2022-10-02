class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle)
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        
        int i = 0, j = 0;
        
        while (j < haystack.size() - needle.size() + 1) {
            while (haystack[i] != needle[0]) {
                if (j >= haystack.size() - needle.size() + 1)
                    return -1;
                i++;
                j++;
            }
            
            bool found = true;
            
            while (j - i < needle.size()) {
                if (needle[j - i] != haystack[j]) {
                    found = false;
                }
                
                j++;
            }
            
            if (found) {
                return i;
            } else {
                i++;
                j = i;
            }
        }
        
        return -1;
    }
};