#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 2056  작업
int N[10001], n, k;
vector<int> nk[10001];
int kk[10001];
void init() {
	for (int i = 0; i <= n; i++) {
		kk[i] = -1;
		while (!nk[i].empty()) {
			nk[i].pop_back();
		}
	}
}
int solve(int j) {
	int m = 0;
	if (kk[j] != -1)
		return kk[j];
	for (int i = 0; i < nk[j].size(); i++) {
		int num = solve(nk[j][i]);
		if (num > m) {
			m = num;
		}
	}
	kk[j] = N[j] + m;
	return kk[j];
}
int main() {
	cin >> n ;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> N[i] >> k;
		while (k--) {
			int a;
			cin >> a;
			nk[i].push_back(a);
		}
	}
	int answer=0;
	for (int i = 1; i <= n;i++) {
		int num = solve(i);
		if (answer < num)
			answer  = num;
	}
	cout << answer << endl;
}