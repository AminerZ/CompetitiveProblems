#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 1;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);

	int min_a = INF, min_b = INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		min_a = min(min_a, a[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		min_b = min(min_b, b[i]);
	}

	long long moves = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > min_a && b[i] > min_b)
			moves += max(a[i] - min_a , b[i] - min_b);
		else if (a[i] > min_a)
			moves +=  a[i] - min_a;
		else if (b[i] > min_b)
			moves += b[i] - min_b;
	}
	cout << moves << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int _t;
	cin >> _t;
	while (_t--) {
		solve();
	}
}