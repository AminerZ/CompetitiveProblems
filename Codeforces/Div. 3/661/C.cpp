#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> w(n), cnt(n+1);
	for (auto& it : w) {
		cin >> it;
		cnt[it]++;
	}

	int ans = 0;
	for (int s = 2; s <= 2 * n; s++) {
		int teams = 0;
		for (int i = 1; i < (s+1) / 2; i++) {
			if (s - i > n)
				continue;
			teams += min(cnt[i], cnt[s - i]);
		}
		if (s % 2 == 0) 
			teams += cnt[s/2]/2;
		ans = max(ans, teams);
	}
	cout << ans <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int _t;
	cin >> _t;
	while (_t--) {
		solve();
	}
}