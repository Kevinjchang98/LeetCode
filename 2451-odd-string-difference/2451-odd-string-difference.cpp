class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>> ans;
        vector<int> a = {};
        vector<int> b = {};
        
        for (int i = 0; i < words.size(); i++) {  
            vector<int> curr = {};
            
            for (int j = 0; j <= words[i].size() - 2; j++) {
                curr.push_back(words[i][j + 1] - words[i][j]);
            }
            
            if (i == 0)
                a = curr;
            else if (i == 1)
                b = curr;
            else if (curr != a && curr != b)
                return words[i];
            else if (curr == a && curr != b && i >= 2)
                return words[1];                
            else if (curr != a && curr == b && i >= 2)
                return words[0];     
        }
        
        return "";
    }
};