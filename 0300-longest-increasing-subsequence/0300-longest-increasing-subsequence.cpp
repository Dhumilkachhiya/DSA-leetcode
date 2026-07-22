class Solution {
public:
    int lisfind(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        int len = lisfind(nums, ind + 1, prev, dp);
        if (prev == -1 || nums[ind] > nums[prev]) {
            len = max(len, 1 + lisfind(nums, ind + 1, ind, dp));
        }
        dp[ind][prev + 1] = len;
        return dp[ind][prev + 1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lisfind(nums, 0, -1, dp);
    }
};