class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        int minpos = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxpos = max_element(nums.begin(), nums.end()) - nums.begin();

        // Make minpos the smaller position and maxpos the larger position
        if (minpos > maxpos)
            swap(minpos, maxpos);

        int ans = INT_MAX;

        // Delete both from the front
        ans = min(ans, maxpos + 1);

        // Delete both from the back
        ans = min(ans, n - minpos);

        // Delete min from front and max from back
        ans = min(ans, minpos + 1 + n - maxpos);
        
        return ans;
    }
};