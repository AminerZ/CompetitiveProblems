#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 1; i++) {
		if (nums[i + 1] - nums[i] > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;	
}

int main() {
	ios_base::sync_with_stdio(false);
	int _t;
	cin >> _t;
	while (_t--) {
		solve();
	}
}