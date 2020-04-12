#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10163 색종이
int n;
int arr[101][101];
int nn[101];
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int ii= a; ii < a+c;ii++) {
			for (int j = b; j < b+d;j++) {
				arr[ii][j] = i + 1;
			}
		}
	}
	for (int i = 0; i < 101;i++) {
		for (int j = 0; j < 101;j++) {
			nn[arr[i][j]]++;
		}
	}
	for (int i = 1; i <= n;i++) {
		cout << nn[i] << endl;
	}
}