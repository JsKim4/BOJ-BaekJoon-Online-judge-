#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 10819 차이를 최대로
int sel[8];
int nnn[] = { 0b00000001 ,0b00000010 ,0b00000100 ,0b00001000 ,0b00010000 ,0b00100000 ,0b01000000 ,0b10000000 };
int now = 0b000000;
int mmm[] = { 0b11111110 ,0b11111101 ,0b11111011 ,0b11110111 ,0b11101111 ,0b11011111 ,0b10111111 ,0b01111111 };
int answer = 0;
int num[8];
void nm(int i,int n) {
	if (i == n) {
		int sum = 0;
		for (int i = 0; i < n-1;i++) {
			sum += abs(num[sel[i]]-num[sel[i+1]]);
		}
		//cout << sum << endl;
		if (sum > answer)
			answer = sum;
	}
	for (int j=0; j < n;j++) {
		if ((now | nnn[j]) != now) {
			now |= nnn[j];
			sel[i] = j;
			nm(i + 1, n);
			now &= mmm[j];
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> num[i];
	}
	nm(0, n);
	cout << answer;
}