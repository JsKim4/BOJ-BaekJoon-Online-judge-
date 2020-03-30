#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 14888 연산자 끼워넣기
int arr[11];
int n;
long long mx = -2100000000, mn = 2100000000;
void solve(long long num,int i,int add,int sub,int mul,int div) {
	if (num > 1000000000 && num < -1000000000)
		return;
	if (i == n - 1) {
		if (mx < num)
			mx = num;
		if (mn > num)
			mn = num;
		return;
	}
	if (add > 0)
		solve(num + arr[i + 1], i + 1, add - 1, sub, mul, div);
	if (sub > 0)
		solve(num - arr[i + 1], i + 1, add, sub - 1, mul, div);
	if (mul > 0)
		solve(num * arr[i + 1], i + 1, add, sub, mul - 1, div);
	if (div > 0)
		solve(num / arr[i + 1], i + 1, add, sub, mul, div - 1);
	
}
int main(){
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	int add, sub, mul, div;
	cin >> add >> sub >> mul >> div;
	solve(arr[0],0,add,sub,mul,div);
	cout << mx << "\n" << mn;
}