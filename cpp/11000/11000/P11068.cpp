#include<iostream>
#include<deque>
#pragma warning (disable:4996)
using namespace std;
// 11068 회문인 수
deque<int>d;
bool ck(int n, int i) {
//	cout << i << endl;
	while (n >= i) {
		d.push_back(n % i);
		n /= i;
	}
	d.push_back(n);
	while (d.size() > 1) {
		//cout << d.front() << " " << d.back()<<endl;
		if (d.front() != d.back()) {
			//cout << "\n\n";
			return false;
		}
		d.pop_back();
		d.pop_front();
	}
//	cout << "\n\n";
	return true;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool ckh = true;
		for (int i = 2; i <= 64; i++) {
			while (!d.empty()) d.pop_back();
			if (ck(n, i)) {
				cout << 1 << endl;
				ckh = false;
				break;
			}
		}
		if (ckh) {
			cout << 0 << endl;
		}
	}
}