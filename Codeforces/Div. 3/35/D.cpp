#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int mi = min(a, b);

	int ans = 0;
	vector<int> ulti;
	for (int i = 0; i < n; i++) {
		int hp;
		cin >> hp;
		int m = ceil((double)(hp - a) / (a+b));
		int dmg = m * (a + b) + a;
		bool can_kill = hp - dmg > -a;
		if (can_kill) {
			ans++;
			continue;
		}

		int needed_k = 0;
		
		if (!can_kill) {
			int hb4d = hp - dmg + a + b;
			needed_k = ceil((float) hb4d / a);
		}

		ulti.push_back(needed_k);
		//char p = can_kill ? 'Y' : 'N';
		//cout << hp << " " << m << " "  << ceil((float)(hp - a) / (a + b)) << " " << p << needed_k << endl;
		
	}
	sort(ulti.begin(), ulti.end());
	for (int i = 0; i < ulti.size(); i++) {
		if (k - ulti[i] >= 0) {
			ans++;
			k -= ulti[i];
		}
		else
			break;
	}
	cout << ans;
}