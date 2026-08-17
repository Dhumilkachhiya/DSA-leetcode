class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if (n % k != 0)
            return false;
        if (k == 1)
            return true;
        sort(nums.begin(),nums.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for(auto x:nums){
            if(mp[x]==0) continue;
            for(int i=0;i<k;i++){
                if(mp[x]==0) return false;
            mp[x]--;
            x++;
            }
        }
        return true;
    }
};