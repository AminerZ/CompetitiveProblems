#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> tests(t);

	for (int i = 0; i < t; i++)
		cin >> tests[i];

	for (auto t : tests) {
		int n = t;
		int res = 0;
		while (n > 9) {
			int s = (n / 10);
			s *= 10;
			res += s;
			n = n % 10 + n / 10;
		}
		res += n;
		cout << res << endl;
	}
}