class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string sn = to_string(n);
        if (digitSum(sn) <= target)
            return 0;
        
        int i = sn.size() - 1;
        
        while (sn[i] == '0' && i - 1 >= 0) {
            i--;
        }
            
        while (digitSum(sn) > target) {
            sn = inc(sn, i);
            i--;
        }
        
        return stoll(sn) - n;
    }
    
    string inc(string num, int i ) {
        while (i > 0) {
            num[i] = '0';
            if (num[i - 1] + 1 > '9') {
                num[i - 1] = '0';
                i--;
            } else {
                num[i - 1]++;
                break;
            }
        }
        
        if (i == 0) {
            num[0] = '0';
            num = '1' + num;
        }
        
        return num;
    }
    
    int digitSum(string num) {
        int ans = 0;
        
        for (int i = 0; i < num.size(); i++) {
            ans += num[i] - '0';
        }
        
        return ans;
    }
};