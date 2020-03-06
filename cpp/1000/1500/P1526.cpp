#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1526 가장 큰 금민수
bool check(int n) {
	int wt = 1;
	for (; wt <= n; wt *= 10);
	for (; wt > 1; wt /= 10) {
		if ((n % wt) / (wt / 10) != 4 && (n % wt) / (wt/10) != 7)
			return false;
	}
	return true;
}
int main(){
	int n=45;
	cin >> n;
	for (int i = n; i >= 0;i--) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
}