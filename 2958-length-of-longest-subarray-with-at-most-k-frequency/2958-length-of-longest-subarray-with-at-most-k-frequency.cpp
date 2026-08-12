class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j = 0;
        int n = nums.size();
        int ans=0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>k)
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};