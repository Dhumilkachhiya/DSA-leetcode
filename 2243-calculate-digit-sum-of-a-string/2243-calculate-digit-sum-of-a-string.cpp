class Solution {
public:
    void minimizesize(string &ans, int k) {
        string temp = "";

        for (int i = 0; i < ans.size(); i += k) {
            int sum = 0;

            for (int j = i; j < min(i + k, (int)ans.size()); j++) {
                sum += ans[j] - '0';
            }

            temp += to_string(sum);
        }

        ans = temp;
    }

    string digitSum(string s, int k) {
        string ans = s;

        while (ans.size() > k) {
            minimizesize(ans, k);
        }

        return ans;
    }
};