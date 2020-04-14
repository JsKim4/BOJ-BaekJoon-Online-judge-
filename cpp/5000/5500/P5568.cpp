#include<iostream>
#include<map>
#pragma warning (disable:4996)
using namespace std;
// 5568 카드 놓기
int nnn[] = { 0b0000000001 ,0b0000000010 ,0b0000000100 ,0b0000001000 ,0b0000010000 ,0b0000100000 ,0b0001000000 ,0b0010000000 ,0b0100000000 ,0b1000000000 };
int mmm[] = { 0b1111111110 ,0b1111111101 ,0b1111111011 ,0b1111110111 ,0b1111101111 ,0b1111011111 ,0b1110111111 ,0b1101111111 ,0b1011111111 ,0b0111111111 };
int now = 0b0000000000;
int n, k;
map<int,bool>m;
int s[4];
int arr[10];
int answer = 0;
void solve(int i) {
	if (i == k) {
		int tn = 0;
		for (int j = 0; j < k;j++) {
			if (arr[s[j]] >= 10) {
				tn *= 100;
			}
			else
				tn *= 10;
			tn += arr[s[j]];
		}
		if (!m[tn])
			answer++;
		m[tn] = true;
		return;
	}
	for (int j = 0; j < n;j++) {
		if ((now | nnn[j]) != now) {
			s[i] = j;
			now |= nnn[j];
			solve(i + 1);
			now &= mmm[j];
		}
	}
}
int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve(0);
	cout << answer;
}