#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1977 완전제곱수
int arr[102];
int main(){
	for (int i = 0; i < 102;i++) {
		arr[i] = i * i;
	}
	int a, b;
	cin >> a >> b;
	int i;
	for (i = 0; arr[i] <a; i++);
	int m = arr[i];
	int sum = 0;
	for (; b >= arr[i];i++) {
		sum += arr[i];
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << " " << m;
}