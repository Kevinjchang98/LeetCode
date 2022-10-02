class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        int i = digits.size() - 1;
        
        do {
            if (digits[i] == 9) {
                carry = true;
                digits[i--] = 0;
            } else {
                digits[i--]++;
                carry = false;
            }
        } while (i >= 0 && carry);
        
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};