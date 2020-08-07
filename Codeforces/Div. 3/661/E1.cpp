#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	long long S;
	cin >> n >> S;
	
	vector<vector<int>> weight(n-1);
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> v >> u >> w;
		weight[v-1][u-1] = w;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int _t;
	cin >> _t;
	while (_t--) {
		solve();
	}
}