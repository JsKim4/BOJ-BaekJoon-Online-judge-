#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2693 N번째 큰 수
int main(){
	int T;
	cin >> T;
	while (T--) {
		int arr[10];
		for (int i = 0; i < 10;i++) 
			cin >> arr[i];
		sort(arr, arr + 10);
		cout << arr[7]<<endl;
	}
}