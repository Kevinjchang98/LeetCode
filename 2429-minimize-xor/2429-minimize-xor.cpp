class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // cout << bitset<32>(num1).to_string() << endl;
        // cout << bitset<32>(num2).to_string() << endl;
        // cout << bitset<32>(num1 ^ num2).to_string() << endl;
        // cout << __builtin_popcount(num2) << endl;
        
        int numSet = __builtin_popcount(num2);
        string num1S = bitset<32>(num1).to_string();
        string ans = "";
        
        for (int i = 0; i < 32; i++) {
            if (num1S[i] == '1' && numSet > 0) {
                ans += '1';
                numSet--;
            } else {
                ans += '0';
            }
        }
        
        // cout << ans << "ans1" << endl;
        
        // cout << (stoi(ans, 0, 2) ^ num1) << endl;
        if (numSet == 0)
            return stoi(ans, 0, 2);
        
        string ans2 = "";
        
        for (int i = 31; i >= 0; i--) {
            if (ans[i] == '0' && numSet > 0) {
                ans2 = '1' + ans2;
                numSet--;
            } else {
                ans2 = ans[i] + ans2;
            }
        }
        
        // cout << ans2 << "ans2" << endl;

        return stoi(ans2, 0, 2);
    }
};