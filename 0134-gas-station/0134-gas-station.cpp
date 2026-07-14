class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        gas.insert(gas.end(), gas.begin(), gas.end());
        cost.insert(cost.end(), cost.begin(), cost.end());
        for (int i = 0; i < n; i++) {
            int cgas = 0;
            bool ohk = false;
            for (int j = i; j < i + n; j++) {
                cgas += gas[j];
                if (cgas < cost[j]) {
                    ohk = true;
                    i=j;
                    break;
                }
                cgas -= cost[j];
            }
            if (!ohk) {
                if (cgas >= 0)
                    return i;
            }
        }
        return -1;
    }
};