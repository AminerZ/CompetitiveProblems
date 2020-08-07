#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	/*
	g = ab
	00, 01, 10, 11
	*/
	vector<int> groups[4];
	for (int i = 0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		groups[2 * a + b].push_back(t);
	}
	
	// Sort all groups
	for(int i = 1; i < 4; i++)
		sort(groups[i].begin(), groups[i].end());

	int read = 0;
	int time = 0;
	while (!groups[3].empty() && read < k ) {
		if (groups[2].empty() || groups[1].empty()) {
			time += *groups[3].begin();
			groups[3].erase(groups[3].begin());
			read++;
			continue;
		}
		if (groups[3][0] <= groups[2][0] + groups[1][0]) {
			time += *groups[3].begin();
			groups[3].erase(groups[3].begin());
			read++;
		}
		else{
			time += *groups[2].begin() + *groups[1].begin();
			groups[2].erase(groups[2].begin());
			groups[1].erase(groups[1].begin());
			read++;
		}
	}
	 if (read >= k) {
		cout << time << '\n';
		return 0;
	}

	while (!groups[2].empty() && !groups[1].empty() && read < k) {
		time += *groups[2].begin() + *groups[1].begin();
		groups[2].erase(groups[2].begin());
		groups[1].erase(groups[1].begin());
		read++;
	}

	if (read >= k)
		cout << time << '\n';
	else
		cout << -1 << '\n';

}