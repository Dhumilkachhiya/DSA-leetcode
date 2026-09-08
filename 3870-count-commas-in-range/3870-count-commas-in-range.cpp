
class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int temp = n;

        while (temp > 0) {
            count++;
            temp /= 10;
        }

        if (count <= 3)
            return 0;

        return n - 999;
    }
};
