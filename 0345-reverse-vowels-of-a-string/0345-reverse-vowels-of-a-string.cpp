class Solution {
public:
    string reverseVowels(string s) {
        vector<char> c;
        vector<int> p;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for (int i = 0; i < s.size(); i++) {
            if (v.count(s[i])) {
                c.push_back(s[i]);
                p.push_back(i);    
            }
        }
        
        reverse(p.begin(), p.end());
        
        for (int i = 0; i < c.size(); i++) {
            s[p[i]] = c[i];
        }

        return s;
    }
};