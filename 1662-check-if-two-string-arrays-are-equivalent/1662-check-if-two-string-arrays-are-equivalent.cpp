class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        
        for (const string& i : word1)
            w1 += i;
        
        for (const string& i: word2)
            w2 += i;
        
        return w1 == w2;
    }
};