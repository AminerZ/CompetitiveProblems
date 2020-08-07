#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> count(n + 1);

	for (long long a = 1; a <= n; a++) {
		for (long long b = a; b <= n; b++) {
			for (long long c = b; c <= n; c++) {
				if (a * b * c <= n)
					++count[a * b * c];
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << count[i] << '\n';
}