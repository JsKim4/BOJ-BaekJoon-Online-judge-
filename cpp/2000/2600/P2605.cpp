#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2605 줄세우기
int arr[100];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;
		for (int j = 0; j < i;j++) {
			if (arr[j] > i - a) {
				arr[j]++;
			}
		}
		arr[i] = i - a + 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n;j++) {
			if (arr[j] == i) {
				cout << j+1 << " ";
				break;
			}
		}
	}
}