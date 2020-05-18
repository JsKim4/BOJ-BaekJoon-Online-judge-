#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 16928 뱀과 사다리 게임
int n, m;
int arr[101];
int answer[101];
int avail(int i) {
	if (i > 0 && i <= 100 )
		return true;
	return false;
}
int main(){
	cin >> n >> m;
	while (n--) {
		int a, b;
		cin >> a >> b;
		arr[a]=b;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 1; i < 101; i++)
		answer[i] = 2100000000;
	answer[1] = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int num = q.front(); q.pop();
		int cnt = answer[num];
		for (int i = 1; i <= 6;i++) {
			int ni = num + i;
			if (arr[ni] != 0)
				ni = arr[ni];
			if (avail(ni) && answer[ni] > cnt+1) {
				answer[ni] = cnt + 1;
				q.push(ni);
			}
		}
	}
	cout << answer[100];
}