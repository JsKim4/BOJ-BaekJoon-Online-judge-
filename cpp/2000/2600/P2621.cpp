#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2621 카드게임
int n[5];
int color[4];
int value[11];
int main() {
	for (int i = 0; i < 5; i++) {
		char a; int b, c;
		cin >> a >> b;
		if (a == 'R')
			c = 0;
		if (a == 'B')
			c = 1;
		if (a == 'Y')
			c = 2;
		if (a == 'G')
			c = 3;
		color[c]++;
		value[b]++;
	}
	int h;
	for (int i = 10; i > 0;i--) {
		if (value[i] == 1) {
			h = i;
			break;
		}
	}
	bool ex = false; int c = 0; 
	for (int i = 10; i > 0; i--) {
		if (ex == true && value[i] != 1) {
			break;
		}
		else if (value[i] == 1) {
			ex = true;
			c++;
		}
	}
	if (c == 5)
		ex = true;
	else
		ex = false;
	for (int i = 0; i < 4;i++) {
		if (color[i] == 5) {
			if (ex)
				cout << 900 + h;
			else
				cout << 600 + h;
			return 0;
		}
	}
	if (ex) {
		cout << 500 + h;
		return 0;
	}
	for (int i = 5; i > 0; i--) {
		for (int j = 10; j > 0; j--) {
			if (value[j] == i) {
				if (i == 4) 
					cout << 800 + j;
				else if (i == 3) {
					for (int w = 10; w > 0;w--) {
						if (value[w] == 2) {
							cout << 700 + j * 10 + w;
							return 0;
						}
					}
					cout << 400 + j;
				}
				else if (i == 2) {
					for (int w = j - 1; w > 0; w--) {
						if (value[w] == 2) {
							cout << 300 + j * 10 + w;
							return 0;
						}
					}
					cout << 200 + j;
				}
				else
					cout << 100 + h;
				return 0;
			}
		}
	}
}