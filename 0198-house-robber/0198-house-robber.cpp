class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int prev1 = nums[0];
        int prev2 = 0;
        int ans = prev1;
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int nonpick = prev1;
            ans = max(pick, nonpick);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};