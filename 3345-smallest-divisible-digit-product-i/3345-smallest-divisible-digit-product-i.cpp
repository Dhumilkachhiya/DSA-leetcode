class Solution {
public:
    int digitproduct(int num) {
        int ans = 1;
        while (num > 0) {
            ans *= num % 10;
            num /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            if (digitproduct(n) % t == 0)
                return n;
            n++;
        }
        return 0;
    }
};