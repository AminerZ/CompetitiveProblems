#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool all_odd = true, all_even = true;
		for (int i = 0; i < n; i++) {
			int d;
			cin >> d;
			if (d % 2 == 0)
				all_odd = false;
			else
				all_even = false;
		}

		if (all_even || (all_odd && n % 2 == 0))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}