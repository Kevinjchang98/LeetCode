class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1);

        return helper(coins, amount, memo);
    }

    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (memo[amount] != 0) return memo[amount];

        int min = INT_MAX;

        for (int c : coins) {
            int curr = helper(coins, amount - c, memo);
            if (curr >= 0 && curr < min) min = 1 + curr;
        }

        memo[amount] = min == INT_MAX ? -1 : min;

        return memo[amount];
    }
};