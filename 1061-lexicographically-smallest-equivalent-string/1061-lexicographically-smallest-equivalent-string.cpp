class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> d;
        
        for (int i = 0; i < s1.size(); i++) {
            bool inserted = false;
            set<char>* first = nullptr;
            set<char>* second = nullptr;
            
            for (set<char>& e : d) {
                if (e.count(s1[i]))
                    first = &e;
                if (e.count(s2[i]))
                    second = &e;
                
                if (first && second && (first != second)) {
                    for (char c : *second) {
                        first->insert(c);
                    }
                    second->clear();
                } else {
                    if (first) {
                        first->insert(s2[i]);
                        inserted = true;
                    }
                    if (second) {
                        second->insert(s1[i]);
                        inserted = true;
                    }
                }
            }
            
            if (!inserted) {
                set<char> n;
                n.insert(s1[i]);
                n.insert(s2[i]);
                d.push_back(n);
            }
        }
        
        string ans = "";
        
        for (char c : baseStr) {
            bool inserted = false;
            
            for (auto e : d) {
                if (e.count(c)) {
                    auto it = e.begin();
                    ans += *it;
                    inserted = true;
                    break;
                }
            }
            
            if (!inserted)
                ans += c;
        }
        
        return ans;
    }
};