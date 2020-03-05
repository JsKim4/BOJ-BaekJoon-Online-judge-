#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 1527 금민수의 개수
int ni[11];
int mi[11];

int wt(int n) {
	int i = 1;
	for (; (int)pow(10, i) <= n; i++);
	return i-1;
}
int main() {
	int n, m;
	for (int i = 0; i < 11; i++) {
		ni[i] = -1;
		mi[i] = -1;
	}
	cin >> n >> m;

	for (int i = wt(n); i >= 0; i--) {
		int num = (n % (int)pow(10, i + 1)) / (int)pow(10, i);
		if (num > 7) {
			ni[i + 1]++;
			ni[i] = 0;
		}
		else if (num > 4)
			ni[i] = 1;
		else
			ni[i] = 0;
	}
	for (int i = wt(m); i >= 0; i--) {
		int num = (m % (int)pow(10, i + 1)) / (int)pow(10, i);
		if (num > 7) {
			mi[i + 1]++;
			mi[i] = 0;
		}
		else if (num > 4)
			mi[i] = 1;
		else
			mi[i] = 0;
	}
	int nn = 0;
	for (; ni[nn] != -1; nn++) {
		if (ni[nn] == 2) {
			ni[nn] = 0;
			ni[nn + 1]++;
		}
	}
	int mm = 0;
	for (; mi[mm] != -1; mm++) {
		if (ni[mm] == 2) {
			ni[mm] = 0;
			ni[mm + 1]++;
		}
	}
	for (int i = 0; i < nn; i++) {
		cout << ni[i];
	}
	cout << endl;
	for (int i = 0; i < mm; i++) {
		cout << ni[i];
	}

}