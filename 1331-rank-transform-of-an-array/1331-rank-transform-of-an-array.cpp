class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> ans(n);
        int renk = 1;
        for (auto& it : mp) {
            vector<int> &temp = it.second;
            for (int i = 0; i < temp.size(); i++) {
                ans[temp[i]] = renk;
            }
            renk++;
        }
        return ans;
    }
};