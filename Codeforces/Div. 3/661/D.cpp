#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> end0, end1, ans;

	int gid = 0;

	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		
		if (t == '1') {
			if (!end0.empty()) {
				auto it = end0.back();
				end1.push_back(it);
				end0.pop_back();

				ans.push_back(it);
			}
			else {
				gid++;
				end1.push_back(gid);
				ans.push_back(gid);
			}
		} else if (t == '0') {
			if (!end1.empty()) {
				auto it = end1.back();
				end0.push_back(it);
				end1.pop_back();

				ans.push_back(it);
			}
			else {
				gid++;
				end0.push_back(gid);
				ans.push_back(gid);
			}
		}
	}
	cout << end0.size() + end1.size() << '\n';
	for (auto it : ans)
		cout << it << " ";
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	int _t;
	cin >> _t;
	while (_t--) {
		solve();
	}
}