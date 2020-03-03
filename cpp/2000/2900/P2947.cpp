#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2947 나무 조각
int main(){
	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 4 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				for (int ii = 0; ii < 5; ii++) {
					cout << arr[ii] << " ";
				}
				cout << endl;
			}
		}
	}
}