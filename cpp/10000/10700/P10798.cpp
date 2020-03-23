#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10798 세로읽기
char a[5][16];
int main(){
	for (int i = 0; i < 5;i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 15;i++) {
		for (int j = 0; j < 5;j++) {
			if (a[j][i] != 0)
				cout << a[j][i];
		}
	}
}