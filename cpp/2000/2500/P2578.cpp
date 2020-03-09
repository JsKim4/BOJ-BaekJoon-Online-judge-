#include<iostream>
#pragma warning (disable:4996)
using namespace std;
//2078 빙고
int n[5][5];
int s[25];
bool ckB() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		bool tf = true;
		for (int j = 0; j < 5; j++) {
			if (n[i][j] != 0) {
				tf = false;
				break;
			}
		}
		if (tf)
			cnt++;
	}
	for (int i = 0; i < 5; i++) {
		bool tf = true;
		for (int j = 0; j < 5; j++) {
			if (n[j][i] != 0) {
				tf = false;
				break;
			}
		}
		if (tf)
			cnt++;
	}
	bool tf = true;
	for (int i = 0; i < 5; i++) {
		if (n[i][i] != 0) {
			tf = false;
			break;
		}
	}
	if (tf)
		cnt++;
	tf = true;
	for (int i = 0; i < 5; i++) {
		if (n[i][4-i] != 0) {
			tf = false;
			break;
		}
	}
	if (tf)
		cnt++;
	if (cnt >= 3)
		return true;
	return false;
}
int main(){
	for (int i = 0; i < 5;i++) 
		for (int j = 0; j < 5;j++) 
			cin >> n[i][j];
	for (int i = 0; i < 25; i++)
		cin >> s[i];
	for (int i = 0; i < 25;i++) {
		for (int j = 0; j < 25;j++) {
			if (n[j / 5][j % 5] == s[i]) {
				n[j / 5][j % 5] = 0;
				if (ckB()) {
					cout << i + 1;
					return 0;
				}
				break;
			}
		}
	}
}