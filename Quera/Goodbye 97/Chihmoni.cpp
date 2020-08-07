#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> events;

	for (int i = 0; i < n; i++) {
		string name;
		int h, m;
		char type;
		cin >> name >> h;
		cin.ignore(1) >> m >> type;
		
		events.push_back({ {h, m}, type == '+' ? +1 : -1 });
	}

	sort(events.begin(), events.end());

	int best = 0;
	int present = 0;
	pair<int, int> ans;
	for (int i = 0; i < events.size(); i++) {
		present += events[i].second;
		if (present > best) {
			best = present;
			ans = events[i].first;
		}
	}

	cout << ans.first <<":" << ans.second;
}