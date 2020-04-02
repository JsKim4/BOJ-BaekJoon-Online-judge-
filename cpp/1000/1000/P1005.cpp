#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 1005 ACM Craft
int N[1001], n,k;
vector<int> nk[1001];
int kk[1001];
void init() {
	for (int i = 0; i <= n;i++) {
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
	for (int i = 0; i < nk[j].size();i++) {
		int num = solve(nk[j][i]);
		if (num> m) {
			m = num;
		}
	}
	kk[j] = N[j] + m;
	return kk[j];
}
int main(){
	int T; cin >> T;
	while (T--) {
		cin >> n >> k;
		init();
		for (int i = 1; i <= n;i++) 
			cin >> N[i];
		for (int i = 0; i < k;i++) {
			int a,b;
			cin >> a >> b;
			nk[b].push_back(a);
		}
		int answer; cin >> answer;
		cout << solve(answer) << endl;
	}
}