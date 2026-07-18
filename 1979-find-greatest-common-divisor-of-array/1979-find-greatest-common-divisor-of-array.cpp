class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = nums[0];
        int g = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            s = min(s, nums[i]);
            g = max(g, nums[i]);
        }
        return gcd(s, g);
    }
};