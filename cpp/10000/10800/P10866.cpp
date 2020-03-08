#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10866 0 = not cute / 1 = cute
int main() {
	int k; cin >> k; int q = 0;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n)
			q++;
	}
	if (q >= (k / 2 + k % 2))
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";
}