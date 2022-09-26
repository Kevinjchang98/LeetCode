class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        
        string ans = "";
        int carry = 0;
        
        int i = a.size() - 1, j = b.size() - 1;
        
        while (i >= 0 || j >= 0) {
            int curr = carry 
                + (i >= 0 ? (a[i--] - '0') : 0)
                + (j >= 0 ? (b[j--] - '0') : 0);
            
            carry = curr > 1 ? 1 : 0;
            ans = (curr & 1 ? "1" : "0") + ans;
        }
        
        
        
        return (carry == 1 ? "1" : "") + ans;
    }
};