class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while (x) {
            int curr = x % 10;
            
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && curr > 7)) 
                return 0;
            
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && curr < -8))
                return 0;
            
            ans = ans * 10 + curr;
            x /= 10;
        }
        
        return ans;
    }
};