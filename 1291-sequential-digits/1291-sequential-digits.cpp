class Solution {
public:
    void generateseq(int num, int low, int high, vector<int>& ans) {
        while (num <= high) {
            if (num >= low)
                ans.push_back(num);

            int last = num % 10;
            if (last == 9)
                break;

            num = num * 10 + last + 1;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 9; i++) {
            int num = i * 10 + i + 1;
            generateseq(num, low, high, ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};