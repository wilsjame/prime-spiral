#include <iostream>
#include <vector>
using namespace std;

#define ll long long

bool sieve (ll n) {
	if (n < 2) return false;
	for (int x = 2; x * x <= n; x++) {
		if (n % x == 0) return false;
	}
	return true;
}

/* square Ulam's spiral
 1 in top left corner
 1 2 9
 4 3 8
 5 6 7
 numbers on main diagonal a(n) = n^2 - n + 1 */
int spiral (ll S) {
	char nonprime, P;
	nonprime = '.';
	P = '0';
	vector<vector<char>> B(S, vector<char> (S, nonprime));

	for (int i = 0; i < S; i++) {
		ll left, up, corner;
		left = up = corner = (i + 1) * (i + 1) - (i + 1) + 1;

		if (sieve(corner))
			B[i][i] = P;
		if ((i + 1) % 2) {
			for (int k = i - 1; k >= 0; k--)
				if (sieve(--left))
					B[i][k] = P;
			for (int k = i - 1; k >= 0; k--)
				if (sieve(++up))
					B[k][i] = P;
		}
		else {
			for (int k = i - 1; k >= 0; k--)
				if (sieve(++left))
					B[i][k] = P;
			for (int k = i - 1; k >= 0; k--)
				if (sieve(--up))
					B[k][i] = P;
		}
	}	
	for (auto row : B) {
		for (auto a : row) {
			cout << a << " ";
		}
		cout << endl;
	}

	return 0;
}

int main() {
	ll size;
	cin >> size;
	spiral(size);

	return 0;
}
