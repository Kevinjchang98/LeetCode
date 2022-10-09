class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxL = logs[0][1];
        int maxE = logs[0][0];
        
        for (int i = 1; i < logs.size(); i++) {
            if (logs[i][1] - logs[i-1][1] > maxL) {
                maxE = logs[i][0];
                maxL = logs[i][1] - logs[i-1][1];
            } else if (logs[i][1] - logs[i-1][1] == maxL) {
                maxE = min(maxE, logs[i][0]);
            }
        }
        
        return maxE;
    }
};