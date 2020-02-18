#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 3052 나머지
bool num[42];
int main(){
	for (int i = 0; i < 10;i++) {
		int k;
		cin >> k;
		num[k % 42]=true;
	}
	int ans = 0;
	for (int i = 0; i < 42;i++) {
		if (num[i])
			ans++;
	}
	cout << ans;
}