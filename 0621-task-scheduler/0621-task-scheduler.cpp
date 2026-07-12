class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char ch : tasks) {
            mp[ch]++;
        }
        priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }
        int ans = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for (auto it : temp) {
                if (it > 0) {
                    pq.push(it);
                }
            }
            if (pq.empty()) {
                ans += temp.size();
            } else {
                ans += n + 1;
            }
        }
        return ans;
    }
};