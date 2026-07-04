class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int maax=nums[0];
        for(int i=k;i<nums.size();i++)
        {
            ans=max(ans,maax+nums[i]);
            maax=max(maax,nums[i-k+1]);
        }
        return ans;
    }
};