class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0;
        int mx2 = 0;
        int ans = 0;
        while (n > 0) {
            int md = n % 10;
            if (md >= mx1) {
                ans = max(ans, md * mx1);
                mx2 = mx1;
                mx1 = md;
            } else {
                mx2 = max(mx2, md);
                ans = max(ans, mx2 * mx1);
            }
            n /= 10;
        }
        return ans;
    }
};