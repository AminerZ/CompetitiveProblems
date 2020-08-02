#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	getchar();

	for (int _ = 0; _ < t; _++) {
		int n;
		string path;
		cin >> n >> path;

		int x = 0, y = 0;
		map<pair<int, int>, int> ans;
		ans[{ 0,0 }] = 0;

		int l = -1, r = n;

		for (int i = 0; i < n; i++) {
			char o = path[i];
			
			if (o == 'R')
				x++;
			else if (o == 'L')
				x--;
			else if (o == 'U')
				y++;
			else if (o == 'D')
				y--;

			pair<int, int> p = { x,y };
			if (ans.count(p)) {
				if (r - l + 1 > i - ans[p] + 1) {
					l = ans[p];
					r = i;
				}
			}
			ans[p] = i + 1;
		}
		if (l == -1)
			cout << -1 << '\n';
		else
			cout << l+1 << " " << r+1<< '\n';
	}
}