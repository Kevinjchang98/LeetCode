class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        if (intervals.empty())
            return {newInterval};
        else if (intervals[0][0] > newInterval[1]) {
            ans.push_back(newInterval);
            for (auto e : intervals) {
                ans.push_back(e);
            }
            
            return ans;
        } else if (intervals.back()[1] < newInterval[0]) {
            for (auto e : intervals) {
                ans.push_back(e);
            }
            ans.push_back(newInterval);
            
            return ans;
        }
        
        int i = 0, j = 0;
        while (i + 1 < intervals.size() && intervals[i][1] < newInterval[0]) {
            i++;
        }
        
        while (j + 1 < intervals.size() && intervals[j][1] < newInterval[1]) {
            j++;
        }
        
        bool inLeft = false, inRight = false;
        
        if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0])
            inLeft = true;
        
        if (intervals[j][0] <= newInterval[1] && intervals[j][1] >= newInterval[1])
            inRight = true;
        
        for (int k = 0; k < i; k++) {
            ans.push_back(intervals[k]);
        }
        
        if (intervals.size() == 1) {
            if (intervals[0][1] < newInterval[0]) {
                intervals.push_back(newInterval);
                return intervals;
            } else if (intervals[0][0] > newInterval[1]) {
                ans.push_back(newInterval);
                ans.push_back(intervals[0]);
                return ans;
            } else {
                vector<int> newI = {min(intervals[0][0], newInterval[0]),
                           max(intervals[0][1], newInterval[1])};
        
                ans.push_back(newI);
                return ans;
            }
        }
        
        vector<int> newI = {min(intervals[i][0], newInterval[0]),
                           max(intervals[inRight ? j : j - 1][1], newInterval[1])};
        
        ans.push_back(newI);
        
        for (int k = inRight ? j + 1 : j; k < intervals.size(); k++) {
            if (newI[1] < intervals[k][0])
                ans.push_back(intervals[k]);
        }
        
        return ans;
    }
};