#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 9625 BABBA
int main(){
	int k;
	int a[2] = { 1,0 };
	cin >> k;
	while (k--) {
		a[0] += a[1];
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	cout << a[0] << " " << a[1];
}