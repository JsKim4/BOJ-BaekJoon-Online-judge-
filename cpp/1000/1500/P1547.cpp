#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1547 공
int main() {
	int arr[] = { 0,1,2,3 };
	int n; cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for (int i = 0; i < 4;i++) {
		if (arr[i] == 1)
			cout << i;
	}
}