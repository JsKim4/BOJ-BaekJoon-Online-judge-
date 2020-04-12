#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1453 피시방 알바
bool arr[101];
int main(){
	int n; cin >> n;
	int cnt = 0;
	while (n--) {
		int a; cin >> a;
		if (arr[a])
			cnt++;
		arr[a] = 1;
	}
	cout << cnt;
}