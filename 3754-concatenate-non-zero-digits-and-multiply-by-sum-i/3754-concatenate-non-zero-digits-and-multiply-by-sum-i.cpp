class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long pow = 1;
        long long sum = 0;
        while (n > 0) {
            if (n % 10 != 0) {
                ans = (n % 10) * pow + ans;
                sum += n % 10;
                pow=pow*10;
            }
            n /= 10;
        }
        return sum*ans;
    }
};