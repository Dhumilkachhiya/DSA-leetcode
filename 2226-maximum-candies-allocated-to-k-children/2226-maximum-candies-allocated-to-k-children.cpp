class Solution {
public:
    bool check(int mid, long long child, vector<int>& candies) {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += (candies[i] / mid);
        }

        return count >= child;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = *max_element(candies.begin(), candies.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, k, candies)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l-1;
    }
};