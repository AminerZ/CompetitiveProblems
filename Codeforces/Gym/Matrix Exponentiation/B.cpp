#include <iostream>

using namespace std;

void mult(long long a[2][2], long long b[2][2], long long c[2][2]) {
	c[0][0] = (a[0][0] * b[0][0]) % (1000000007) + (a[0][1] * b[1][0]) % (1000000007);
	c[0][1] = (a[0][0] * b[0][1]) % (1000000007) + (a[0][1] * b[1][1]) % (1000000007);
	c[1][0] = (a[1][0] * b[0][0]) % (1000000007) + (a[1][1] * b[1][0]) % (1000000007);
	c[1][1] = (a[1][0] * b[0][1]) % (1000000007) + (a[1][1] * b[1][1]) % (1000000007);
}

int main() {
	int n;
	cin >> n;

	/*
	P: probelaty that doesnt change mod
	p1 = 1 - p
	p2 = (1-p1)(1-p1) + p1p1 = 1 + 2p1(p1-1)
	p4 = (1-p2)(1-p2) + p2p2 = 1 + 2p2(p2-1)
	110

	*/

	long long p[2][2] = { {19, 7}, {6, 20} };
	long long ans[2][2] = { {1,0}, {0,1} };
	while (n > 0)
	{
		long long temp[2][2];
		if (n % 2) {
			mult(ans, p, temp);
			ans[0][0] = temp[0][0];
			ans[0][1] = temp[0][1];
			ans[1][0] = temp[1][0];
			ans[1][1] = temp[1][1];
		}
		mult(p, p, temp);

		p[0][0] = temp[0][0];
		p[0][1] = temp[0][1];
		p[1][0] = temp[1][0];
		p[1][1] = temp[1][1];
		n /= 2;
	}

	printf("%lld", ans[0][0]);
}
