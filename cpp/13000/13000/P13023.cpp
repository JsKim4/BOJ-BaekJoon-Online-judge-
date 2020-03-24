#include<iostream>
#include<queue>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 13023 ABCDE
int n,m;
vector<int> arr[2000];
bool v[2000];
void init() {
	for (int i = 0; i < n;i++) {
		v[i] = 0;
	}
}
bool dfs(int i,int cnt) {
	if (cnt == 5) {
		return true;
	}
	v[i] = true;
	bool answer = false;
	for (int j = 0; j < arr[i].size();j++) {
		int next = arr[i][j];
		if (v[next] == false) {
			answer = dfs(next, cnt + 1);
			if (answer)
				return true;
		}
	}
	v[i] = false;
	return false;

}
int main(){
	cin >> n >> m;
	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	init();
	for (int i = 0; i < n;i++) {
		if (dfs(i, 1)) {
			cout << 1;
			return 0;
		}
		init();
	}
	cout << 0;
}