#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1914 하노이 탑
int move(int i,int from, int by,int to) {
	if (i == 1) {
		printf("%d %d\n",from,to);
		return 0;
	}
	move(i - 1, from,to,by);
	printf("%d %d\n", from, to);
	move(i - 1, by,from, to);
	return 0;
}
int main(){

	unsigned long long  n;
	cin >> n;
	long long cnt1 = 1;
	long long cnt2 = 0;
	for (int i = 1; i < n; i++) {
		cnt2 *= 2;
		cnt1 *= 2;
		cnt1 += 1;
		cnt2 += cnt1 / 10000000000000000;
		cnt1 %= 10000000000000000;
	}
	if (cnt2 > 0)
		cout << cnt2;
	cout << cnt1 << endl;
	if (n > 20)
		return 0;
	move(n, 1,2, 3);
	return 0;
}