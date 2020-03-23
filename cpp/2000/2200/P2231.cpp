#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2231 분해합
int n[1000001];
int main(){
	int ans;
	cin >> ans;
	for (int i = 1; i <= 1000000; i++) {
		int sum = i;
		for (int j = 1; j <= 1000000; j *= 10) {
			sum += (i % (j * 10)) / j;
		}
		if (n[sum] == 0)
			n[sum] = i;
	}
	cout << n[ans];
}