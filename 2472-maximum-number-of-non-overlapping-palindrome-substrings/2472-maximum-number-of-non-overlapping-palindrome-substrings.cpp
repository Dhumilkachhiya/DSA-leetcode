class Solution {
public:

    bool checkpalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;

        int i = k - 1;
        int lastend = -1;

        while (i < n) {

            for (int j = lastend + 1; j <= i - k + 1; j++) {

                if (checkpalindrome(s, j, i)) {

                    count++;

                    lastend = i;

                    break;
                }
            }

            i++;
        }

        return count;
    }
};