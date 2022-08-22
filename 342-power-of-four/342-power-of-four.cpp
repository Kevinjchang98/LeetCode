class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0) {
            return false;
        }
        
        long x = n;
        return (x & (-x)) == x && (x & 1431655765) != 0;
    }
};