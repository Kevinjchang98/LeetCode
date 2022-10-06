class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        
        int i = number.size();
        while (i > 0) {
            string temp = "";
            
            while (i >= 0) {
                if (number[i] == digit)
                    break;
                i--;
            }

            if (i < 0)
                return ans;
            
            temp = number.substr(0, i);
            temp += number.substr(i + 1, number.size() - i - 1);
            
            //cout << ans << " " << temp << endl;
            
            ans = max(ans, temp);
            
            i--;
        }
        
        return ans;
    }
};