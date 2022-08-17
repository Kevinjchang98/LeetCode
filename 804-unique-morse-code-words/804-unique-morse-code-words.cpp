class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> transformations;
        string letters[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int count = 0;
        
        for (string word : words) {
            string ans = "";
            
            for (char letter : word) {
                ans += letters[letter - 97];
            }
            
            if (transformations.find(ans) == transformations.end()) {
                transformations.insert(ans);
            }
        }
        
        return transformations.size();
    }
};