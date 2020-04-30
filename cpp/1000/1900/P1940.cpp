#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1940 주몽
bool arr[100001] = {};
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	while (n--) {
		int a;
		scanf("%d", &a);
		arr[a] = true;
	}
	if (m >= 200000) {
		cout << 0;
		return 0;
	}
	int answer = 0;
	for (int i = 0;i<m && i <= 100000;i++) {
		if (arr[i]) {
			if (m - i < 0)
				continue;
			if (arr[m - i]&&i!=(m - i)) {
				answer++;
				arr[m - i] = false;
				arr[i] = false;
			}
		}
	}
	cout << answer;
}