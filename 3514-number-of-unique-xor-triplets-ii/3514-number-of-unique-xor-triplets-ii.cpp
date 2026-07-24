class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_set<int> pair;
        pair.insert(0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair.insert(nums[i] ^ nums[j]);
            }
        }
        for (auto x : pair) {
            for (auto v : nums) {
                st.insert(x ^ v);
            }
        }
        return st.size();
    }
};