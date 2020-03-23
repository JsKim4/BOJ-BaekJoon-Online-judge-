#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 별 찍기 - 15
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n-i-1;j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < i * 2 - 1;j++) {
			cout << " ";
		}
		if (i == 0) {
			cout << "\n";
			continue;
		}
		cout << "*\n";
	}
}