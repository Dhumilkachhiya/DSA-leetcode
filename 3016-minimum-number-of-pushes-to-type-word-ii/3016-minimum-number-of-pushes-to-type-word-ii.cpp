class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());

        int m = freq.size();
        int ans = 0;
        int miin = min(8, m);
        for (int i = 0; i < miin; i++) {
            ans += freq[i];
        }
        miin = min(16, m);
        for (int i = 8; i < miin; i++) {
            ans += freq[i] * 2;
        }
        miin = min(24, m);
        for (int i = 16; i < miin; i++) {
            ans += freq[i] * 3;
        }
        for (int i = 24; i < m; i++) {
            ans += freq[i] * 4;
        }
        return ans;
    }
};