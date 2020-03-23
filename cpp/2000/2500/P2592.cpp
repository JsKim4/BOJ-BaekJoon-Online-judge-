#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2592 대표값
int num[1001];
int main(){
	int sum = 0;
	int n = 10;
	while (n--) {
		int a;
		cin >> a;
		num[a]++;
		sum += a;
	}
	cout << sum / 10 << " ";
	int mm = 0, nn = 0;
	for (int i = 0; i < 1001;i++) {
		if (mm < num[i]) {
			mm = num[i];
			nn = i;
		}
	}
	cout << nn;
}