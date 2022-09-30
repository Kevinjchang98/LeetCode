class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        
        for (vector<int> i : prerequisites) {
            preMap[i[0]].push_back(i[1]);
        }

        unordered_set<int> visited;
        
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(preMap, visited, course))
                return false;
        }
        
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>>& preMap, 
             unordered_set<int>& visited, int course) {
        if (visited.find(course) != visited.end())
            return false;
        
        if (preMap[course].size() == 0)
            return true;
        
        visited.insert(course);
        
        for (auto pre : preMap[course]) {
            if (!dfs(preMap, visited, pre))
                return false;
        }
        
        visited.erase(course);
        preMap[course] = {};
        return true;
    }
};