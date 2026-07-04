class Solution {
	public:
	int maxSumSubarray(vector<int>& arr) {
		int keep = arr[0];
		int drop = INT_MIN;
		int ans = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			if (drop == INT_MIN) {
				drop = keep;
			} else {
				drop = max(drop + arr[i], keep);
			}
			keep = max(keep + arr[i], arr[i]);
			ans = max(ans, max(drop, keep));
		}
		return ans;
		
	}
};
