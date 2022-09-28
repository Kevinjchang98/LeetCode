class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int target = 0 - nums[i];

                unordered_set<int> m;

                for (int j = i + 1; j < nums.size(); j++) {
                    int comp = target - nums[j];

                    if (m.count(comp)) {
                        //vector<int> toInsert = {nums[i], nums[j], comp};
                        //sort(toInsert.begin(), toInsert.end());

                        //if (!(find(ans.begin(), ans.end(), toInsert) != ans.end()))
                        //    ans.push_back(toInsert);
                        ans.push_back({nums[i], comp, nums[j]});
                        while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                            ++j;
                    }

                    m.insert(nums[j]);
                }
            }
        }
        
        return ans;
    }
};