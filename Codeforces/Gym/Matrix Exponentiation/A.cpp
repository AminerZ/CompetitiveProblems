#include <iostream>

using namespace std;

int main() {
	int n;
	double p;
	cin >> n >> p;

	/*
	P: probelaty that doesnt change mod
	p1 = 1 - p
	p2 = (1-p1)(1-p1) + p1p1 = 1 + 2p1(p1-1)
	p4 = (1-p2)(1-p2) + p2p2 = 1 + 2p2(p2-1)
	110

	*/

	double ans = 1;
	p = 1 - p;
	while (n>0)
	{
		if (n % 2) ans = ans*p + (1-p)*(1-ans);
		p = 1 + 2 * p * (p - 1);
		n /= 2;
	}

	printf("%.10f", ans);
}