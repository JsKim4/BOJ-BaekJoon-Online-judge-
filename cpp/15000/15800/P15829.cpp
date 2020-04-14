#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;
// 15829 Hashing
long long arr[50] = {1};
long long M = 1234567891;
int main(){
	for (int i = 1; i < 50;i++) {
		arr[i] = (arr[i - 1] * 31) % M;
	}
	int n;
	string s;
	cin >> n;
	cin >> s;
	long long sum = 0;
	for (int i = 0; i < n;i++) {
		sum += ((s[i] - 'a' + 1) * arr[i])%M;
	}
	cout << sum%M;
}