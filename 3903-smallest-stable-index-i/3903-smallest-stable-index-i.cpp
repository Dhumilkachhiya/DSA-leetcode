class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minpost(n);
        int miin = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            miin = min(nums[i], miin);
            minpost[i] = miin;
        }
         int maax = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            maax=max(maax,nums[i]);
            int val = maax - minpost[i];
            if (val <= k)
                return i;
            
        }
        return -1;
    }
};